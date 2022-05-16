#ifndef _RB_TREE_H_
#define _RB_TREE_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <utils/utils.h>


#define RB_ASSERT(expr, tree) \
	if (__builtin_expect(!(expr), 0)) { \
		printf("tree %p:\n", (tree)); \
		rb_print(tree); \
	} \
	dbg_assert(expr)


#ifdef __cplusplus
extern "C" {
#endif

// declare red-black nodes early for usage in this struct
typedef struct rb_node {
	struct rb_node *left;
	struct rb_node *right;
	struct rb_node *parent;
} rb_node_t;



struct __int_rb_tree {
	struct rb_node *root;
	uint64_t size;
};

/*
 * pointers as bitfields:
 *
 * the first bit of each pointer field in an rb_node struct is to be used
 * by the node to store information about its own state. The second bit stores
 * information about the node it points to
 *
 *
 *      - R/B says whether node it points to is red or black
 *      - root is set if this node is the root
 *      - col is the color (red or black) of this node
 *
 * left:
 *      +-------- ... -+-----+-----+-----+
 *      |         ...  |     | R/B |root?|
 *      +-------- ... -+-----+-----+-----+
 *
 * right:
 *      +-------- ... -+-----+-----+-----+
 *      |         ...  |     | R/B |     |
 *      +-------- ... -+-----+-----+-----+
 *
 * parent:
 *      +-------- ... -+-----+-----+-----+
 *      |         ...  |     | R/B | col |
 *      +-------- ... -+-----+-----+-----+
 *
 *
 *
 */



// to be put in the parent pointer field, 
#define BLACK 0x0
#define RED 0x1

#define COLOR_MASK (BLACK | RED)

// to be put in left pointer field
#define ROOT 0x1

// mask covering all used bitfields in a pointer
#define PTR_MASK (RED | BLACK | ROOT)

#define LEAF ((rb_node_t*) BLACK)



static rb_node_t* rb_get_root(struct __int_rb_tree *t) {
	return t->root;
}

static void rb_set_parent(rb_node_t *n, rb_node_t *p) {
	n->parent = (rb_node_t*) (
			(((unsigned long) n->parent) & PTR_MASK) | ((unsigned long) p));
}

static rb_node_t* rb_get_left(rb_node_t *n) {
	return (rb_node_t*) (((unsigned long) n->left) & ~PTR_MASK);
}

static void rb_set_left(rb_node_t *n, rb_node_t *l) {
	n->left = (rb_node_t*) ((((unsigned long) n->left) & PTR_MASK)
			| (unsigned long) l);
	if (l != LEAF) {
		rb_set_parent(l, n);
	}
}

static rb_node_t* rb_get_right(rb_node_t *n) {
	return n->right;
}

static void rb_set_right(rb_node_t *n, rb_node_t *r) {
	n->right = r;
	if (r != LEAF) {
		rb_set_parent(r, n);
	}
}


/*
 * Initialize the red black tree. Called only once during the initialization
 * of the state struct.
 *
 */
static void rb_init(struct __int_rb_tree* tree) {
	tree->root = LEAF;
	tree->size = 0;
}


void rb_free_node(rb_node_t* node);

/*
 * called to free the rbtree. Should only be called on trees with scalar
 * types, since only then is the memory managed by the tree
 */
static void rb_free(struct __int_rb_tree* tree) {
	rb_node_t* root = rb_get_root(tree);
	if (root != LEAF) {
		rb_free_node(root);
	}
}


/*
 * macro for defining the find function for rb nodes, which essentially
 * determines the way in which the red-black tree sorts its elements.
 *
 * Find will return the leftmost node of tree which could be a parent of node
 * without violating the BST property of the tree
 */
#define RB_DEFINE_FIND_LOC(name, cmp_fn) \
static rb_node_t* rb_find_ ## name ## _loc(struct __int_rb_tree *tree, rb_node_t *node) { \
	rb_node_t *prev_node = LEAF; \
	rb_node_t *root = rb_get_root(tree); \
	while (root != LEAF) { \
		prev_node = root; \
		root = (cmp_fn(root, node) < 0 ? \
				rb_get_right(root) : rb_get_left(root)); \
	} \
	return prev_node; \
}


/*
 * returns the largest node which is less than or equal to the supplied node
 */
#define RB_DEFINE_UPPER_BOUND(name, cmp_fn) \
static rb_node_t* rb_upper_bound_ ## name(struct __int_rb_tree *tree, rb_node_t *node) { \
	rb_node_t * prev_less_node = LEAF; \
	rb_node_t * root = rb_get_root(tree); \
	while (root != LEAF) { \
		if (cmp_fn(node, root) >= 0) { \
			prev_less_node = root; \
			root = rb_get_right(root); \
		} \
		else { \
			root = rb_get_left(root); \
		} \
	} \
	return prev_less_node; \
}

