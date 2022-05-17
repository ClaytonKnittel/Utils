
/**********************************************************
 *                        Includes                        *
 **********************************************************/

#include <utils/algorithms/rect_packing.h>


/**********************************************************
 *                  Forward Declarations                  *
 **********************************************************/

static packed_rect_el_t* _node_base_to_el(const rb_node_t*);

static packed_rect_row_t* _node_base_height_to_row(const rb_node_t*);
static packed_rect_row_t* _node_base_ly_to_row(const rb_node_t*);
static packed_rect_el_t* _row_freelist_terminal(const packed_rect_row_t* row);
static void _row_freelist_insert(packed_rect_el_t* after, packed_rect_el_t* el);
static void _row_freelist_remove(packed_rect_el_t* el);
static void _row_remove(packed_rect_row_t* row, packed_rect_el_t* el);


/**********************************************************
 *               Red-Black Tree Definitions               *
 **********************************************************/

static int
_rb_cmp_packed_rect_el(const rb_node_t* a_ptr, const rb_node_t* b_ptr)
{
	const packed_rect_el_t* a = _node_base_to_el(a_ptr);
	const packed_rect_el_t* b = _node_base_to_el(b_ptr);
	return a->lx < b->lx ? -1 : a->lx == b->lx ? 0 : 1;
}

RB_DEFINE_TYPE(packed_rect_el, _rb_cmp_packed_rect_el)

static int
_rb_cmp_packed_rect_row_height(const rb_node_t* a_ptr, const rb_node_t* b_ptr)
{
	const packed_rect_row_t* a = _node_base_height_to_row(a_ptr);
	const packed_rect_row_t* b = _node_base_height_to_row(b_ptr);
	return a->h < b->h ? -1 : a->h == b->h ? 0 : 1;
}

RB_DEFINE_TYPE(packed_rect_row_height, _rb_cmp_packed_rect_row_height)

static int
_rb_cmp_packed_rect_row_ly(const rb_node_t* a_ptr, const rb_node_t* b_ptr)
{
	const packed_rect_row_t* a = _node_base_ly_to_row(a_ptr);
	const packed_rect_row_t* b = _node_base_ly_to_row(b_ptr);
	return a->ly < b->ly ? -1 : a->ly == b->ly ? 0 : 1;
}

RB_DEFINE_TYPE(packed_rect_row_ly, _rb_cmp_packed_rect_row_ly)


/**********************************************************
 *                    Element Helpers                     *
 **********************************************************/

static packed_rect_el_t*
_node_base_to_el(const rb_node_t* rb_node_base)
{
	return (packed_rect_el_t*) (((uint8_t*) rb_node_base) -
			offsetof(packed_rect_el_t, rb_node_base));
}

/*
 * Creates a new empty rectangle element object, initializing the given fields
 * without inserting it into any of the data structures it will eventually be a
 * member of.
 */
static packed_rect_el_t*
_alloc_empty_el(packed_rect_coord_t lx, packed_rect_coord_t w)
{
	packed_rect_el_t* el = (packed_rect_el_t*) malloc(sizeof(packed_rect_el_t));
	if (el == NULL) {
		return NULL;
	}

	el->lx = lx;
	el->w = w;

	return el;
}

/*
 * Creates a new allocated rectangle element object.
 */
static packed_rect_el_t*
_alloc_el(packed_rect_coord_t lx, packed_rect_coord_t ly,
		packed_rect_coord_t w, packed_rect_coord_t h, bool rotated)
{
	packed_rect_el_t* el = (packed_rect_el_t*) malloc(sizeof(packed_rect_el_t));
	if (el == NULL) {
		return NULL;
	}

	el->lx = lx;
	el->ly = ly;
	el->w = w;
	el->h = h;
	el->rotated = rotated;

	return el;
}

static void
_free_el(packed_rect_el_t* el)
{
	free(el);
}

static uint64_t
_calc_el_loss(const packed_rect_row_t* row, const packed_rect_el_t* el,
		packed_rect_coord_t w, packed_rect_coord_t h)
{
	return el->w * row->h - w * h;
}


