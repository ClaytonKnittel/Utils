
/**********************************************************
 *                       Includes                         *
 **********************************************************/

#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <utils/algorithms/sort.h>
#include <utils/data_structs/int_set.h>
#include <utils/data_structs/rtree.h>
#include <utils/utils.h>


/**********************************************************
 *                 Node Allocation Helpers                *
 **********************************************************/

static rtree_node_base_t*
_new_inner_node(uint32_t m_max)
{
	// TODO: test calloc vs clear first bit
	rtree_node_t* n = (rtree_node_t*) malloc(sizeof(rtree_node_t) +
			m_max * sizeof(rtree_node_base_t*));

	if (n == NULL) {
		return NULL;
	}

	return &n->base;
}

static rtree_node_base_t*
_new_empty_leaf_node(uint32_t m_max)
{
	// TODO: test calloc vs clear first bit
	rtree_leaf_t* n = (rtree_leaf_t*) malloc(sizeof(rtree_leaf_t) +
			m_max * sizeof(rtree_el_t*));

	if (n == NULL) {
		return NULL;
	}

	// set everything but the children pointers to 0
	memset(n, 0, sizeof(rtree_leaf_t));
	return &n->base;
}

static rtree_node_base_t*
_new_leaf_node(uint32_t m_max)
{
	// TODO: test calloc vs clear first bit
	rtree_leaf_t* n = (rtree_leaf_t*) malloc(sizeof(rtree_leaf_t) +
			m_max * sizeof(rtree_el_t*));

	if (n == NULL) {
		return NULL;
	}

	return &n->base;
}


/**********************************************************
 *                      RTree Init                        *
 **********************************************************/

int
rtree_init(rtree_t* tree, uint32_t m_min, uint32_t m_max)
{
	if (m_min < 2) {
		fprintf(stderr, "R* tree m_min must be at least 2\n");
		return -1;
	}
	if (m_min > m_max / 2) {
		fprintf(stderr, "R* tree m_min must be no more than half of m_max\n");
		return -1;
	}

	rtree_node_base_t* root = _new_empty_leaf_node(m_max);
	if (root == NULL) {
		return -1;
	}

	tree->root = root;
	tree->m_min = m_min;
	tree->m_max = m_max;
	tree->reinsert_p = (uint32_t) nearbyintf((float) m_max * DEFAULT_REINSERT_P_PCT);
	tree->reinsert_p = MAX(tree->reinsert_p, 1);
	tree->depth = 0;
	return 0;
}


/**********************************************************
 *                      RTree Free                        *
 **********************************************************/

static void
_rtree_leaf_free(rtree_leaf_t* leaf)
{
	free(leaf);
}

static void
_rtree_node_free(rtree_node_base_t* node, uint64_t depth)
{
	if (depth == 0) {
		_rtree_leaf_free((rtree_leaf_t*) node);
	}
	else {
		rtree_node_t* inode = (rtree_node_t*) node;
		for (uint32_t i = 0; i < inode->base.n; i++) {
			_rtree_node_free(inode->children[i], depth - 1);
		}
		free(inode);
	}
}

void
rtree_free(rtree_t* tree)
{
	_rtree_node_free(tree->root, tree->depth);
}


/**********************************************************
 *                 RTree Rectangle Helpers                *
 **********************************************************/

rtree_coord_t
rtree_rect_area(const rtree_rect_t* r)
{
	return (r->ux - r->lx) * (r->uy - r->ly);
}

rtree_coord_t
rtree_rect_margin(const rtree_rect_t* r)
{
	return 2 * ((r->ux - r->lx) + (r->uy - r->ly));
}

/*
 * returns true if the two rtree_rect_t's are identical
 */
bool
rtree_rect_eq(const rtree_rect_t* a, const rtree_rect_t* b)
{
	return a->lx == b->lx && a->ly == b->ly && a->ux == b->ux && a->uy == b->uy;
}

// TODO: optimize this with AVX
bool
rtree_rect_intersects(const rtree_rect_t* a, const rtree_rect_t* b)
{
	return !((a->ux < b->lx) || (b->ux < a->lx) ||
			 (a->uy < b->ly) || (b->uy < a->ly));
}

/*
 * returns true if p contains r (borders may intersect), false otherwise
 */
bool
rtree_rect_contains(const rtree_rect_t* p, const rtree_rect_t* r)
{
	return ((p->lx <= r->lx) && (r->ux <= p->ux) &&
			(p->ly <= r->ly) && (r->uy <= p->uy));
}

rtree_coord_t
rtree_rect_overlap(const rtree_rect_t* a_ptr, const rtree_rect_t* b_ptr)
{
	rtree_rect_t a = *a_ptr;
	rtree_rect_t b = *b_ptr;

	a.lx = MAX(a.lx, b.lx);
	a.ux = MIN(a.ux, b.ux);
	a.ly = MAX(a.ly, b.ly);
	a.uy = MIN(a.uy, b.uy);

	a.lx = MIN(a.lx, a.ux);
	a.ly = MIN(a.ly, a.uy);

	return rtree_rect_area(&a);
}

/*
 * returns the amount of area increase that would be required to accomodate rect
 */
rtree_coord_t
rtree_rect_area_increase(const rtree_rect_t* base, const rtree_rect_t* rect)
{
	rtree_coord_t area_inc = 0;
	rtree_rect_t b = *base;

	b.lx = MIN(b.lx, rect->lx);
	b.ux = MAX(b.ux, rect->ux);
	b.ly = MIN(b.ly, rect->ly);
	b.uy = MAX(b.uy, rect->uy);

	area_inc = ((b.ux - b.lx) * (b.uy - b.ly)) - ((base->ux - base->lx) * (base->uy - base->ly));

	return area_inc;
}

/*
 * extends base to accomodate rect, returning the amount of area increase that
 * would be required to accomodate rect
 */
rtree_coord_t
rtree_rect_combine(rtree_rect_t* dst, const rtree_rect_t* base, const rtree_rect_t* rect)
{
	rtree_coord_t area_inc = 0;
	rtree_rect_t b = *base;

	b.lx = MIN(b.lx, rect->lx);
	b.ux = MAX(b.ux, rect->ux);
	b.ly = MIN(b.ly, rect->ly);
	b.uy = MAX(b.uy, rect->uy);

	area_inc = ((b.ux - b.lx) * (b.uy - b.ly)) - ((base->ux - base->lx) * (base->uy - base->ly));

	*dst = b;

	return area_inc;
}

/*
 * extends base to accomodate rect, returning the amount of area increase that
 * would be required to accomodate rect
 */
rtree_coord_t
rtree_rect_extend(rtree_rect_t* base, const rtree_rect_t* rect)
{
	return rtree_rect_combine(base, base, rect);
}


/**********************************************************
 *                      RTree Insert                      *
 **********************************************************/