/*
 * returns the smallest node which is greater than or equal to the supplied node
 */
#define RB_DEFINE_LOWER_BOUND(name, cmp_fn) \
static rb_node_t* rb_lower_bound_ ## name(struct __int_rb_tree *tree, rb_node_t *node) { \
	rb_node_t * prev_ge_node = LEAF; \
	rb_node_t * root = rb_get_root(tree); \
	while (root != LEAF) { \
		if (cmp_fn(root, node) < 0) { \
			root = rb_get_right(root); \
		} \
		else { \
			prev_ge_node = root; \
			root = rb_get_left(root); \
		} \
	} \
	return prev_ge_node; \
}



#define RB_DEFINE_FIND_HELPER(name, cmp_fn) \
static rb_node_t* _rb_find_ ## name ## _helper(rb_node_t *root, rb_node_t *node) { \
	while (root != LEAF) { \
		int cmp = cmp_fn(root, node); \
		if (cmp == 0) return root; \
		root = cmp < 0 ? rb_get_right(root) : rb_get_left(root); \
	} \
	return NULL; \
}


#define RB_DEFINE_FIND(name) \
static rb_node_t* rb_find_ ## name(struct __int_rb_tree *tree, rb_node_t *node) { \
	rb_node_t *root; \
	root = rb_get_root(tree); \
	return _rb_find_ ## name ## _helper(root, node); \
}

#define RB_DEFINE_CONTAINS(name) \
static int rb_contains_ ## name(struct __int_rb_tree *tree, rb_node_t *node) { \
	return rb_find_ ## name(tree, node) != NULL; \
}



int _rb_insert_helper(struct __int_rb_tree *tree, rb_node_t *node, rb_node_t* p);

#define RB_DEFINE_INSERT(name, cmp_fn) \
static int rb_insert_ ## name(struct __int_rb_tree *tree, rb_node_t* node) { \
	rb_node_t *p; \
	memset(node, 0, sizeof(rb_node_t)); \
	p = rb_find_ ## name ## _loc(tree, node); \
	if (p != LEAF) { \
		if (cmp_fn(p, node) < 0) { \
			rb_set_right(p, node); \
		} else { \
			rb_set_left(p, node); \
		} \
	} \
	return _rb_insert_helper(tree, node, p); \
}


void _rb_remove_helper(struct __int_rb_tree *tree, rb_node_t *node);

#define RB_DEFINE_REMOVE(name) \
static void rb_remove_ ## name(struct __int_rb_tree *tree, rb_node_t *node) { \
	RB_ASSERT(rb_contains_ ## name(tree, node), tree); \
	_rb_remove_helper(tree, node); \
}


/*
 * does generic consistency checks (all besides BST property, which must
 * be generated with macros)
 */
void _rb_validate_helper(struct __int_rb_tree *tree);


#define RB_DEFINE_BST_CHECK(name, cmp_fn) \
static void _bst_check_ ## name(rb_node_t *node) { \
	if (rb_get_left(node) != LEAF) { \
		dbg_assert(cmp_fn(node, rb_get_left(node)) >= 0); \
		_bst_check_ ## name(rb_get_left(node)); \
	} \
	if (rb_get_right(node) != LEAF) { \
		dbg_assert(cmp_fn(rb_get_right(node), node) >= 0); \
		_bst_check_ ## name(rb_get_right(node)); \
	} \
}


#define RB_DEFINE_VALIDATE(name) \
static void rb_validate_ ## name(struct __int_rb_tree *tree) { \
	rb_node_t *root = rb_get_root(tree); \
	_rb_validate_helper(tree); \
	if(root != LEAF) { \
		_bst_check_ ## name(root); \
	} \
}


#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic push

/*
 * only defines the search functions for this type
 *
 * the left operand of cmp_find will always be rb_nodes found in the tree, and
 * the right will always be the thing you are comparing against, so the latter
 * may be whatever type you desire, even if incompatible with the rb_node type
 */
#define RB_DEFINE_TYPE_SEARCH(name, cmp_fn) \
	RB_DEFINE_FIND_HELPER(name, cmp_fn) \
	RB_DEFINE_FIND(name) \
	RB_DEFINE_CONTAINS(name)

#define RB_DEFINE_TYPE(name, cmp_fn) \
	RB_DEFINE_FIND_LOC(name, cmp_fn) \
	RB_DEFINE_UPPER_BOUND(name, cmp_fn) \
	RB_DEFINE_LOWER_BOUND(name, cmp_fn) \
	RB_DEFINE_TYPE_SEARCH(name, cmp_fn) \
	RB_DEFINE_INSERT(name, cmp_fn) \
	RB_DEFINE_REMOVE(name) \
	RB_DEFINE_BST_CHECK(name, cmp_fn) \
	RB_DEFINE_VALIDATE(name)