/**********************************************************
 *                      Row Helpers                       *
 **********************************************************/

static packed_rect_row_t*
_node_base_height_to_row(const rb_node_t* rb_node_base)
{
	return (packed_rect_row_t*) (((uint8_t*) rb_node_base) -
			offsetof(packed_rect_row_t, rb_node_base_height));
}

static packed_rect_row_t*
_node_base_ly_to_row(const rb_node_t* rb_node_base)
{
	return (packed_rect_row_t*) (((uint8_t*) rb_node_base) -
			offsetof(packed_rect_row_t, rb_node_base_ly));
}

/*
 * Given a row, returns the pointer it should use as the freelist start/end
 * pointers (i.e. what the first element's prev pointer and the last element's
 * end pointer should be).
 */
static packed_rect_el_t*
_row_freelist_terminal(const packed_rect_row_t* row)
{
	return (packed_rect_el_t*) (((uint8_t*) &row->freelist_start) -
			offsetof(packed_rect_el_t, next));
}

/*
 * Inserts an empty rectangle after the given element.
 */
static void
_row_freelist_insert(packed_rect_el_t* after, packed_rect_el_t* el)
{
	el->next = after->next;
	el->prev = after;
	after->next = el;
	el->next->prev = el;
}

/*
 * Removes an empty rectangle from the node's freelist.
 */
static void
_row_freelist_remove(packed_rect_el_t* el)
{
	packed_rect_el_t* prev = el->prev;
	packed_rect_el_t* next = el->next;

	prev->next = next;
	next->prev = prev;
}

/*
 * Creates a new row object and returns a pointer to it without initializing the
 * rb_node_base or parent_bin pointer elements.
 */
static packed_rect_row_t*
_alloc_row(packed_rect_coord_t ly, packed_rect_coord_t row_w,
		packed_rect_coord_t row_h)
{
	packed_rect_el_t* empty_el;
	packed_rect_el_t* freelist_terminal;

	packed_rect_row_t* row =
		(packed_rect_row_t*) malloc(sizeof(packed_rect_row_t));
	if (row == NULL) {
		return NULL;
	}

	empty_el = _alloc_empty_el(0, row_w);
	if (empty_el == NULL) {
		free(row);
		return NULL;
	}

	row->ly = ly;
	row->h = row_h;

	rb_init(&row->elements);
	rb_insert_packed_rect_el(&row->elements, &empty_el->rb_node_base);

	// Insert empty_el into the freelist.
	row->freelist_start = empty_el;
	row->freelist_end = empty_el;

	// Point empty_el to the freelist terminal
	freelist_terminal = _row_freelist_terminal(row);
	empty_el->next = freelist_terminal;
	empty_el->prev = freelist_terminal;

	return row;
}

static void
_free_row(packed_rect_row_t* row)
{
	rb_node_t* node_ptr;
	rb_for_each_mod(&row->elements, node_ptr) {
		packed_rect_el_t* el = _node_base_to_el(node_ptr);
		rb_remove_packed_rect_el(&row->elements, node_ptr);
		_free_el(el);
	}
	rb_for_each_mod_fin();

	free(row);
}

/*
 * Removes an element from the row freelist/
 */
static void
_row_remove(packed_rect_row_t* row, packed_rect_el_t* el)
{
	_row_freelist_remove(el);
	rb_remove_packed_rect_el(&row->elements, &el->rb_node_base);
}

/*
 * Finds the rectangle of smallest width greater or equal to the given width in
 * this row.
 *
 * Returns NULL if no elements in the row have sufficient width.
 */
static packed_rect_el_t* __attribute__ ((noinline))
_row_find_fit(const packed_rect_row_t* row, packed_rect_coord_t w)
{
	packed_rect_el_t* freelist_end = _row_freelist_terminal(row);
	for (packed_rect_el_t* el = row->freelist_start; el != freelist_end; el = el->next) {
		if (el->w >= w) {
			return el;
		}
	}
	return NULL;
}