/*
 * returns the index of the child with least overlap increase
 */
static uint32_t
_min_overlap_cost_child(rtree_node_base_t** children, uint32_t n, rtree_rect_t* rect)
{
	struct cost {
		rtree_coord_t overlap_inc;
		rtree_coord_t area_inc;
		rtree_coord_t area;
	} opt, cur;
	uint32_t opt_idx = 0;

	rtree_rect_t r = children[0]->bb;
	opt.overlap_inc = 0;
	opt.area_inc = rtree_rect_extend(&r, rect);
	opt.area = rtree_rect_area(&children[0]->bb);

	for (uint32_t idx = 1; idx < n; idx++) {
		opt.overlap_inc += rtree_rect_overlap(&r, &children[idx]->bb);
		opt.overlap_inc -= rtree_rect_overlap(&children[0]->bb, &children[idx]->bb);
	}

	for (uint32_t i = 1; i < n; i++) {
		r = children[i]->bb;
		cur.overlap_inc = 0;
		cur.area_inc = rtree_rect_extend(&r, rect);
		cur.area = rtree_rect_area(&children[i]->bb);

		for (uint32_t _idx = 0; _idx < n - 1; _idx++) {
			uint32_t idx = _idx + (_idx >= i);
			cur.overlap_inc += rtree_rect_overlap(&r, &children[idx]->bb);
			cur.overlap_inc -= rtree_rect_overlap(&children[i]->bb, &children[idx]->bb);
		}

		if (cur.overlap_inc < opt.overlap_inc ||
				(cur.overlap_inc == opt.overlap_inc &&
				 (cur.area_inc < opt.area_inc ||
				  (cur.area_inc == opt.area_inc && cur.area < opt.area)))) {
			opt = cur;
			opt_idx = i;
		}
	}

	return opt_idx;
}


/*
 * returns the index of the child with least area increase
 */
static uint32_t
_min_area_increase_child(rtree_node_base_t** children, uint32_t n, rtree_rect_t* rect)
{
	struct cost {
		rtree_coord_t area_inc;
		rtree_coord_t area;
	} opt, cur;
	uint32_t opt_idx = 0;

	rtree_rect_t r = children[0]->bb;
	opt.area_inc = rtree_rect_extend(&r, rect);
	opt.area = rtree_rect_area(&children[0]->bb);

	for (uint32_t i = 1; i < n; i++) {
		r = children[i]->bb;
		cur.area_inc = rtree_rect_extend(&r, rect);
		cur.area = rtree_rect_area(&children[i]->bb);

		if (cur.area_inc < opt.area_inc ||
				(cur.area_inc == opt.area_inc && cur.area < opt.area)) {
			opt = cur;
			opt_idx = i;
		}
	}

	return opt_idx;
}


/*
 * to be called when the bounding box of a node shrinks along any axis
 *
 * this call runs up the tree, starting at node's parent, adjusting the bounding
 * box of each
 */
static void
_shrunk_node_bb(rtree_node_base_t* node)
{
	rtree_rect_t new_bb;
	rtree_node_t* p = node->parent;

	while (p != NULL) {
		new_bb = p->children[0]->bb;

		for (uint32_t i = 1; i < p->base.n; i++) {
			rtree_rect_extend(&new_bb, &p->children[i]->bb);
		}

		if (rtree_rect_eq(&new_bb, &p->base.bb)) {
			// shrinking this child's bounding box had no effect on the bounding
			// box of the parent, so we can stop propagating the change up
			break;
		}

		p->base.bb = new_bb;
		p = p->base.parent;
	}
}

/*
 * To be called if the bounding box of a leaf should shrink (due to an element
 * being removed)
 */
static void
_shrink_leaf_bb(rtree_leaf_t* leaf)
{
	if (leaf->base.n == 0) {
		// it doesn't matter what the bounding box for empty nodes is
		return;
	}

	rtree_rect_t new_bb = leaf->elements[0]->bb;

	for (uint32_t i = 1; i < leaf->base.n; i++) {
		rtree_rect_extend(&new_bb, &leaf->elements[i]->bb);
	}

	if (!rtree_rect_eq(&new_bb, &leaf->base.bb)) {
		// shrinking this child's bounding changed it, so we need to propagate
		// this change up the tree
		leaf->base.bb = new_bb;
		_shrunk_node_bb(&leaf->base);
	}
}


#define rect_x_sort_cmp(a, b) \
	((a)->lx < (b)->lx || ((a)->lx == (b)->lx && (a)->ux < (b)->ux))

#define rect_x_sort_cswap(T, a, b) \
	do { \
		if (rect_x_sort_cmp(b, a)) { \
			T m = (a); \
			(a) = (b); \
			(b) = m; \
		} \
	} while (0)

#define rect_y_sort_cmp(a, b) \
	((a)->ly < (b)->ly || ((a)->ly == (b)->ly && (a)->uy < (b)->uy))

#define rect_y_sort_cswap(T, a, b) \
	do { \
		if (rect_y_sort_cmp(b, a)) { \
			T m = (a); \
			(a) = (b); \
			(b) = m; \
		} \
	} while (0)

/*#define node_info_sort_cswap(T, a, b) \
	do { \
		int res = node_info_sort_cmp(a, b); \
		T m = res ? b : a; \
		T n = res ? a : b; \
		(a) = n; \
		(b) = m; \
	} while (0)*/

DEFINE_CSORT_DEFAULT_FNS_NAMED_16(rtree_rect_t*, rtree_rect_x, rect_x_sort_cmp, rect_x_sort_cswap)
DEFINE_CSORT_DEFAULT_FNS_NAMED_16(rtree_rect_t*, rtree_rect_y, rect_y_sort_cmp, rect_y_sort_cswap)

struct split_cost {
	rtree_coord_t overlap;
	rtree_coord_t area;
	uint32_t split_idx;
	rtree_rect_t lower_bb;
	rtree_rect_t upper_bb;
};


/*
 * determines which axis to split a set of rectangles on, also populating x_cost
 * and y_cost with respective optimal split index + margin and area values
 *
 * returns true if it should be split along the x-axis, false for y-axis
 */
static bool
_determine_split(rtree_t* tree, uint32_t n, rtree_rect_t** x_sort,
		rtree_rect_t** y_sort, struct split_cost* x_cost,
		struct split_cost* y_cost)
{
	uint32_t m_min = tree->m_min;
	rtree_rect_t* rev_rects;

	// first sort the lists
	csort_rtree_rect_x(x_sort, n);
	csort_rtree_rect_y(y_sort, n);

	// sum up the margin values of all distributions along each axis
	struct split_cost opt_x;
	struct split_cost opt_y;
	rtree_coord_t x_margin;
	rtree_coord_t y_margin;