#pragma GCC diagnostic pop


static int rb_is_empty(struct __int_rb_tree *tree) {
	return rb_get_root(tree) == LEAF;
}


rb_node_t* rb_find_leftmost(struct __int_rb_tree *tree);
rb_node_t* rb_find_rightmost(struct __int_rb_tree *tree);

rb_node_t* rb_find_succ(rb_node_t *node);
rb_node_t* rb_find_pred(rb_node_t *node);


/*
 * Iterators over the elements of a red-black tree.
 */
#define rb_for_each(tree, node) \
	for ((node) = rb_find_leftmost((tree)); (node) != LEAF; \
			(node) = rb_find_succ(node))

#define rb_for_each_rev(tree, node) \
	for ((node) = rb_find_rightmost((tree)); (node) != LEAF; \
			(node) = rb_find_pred(node))

/*
 * Iterators over the elements of a red-black tree that is safe if the elements
 * are concurrently modified (but not if other elements in the tree are
 * removed).
 */
#define rb_for_each_mod(tree, node) \
	do { \
		(node) = rb_find_leftmost((tree)); \
		for (rb_node_t* __rb_succ_ ## node = ((node) == LEAF ? LEAF : \
					rb_find_succ(node)); \
				(node) != LEAF; \
				(node) = __rb_succ_ ## node, \
				__rb_succ_ ## node = (__rb_succ_ ## node == LEAF ? LEAF : \
					rb_find_succ(__rb_succ_ ## node)))

#define rb_for_each_mod_fin() \
	} while(0)

#define rb_for_each_mod_rev(tree, node) \
	do { \
		(node) = rb_find_rightmost((tree)); \
		for (rb_node_t* __rb_pred_ ## node = ((node) == LEAF ? LEAF : \
					rb_find_pred(node)); \
				(node) != LEAF; \
				(node) = __rb_pred_ ## node, \
				__rb_pred_ ## node = (__rb_pred_ ## node == LEAF ? LEAF : \
					rb_find_pred(__rb_succ_ ## node)))

#define rb_for_each_mod_rev_fin() \
	} while(0)


void rb_print(struct __int_rb_tree *tree);


#define RB_DEFINE_GET_VAL(name, s_type) \
static s_type rb_ ## name ## _val(rb_node_t* n) { \
	return *(s_type*) (((uint64_t) n) + offsetof(rb_int_node_t, val)); \
}

#define RB_DEFINE_SET_VAL(name, s_type) \
static void rb_ ## name ## _set_val(rb_node_t* n, s_type v) { \
	*(s_type*) (((uint64_t) n) + offsetof(rb_int_node_t, val)) = v; \
}

/*
 * macro for defining the find function for rb nodes, which essentially
 * determines the way in which the red-black tree sorts its elements.
 *
 * Find will return the leftmost node of tree which could be a parent of node
 * without violating the BST property of the tree
 */
#define RB_DEFINE_SCALAR_FIND_LOC(name, s_type) \
static rb_node_t* rb_find_ ## name ## _loc(struct __int_rb_tree *tree, s_type val) { \
	rb_node_t *prev_node = LEAF; \
	rb_node_t *root = rb_get_root(tree); \
	while (root != LEAF) { \
		prev_node = root; \
		s_type root_val = rb_ ## name ## _val(root); \
		root = (root_val < val ? \
				rb_get_right(root) : rb_get_left(root)); \
	} \
	return prev_node; \
}

/*
 * returns the largest node which is less than or equal to the supplied node
 */
#define RB_DEFINE_SCALAR_UPPER_BOUND(name, s_type) \
static rb_node_t* rb_upper_bound_ ## name(struct __int_rb_tree *tree, s_type val) { \
	rb_node_t * prev_less_node = LEAF; \
	rb_node_t * root = rb_get_root(tree); \
	while (root != LEAF) { \
		s_type root_val = rb_ ## name ## _val(root); \
		if (root_val <= val) { \
			prev_less_node = root; \
			root = rb_get_right(root); \
		} \
		else { \
			root = rb_get_left(root); \
		} \
	} \
	return prev_less_node; \
}

/*
 * returns the smallest node which is greater than or equal to the supplied node
 */
