
#include <stdlib.h>
#include <string.h>

#include <data_structs/rtree.h>


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
	return 0;
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