	// first construct the higher-coordinate split rectangles in reverse
	uint32_t n_dists = n - 2 * m_min + 1;
	rev_rects = (rtree_rect_t*) alloca(n_dists * sizeof(rtree_rect_t));
	{
		rev_rects[n_dists - 1] = *x_sort[n - 1];
		uint32_t i = n - 2;
		for (; i >= n - m_min; i--) {
			rtree_rect_extend(&rev_rects[n_dists - 1], x_sort[i]);
		}
		for (; i >= m_min; i--) {
			rtree_rect_combine(&rev_rects[i - m_min], &rev_rects[i - m_min + 1], x_sort[i]);
		}
	}

	// then go through the lower-coordinate split rectangles and combine with
	// the pre-calculated higher ones
	{
		rtree_rect_t x_bb = *x_sort[0];
		uint32_t i = 1;
		for (; i < m_min; i++) {
			rtree_rect_extend(&x_bb, x_sort[i]);
		}
		x_margin = rtree_rect_margin(&x_bb) + rtree_rect_margin(&rev_rects[0]);
		opt_x.overlap = rtree_rect_overlap(&x_bb, &rev_rects[0]);
		opt_x.area = rtree_rect_area(&x_bb) + rtree_rect_area(&rev_rects[0]);
		opt_x.split_idx = i;
		opt_x.lower_bb = x_bb;
		opt_x.upper_bb = rev_rects[0];

		/*
		printf("x at %u,\n"
				"  <(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")>\n"
				"  <(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")> (%llu)\n",
				i,
				x_bb.lx, x_bb.ly,
				x_bb.ux, x_bb.uy,
				rev_rects[0].lx, rev_rects[0].ly,
				rev_rects[0].ux, rev_rects[0].uy,
				rtree_rect_margin(&x_bb) + rtree_rect_margin(&rev_rects[0]));
				*/

		for (; i < n - m_min; i++) {
			rtree_rect_extend(&x_bb, x_sort[i]);
			x_margin += rtree_rect_margin(&x_bb) +
				rtree_rect_margin(&rev_rects[i - m_min + 1]);

			rtree_coord_t overlap = rtree_rect_overlap(&x_bb, &rev_rects[i - m_min + 1]);
			rtree_coord_t area = rtree_rect_area(&x_bb) +
				rtree_rect_area(&rev_rects[i - m_min + 1]);

			/*
			printf("x at %u,\n"
					"  <(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")>\n"
					"  <(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")> (%llu)",
					i,
					x_bb.lx, x_bb.ly,
					x_bb.ux, x_bb.uy,
					rev_rects[i - m_min + 1].lx, rev_rects[i - m_min + 1].ly,
					rev_rects[i - m_min + 1].ux, rev_rects[i - m_min + 1].uy,
					rtree_rect_margin(&x_bb) + rtree_rect_margin(&rev_rects[i - m_min + 1]));
					*/

			if (overlap < opt_x.overlap || (overlap == opt_x.overlap && area < opt_x.area)) {
				opt_x.overlap = overlap;
				opt_x.area = area;
				opt_x.split_idx = i + 1;
				opt_x.lower_bb = x_bb;
				opt_x.upper_bb = rev_rects[i - m_min + 1];
			}
		}
	}

	// do the same for y
	{
		// first construct the higher-coordinate split rectangles in reverse
		rev_rects[n_dists - 1] = *y_sort[n - 1];
		uint32_t i = n - 2;
		for (; i >= n - m_min; i--) {
			rtree_rect_extend(&rev_rects[n_dists - 1], y_sort[i]);
		}
		for (; i >= m_min; i--) {
			rtree_rect_combine(&rev_rects[i - m_min], &rev_rects[i - m_min + 1], y_sort[i]);
		}
	}

	// then go through the lower-coordinate split rectangles and combine with
	// the pre-calculated higher ones
	{
		rtree_rect_t y_bb = *y_sort[0];
		uint32_t i = 1;
		for (; i < m_min; i++) {
			rtree_rect_extend(&y_bb, y_sort[i]);
		}
		y_margin = rtree_rect_margin(&y_bb) + rtree_rect_margin(&rev_rects[0]);
		opt_y.overlap = rtree_rect_overlap(&y_bb, &rev_rects[0]);
		opt_y.area = rtree_rect_area(&y_bb) + rtree_rect_area(&rev_rects[0]);
		opt_y.split_idx = i;
		opt_y.lower_bb = y_bb;
		opt_y.upper_bb = rev_rects[0];

		/*
		printf("y at %u,\n"
				"  <(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")>\n"
				"  <(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")> (%llu)\n",
				i,
				y_bb.lx, y_bb.ly,
				y_bb.ux, y_bb.uy,
				rev_rects[0].lx, rev_rects[0].ly,
				rev_rects[0].ux, rev_rects[0].uy,
				rtree_rect_margin(&y_bb) + rtree_rect_margin(&rev_rects[0]));
				*/

		for (; i < n - m_min; i++) {
			rtree_rect_extend(&y_bb, y_sort[i]);
			y_margin += rtree_rect_margin(&y_bb) +
				rtree_rect_margin(&rev_rects[i - m_min + 1]);

			rtree_coord_t overlap = rtree_rect_overlap(&y_bb, &rev_rects[i - m_min + 1]);
			rtree_coord_t area = rtree_rect_area(&y_bb) +
				rtree_rect_area(&rev_rects[i - m_min + 1]);

			/*
			printf("y at %u,\n"
					"  <(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")>\n"
					"  <(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")> (%llu)",
					i,
					y_bb.lx, y_bb.ly,
					y_bb.ux, y_bb.uy,
					rev_rects[i - m_min + 1].lx, rev_rects[i - m_min + 1].ly,
					rev_rects[i - m_min + 1].ux, rev_rects[i - m_min + 1].uy,
					rtree_rect_margin(&y_bb) + rtree_rect_margin(&rev_rects[i - m_min + 1]));
					*/

			if (overlap < opt_y.overlap || (overlap == opt_y.overlap && area < opt_y.area)) {
				opt_y.overlap = overlap;
				opt_y.area = area;
				opt_y.split_idx = i + 1;
				opt_y.lower_bb = y_bb;
				opt_y.upper_bb = rev_rects[i - m_min + 1];
			}
		}
	}

	/*
	printf("sorted x:\n");
	for (int i = 0; i < n; i++) {
		printf("<(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")>\n",
				x_sort[i]->lx, x_sort[i]->ly,
				x_sort[i]->ux, x_sort[i]->uy);
	}

	printf("\nsorted y:\n");
	for (int i = 0; i < n; i++) {
		printf("<(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")>\n",
				y_sort[i]->lx, y_sort[i]->ly,
				y_sort[i]->ux, y_sort[i]->uy);
	}

	printf("\nx total: %" PRIu64 "\ny total: %" PRIu64 "\n", x_margin, y_margin);
	*/