static packed_rect_el_t*
_split_el(rect_packing_t* packing, packed_rect_row_t* row, packed_rect_el_t* el,
		packed_rect_coord_t w, packed_rect_coord_t h, bool was_rotated)
{
	packed_rect_el_t* new_el;

	packed_rect_el_t* terminal = _row_freelist_terminal(row);
	packed_rect_el_t* first_el = row->freelist_start;
	bool row_was_empty = first_el->next == terminal && first_el->lx == 0 &&
		first_el->w == packing->bin_w;

	// if the element is tall enough, flip this rectangle on its side (w >= h).
	if (!row_was_empty && row->h >= w) {
		packed_rect_coord_t tmp = w;
		w = h;
		h = tmp;

		was_rotated = !was_rotated;
	}

	if (el->w == w) {
		_row_freelist_remove(el);
		rb_remove_packed_rect_el(&row->elements, &el->rb_node_base);
		new_el = el;

		new_el->ly = row->ly;
		new_el->h = h;
		new_el->rotated = was_rotated;
		new_el->parent_row = row;
		goto adjust_row;
	}

	new_el = _alloc_el(el->lx, row->ly, w, row->h, was_rotated);
	new_el->ly = row->ly;
	new_el->h = h;
	new_el->parent_row = row;

	el->lx += w;
	el->w -= w;

	// search for where to re-insert the remainder el in the freelist, which
	// is sorted by width:
	packed_rect_el_t* prev = el->prev;
	for (; prev != terminal && prev->w > el->w; prev = prev->prev);

	_row_freelist_remove(el);
	_row_freelist_insert(prev, el);

	// No need to adjust the position of el in the rb tree, it hasn't
	// shifted laterally, just shrunk.

adjust_row:
	if (row_was_empty && h < row->h) {
		// split the row
		packed_rect_row_t* split_row = _alloc_row(row->ly + h, packing->bin_w, row->h - h);

		packed_rect_bin_t* bin = row->parent_bin;
		split_row->parent_bin = bin;
		row->h = h;

		// reinsert row into the rows height tree
		rb_remove_packed_rect_row_height(&packing->rows_height, &row->rb_node_base_height);
		rb_insert_packed_rect_row_height(&packing->rows_height, &row->rb_node_base_height);

		// insert the new row into both trees
		rb_insert_packed_rect_row_height(&packing->rows_height, &split_row->rb_node_base_height);
		rb_insert_packed_rect_row_ly(&bin->rows_ly, &split_row->rb_node_base_ly);
	}

	return new_el;
}


/**********************************************************
 *                      Bin Helpers                       *
 **********************************************************/

static int
_alloc_bin(rect_packing_t* packing)
{
	packed_rect_row_t* row;
	packed_rect_bin_t* bin =
		(packed_rect_bin_t*) vector_reserve(&packing->bin_list);
	if (bin == NULL) {
		return -1;
	}

	row = _alloc_row(0, packing->bin_w, packing->bin_h);
	if (row == NULL) {
		vector_pop(&packing->bin_list);
		return -1;
	}

	row->parent_bin = bin;

	rb_init(&bin->rows_ly);

	rb_insert_packed_rect_row_ly(&bin->rows_ly, &row->rb_node_base_ly);
	rb_insert_packed_rect_row_height(&packing->rows_height,
			&row->rb_node_base_height);

	return 0;
}

static void
_free_bin(rect_packing_t* packing, packed_rect_bin_t* bin)
{
	rb_node_t* node_ptr;
	rb_for_each_mod(&bin->rows_ly, node_ptr) {
		packed_rect_row_t* row = _node_base_ly_to_row(node_ptr);

		rb_remove_packed_rect_row_ly(&bin->rows_ly, node_ptr);
		rb_remove_packed_rect_row_height(&packing->rows_height, &row->rb_node_base_height);

		_free_row(row);
	}
	rb_for_each_mod_fin();
}

