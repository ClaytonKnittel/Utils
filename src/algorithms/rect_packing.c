
/**********************************************************
 *                        Includes                        *
 **********************************************************/

#include <utils/algorithms/rect_packing.h>


/**********************************************************
 *               Red-Black Tree Definitions               *
 **********************************************************/

static int
_rb_cmp_packed_rect_el(const rb_node_t* a_ptr, const rb_node_t* b_ptr)
{
	const packed_rect_el_t* a = (const packed_rect_el_t*) a_ptr;
	const packed_rect_el_t* b = (const packed_rect_el_t*) b_ptr;
	return a->lx < b->lx ? -1 : a->lx == b->lx ? 0 : 1;
}

RB_DEFINE_TYPE(packed_rect_el, _rb_cmp_packed_rect_el)

static int
_rb_cmp_packed_rect_row_height(const rb_node_t* a_ptr, const rb_node_t* b_ptr)
{
	const packed_rect_row_t* a = (const packed_rect_row_t*) a_ptr;
	const packed_rect_row_t* b = (const packed_rect_row_t*) b_ptr;
	return a->h < b->h ? -1 : a->h == b->h ? 0 : 1;
}

RB_DEFINE_TYPE(packed_rect_row_height, _rb_cmp_packed_rect_row_height)

static int
_rb_cmp_packed_rect_row_ly(const rb_node_t* a_ptr, const rb_node_t* b_ptr)
{
	const packed_rect_row_t* a = (const packed_rect_row_t*) a_ptr;
	const packed_rect_row_t* b = (const packed_rect_row_t*) b_ptr;
	return a->ly < b->ly ? -1 : a->ly == b->ly ? 0 : 1;
}

RB_DEFINE_TYPE(packed_rect_row_ly, _rb_cmp_packed_rect_row_ly)


/**********************************************************
 *                    Element Helpers                     *
 **********************************************************/

/*
 * Creates a new rectangle element object, initializing the given fields without
 * inserting it into any of the data structures it will eventually be a member
 * of.
 */
static packed_rect_el_t*
_rect_packing_alloc_el(packed_rect_coord_t lx, packed_rect_coord_t ly,
		packed_rect_coord_t w, packed_rect_coord_t h, uint32_t bin_idx,
		bool rotated)
{
	packed_rect_el_t* el = (packed_rect_el_t*) malloc(sizeof(packed_rect_el_t));
	if (el == NULL) {
		return NULL;
	}

	el->lx = lx;
	el->ly = ly;
	el->bin_idx = bin_idx;
	el->rotated = rotated;
	el->w = w;
	el->h = h;

	return el;
}

static void
_rect_packing_free_el(packed_rect_el_t* el)
{
	free(el);
}


/**********************************************************
 *                      Row Helpers                       *
 **********************************************************/

/*
 * Given a row, returns the pointer it should use as the freelist start/end
 * pointers (i.e. what the first element's prev pointer and the last element's
 * end pointer should be).
 */
static packed_rect_el_t*
_rect_packing_row_freelist_terminal(const packed_rect_row_t* row)
{
	return (packed_rect_el_t*) (((uint8_t*) &row->freelist_start) -
			offsetof(packed_rect_el_t, next));
}

/*
 * Inserts an empty rectangle into the row's freelist.
 */
static void
_rect_packing_row_freelist_insert(packed_rect_row_t* row, packed_rect_el_t* el)
{
	packed_rect_el_t* start = row->freelist_start;

	el->next = start;
	el->prev = start->prev;
	start->prev = el;
	row->freelist_start = el;
}

/*
 * Removes an empty rectangle from the node's freelist.
 */
static void
_rect_packing_row_freelist_remove(packed_rect_el_t* el)
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
_rect_packing_alloc_row(packed_rect_coord_t ly, packed_rect_coord_t row_w,
		packed_rect_coord_t row_h, uint32_t bin_idx)
{
	packed_rect_el_t* empty_el;
	packed_rect_el_t* freelist_terminal;

	packed_rect_row_t* row =
		(packed_rect_row_t*) malloc(sizeof(packed_rect_row_t));
	if (row == NULL) {
		return NULL;
	}

	empty_el = _rect_packing_alloc_el(0, ly, row_w, row_h, bin_idx, false);
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
	freelist_terminal = _rect_packing_row_freelist_terminal(row);
	empty_el->next = freelist_terminal;
	empty_el->prev = freelist_terminal;

	return row;
}

static void
_rect_packing_free_row(packed_rect_row_t* row)
{
	rb_node_t* node_ptr;
	rb_for_each_mod(&row->elements, node_ptr) {
		packed_rect_el_t* el = (packed_rect_el_t*) node_ptr;
		rb_remove_packed_rect_el(&row->elements, node_ptr);
		_rect_packing_free_el(el);
	}
	rb_for_each_mod_fin();

	free(row);
}


/**********************************************************
 *                      Bin Helpers                       *
 **********************************************************/

static int
_rect_packing_alloc_bin(rect_packing_t* packing)
{
	packed_rect_row_t* row;
	packed_rect_bin_t* bin =
		(packed_rect_bin_t*) vector_reserve(&packing->bin_list);
	if (bin == NULL) {
		return -1;
	}

	row = _rect_packing_alloc_row(0, packing->bin_w, packing->bin_h,
			vector_size(&packing->bin_list) - 1);
	if (row == NULL) {
		vector_pop(&packing->bin_list);
		return -1;
	}

	row->parent_bin = bin;

	rb_init(&bin->rows_height);
	rb_init(&bin->rows_ly);

	rb_insert_packed_rect_row_height(&bin->rows_height,
			&row->rb_node_base_height);
	rb_insert_packed_rect_row_ly(&bin->rows_ly, &row->rb_node_base_ly);

	return 0;
}

static void
_rect_packing_free_bin(packed_rect_bin_t* bin)
{
	rb_node_t* node_ptr;
	rb_for_each_mod(&bin->rows_height, node_ptr) {
		packed_rect_row_t* row = (packed_rect_row_t*) node_ptr;
		rb_remove_packed_rect_row_height(&bin->rows_height, node_ptr);
		_rect_packing_free_row(row);
	}
	rb_for_each_mod_fin();
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
	if (_rect_packing_alloc_bin(packing) != 0) {
		vector_free(&packing->bin_list);
		return -1;
	}

	packing->bin_w = bin_w;
	packing->bin_h = bin_h;

	return 0;
}

void
rect_packing_free(rect_packing_t* packing)
{
	uint64_t n_bins = vector_size(&packing->bin_list);
	for (uint64_t i = 0; i < n_bins; i++) {
		packed_rect_bin_t* bin =
			(packed_rect_bin_t*) vector_get(&packing->bin_list, i);
		_rect_packing_free_bin(bin);
	}
	vector_free(&packing->bin_list);
}

