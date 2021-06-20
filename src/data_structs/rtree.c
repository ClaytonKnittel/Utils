
#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <algorithms/sort.h>
#include <data_structs/int_set.h>
#include <data_structs/rtree.h>
#include <util/util.h>


static __attribute__((always_inline)) inline rtree_coord_t
_rtree_rect_area(const rtree_rect_t* r)
{
	return (r->ux - r->lx) * (r->uy - r->ly);
}

static __attribute__((always_inline)) inline rtree_coord_t
_rtree_rect_margin(const rtree_rect_t* r)
{
	return 2 * ((r->ux - r->lx) + (r->uy - r->ly));
}

// TODO: optimize this with AVX
static __attribute__((always_inline)) inline bool
_rtree_rect_intersects(const rtree_rect_t* a, const rtree_rect_t* b)
{
	return !((a->ux < b->lx) || (b->ux < a->lx) ||
			 (a->uy < b->ly) || (b->uy < a->ly));
}

/*
 * returns true if p contains r (borders may intersect), false otherwise
 */
static __attribute__((always_inline)) inline bool
_rtree_rect_contains(const rtree_rect_t* p, const rtree_rect_t* r)
{
	return ((p->lx <= r->lx) && (r->ux <= p->ux) &&
			(p->ly <= r->ly) && (r->uy <= p->uy));
}

static __attribute__((always_inline)) inline rtree_coord_t
_rtree_rect_overlap(const rtree_rect_t* a_ptr, const rtree_rect_t* b_ptr)
{
	rtree_rect_t a = *a_ptr;
	rtree_rect_t b = *b_ptr;

	a.lx = MAX(a.lx, b.lx);
	a.ux = MIN(a.ux, b.ux);
	a.ly = MAX(a.ly, b.ly);
	a.uy = MIN(a.uy, b.uy);

	a.lx = MIN(a.lx, a.ux);
	a.ly = MIN(a.ly, a.uy);

	return _rtree_rect_area(&a);
}

/*
 * returns the amount of area increase that would be required to accomodate rect
 */
static __attribute__((always_inline)) inline rtree_coord_t
_rtree_rect_area_increase(const rtree_rect_t* base, const rtree_rect_t* rect)
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
static __attribute__((always_inline)) inline rtree_coord_t
_rtree_rect_combine(rtree_rect_t* dst, const rtree_rect_t* base, const rtree_rect_t* rect)
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
static __attribute__((always_inline)) inline rtree_coord_t
_rtree_rect_extend(rtree_rect_t* base, const rtree_rect_t* rect)
{
	return _rtree_rect_combine(base, base, rect);
}


static rtree_node_base_t*
_new_inner_node(uint32_t m_max)
{
	// TODO: test calloc vs clear first bit
	rtree_node_t* n = (rtree_node_t*) malloc(sizeof(rtree_node_t) +
			m_max * sizeof(rtree_node_base_t*));
	return &n->base;
}

static rtree_node_base_t*
_new_empty_leaf_node(uint32_t m_max)
{
	// TODO: test calloc vs clear first bit
	rtree_leaf_t* n = (rtree_leaf_t*) malloc(sizeof(rtree_leaf_t) +
			m_max * sizeof(rtree_el_t));
	// set everything but the children pointers to 0
	memset(n, 0, sizeof(rtree_leaf_t));
	return &n->base;
}

