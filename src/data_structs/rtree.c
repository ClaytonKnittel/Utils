
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <algorithms/sort.h>
#include <data_structs/rtree.h>
#include <util/util.h>


static __attribute__((always_inline)) inline rtree_coord_t
_rtree_rect_area(rtree_rect_t* r)
{
	return (r->ux - r->lx) * (r->uy - r->ly);
}

// TODO: optimize this with AVX
static __attribute__((always_inline)) inline bool
_rtree_rect_intersects(rtree_rect_t* a, rtree_rect_t* b)
{
	return !((a->ux < b->lx) || (b->ux < a->lx) ||
			 (a->uy < b->ly) || (b->uy < a->ly));
}

static __attribute__((always_inline)) inline rtree_coord_t
_rtree_rect_overlap(rtree_rect_t* a_ptr, rtree_rect_t* b_ptr)
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
 would be required to accomodate rect
 */
static __attribute__((always_inline)) inline rtree_coord_t
_rtree_rect_extend(rtree_rect_t* base, const rtree_rect_t* rect)
{
	rtree_coord_t area_inc = 0;
	rtree_rect_t b = *base;

	b.lx = MIN(b.lx, rect->lx);
	b.ux = MAX(b.ux, rect->ux);
	b.ly = MIN(b.ly, rect->ly);
	b.uy = MAX(b.uy, rect->uy);

	area_inc = ((b.ux - b.lx) * (b.uy - b.ly)) - ((base->ux - base->lx) * (base->uy - base->ly));

	*base = b;

	return area_inc;
}


static rtree_node_base_t*
_new_empty_inner_node(uint32_t m)
{
	// TODO: test calloc vs clear first bit
	rtree_node_t* n = (rtree_node_t*) malloc(sizeof(rtree_node_t) +
			m * sizeof(rtree_node_base_t*));
	// set everything but the children pointers to 0
	memset(n, 0, sizeof(rtree_node_t));
	return &n->base;
}

static rtree_node_base_t*
_new_empty_leaf_node(uint32_t m)
{
	// TODO: test calloc vs clear first bit
	rtree_leaf_t* n = (rtree_leaf_t*) malloc(sizeof(rtree_leaf_t) +
			m * sizeof(rtree_el_t*));
	// set everything but the children pointers to 0
	memset(n, 0, sizeof(rtree_leaf_t));
	return &n->base;
}

/*
 * returns the index of the child with least overlap increase
 */
static uint32_t
_min_overlap_cost_child(rtree_node_base_t* children, uint32_t n, rtree_rect_t* rect)
{
	struct cost {
		rtree_coord_t overlap_inc;
		rtree_coord_t area_inc;
		rtree_coord_t area;
	} opt, cur;
	uint32_t opt_idx = 0;

	rtree_rect_t r = children[0].bb;
	opt.overlap_inc = 0;
	opt.area_inc = _rtree_rect_extend(&r, rect);
	opt.area = _rtree_rect_area(&children[0].bb);

	for (uint32_t idx = 1; idx < n; idx++) {
		cur.overlap_inc += _rtree_rect_overlap(&r, &children[idx].bb);
		cur.overlap_inc -= _rtree_rect_overlap(&children[0].bb, &children[idx].bb);
	}

	for (uint32_t i = 1; i < n; i++) {
		r = children[i].bb;
		cur.overlap_inc = 0;
		cur.area_inc = _rtree_rect_extend(&r, rect);
		cur.area = _rtree_rect_area(&children[i].bb);

		for (uint32_t _idx = 0; _idx < n; _idx++) {
			uint32_t idx = _idx + (_idx >= i);
			cur.overlap_inc += _rtree_rect_overlap(&r, &children[idx].bb);
			cur.overlap_inc -= _rtree_rect_overlap(&children[0].bb, &children[idx].bb);
		}

		if (cur.overlap_inc > opt.overlap_inc ||
				(cur.overlap_inc == opt.overlap_inc &&
				 (cur.area_inc > opt.area_inc ||
				  (cur.area_inc == opt.area_inc && cur.area > opt.area)))) {
			opt = cur;
			opt_idx = i;
		}
	}

	return opt_idx;
}


static void
_do_insert(rtree_t* tree, rtree_rect_t* rect, void* udata)
{
	rtree_node_base_t* n = tree->root;

	// first, find the node we'll be inserting this element into
	if (!(n->state & RTREE_ROOT_LEAF)) {
		// the root is not a leaf node, search down it
		for(;;) {
			if (n->state & RTREE_NODE_LEAF_CHILDREN) {
				// this node's children are leaves, so we find the minimum
				// overlap cost
				
			}
		}
	}
}


void
rtree_init(rtree_t* tree, uint32_t m_inner, uint32_t m_leaf)
{
	tree->root = _new_empty_leaf_node(m_leaf);
	tree->m_inner = m_inner;
	tree->m_leaf = m_leaf;
}