static uint32_t
_calc_bin_idx(const rect_packing_t* packing, const packed_rect_bin_t* bin)
{
	const packed_rect_bin_t* first_el =
		(const packed_rect_bin_t*) vector_get((vector_t*) &packing->bin_list, 0);
	return (uint32_t) (bin - first_el);
}


/**********************************************************
 *                     Public Methods                     *
 **********************************************************/

int
rect_packing_init(rect_packing_t* packing, packed_rect_coord_t bin_w,
		packed_rect_coord_t bin_h)
{
	if (vector_init(&packing->bin_list, sizeof(packed_rect_bin_t), 4) != 0) {
		return -1;
	}

	rb_init(&packing->rows_height);

	packing->bin_w = bin_w;
	packing->bin_h = bin_h;

	if (_alloc_bin(packing) != 0) {
		rb_free(&packing->rows_height);
		vector_free(&packing->bin_list);
		return -1;
	}

	return 0;
}

void
rect_packing_free(rect_packing_t* packing)
{
	uint64_t n_bins = vector_size(&packing->bin_list);
	for (uint64_t i = 0; i < n_bins; i++) {
		packed_rect_bin_t* bin =
			(packed_rect_bin_t*) vector_get(&packing->bin_list, i);
		_free_bin(packing, bin);
	}
	rb_free(&packing->rows_height);
	vector_free(&packing->bin_list);
}

packed_rect_el_t*
rect_packing_insert(rect_packing_t* packing, packed_rect_coord_t w,
		packed_rect_coord_t h)
{
	bool rotated;
	if ((rotated = (h > w))) {
		packed_rect_coord_t tmp = w;
		w = h;
		h = tmp;
	}

	packed_rect_row_t* pseudo_row =
		(packed_rect_row_t*) (((uint8_t*) &h) - offsetof(packed_rect_row_t, h));
	rb_node_t* candidate_row_base =
		rb_lower_bound_packed_rect_row_height(&packing->rows_height,
				&pseudo_row->rb_node_base_height);

	packed_rect_row_t* row = _node_base_height_to_row(candidate_row_base);
	packed_rect_row_t* best_row;
	packed_rect_el_t* best_fit = NULL;
	uint64_t best_loss;

	while (candidate_row_base != LEAF /*&& row->h < 2 * h*/) {
		packed_rect_el_t* el = _row_find_fit(row, w);

		if (el != NULL) {
			uint64_t el_loss = _calc_el_loss(row, el, w, h);
			if (best_fit == NULL || best_loss > el_loss) {
				best_row = row;
				best_fit = el;
				best_loss = el_loss;
			}
		}

		candidate_row_base = rb_find_succ(candidate_row_base);
		row = _node_base_height_to_row(candidate_row_base);
	}

	if (best_fit != NULL) {
		packed_rect_el_t* new_el = _split_el(packing, best_row, best_fit, w, h,
				rotated);
		new_el->bin_idx = _calc_bin_idx(packing, best_row->parent_bin);
		return new_el;
	}

	return NULL;
}

void
rect_packing_validate(const rect_packing_t* packing)
{
	uint64_t n_rows = 0;
	uint64_t bin_rows = 0;
	uint64_t prev_h = 0;
	rb_node_t* node;
	rb_for_each((rb_tree_t*) &packing->rows_height, node) {
		packed_rect_row_t* row = _node_base_height_to_row(node);

		dbg_assert(prev_h <= row->h);
		prev_h = row->h;
		n_rows++;
	}

	for (uint64_t bin_idx = 0; bin_idx < vector_size(&packing->bin_list); bin_idx++) {
		packed_rect_bin_t* bin =
			(packed_rect_bin_t*) vector_get((vector_t*) &packing->bin_list, bin_idx);
		uint64_t prev_ly = -1lu;

		rb_for_each((rb_tree_t*) &bin->rows_ly, node) {
			packed_rect_row_t* row = _node_base_ly_to_row(node);

			dbg_assert((int64_t) prev_ly < (int64_t) row->ly);
			prev_ly = row->ly;

			bin_rows++;
		}
	}

	dbg_assert(bin_rows == n_rows);
}