	*x_cost = opt_x;
	*y_cost = opt_y;

	return x_margin < y_margin; // TODO bit parity || (x_sum == y_sum && (__builtin_(x_sum ^ y_sum) & 1)))
}

static rtree_node_base_t*
_split_leaf(rtree_t* tree, rtree_leaf_t* node, rtree_el_t* to_add)
{
	uint32_t n = node->base.n;
	rtree_el_t** x_sort;
	rtree_el_t** y_sort;
	struct split_cost x_cost, y_cost;

	x_sort = (rtree_el_t**) alloca((n + 1) * sizeof(rtree_el_t*));
	y_sort = (rtree_el_t**) alloca((n + 1) * sizeof(rtree_el_t*));

	memcpy(x_sort, node->elements, n * sizeof(rtree_el_t*));
	memcpy(y_sort, node->elements, n * sizeof(rtree_el_t*));
	x_sort[n] = to_add;
	y_sort[n] = to_add;
	n++;

	bool split_x = _determine_split(tree, n, (rtree_rect_t**) x_sort, (rtree_rect_t**) y_sort,
			&x_cost, &y_cost);

	// determine split axis
	rtree_leaf_t* split_node = (rtree_leaf_t*) _new_leaf_node(tree->m_max);
	if (split_node == NULL) {
		return NULL;
	}
	split_node->base.parent = node->base.parent;

	if (split_x) {
		node->base.bb = x_cost.lower_bb;
		node->base.n = x_cost.split_idx;
		split_node->base.bb = x_cost.upper_bb;
		split_node->base.n = n - x_cost.split_idx;

		// update the children of both nodes
		for (uint32_t i = 0; i < x_cost.split_idx; i++) {
			node->elements[i] = x_sort[i];
			node->elements[i]->parent_idx = i;
		}
		for (uint32_t i = 0; i < n - x_cost.split_idx; i++) {
			split_node->elements[i] = x_sort[i + x_cost.split_idx];
			split_node->elements[i]->parent = split_node;
			split_node->elements[i]->parent_idx = i;
		}
	}
	else {
		node->base.bb = y_cost.lower_bb;
		node->base.n = y_cost.split_idx;
		split_node->base.bb = y_cost.upper_bb;
		split_node->base.n = n - y_cost.split_idx;

		// update the children of both nodes
		for (uint32_t i = 0; i < y_cost.split_idx; i++) {
			node->elements[i] = y_sort[i];
			node->elements[i]->parent_idx = i;
		}
		for (uint32_t i = 0; i < n - y_cost.split_idx; i++) {
			split_node->elements[i] = y_sort[i + y_cost.split_idx];
			split_node->elements[i]->parent = split_node;
			split_node->elements[i]->parent_idx = i;
		}
	}

	return (rtree_node_base_t*) split_node;
}

static rtree_node_base_t*
_split_node(rtree_t* tree, rtree_node_t* node, rtree_node_base_t* to_add)
{
	// first construct the two lists that are to be sorted (one for each axis)
	uint32_t n = node->base.n;
	rtree_node_base_t** x_sort;
	rtree_node_base_t** y_sort;
	struct split_cost x_cost, y_cost;

	x_sort = (rtree_node_base_t**) alloca((n + 1) * sizeof(rtree_node_base_t*));
	y_sort = (rtree_node_base_t**) alloca((n + 1) * sizeof(rtree_node_base_t*));

	memcpy(x_sort, node->children, n * sizeof(rtree_node_base_t*));
	memcpy(y_sort, node->children, n * sizeof(rtree_node_base_t*));

	x_sort[n] = to_add;
	y_sort[n] = to_add;
	n++;

	bool split_x = _determine_split(tree, n, (rtree_rect_t**) x_sort, (rtree_rect_t**) y_sort,
			&x_cost, &y_cost);

	// determine split axis
	rtree_node_t* split_node = (rtree_node_t*) _new_inner_node(tree->m_max);
	if (split_node == NULL) {
		return NULL;
	}
	split_node->base.parent = node->base.parent;

	if (split_x) {
		node->base.bb = x_cost.lower_bb;
		node->base.n = x_cost.split_idx;
		split_node->base.bb = x_cost.upper_bb;
		split_node->base.n = n - x_cost.split_idx;

		// udate the children of both nodes
		memcpy(node->children, &x_sort[0],
				x_cost.split_idx * sizeof(rtree_node_base_t*));
		memcpy(split_node->children, &x_sort[x_cost.split_idx],
				(n - x_cost.split_idx) * sizeof(rtree_node_base_t*));

		// update the parent pointers of the nodes that moved under split_node
		for (uint32_t i = 0; i < x_cost.split_idx; i++) {
			x_sort[i]->parent_idx = i;
		}

		for (uint32_t i = x_cost.split_idx; i < n; i++) {
			x_sort[i]->parent = split_node;
			x_sort[i]->parent_idx = i - x_cost.split_idx;
		}
	}
	else {
		node->base.bb = y_cost.lower_bb;
		node->base.n = y_cost.split_idx;
		split_node->base.bb = y_cost.upper_bb;
		split_node->base.n = n - y_cost.split_idx;

		// udate the children of both nodes
		memcpy(node->children, &y_sort[0],
				y_cost.split_idx * sizeof(rtree_node_base_t*));
		memcpy(split_node->children, &y_sort[y_cost.split_idx],
				(n - y_cost.split_idx) * sizeof(rtree_node_base_t*));

		// update the parent pointers of the nodes that moved under split_node
		for (uint32_t i = 0; i < y_cost.split_idx; i++) {
			y_sort[i]->parent_idx = i;
		}

		for (uint32_t i = y_cost.split_idx; i < n; i++) {
			y_sort[i]->parent = split_node;
			y_sort[i]->parent_idx = i - y_cost.split_idx;
		}
	}

	return (rtree_node_base_t*) split_node;
}

struct node_dist {
	/*
	 * 4 * squared distance of the center of node's bb to the center of its parent's bb
	 *
	 * the factor of 4 comes from keeping all bits of precision when calculating
	 * the center points of the rectangles, which requires dividing by 2 (and
	 * those values are then multiplied together)
	 */
	uint64_t dist2;

	union {
		// when reinserting leaf elements, this holds the rtree_el_t for the
		// corresponding element
		rtree_el_t* el;
		// when reinserting inner node children, this holds the corresponding
		// child
		rtree_node_base_t* node;
	};
};

#define node_dist_sort_cmp(a, b) \
	((a).dist2 < (b).dist2)

/*
#define node_dist_sort_cswap(T, a, b) \
	do { \
		if (node_dist_sort_cmp(b, a)) { \
			T m = (a); \
			(a) = (b); \
			(b) = m; \
		} \
	} while (0)
*/