#define RB_DEFINE_SCALAR_LOWER_BOUND(name, s_type) \
static rb_node_t* rb_lower_bound_ ## name(struct __int_rb_tree *tree, s_type val) { \
	rb_node_t * prev_ge_node = LEAF; \
	rb_node_t * root = rb_get_root(tree); \
	while (root != LEAF) { \
		s_type root_val = rb_ ## name ## _val(root); \
		if (root_val < val) { \
			root = rb_get_right(root); \
		} \
		else { \
			prev_ge_node = root; \
			root = rb_get_left(root); \
		} \
	} \
	return prev_ge_node; \
}



#define RB_DEFINE_SCALAR_FIND_HELPER(name, s_type) \
static rb_node_t* _rb_contains_ ## name ## _helper(rb_node_t *root, s_type val) { \
	while (root != LEAF) { \
		s_type root_val = rb_ ## name ## _val(root); \
		if (root_val == val) return root; \
		root = root_val < val ? rb_get_right(root) : rb_get_left(root); \
	} \
	return NULL; \
}


#define RB_DEFINE_SCALAR_FIND(name, s_type) \
static rb_node_t* rb_find_ ## name(struct __int_rb_tree *tree, s_type val) { \
	rb_node_t *root; \
	root = rb_get_root(tree); \
	return _rb_contains_ ## name ## _helper(root, val); \
}

#define RB_DEFINE_SCALAR_CONTAINS(name, s_type) \
static int rb_contains_ ## name(struct __int_rb_tree *tree, s_type val) { \
	return rb_find_ ## name(tree, val) != NULL; \
}


#define RB_DEFINE_SCALAR_INSERT(name, s_type) \
static rb_node_t* rb_insert_ ## name(struct __int_rb_tree *tree, s_type val) { \
	rb_node_t* node = (rb_node_t*) malloc(sizeof(rb_int_node_t) + sizeof(s_type)); \
	rb_ ## name ## _set_val(node, val); \
	rb_node_t *p; \
	memset(node, 0, sizeof(rb_node_t)); \
	p = rb_find_ ## name ## _loc(tree, val); \
	if (p != LEAF) { \
		s_type p_val = rb_ ## name ## _val(p); \
		if (p_val < val) { \
			rb_set_right(p, node); \
		} else { \
			rb_set_left(p, node); \
		} \
	} \
	if (_rb_insert_helper(tree, node, p)) { \
		return node; \
	} \
	return NULL; \
}


#define RB_DEFINE_SCALAR_REMOVE(name, s_type) \
static void rb_remove_ ## name(struct __int_rb_tree *tree, s_type val) { \
	rb_node_t* node = rb_find_ ## name(tree, val); \
	RB_ASSERT(node != NULL, tree); \
	_rb_remove_helper(tree, node); \
	free(node); \
}

#define RB_DEFINE_SCALAR_BST_CHECK(name, s_type) \
static void _bst_check_ ## name(rb_node_t *node) { \
	s_type node_val = rb_ ## name ## _val(node); \
	if (rb_get_left(node) != LEAF) { \
		s_type left_val = rb_ ## name ## _val(rb_get_left(node)); \
		dbg_assert(left_val <= node_val); \
		_bst_check_ ## name(rb_get_left(node)); \
	} \
	if (rb_get_right(node) != LEAF) { \
		s_type right_val = rb_ ## name ## _val(rb_get_right(node)); \
		dbg_assert(node_val <= right_val); \
		_bst_check_ ## name(rb_get_right(node)); \
	} \
}


#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic push

#define RB_DEFINE_SCALAR_TYPE(name, s_type) \
	RB_DEFINE_GET_VAL(name, s_type) \
	RB_DEFINE_SET_VAL(name, s_type) \
	RB_DEFINE_SCALAR_FIND_LOC(name, s_type) \
	RB_DEFINE_SCALAR_UPPER_BOUND(name, s_type) \
	RB_DEFINE_SCALAR_LOWER_BOUND(name, s_type) \
	RB_DEFINE_SCALAR_FIND_HELPER(name, s_type) \
	RB_DEFINE_SCALAR_FIND(name, s_type) \
	RB_DEFINE_SCALAR_CONTAINS(name, s_type) \
	RB_DEFINE_SCALAR_INSERT(name, s_type) \
	RB_DEFINE_SCALAR_REMOVE(name, s_type) \
	RB_DEFINE_SCALAR_BST_CHECK(name, s_type) \
	RB_DEFINE_VALIDATE(name)

#pragma GCC diagnostic pop


#ifdef __cplusplus
// terminate the extern "C"
}


template<typename T>
class rb_tree {
private:

	struct __int_rb_tree _tree;

public:

	rb_tree();
	~rb_tree();

	// TODO implement this when I need it

};


#else

typedef struct __int_rb_tree rb_tree_t;

#endif /* __cplusplus */


#endif /* _RB_TREE_H */
