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

	struct rtree_node* parent;

	// the number of children of this node
	uint32_t n;
	// the index of this node in parent's elements list
	uint32_t parent_idx;
} rtree_node_base_t;


/*
 * rtree_nodes are internal nodes in an rtree
 */
typedef struct rtree_node {
	rtree_node_base_t base;

	// the list of children of this node
	rtree_node_base_t* children[];
} rtree_node_t;

// forward declare for rtree_el
typedef struct rtree_leaf rtree_leaf_t;

/*
 * the base element stored in the rtree, which consists of a bounding box and a
 * pointer to the element's parent
 */
typedef struct rtree_el {
	rtree_rect_t bb;
	rtree_leaf_t* parent;
	// the index of this node in parent's elements list
	uint32_t parent_idx;
} rtree_el_t;

/*
 * rtree_leaf's are leaf nodes in an rtree
 */
typedef struct rtree_leaf {
	rtree_node_base_t base;

	// the list of elements of this node
	rtree_el_t* elements[];
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
 * Callback method signature for find-all-intersecting methods. The current
 * intersecting rect in the rtree is passed via el.
 *
 * If this callback returns false, iteration is stopped, otherwise continuing
 * until all intersecting rectangles have been found.
 */
typedef bool (*rtree_intersects_cb)(const rtree_el_t* el, void* udata,
		const rtree_rect_t* rect, const rtree_t* tree);


int rtree_init(rtree_t*, uint32_t m_min, uint32_t m_max);
void rtree_free(rtree_t*);

int rtree_insert(rtree_t*, rtree_el_t* el_ptr);

/*
 * Removes the rtree_el from the tree.
 */
int rtree_delete(rtree_t*, rtree_el_t*);

/*
 * Finds the rtree node with rectangle exactly matching that of the rectangle
 * passed. Will only return one rectangle if multiple matches exist in the tree.
 */
rtree_el_t* rtree_find_exact(const rtree_t*, const rtree_rect_t* rect);

/*
 * Iterates over every element in the tree that intersects with the given
 * rectangle, calling callback on each instance.
 */
void rtree_intersects_foreach(const rtree_t*, const rtree_rect_t* rect,
		rtree_intersects_cb callback, void* udata);

/*
 * Updates the rtree_el's bounding box to the supplied new bounding box. This
 * method is most efficient when the bounding box changes only slightly.
 */
void rtree_move(rtree_t*, rtree_el_t*, const rtree_rect_t* new_rect);

#ifdef DO_TESTING
void rtree_print(const rtree_t*);

void rtree_validate(const rtree_t*);
#endif /* DO_TESTING */

#endif /* _R_TREE_H_ */