#define node_dist_sort_cswap(T, a, b) \
	do { \
		if (node_dist_sort_cmp(b, a)) { \
			int res = node_dist_sort_cmp(a, b); \
			T min = res ? (a) : (b); \
			T max = res ? (b) : (a); \
			(a) = min; \
			(b) = max; \
		} \
	} while (0)

DEFINE_CSORT_DEFAULT_FNS_NAMED_16(struct node_dist, node_dist, node_dist_sort_cmp, node_dist_sort_cswap)


// forward declarations for use in __continue_split
static int _do_insert(rtree_t* tree, rtree_el_t* el_ptr,
		int_set_t reinserted_levels);
static int _do_inner_insert(rtree_t* tree, rtree_node_base_t* n,
		int_set_t reinserted_levels, uint64_t depth);

static int
_do_reinsert_leaf(rtree_t* tree, rtree_leaf_t* parent, int_set_t reinserted_levels,
		rtree_el_t* el_ptr)
{
	uint32_t m_max = tree->m_max;
	uint32_t reinsert_p = tree->reinsert_p;

	// xc and yx are 2 * the center coordinates (i.e. fixed point
	// coordinates with decimal after bit 1)
	rtree_coord_t parent_xc = parent->base.bb.lx + parent->base.bb.ux;
	rtree_coord_t parent_yc = parent->base.bb.ly + parent->base.bb.uy;

	struct node_dist* dists =
		(struct node_dist*) alloca((m_max + 1) * sizeof(struct node_dist));
	for (uint64_t i = 0; i < m_max; i++) {
		rtree_el_t* el = parent->elements[i];
		rtree_coord_t xc = el->bb.lx + el->bb.ux;
		rtree_coord_t yc = el->bb.ly + el->bb.uy;
		rtree_coord_t dx = xc - parent_xc;
		rtree_coord_t dy = yc - parent_yc;
		uint64_t d2 = dx * dx + dy * dy;

		dists[i].dist2 = d2;
		dists[i].el = el;
	}

	rtree_coord_t xc = el_ptr->bb.lx + el_ptr->bb.ux;
	rtree_coord_t yc = el_ptr->bb.ly + el_ptr->bb.uy;
	rtree_coord_t dx = xc - parent_xc;
	rtree_coord_t dy = yc - parent_yc;
	uint64_t d2 = dx * dx + dy * dy;

	dists[m_max].dist2 = d2;
	dists[m_max].el = el_ptr;

	csort_node_dist(dists, m_max + 1);

	parent->base.n = m_max + 1 - reinsert_p;

	parent->base.bb = dists[0].el->bb;
	parent->elements[0] = dists[0].el;
	parent->elements[0]->parent_idx = 0;
	uint32_t i;
	for (i = 1; i < parent->base.n; i++) {
		rtree_rect_extend(&parent->base.bb, &dists[i].el->bb);
		parent->elements[i] = dists[i].el;
		parent->elements[i]->parent_idx = i;
	}

	// since the bounding box of parent may have changed, try propagating this
	// change up the tree
	_shrunk_node_bb(&parent->base);

	for (; i <= m_max; i++) {
		if (_do_insert(tree, dists[i].el, reinserted_levels) != 0) {
			return -1;
		}
	}

	return 0;
}

static void
_do_reinsert(rtree_t* tree, rtree_node_t* parent, int_set_t reinserted_levels,
		uint64_t depth, rtree_node_base_t* to_add)
{
	uint32_t m_max = tree->m_max;
	uint32_t reinsert_p = tree->reinsert_p;

	// xc and yx are 2 * the center coordinates (i.e. fixed point
	// coordinates with decimal after bit 1)
	rtree_coord_t parent_xc = parent->base.bb.lx + parent->base.bb.ux;
	rtree_coord_t parent_yc = parent->base.bb.ly + parent->base.bb.uy;

	struct node_dist* dists =
		(struct node_dist*) alloca((m_max + 1) * sizeof(struct node_dist));
	for (uint64_t i = 0; i < m_max; i++) {
		rtree_node_base_t* child = parent->children[i];
		rtree_coord_t xc = child->bb.lx + child->bb.ux;
		rtree_coord_t yc = child->bb.ly + child->bb.uy;
		rtree_coord_t dx = xc - parent_xc;
		rtree_coord_t dy = yc - parent_yc;
		uint64_t d2 = dx * dx + dy * dy;

		dists[i].dist2 = d2;
		dists[i].node = child;
	}

	rtree_coord_t xc = to_add->bb.lx + to_add->bb.ux;
	rtree_coord_t yc = to_add->bb.ly + to_add->bb.uy;
	rtree_coord_t dx = xc - parent_xc;
	rtree_coord_t dy = yc - parent_yc;
	uint64_t d2 = dx * dx + dy * dy;

	dists[m_max].dist2 = d2;
	dists[m_max].node = to_add;

	csort_node_dist(dists, m_max + 1);

	parent->base.n = m_max + 1 - reinsert_p;

	parent->base.bb = dists[0].node->bb;
	parent->children[0] = dists[0].node;
	parent->children[0]->parent_idx = 0;
	uint32_t i;
	for (i = 1; i < parent->base.n; i++) {
		rtree_rect_extend(&parent->base.bb, &dists[i].node->bb);
		parent->children[i] = dists[i].node;
		parent->children[i]->parent_idx = i;
	}

	// since the bounding box of parent may have changed, try propagating this
	// change up the tree
	_shrunk_node_bb(&parent->base);

	// since tree depth may change between successive _do_inner_insert calls,
	// measure depth as distane from the leaves
	uint64_t inv_depth = tree->depth - depth;
	for (; i <= m_max; i++) {
		_do_inner_insert(tree, dists[i].node, reinserted_levels,
				tree->depth - inv_depth);
	}
}

/*
 * given a node "n" that is to be added to n->parent, add the node to the
 * parent, continuing to split up the tree if necessary
 *
 * return on success and -1 on failure
 */
