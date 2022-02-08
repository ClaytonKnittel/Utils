#ifndef _R_TREE_H_
#define _R_TREE_H_

#include <stdbool.h>
#include <stdint.h>

/*
 * Implementation file of R* trees for storage of rectangular elements
 */

typedef int64_t rtree_coord_t;

// the default fraction of m_max that p is set to (the number of nodes to reinsert)
#define DEFAULT_REINSERT_P_PCT .30f


typedef struct rtree_rect {
	rtree_coord_t lx;
	rtree_coord_t ly;
	rtree_coord_t ux;
	rtree_coord_t uy;
} rtree_rect_t;

/*
 * the base struct that all nodes have in common
 */
typedef struct rtree_node_base {
	// the bounding box of the node
	rtree_rect_t bb;

	struct rtree_node_base* parent;

	// the number of children of this node
	uint32_t n;
} rtree_node_base_t;


/*
 * rtree_nodes are internal nodes in an rtree
 */
typedef struct rtree_node {
	rtree_node_base_t base;

	// the list of children of this node
	rtree_node_base_t* children[];
} rtree_node_t;

/*
 * the base element stored in the rtree, which consists of a bounding box and a
 * pointer to user data associated with the bounding box
 */
typedef struct rtree_el {
	rtree_rect_t bb;
	void* udata;
} rtree_el_t;

/*
 * this is returned by all find_id functions, which should be used when needing
 * to call other methods with an element as an argument. This gives information
 * on where to find a specific element
 */
typedef struct rtree_el_id {
	struct rtree_leaf* parent;
	uint64_t idx;
} rtree_el_id_t;

/*
 * rtree_leaf's are leaf nodes in an rtree
 */
typedef struct rtree_leaf {
	rtree_node_base_t base;

	// the list of elements of this node
	rtree_el_t elements[];
} rtree_leaf_t;


typedef struct rtree {
	rtree_node_base_t* root;
	// min number of children a node can have
	uint32_t m_min;
	// max number of children a node can have
	uint32_t m_max;

	// the number of elements to reinsert when a node overflows
	uint32_t reinsert_p;

	// the depth of the tree (i.e. number of ancestors the leaves have)
	uint64_t depth;
} rtree_t;

/*
 * Callback method signatures for find-all-intersecting methods. The current
 * intersecting rect in the rtree is passed via el_id/el.
 *
 * If these callbacks return false, iteration is stopped, otherwise continuing
 * until all intersecting rectangles have been found.
 */
typedef bool (*rtree_intersects_id_cb)(rtree_el_id_t el_id, void* udata,
		const rtree_rect_t* rect, const rtree_t* tree);
typedef bool (*rtree_intersects_cb)(const rtree_el_t* el, void* udata,
		const rtree_rect_t* rect, const rtree_t* tree);


/*
 * given an rtree_el_id_t, returns a pointer to the corresponding rtree_el_t
 */
rtree_el_t* rtree_el_id_get(rtree_el_id_t id);


int rtree_init(rtree_t*, uint32_t m_min, uint32_t m_max);
void rtree_free(rtree_t*);

int rtree_insert(rtree_t*, rtree_rect_t* rect, void* udata);

int rtree_delete(rtree_t*, rtree_el_id_t*);

/*
 * Finds the rtree node with rectangle exactly matching that of the rectangle
 * passed. Will only return one rectangle if multiple matches exist in the tree.
 */
rtree_el_id_t rtree_find_exact_id(const rtree_t*, const rtree_rect_t* rect);
rtree_el_t* rtree_find_exact(const rtree_t*, const rtree_rect_t* rect);

/*
 * Iterates over every element in the tree that intersects with the given
 * rectangle, calling callback on each instance.
 */
void rtree_intersects_id_foreach(const rtree_t*, const rtree_rect_t* rect,
		rtree_intersects_id_cb callback, void* udata);
void rtree_intersects_foreach(const rtree_t*, const rtree_rect_t* rect,
		rtree_intersects_cb callback, void* udata);

rtree_el_id_t* rtree_k_nearest_id(const rtree_t*, const rtree_rect_t* rect,
		rtree_el_id_t* ids, uint32_t k);
rtree_el_t** rtree_k_nearest(const rtree_t*, const rtree_rect_t* rect,
		rtree_el_t** els, uint32_t k);

void rtree_print(const rtree_t*);

#ifdef DO_TESTING
void rtree_validate(const rtree_t*);
#endif /* DO_TESTING */

#endif /* _R_TREE_H_ */