static rtree_node_base_t*
_new_leaf_node(uint32_t m_max)
{
	// TODO: test calloc vs clear first bit
	rtree_leaf_t* n = (rtree_leaf_t*) malloc(sizeof(rtree_leaf_t) +
			m_max * sizeof(rtree_el_t));
	return &n->base;
}

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
	opt.area_inc = _rtree_rect_extend(&r, rect);
	opt.area = _rtree_rect_area(&children[0]->bb);

	for (uint32_t idx = 1; idx < n; idx++) {
		opt.overlap_inc += _rtree_rect_overlap(&r, &children[idx]->bb);
		opt.overlap_inc -= _rtree_rect_overlap(&children[0]->bb, &children[idx]->bb);
	}

	for (uint32_t i = 1; i < n; i++) {
		r = children[i]->bb;
		cur.overlap_inc = 0;
		cur.area_inc = _rtree_rect_extend(&r, rect);
		cur.area = _rtree_rect_area(&children[i]->bb);

		for (uint32_t _idx = 0; _idx < n - 1; _idx++) {
			uint32_t idx = _idx + (_idx >= i);
			cur.overlap_inc += _rtree_rect_overlap(&r, &children[idx]->bb);
			cur.overlap_inc -= _rtree_rect_overlap(&children[i]->bb, &children[idx]->bb);
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
	opt.area_inc = _rtree_rect_extend(&r, rect);
	opt.area = _rtree_rect_area(&children[0]->bb);

	for (uint32_t i = 1; i < n; i++) {
		r = children[i]->bb;
		cur.area_inc = _rtree_rect_extend(&r, rect);
		cur.area = _rtree_rect_area(&children[i]->bb);

		if (cur.area_inc < opt.area_inc ||
				(cur.area_inc == opt.area_inc && cur.area < opt.area)) {
			opt = cur;
			opt_idx = i;
		}
	}

	return opt_idx;
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

DEFINE_CSORT_DEFAULT_FNS_NAMED_16(rtree_rect_t*, rtree_rect_x, rect_x_sort_cmp, rect_x_sort_cswap);
DEFINE_CSORT_DEFAULT_FNS_NAMED_16(rtree_rect_t*, rtree_rect_y, rect_y_sort_cmp, rect_y_sort_cswap);

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
	csort_rtree_rect_x(n, x_sort);
	csort_rtree_rect_y(n, y_sort);

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
			_rtree_rect_extend(&rev_rects[n_dists - 1], x_sort[i]);
		}
		for (; i >= m_min; i--) {
			_rtree_rect_combine(&rev_rects[i - m_min], &rev_rects[i - m_min + 1], x_sort[i]);
		}
	}

	// then go through the lower-coordinate split rectangles and combine with
	// the pre-calculated higher ones
	{
		rtree_rect_t x_bb = *x_sort[0];
		uint32_t i = 1;
		for (; i < m_min; i++) {
			_rtree_rect_extend(&x_bb, x_sort[i]);
		}
		x_margin = _rtree_rect_margin(&x_bb) + _rtree_rect_margin(&rev_rects[0]);
		opt_x.overlap = _rtree_rect_overlap(&x_bb, &rev_rects[0]);
		opt_x.area = _rtree_rect_area(&x_bb) + _rtree_rect_area(&rev_rects[0]);
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
				_rtree_rect_margin(&x_bb) + _rtree_rect_margin(&rev_rects[0]));
				*/

		for (; i < n - m_min; i++) {
			_rtree_rect_extend(&x_bb, x_sort[i]);
			x_margin += _rtree_rect_margin(&x_bb) +
				_rtree_rect_margin(&rev_rects[i - m_min + 1]);

			rtree_coord_t overlap = _rtree_rect_overlap(&x_bb, &rev_rects[i - m_min + 1]);
			rtree_coord_t area = _rtree_rect_area(&x_bb) +
				_rtree_rect_area(&rev_rects[i - m_min + 1]);

			/*
			printf("x at %u,\n"
					"  <(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")>\n"
					"  <(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")> (%llu)",
					i,
					x_bb.lx, x_bb.ly,
					x_bb.ux, x_bb.uy,
					rev_rects[i - m_min + 1].lx, rev_rects[i - m_min + 1].ly,
					rev_rects[i - m_min + 1].ux, rev_rects[i - m_min + 1].uy,
					_rtree_rect_margin(&x_bb) + _rtree_rect_margin(&rev_rects[i - m_min + 1]));
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
			_rtree_rect_extend(&rev_rects[n_dists - 1], y_sort[i]);
		}
		for (; i >= m_min; i--) {
			_rtree_rect_combine(&rev_rects[i - m_min], &rev_rects[i - m_min + 1], y_sort[i]);
		}
	}

	// then go through the lower-coordinate split rectangles and combine with
	// the pre-calculated higher ones
	{
		rtree_rect_t y_bb = *y_sort[0];
		uint32_t i = 1;
		for (; i < m_min; i++) {
			_rtree_rect_extend(&y_bb, y_sort[i]);
		}
		y_margin = _rtree_rect_margin(&y_bb) + _rtree_rect_margin(&rev_rects[0]);
		opt_y.overlap = _rtree_rect_overlap(&y_bb, &rev_rects[0]);
		opt_y.area = _rtree_rect_area(&y_bb) + _rtree_rect_area(&rev_rects[0]);
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
				_rtree_rect_margin(&y_bb) + _rtree_rect_margin(&rev_rects[0]));
				*/

		for (; i < n - m_min; i++) {
			_rtree_rect_extend(&y_bb, y_sort[i]);
			y_margin += _rtree_rect_margin(&y_bb) +
				_rtree_rect_margin(&rev_rects[i - m_min + 1]);

			rtree_coord_t overlap = _rtree_rect_overlap(&y_bb, &rev_rects[i - m_min + 1]);
			rtree_coord_t area = _rtree_rect_area(&y_bb) +
				_rtree_rect_area(&rev_rects[i - m_min + 1]);

			/*
			printf("y at %u,\n"
					"  <(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")>\n"
					"  <(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")> (%llu)",
					i,
					y_bb.lx, y_bb.ly,
					y_bb.ux, y_bb.uy,
					rev_rects[i - m_min + 1].lx, rev_rects[i - m_min + 1].ly,
					rev_rects[i - m_min + 1].ux, rev_rects[i - m_min + 1].uy,
					_rtree_rect_margin(&y_bb) + _rtree_rect_margin(&rev_rects[i - m_min + 1]));
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
	rtree_el_t* x_sort_base;
	rtree_el_t* y_sort_base;
	rtree_el_t** x_sort;
	rtree_el_t** y_sort;
	struct split_cost x_cost, y_cost;

	x_sort_base = (rtree_el_t*) alloca((n + 1) * sizeof(rtree_el_t));
	y_sort_base = (rtree_el_t*) alloca((n + 1) * sizeof(rtree_el_t));

	x_sort = (rtree_el_t**) alloca((n + 1) * sizeof(rtree_el_t*));
	y_sort = (rtree_el_t**) alloca((n + 1) * sizeof(rtree_el_t*));

	memcpy(x_sort_base, node->elements, n * sizeof(rtree_el_t));
	memcpy(y_sort_base, node->elements, n * sizeof(rtree_el_t));
	x_sort_base[n] = *to_add;
	y_sort_base[n] = *to_add;

	for (uint32_t i = 0; i < n + 1; i++) {
		x_sort[i] = &x_sort_base[i];
		y_sort[i] = &y_sort_base[i];
	}
	n++;

	bool split_x = _determine_split(tree, n, (rtree_rect_t**) x_sort, (rtree_rect_t**) y_sort,
			&x_cost, &y_cost);

	// determine split axis
	rtree_leaf_t* split_node = (rtree_leaf_t*) _new_leaf_node(tree->m_max);
	split_node->base.parent = node->base.parent;
	split_node->base.state = node->base.state;
	split_node->base.depth = 0;

	if (split_x) {
		node->base.bb = x_cost.lower_bb;
		node->base.n = x_cost.split_idx;
		split_node->base.bb = x_cost.upper_bb;
		split_node->base.n = n - x_cost.split_idx;

		// udate the children of both nodes
		for (uint32_t i = 0; i < x_cost.split_idx; i++) {
			node->elements[i] = *x_sort[i];
		}
		for (uint32_t i = 0; i < n - x_cost.split_idx; i++) {
			split_node->elements[i] = *x_sort[i + x_cost.split_idx];
		}
	}
	else {
		node->base.bb = y_cost.lower_bb;
		node->base.n = y_cost.split_idx;
		split_node->base.bb = y_cost.upper_bb;
		split_node->base.n = n - y_cost.split_idx;

		// udate the children of both nodes
		for (uint32_t i = 0; i < y_cost.split_idx; i++) {
			node->elements[i] = *y_sort[i];
		}
		for (uint32_t i = 0; i < n - y_cost.split_idx; i++) {
			split_node->elements[i] = *y_sort[i + y_cost.split_idx];
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
	split_node->base.parent = node->base.parent;
	split_node->base.state = node->base.state;

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

		// calculate the new depths of each node
		uint32_t node_depth;
		uint32_t split_depth;

		node_depth = x_sort[0]->depth;
		for (uint32_t i = 1; i < x_cost.split_idx; i++) {
			node_depth = MAX(node_depth, x_sort[i]->depth);
		}

		x_sort[x_cost.split_idx]->parent = split_node;
		split_depth = x_sort[x_cost.split_idx]->depth;
		for (uint32_t i = x_cost.split_idx + 1; i < n; i++) {
			x_sort[i]->parent = split_node;
			split_depth = MAX(split_depth, x_sort[i]->depth);
		}

		node->base.depth = node_depth + 1;
		split_node->base.depth = split_depth + 1;
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

		// calculate the new depths of each node and update their parents
		uint32_t node_depth;
		uint32_t split_depth;

		node_depth = y_sort[0]->depth;
		for (uint32_t i = 1; i < y_cost.split_idx; i++) {
			node_depth = MAX(node_depth, y_sort[i]->depth);
		}

		y_sort[y_cost.split_idx]->parent = split_node;
		split_depth = y_sort[y_cost.split_idx]->depth;
		for (uint32_t i = y_cost.split_idx + 1; i < n; i++) {
			y_sort[i]->parent = split_node;
			split_depth = MAX(split_depth, y_sort[i]->depth);
		}

		node->base.depth = node_depth + 1;
		split_node->base.depth = split_depth + 1;
	}

	return (rtree_node_base_t*) split_node;
}


static void
_do_insert(rtree_t* tree, rtree_rect_t* rect, void* udata, int_set_t reinserted_levels)
{
	rtree_node_base_t* n = tree->root;
	uint32_t m_max = tree->m_max;
	uint64_t depth = 0;

	// first, find the node we'll be inserting this element into
	if (!(n->state & RTREE_ROOT_LEAF)) {
		// the root is not a leaf node, search down it
		for(;;) {
			if (n->state & RTREE_NODE_LEAF_CHILDREN) {
				// this node's children are leaves, so we find the minimum
				// overlap cost
				rtree_node_t* node = (rtree_node_t*) n;
				uint32_t c_idx = _min_overlap_cost_child(node->children, node->base.n, rect);
				n = node->children[c_idx];
				break;
			}
			else {
				// this node's children aren't leaves, so we find the node
				// requiring the least area increase
				rtree_node_t* node = (rtree_node_t*) n;
				uint32_t c_idx = _min_area_increase_child(node->children, node->base.n, rect);
				n = node->children[c_idx];
				depth++;
			}
		}
	}
	// if the root is a leaf node, just go ahead and insert directly into it

	// insert into n, which is gurarnteed to be a leaf node
	rtree_leaf_t* leaf = (rtree_leaf_t*) n;
	if (leaf->base.n < m_max) {
		// there is still room for this entry, simply insert it
		leaf->elements[leaf->base.n++] = (rtree_el_t) {
			.bb = *rect,
			.udata = udata
		};
		_rtree_rect_extend(&leaf->base.bb, rect);

		rtree_node_base_t* child = n;
		n = child->parent;
		// update the bounding boxes of all of this node's parents
		while (n != NULL) {
			_rtree_rect_extend(&n->bb, &child->bb);
			child = n;
			n = n->parent;
		}
		return;
	}

	// otherwise, we need to split up the tree
	// leaves are a special case
	if (false && depth != 0 && !int_set_contains(reinserted_levels, depth)) {
		// perform reinsertion
		int_set_insert(reinserted_levels, depth);
	}
	else {
		// perform a split
		rtree_el_t new_el = {
			.bb = *rect,
			.udata = udata
		};
		n = _split_leaf(tree, (rtree_leaf_t*) n, &new_el);
	}

	rtree_node_base_t* split_child = n;
	for (;;) {
		n = split_child->parent;
		if (n == NULL) {
			// we have split the root! Make a new one, make n and the old root its children
			rtree_node_t* new_root = (rtree_node_t*) _new_inner_node(m_max);
			rtree_node_base_t* old_root = tree->root;

			_rtree_rect_combine(&new_root->base.bb, &old_root->bb, &split_child->bb);
			new_root->base.parent = NULL;
			new_root->base.n = 2;
			new_root->base.state = (old_root->state & RTREE_ROOT_LEAF) ?
				RTREE_NODE_LEAF_CHILDREN : 0;
			new_root->base.depth = old_root->depth + 1;
			new_root->children[0] = old_root;
			new_root->children[1] = split_child;

			old_root->parent = (rtree_node_base_t*) new_root;
			// since old_root is no longer the root, it can't have this flag set
			old_root->state &= ~RTREE_ROOT_LEAF;

			split_child->parent = (rtree_node_base_t*) new_root;
			split_child->state &= ~RTREE_ROOT_LEAF;

			tree->root = &new_root->base;
			break;
		}

		if (n->n < m_max) {
			// we can accomodate split_child
			rtree_node_t* node = (rtree_node_t*) n;
			node->children[node->base.n++] = split_child;

			// update the bounding boxes of all of this node's parents
			do {
				_rtree_rect_extend(&n->bb, &split_child->bb);
				split_child = n;
				n = n->parent;
			} while (n != NULL);
			break;
		}

		if (false && depth != 0 && !int_set_contains(reinserted_levels, depth)) {
			// perform reinsertion
			int_set_insert(reinserted_levels, depth);
		}
		else {
			// perform a split
			split_child = _split_node(tree, (rtree_node_t*) n, split_child);
		}
		depth--;
	}
}


void
rtree_init(rtree_t* tree, uint32_t m_min, uint32_t m_max)
{
	tree->root = _new_empty_leaf_node(m_max);
	tree->root->state |= RTREE_ROOT_LEAF;
	tree->m_min = m_min;
	tree->m_max = m_max;
}

static void
_rtree_leaf_free(rtree_leaf_t* leaf)
{
	free(leaf);
}

static void
_rtree_node_free(rtree_node_base_t* node)
{
	if (node->state & RTREE_ROOT_LEAF) {
		_rtree_leaf_free((rtree_leaf_t*) node);
	}
	else if (node->state & RTREE_NODE_LEAF_CHILDREN) {
		rtree_node_t* inode = (rtree_node_t*) node;
		for (uint32_t i = 0; i < inode->base.n; i++) {
			rtree_leaf_t* leaf = (rtree_leaf_t*) inode->children[i];
			_rtree_leaf_free(leaf);
		}
		free(inode);
	}
	else {
		rtree_node_t* inode = (rtree_node_t*) node;
		for (uint32_t i = 0; i < inode->base.n; i++) {
			_rtree_node_free(inode->children[i]);
		}
		free(inode);
	}
}

void
rtree_free(rtree_t* tree)
{
	_rtree_node_free(tree->root);
}

void
rtree_insert(rtree_t* tree, rtree_rect_t* rect, void* udata)
{
	int_set_t iset;
	int_set_inita(iset, tree->root->depth);
	_do_insert(tree, rect, udata, iset);
}


void
rtree_print_leaf(const rtree_leaf_t* leaf, int depth)
{
	printf("%*s{ ((%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 "))", depth, "",
				leaf->base.bb.lx, leaf->base.bb.ly,
				leaf->base.bb.ux, leaf->base.bb.uy);
	for (uint32_t i = 0; i < leaf->base.n; i++) {
		printf("\n%*s<(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")>", depth + 2, "",
				leaf->elements[i].bb.lx, leaf->elements[i].bb.ly,
				leaf->elements[i].bb.ux, leaf->elements[i].bb.uy);
	}
	printf("\n%*s}", depth, "");
}

void
rtree_print_node(const rtree_node_base_t* node, int depth)
{
	if (node->state & RTREE_ROOT_LEAF) {
		rtree_print_leaf((rtree_leaf_t*) node, depth);
	}
	else if (node->state & RTREE_NODE_LEAF_CHILDREN) {
		rtree_node_t* n = (rtree_node_t*) node;
		printf("%*s[ ((%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 "))", depth, "",
				n->base.bb.lx, n->base.bb.ly,
				n->base.bb.ux, n->base.bb.uy);
		for (uint32_t i = 0; i < node->n; i++) {
			printf("\n");
			rtree_print_leaf((rtree_leaf_t*) n->children[i], depth + 2);
		}
		printf("\n%*s]", depth, "");
	}
	else {
		rtree_node_t* n = (rtree_node_t*) node;
		printf("%*s[ ((%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 "))", depth, "",
				n->base.bb.lx, n->base.bb.ly,
				n->base.bb.ux, n->base.bb.uy);
		for (uint32_t i = 0; i < node->n; i++) {
			printf("\n");
			rtree_print_node(n->children[i], depth + 2);
		}
		printf("\n%*s]", depth, "");
	}
}

void
rtree_print(const rtree_t* tree)
{
	rtree_print_node(tree->root, 0);
	printf("\n");
}


struct check_state {
	uint64_t depth;
};


static void
_rtree_check_leaf(const rtree_t* tree, struct check_state* state,
		const rtree_leaf_t* leaf, const rtree_node_base_t* parent,
		uint64_t depth)
{
	assert(leaf->base.depth == 0);
	state->depth = MAX(state->depth, depth);
	assert(leaf->base.parent == parent);

	uint32_t n_children = leaf->base.n;
	if (leaf->base.parent != NULL) {
		// only check if this isn't the root
		assert(tree->m_min <= n_children);
	}
	assert(n_children <= tree->m_max);

	rtree_rect_t bb;

	for (uint32_t i = 0; i < n_children; i++) {
		const rtree_el_t* el = &leaf->elements[i];
		assert(_rtree_rect_contains(&leaf->base.bb, &el->bb));

		if (i == 0) {
			bb = el->bb;
		}
		else {
			_rtree_rect_extend(&bb, &el->bb);
		}
	}

	if (n_children > 0) {
		assert(bb.lx == leaf->base.bb.lx);
		assert(bb.ly == leaf->base.bb.ly);
		assert(bb.ux == leaf->base.bb.ux);
		assert(bb.uy == leaf->base.bb.uy);
	}
}

static void
_rtree_check_node(const rtree_t* tree, struct check_state* p_state,
		const rtree_node_base_t* n, const rtree_node_base_t* parent,
		uint64_t depth)
{
	struct check_state state = {
		.depth = depth
	};

	if (n->state & RTREE_ROOT_LEAF) {
		// this flag can only be set in the root
		assert(parent == NULL);

		_rtree_check_leaf(tree, &state, (const rtree_leaf_t*) n, parent, depth);
	}
	else if (n->state & RTREE_NODE_LEAF_CHILDREN) {
		const rtree_node_t* node = (const rtree_node_t*) n;
		uint32_t n_children = node->base.n;
		assert(n_children <= tree->m_max);

		assert(node->base.parent == parent);

		rtree_rect_t bb;

		for (uint32_t i = 0; i < n_children; i++) {
			const rtree_leaf_t* child = (const rtree_leaf_t*) node->children[i];
			assert(_rtree_rect_contains(&node->base.bb, &child->base.bb));
			_rtree_check_leaf(tree, &state, child, n, depth + 1);

			if (i == 0) {
				bb = child->base.bb;
			}
			else {
				_rtree_rect_extend(&bb, &child->base.bb);
			}
		}

		assert(bb.lx == node->base.bb.lx);
		assert(bb.ly == node->base.bb.ly);
		assert(bb.ux == node->base.bb.ux);
		assert(bb.uy == node->base.bb.uy);
	}
	else {
		const rtree_node_t* node = (const rtree_node_t*) n;
		uint32_t n_children = node->base.n;
		if (node->base.parent != NULL) {
			// only check if this isn't the root
			assert(tree->m_min <= n_children);
		}
		assert(n_children <= tree->m_max);

		assert(node->base.parent == parent);

		rtree_rect_t bb;

		for (uint32_t i = 0; i < n_children; i++) {
			const rtree_node_t* child = (const rtree_node_t*) node->children[i];
			assert(_rtree_rect_contains(&node->base.bb, &child->base.bb));
			_rtree_check_node(tree, &state, &child->base, n, depth + 1);

			if (i == 0) {
				bb = child->base.bb;
			}
			else {
				_rtree_rect_extend(&bb, &child->base.bb);
			}
		}

		assert(bb.lx == node->base.bb.lx);
		assert(bb.ly == node->base.bb.ly);
		assert(bb.ux == node->base.bb.ux);
		assert(bb.uy == node->base.bb.uy);
	}

	assert(n->depth == state.depth - depth);
	p_state->depth = MAX(p_state->depth, state.depth);
}

void
rtree_check(const rtree_t* tree)
{
	struct check_state state = {
		.depth = 0
	};
	_rtree_check_node(tree, &state, tree->root, NULL, 0);
}