static int
__continue_split(rtree_t* tree, rtree_node_base_t* n, int_set_t reinserted_levels,
		uint64_t depth, const rtree_rect_t* rect)
{
	rtree_node_base_t* split_child = n;
	uint32_t m_max = tree->m_max;

	for (;;) {
		n = &split_child->parent->base;
		if (n == NULL) {
			// we have split the root! Make a new one, make n and the old root its children
			rtree_node_t* new_root = (rtree_node_t*) _new_inner_node(m_max);
			if (new_root == NULL) {
				return -1;
			}
			rtree_node_base_t* old_root = tree->root;

			rtree_rect_combine(&new_root->base.bb, &old_root->bb, &split_child->bb);
			new_root->base.parent = NULL;
			new_root->base.n = 2;
			new_root->children[0] = old_root;
			new_root->children[1] = split_child;

			old_root->parent = new_root;
			old_root->parent_idx = 0;
			split_child->parent = new_root;
			split_child->parent_idx = 1;

			tree->root = &new_root->base;
			tree->depth++;
			break;
		}

		if (n->n < m_max) {
			// we can accomodate split_child
			rtree_node_t* node = (rtree_node_t*) n;
			node->children[node->base.n] = split_child;
			split_child->parent_idx = node->base.n;
			node->base.n++;

			// update the bounding boxes of all of this node's parents
			do {
				rtree_rect_extend(&n->bb, rect);
				split_child = n;
				n = &n->parent->base;
			} while (n != NULL);
			break;
		}

		if (depth != 0 && !int_set_contains(reinserted_levels, depth)) {
			// perform reinsertion
			int_set_insert(reinserted_levels, depth);

			_do_reinsert(tree, (rtree_node_t*) n, reinserted_levels, depth, split_child);

			// reinsert completes the operation, so don't continue splitting up the tree
			break;
		}
		else {
			// perform a split
			split_child = _split_node(tree, (rtree_node_t*) n, split_child);
		}
		depth--;
	}

	return 0;
}

/*
 * reinserts an inner node at the specified depth, width depth = 0 being the root
 *
 * depth cannot be 0 since nodes can't be reinserted at the root
 *
 * returns 0 on success and -1 on failure
 */
static int
_do_inner_insert(rtree_t* tree, rtree_node_base_t* n, int_set_t reinserted_levels,
		uint64_t depth)
{
	rtree_rect_t* rect = &n->bb;
	// inner insert cannot happen unless the root is an inner node
	rtree_node_t* new_parent = (rtree_node_t*) tree->root;

	dbg_assert(depth != 0);

	for (uint64_t i = 0; i < depth - 1; i++) {
		// this node's children are inner nodes, so we find the node
		// requiring the least area increase
		rtree_node_t* node = new_parent;
		uint32_t c_idx = _min_area_increase_child(node->children, node->base.n, rect);
		new_parent = (rtree_node_t*) node->children[c_idx];
	}

	// set the parent of n so that n will be inserted into the new parent
	n->parent = new_parent;
	return __continue_split(tree, n, reinserted_levels, depth, &n->bb);
}

/*
 * Inserts el_ptr under node n. Depth is the depth of the tree rooted at n.
 */
static int
_do_insert_under_node(rtree_t* tree, rtree_el_t* el_ptr, int_set_t reinserted_levels,
		rtree_node_base_t* n, uint64_t depth)
{
	uint32_t m_max = tree->m_max;

	// first, find the node we'll be inserting this element into
	if (depth > 0) {
		for (uint64_t i = 0; i < depth - 1; i++) {
			// this node's children are inner nodes, so we find the node
			// requiring the least area increase
			rtree_node_t* node = (rtree_node_t*) n;
			uint32_t c_idx = _min_area_increase_child(node->children, node->base.n,
					&el_ptr->bb);
			n = node->children[c_idx];
		}

		// this node's children are leaves, so we find the minimum
		// overlap cost
		rtree_node_t* node = (rtree_node_t*) n;
		uint32_t c_idx = _min_overlap_cost_child(node->children, node->base.n,
				&el_ptr->bb);
		n = node->children[c_idx];
	}

	// insert into n, which is a leaf node
	rtree_leaf_t* leaf = (rtree_leaf_t*) n;
	// reinsertion/split methods assume leaf's parent is already assigned
	el_ptr->parent = leaf;

	if (leaf->base.n < m_max) {
		// there is still room for this entry, simply insert it
		leaf->elements[leaf->base.n] = el_ptr;
		el_ptr->parent_idx = leaf->base.n;
		leaf->base.n++;

		if (leaf->base.n == 1) {
			// this can only happen for the very first element inserted
			leaf->base.bb = el_ptr->bb;
		}
		else {
			rtree_rect_extend(&leaf->base.bb, &el_ptr->bb);

			rtree_node_base_t* child = n;
			n = &child->parent->base;
			// update the bounding boxes of all of this node's parents
			while (n != NULL) {
				rtree_rect_extend(&n->bb, &el_ptr->bb);
				child = n;
				n = &n->parent->base;
			}
		}
		return 0;
	}

	// otherwise, we need to split up the tree
	// leaves are a special case
	if (depth != 0 && !int_set_contains(reinserted_levels, depth)) {
		// perform reinsertion
		int_set_insert(reinserted_levels, depth);

		return _do_reinsert_leaf(tree, leaf, reinserted_levels, el_ptr);
	}
	else {
		// perform a split
		n = _split_leaf(tree, leaf, el_ptr);

		return __continue_split(tree, n, reinserted_levels, depth, &el_ptr->bb);
	}
}

static int
_do_insert(rtree_t* tree, rtree_el_t* el_ptr, int_set_t reinserted_levels)
{
	return _do_insert_under_node(tree, el_ptr, reinserted_levels, tree->root,
			tree->depth);
}

int
rtree_insert(rtree_t* tree, rtree_el_t* el_ptr)
{
	int_set_t reinserted_levels;
	int_set_inita(reinserted_levels, tree->depth);
	return _do_insert(tree, el_ptr, reinserted_levels);
}


/**********************************************************
 *                     RTree Delete                       *
 **********************************************************/

static void _do_delete_node(rtree_t* tree, rtree_node_base_t* node,
		int_set_t reinserted_levels, uint64_t depth);

/*
 * Handles the reinsertion of all children of an underfilled rtree_node node
 * except the child at delete_idx.
 *
 * depth is the level that the children of node are at
 */
static void
_reinsert_node_children(rtree_t* tree, rtree_node_t* node,
		int_set_t reinserted_levels, uint64_t depth, uint32_t delete_idx)
{
	uint64_t inv_depth = tree->depth - depth;
	// remove the node before reinserting it into the tree
	_do_delete_node(tree, &node->base, reinserted_levels, depth - 1);

	for (uint32_t i = 0; i < delete_idx; i++) {
		_do_inner_insert(tree, node->children[i], reinserted_levels, tree->depth - inv_depth);
	}

	for (uint32_t i = delete_idx + 1; i < node->base.n; i++) {
		_do_inner_insert(tree, node->children[i], reinserted_levels, tree->depth - inv_depth);
	}

	free(node);
}

/*
 * Removes the node from the tree without deleting the node's contents or its
 * children.
 *
 * depth is the level that node is at.
 */
