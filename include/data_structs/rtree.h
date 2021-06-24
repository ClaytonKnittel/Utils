#ifndef _R_TREE_H_
#define _R_TREE_H_

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

	// the number of elements to reinsert 
	uint32_t reinsert_p;

	// the depth of the tree (i.e. number of ancestors the leaves have)
	uint64_t depth;
} rtree_t;


void rtree_init(rtree_t*, uint32_t m_min, uint32_t m_max);
void rtree_free(rtree_t*);

void rtree_insert(rtree_t*, rtree_rect_t* rect, void* udata);

void rtree_print(const rtree_t*);

void rtree_check(const rtree_t*);

#endif /* _R_TREE_H_ */