static void
_do_delete_node(rtree_t* tree, rtree_node_base_t* node,
		int_set_t reinserted_levels, uint64_t depth)
{
	rtree_node_t* parent = node->parent;

	if (parent->base.n > tree->m_min || (depth == 1 && parent->base.n > 2)) {
		// if this node will not be underfilled after deletion, we can remove it
		// without adjusting any of the rest of the tree
		for (uint32_t i = node->parent_idx; i < parent->base.n - 1; i++) {
			rtree_node_base_t* move_el = parent->children[i + 1];
			parent->children[i] = move_el;
			move_el->parent_idx = i;
		}
		parent->base.n--;
		_shrunk_node_bb(node);
	}
	else if (depth == 1) {
		// if parent is the root, the deletion would have made the root go down
		// to one child. Make that child the new root and free the old one.
		tree->root = parent->children[1 - node->parent_idx];
		tree->root->parent = NULL;
		tree->depth--;
	}
	else {
		// this node will be underfilled after removing node, so reinsert all
		// its children and propagate the deletion updward
		_reinsert_node_children(tree, parent, reinserted_levels, depth,
				node->parent_idx);
	}
}

/*
 * Handles the reinsertion of all children of an underfilled rtree_leaf except
 * the element at delete_idx.
 */
static int
_reinsert_leaf_children(rtree_t* tree, rtree_leaf_t* leaf,
		int_set_t reinserted_levels, uint32_t delete_idx)
{
	// remove the node before reinserting it into the tree
	_do_delete_node(tree, &leaf->base, reinserted_levels, tree->depth);

	for (uint32_t i = 0; i < delete_idx; i++) {
		if (_do_insert(tree, leaf->elements[i], reinserted_levels) != 0) {
			return -1;
		}
	}

	for (uint32_t i = delete_idx + 1; i < leaf->base.n; i++) {
		if (_do_insert(tree, leaf->elements[i], reinserted_levels) != 0) {
			return -1;
		}
	}

	free(leaf);
	return 0;
}

/*
 * Deletes el_ptr from the rtree_leaf it is part of.
 */
static int
_do_delete_element(rtree_t* tree, rtree_el_t* el_ptr, int_set_t reinserted_levels)
{
	rtree_leaf_t* parent = el_ptr->parent;

	// if parent is the root, always allow removing one of its chidren without
	// splitting
	if (parent->base.n > tree->m_min || (parent->base.parent == NULL)) {
		// if this node will not be underfilled after deletion, we can remove it
		// without adjusting any of the rest of the tree
		for (uint32_t i = el_ptr->parent_idx; i < parent->base.n - 1; i++) {
			rtree_el_t* move_el = parent->elements[i + 1];
			parent->elements[i] = move_el;
			move_el->parent_idx = i;
		}
		parent->base.n--;

		_shrink_leaf_bb(parent);
		return 0;
	}
	else {
		// this node will be underfilled after removing el_ptr, so reinsert all its
		// children and propagate the deletion updward
		return _reinsert_leaf_children(tree, parent, reinserted_levels,
				el_ptr->parent_idx);
	}
}

int
rtree_delete(rtree_t* tree, rtree_el_t* el)
{
	int_set_t reinserted_levels;
	int_set_inita(reinserted_levels, tree->depth);
	return _do_delete_element(tree, el, reinserted_levels);
}


/**********************************************************
 *                     RTree For Each                     *
 **********************************************************/

bool
rtree_foreach(const rtree_t* tree, rtree_foreach_cb callback, void* udata)
{
	uint64_t depth = tree->depth;
	const rtree_node_base_t* node = tree->root;
	uint32_t i = 0;
	uint32_t n = node->n;

	if (node == NULL) {
		return true;
	}

	while (true) {
		if (i == n) {
ascent_parent:
			i = node->parent_idx + 1;
			node = &node->parent->base;

			if (node == NULL) {
				return true;
			}

			n = node->n;
			depth++;
			continue;
		}

		if (depth > 0) {
			const rtree_node_t* inner_node = (rtree_node_t*) node;
			node = inner_node->children[i];
			i = 0;
			n = node->n;
			depth--;
			continue;
		}

		const rtree_leaf_t* leaf = (rtree_leaf_t*) node;
		for (; i < n; i++) {
			const rtree_el_t* el = leaf->elements[i];
			if (!callback(el, udata, tree)) {
				// stop iteration.
				return false;
			}
		}
		goto ascent_parent;
	}

	return true;
}


/**********************************************************
 *                    RTree Find Exact                    *
 **********************************************************/

static rtree_el_t*
_rtree_find_exact_leaf(const rtree_leaf_t* leaf, const rtree_rect_t* rect)
{
	for (uint32_t i = 0; i < leaf->base.n; i++) {
		if (rtree_rect_eq(&leaf->elements[i]->bb, rect)) {
			return leaf->elements[i];
		}
	}
	return NULL;
}

static rtree_el_t*
_rtree_find_exact(const rtree_node_t* node, const rtree_rect_t* rect, int depth)
{
	for (uint32_t i = 0; i < node->base.n; i++) {
		if (!rtree_rect_contains(&node->base.bb, rect)) {
			continue;
		}

		rtree_el_t* q;
		if (depth == 0) {
			q = _rtree_find_exact_leaf((const rtree_leaf_t*) node->children[i], rect);
		}
		else {
			q = _rtree_find_exact((const rtree_node_t*) node->children[i], rect, depth - 1);
		}
		if (q != NULL) {
			return q;
		}
	}
	return NULL;
}

rtree_el_t*
rtree_find_exact(const rtree_t* tree, const rtree_rect_t* rect)
{
	rtree_node_base_t* n = tree->root;
	uint64_t depth = tree->depth;

	if (depth > 0) {
		return _rtree_find_exact((const rtree_node_t*) n, rect, depth - 1);
	}
	else {
		return _rtree_find_exact_leaf((const rtree_leaf_t*) n, rect);
	}
}


/**********************************************************
 *                    RTree Intersects                    *
 **********************************************************/

static bool
_rtree_intersects_leaf(const rtree_t* tree, const rtree_leaf_t* leaf,
		const rtree_rect_t* rect, rtree_intersects_cb callback, void* udata)
{
	for (uint32_t i = 0; i < leaf->base.n; i++) {
		if (rtree_rect_intersects(&leaf->elements[i]->bb, rect)) {
			if (!callback(leaf->elements[i], udata, rect, tree)) {
				return false;
			}
		}
	}

	return true;
}

static bool
_rtree_intersects(const rtree_t* tree, const rtree_node_t* node,
		const rtree_rect_t* rect, rtree_intersects_cb callback, void* udata,
		int depth)
{
	for (uint32_t i = 0; i < node->base.n; i++) {
		if (!rtree_rect_intersects(&node->children[i]->bb, rect)) {
			continue;
		}

		if (depth == 0) {
			if (!_rtree_intersects_leaf(tree,
					(const rtree_leaf_t*) node->children[i], rect, callback,
					udata)) {
				return false;
			}
		}
		else {
			if (!_rtree_intersects(tree,
						(const rtree_node_t*) node->children[i], rect, callback,
						udata, depth - 1)) {
				return false;
			}
		}
	}

	return true;
}

bool
rtree_intersects_foreach(const rtree_t* tree, const rtree_rect_t* rect,
		rtree_intersects_cb callback, void* udata)
{
	rtree_node_base_t* n = tree->root;
	uint64_t depth = tree->depth;

	if (depth > 0) {
		return _rtree_intersects(tree, (const rtree_node_t*) n, rect, callback,
				udata, depth - 1);
	}
	else {
		return _rtree_intersects_leaf(tree, (const rtree_leaf_t*) n, rect,
				callback, udata);
	}
}


/**********************************************************
 *                       RTree Move                       *
 **********************************************************/

static int
_do_move(rtree_t* tree, rtree_el_t* el_ptr, const rtree_rect_t* new_rect)
{
	rtree_leaf_t* prev_leaf = el_ptr->parent;
	if (rtree_rect_contains(&prev_leaf->base.bb, new_rect)) {
		el_ptr->bb = *new_rect;
		_shrink_leaf_bb(prev_leaf);
		return 0;
	}

	uint64_t inv_depth = 1;
	rtree_node_t* node = prev_leaf->base.parent;
	while (node != NULL && !rtree_rect_contains(&node->base.bb, new_rect)) {
		node = node->base.parent;
		inv_depth++;
	}

	if (node == NULL) {
		if (rtree_delete(tree, el_ptr) != 0) {
			return -1;
		}
		el_ptr->bb = *new_rect;
		if (rtree_insert(tree, el_ptr) != 0) {
			return -1;
		}
		return 0;
	}
	else {
		// replace el_ptr with a temporary rtree_el
		rtree_el_t old_el = *el_ptr;
		prev_leaf->elements[old_el.parent_idx] = &old_el;

		// update el_ptr's bb to the new bb
		el_ptr->bb = *new_rect;

		int_set_t reinserted_levels;
		int_set_inita(reinserted_levels, tree->depth);
		if (_do_insert_under_node(tree, el_ptr, reinserted_levels, &node->base,
				inv_depth) != 0) {
			return -1;
		}

		int_set_clear(reinserted_levels, tree->depth);
		if (_do_delete_element(tree, &old_el, reinserted_levels) != 0) {
			return -1;
		}
		return 0;
	}
}

int
rtree_move(rtree_t* tree, rtree_el_t* el, const rtree_rect_t* new_rect)
{
	return _do_move(tree, el, new_rect);
}


#ifdef DO_TESTING

/**********************************************************
 *                      RTree Print                       *
 **********************************************************/

static void
rtree_print_leaf(const rtree_leaf_t* leaf, int depth)
{
	printf("%*s{ ((%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 "))", 2*depth, "",
				leaf->base.bb.lx, leaf->base.bb.ly,
				leaf->base.bb.ux, leaf->base.bb.uy);
	for (uint32_t i = 0; i < leaf->base.n; i++) {
		printf("\n%*s<(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")>", 2*depth + 2, "",
				leaf->elements[i]->bb.lx, leaf->elements[i]->bb.ly,
				leaf->elements[i]->bb.ux, leaf->elements[i]->bb.uy);
	}
	printf("\n%*s}", 2*depth, "");
}

static void
rtree_print_node(const rtree_t* tree, const rtree_node_base_t* node, int depth)
{
	if (depth == (int) tree->depth) {
		rtree_print_leaf((rtree_leaf_t*) node, depth);
	}
	else {
		rtree_node_t* n = (rtree_node_t*) node;
		printf("%*s[ ((%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 "))", 2*depth, "",
				n->base.bb.lx, n->base.bb.ly,
				n->base.bb.ux, n->base.bb.uy);
		for (uint32_t i = 0; i < node->n; i++) {
			printf("\n");
			rtree_print_node(tree, n->children[i], depth + 1);
		}
		printf("\n%*s]", 2*depth, "");
	}
}

void
rtree_print(const rtree_t* tree)
{
	rtree_print_node(tree, tree->root, 0);
	printf("\n");
}


/**********************************************************
 *                   RTree Validation                     *
 **********************************************************/

static void
_rtree_validate_leaf(const rtree_t* tree, const rtree_leaf_t* leaf,
		const rtree_node_base_t* parent)
{
	dbg_assert(&leaf->base.parent->base == parent);

	uint32_t n_children = leaf->base.n;
	if (leaf->base.parent != NULL) {
		// only check if this isn't the root
		dbg_assert(tree->m_min <= n_children);
	}
	dbg_assert(n_children <= tree->m_max);

	rtree_rect_t bb;

	for (uint32_t i = 0; i < n_children; i++) {
		const rtree_el_t* el = leaf->elements[i];
		dbg_assert(rtree_rect_contains(&leaf->base.bb, &el->bb));
		dbg_assert(el->parent == leaf);
		dbg_assert(el->parent_idx == i);

		if (i == 0) {
			bb = el->bb;
		}
		else {
			rtree_rect_extend(&bb, &el->bb);
		}
	}

	if (n_children > 0) {
		dbg_assert(bb.lx == leaf->base.bb.lx);
		dbg_assert(bb.ly == leaf->base.bb.ly);
		dbg_assert(bb.ux == leaf->base.bb.ux);
		dbg_assert(bb.uy == leaf->base.bb.uy);
	}
}

static void
_rtree_validate_node(const rtree_t* tree, const rtree_node_base_t* n,
		const rtree_node_base_t* parent, uint64_t depth)
{
	if (depth == 0) {
		dbg_assert(n->parent == NULL);
	}

	if (depth == tree->depth) {
		_rtree_validate_leaf(tree, (const rtree_leaf_t*) n, parent);
	}
	else {
		const rtree_node_t* node = (const rtree_node_t*) n;
		uint32_t n_children = node->base.n;

		dbg_assert(&node->base.parent->base == parent);
		if (node->base.parent != NULL) {
			// only check if this isn't the root
			dbg_assert(tree->m_min <= n_children);
		}
		dbg_assert(n_children <= tree->m_max);

		rtree_rect_t bb;

		for (uint32_t i = 0; i < n_children; i++) {
			const rtree_node_t* child = (const rtree_node_t*) node->children[i];
			dbg_assert(rtree_rect_contains(&node->base.bb, &child->base.bb));
			dbg_assert(child->base.parent_idx == i);
			_rtree_validate_node(tree, &child->base, n, depth + 1);

			if (i == 0) {
				bb = child->base.bb;
			}
			else {
				rtree_rect_extend(&bb, &child->base.bb);
			}
		}

		dbg_assert(bb.lx == node->base.bb.lx);
		dbg_assert(bb.ly == node->base.bb.ly);
		dbg_assert(bb.ux == node->base.bb.ux);
		dbg_assert(bb.uy == node->base.bb.uy);
	}
}

void
rtree_validate(const rtree_t* tree)
{
	_rtree_validate_node(tree, tree->root, NULL, 0);
}

#endif /* DO_TESTING */

