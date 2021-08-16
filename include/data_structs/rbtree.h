#ifndef _RB_TREE_H_
#define _RB_TREE_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>



#define RB_ASSERT(expr, tree) \
	if (__builtin_expect(!(expr), 0)) { \
		printf("tree %p:\n", (tree)); \
		rb_print(tree); \
	} \
	assert(expr)


// declare red-black nodes early for usage in this struct
typedef struct rb_node {
	struct rb_node *left;
	struct rb_node *right;
	struct rb_node *parent;
} rb_node_t;



struct __int_rb_tree {
	struct rb_node *root;
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
#define RB_DEFINE_FIND_LOC(name, less_fn) \
static rb_node_t* rb_find_ ## name ## _loc(struct __int_rb_tree *tree, rb_node_t *node) { \
	rb_node_t *prev_node = LEAF; \
	rb_node_t *root = rb_get_root(tree); \
	while (root != LEAF) { \
		prev_node = root; \
		root = (less_fn(root, node) ? \
				rb_get_right(root) : rb_get_left(root)); \
	} \
	return prev_node; \
}


/*
 * returns the largest node which is less than or equal to the supplied node
 */
#define RB_DEFINE_UPPER_BOUND(name, less_fn) \
static rb_node_t* rb_upper_bound_ ## name(struct __int_rb_tree *tree, rb_node_t *node) { \
	rb_node_t * prev_less_node = LEAF; \
	rb_node_t * root = rb_get_root(tree); \
	while (root != LEAF) { \
		if (!less_fn(node, root)) { \
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
#define RB_DEFINE_LOWER_BOUND(name, less_fn) \
static rb_node_t* rb_lower_bound_ ## name(struct __int_rb_tree *tree, rb_node_t *node) { \
	rb_node_t * prev_ge_node = LEAF; \
	rb_node_t * root = rb_get_root(tree); \
	while (root != LEAF) { \
		if (less_fn(root, node)) { \
			root = rb_get_right(root); \
		} \
		else { \
			prev_ge_node = root; \
			root = rb_get_left(root); \
		} \
	} \
	return prev_ge_node; \
}



#define RB_DEFINE_CONTAINS_HELPER(name, less_fn) \
static int _rb_contains_ ## name ## _helper(rb_node_t *root, rb_node_t *node) { \
	while (root != LEAF) { \
		if (root == node) return 1; \
		root = less_fn(root, node) ? rb_get_right(root) : rb_get_left(root); \
	} \
	return 0; \
}


#define RB_DEFINE_CONTAINS(name, less_fn) \
static int rb_contains_ ## name(struct __int_rb_tree *tree, rb_node_t *node) { \
	rb_node_t *root; \
	root = rb_get_root(tree); \
	return _rb_contains_ ## name ## _helper(root, node); \
}



int _rb_insert_helper(struct __int_rb_tree *tree, rb_node_t *node, rb_node_t* p);

#define RB_DEFINE_INSERT(name, less_fn) \
static int rb_insert_ ## name(struct __int_rb_tree *tree, rb_node_t* node) { \
	rb_node_t *p; \
	memset(node, 0, sizeof(rb_node_t)); \
	p = rb_find_ ## name ## _loc(tree, node); \
	if (p != LEAF) { \
		if (less_fn(p, node)) { \
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


#define RB_DEFINE_BST_CHECK(name, less_fn) \
static void _bst_check_ ## name(rb_node_t *node) { \
	if (rb_get_left(node) != LEAF) { \
		assert(!less_fn(node, rb_get_left(node))); \
		_bst_check_ ## name(rb_get_left(node)); \
	} \
	if (rb_get_right(node) != LEAF) { \
		assert(!less_fn(rb_get_right(node), node)); \
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



#define RB_DEFINE_TYPE(name, less_fn) \
	RB_DEFINE_FIND_LOC(name, less_fn) \
	RB_DEFINE_UPPER_BOUND(name, less_fn) \
	RB_DEFINE_LOWER_BOUND(name, less_fn) \
	RB_DEFINE_CONTAINS_HELPER(name, less_fn) \
	RB_DEFINE_CONTAINS(name, less_fn) \
	RB_DEFINE_INSERT(name, less_fn) \
	RB_DEFINE_REMOVE(name) \
	RB_DEFINE_BST_CHECK(name, less_fn) \
	RB_DEFINE_VALIDATE(name)

static int rb_is_empty(struct __int_rb_tree *tree) {
	return rb_get_root(tree) == LEAF;
}



rb_node_t* rb_find_leftmost(struct __int_rb_tree *tree);
rb_node_t* rb_find_rightmost(struct __int_rb_tree *tree);

rb_node_t* rb_find_succ(rb_node_t *node);
rb_node_t* rb_find_pred(rb_node_t *node);


#define rb_for_each(tree, node) \
	for ((node) = rb_find_leftmost((tree)); (node) != LEAF; \
			(node) = rb_find_succ(node))



void rb_print(struct __int_rb_tree *tree);


/*
 * ptr rb trees: sorted by location of nodes in memory
 */

static int ptr_less(rb_node_t* a, rb_node_t* b) {
	return ((uint64_t) a) < ((uint64_t) b);
}

RB_DEFINE_TYPE(ptr, ptr_less)


/*
 * macro for defining the find function for rb nodes, which essentially
 * determines the way in which the red-black tree sorts its elements.
 *
 * Find will return the leftmost node of tree which could be a parent of node
 * without violating the BST property of the tree
 */
#define RB_DEFINE_SCALAR_FIND_LOC(name, s_type, less_fn) \
static rb_node_t* rb_find_ ## name ## _loc(struct __int_rb_tree *tree, s_type val) { \
	rb_node_t *prev_node = LEAF; \
	rb_node_t *root = rb_get_root(tree); \
	while (root != LEAF) { \
		prev_node = root; \
		root = (less_fn(root, val_to_node(&val)) ? \
				rb_get_right(root) : rb_get_left(root)); \
	} \
	return prev_node; \
}

/*
 * macro for defining the find function for rb nodes, which returns a pointer
 * to the node containing the queried value
 */
#define RB_DEFINE_SCALAR_FIND(name, s_type, less_fn) \
static rb_node_t* rb_find_ ## name(struct __int_rb_tree *tree, s_type val) { \
	rb_node_t *root = rb_get_root(tree); \
	while (root != LEAF) { \
		s_type root_val = *(s_type*) (((uint64_t) root) + \
				offsetof(rb_int_node_t, val)); \
		if (root_val == val) { \
			return root; \
		} \
		root = root_val < val ? \
				rb_get_right(root) : rb_get_left(root); \
	} \
	return NULL; \
}

/*
 * returns the largest node which is less than or equal to the supplied node
 */
#define RB_DEFINE_SCALAR_UPPER_BOUND(name, s_type, less_fn) \
static rb_node_t* rb_upper_bound_ ## name(struct __int_rb_tree *tree, s_type val) { \
	rb_node_t * prev_less_node = LEAF; \
	rb_node_t * root = rb_get_root(tree); \
	while (root != LEAF) { \
		if (!less_fn(val_to_node(&val), root)) { \
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
#define RB_DEFINE_SCALAR_LOWER_BOUND(name, s_type, less_fn) \
static rb_node_t* rb_lower_bound_ ## name(struct __int_rb_tree *tree, s_type val) { \
	rb_node_t * prev_ge_node = LEAF; \
	rb_node_t * root = rb_get_root(tree); \
	while (root != LEAF) { \
		if (less_fn(root, val_to_node(&val))) { \
			root = rb_get_right(root); \
		} \
		else { \
			prev_ge_node = root; \
			root = rb_get_left(root); \
		} \
	} \
	return prev_ge_node; \
}



#define RB_DEFINE_SCALAR_CONTAINS_HELPER(name, s_type, less_fn) \
static rb_node_t* _rb_contains_ ## name ## _helper(rb_node_t *root, s_type val) { \
	while (root != LEAF) { \
		s_type root_val = *(s_type*) (((uint64_t) root) + \
				offsetof(rb_int_node_t, val)); \
		if (root_val == val) return root; \
		root = root_val < val ? rb_get_right(root) : rb_get_left(root); \
	} \
	return NULL; \
}


#define RB_DEFINE_SCALAR_CONTAINS(name, s_type, less_fn) \
static rb_node_t* rb_contains_ ## name(struct __int_rb_tree *tree, s_type val) { \
	rb_node_t *root; \
	root = rb_get_root(tree); \
	return _rb_contains_ ## name ## _helper(root, val); \
}


#define RB_DEFINE_SCALAR_INSERT(name, s_type, less_fn) \
static rb_node_t* rb_insert_ ## name(struct __int_rb_tree *tree, s_type val) { \
	rb_node_t* node = (rb_node_t*) malloc(sizeof(rb_int_node_t) + sizeof(s_type)); \
	*(s_type*) (((uint64_t) node) + offsetof(rb_int_node_t, val)) = val; \
	rb_node_t *p; \
	memset(node, 0, sizeof(rb_node_t)); \
	p = rb_find_ ## name ## _loc(tree, val); \
	if (p != LEAF) { \
		if (less_fn(p, val_to_node(&val))) { \
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
	rb_node_t* node = rb_contains_ ## name(tree, val); \
	RB_ASSERT(node != NULL, tree); \
	_rb_remove_helper(tree, node); \
}



#define RB_DEFINE_SCALAR_TYPE(name, s_type, less_fn) \
	RB_DEFINE_SCALAR_FIND_LOC(name, s_type, less_fn) \
	RB_DEFINE_SCALAR_FIND(name, s_type, less_fn) \
	RB_DEFINE_SCALAR_UPPER_BOUND(name, s_type, less_fn) \
	RB_DEFINE_SCALAR_LOWER_BOUND(name, s_type, less_fn) \
	RB_DEFINE_SCALAR_CONTAINS_HELPER(name, s_type, less_fn) \
	RB_DEFINE_SCALAR_CONTAINS(name, s_type, less_fn) \
	RB_DEFINE_SCALAR_INSERT(name, s_type, less_fn) \
	RB_DEFINE_SCALAR_REMOVE(name, s_type) \
	RB_DEFINE_BST_CHECK(name, less_fn) \
	RB_DEFINE_VALIDATE(name)


/*
 * int rb trees: sorted by an int value stored immediately after the node in memory
 */

typedef struct rb_int_node {
	rb_node_t base;
	int64_t val;
} rb_int_node_t;

typedef struct rb_uint_node {
	rb_node_t base;
	uint64_t val;
} rb_uint_node_t;

static rb_node_t* val_to_node(void* val) {
	return (rb_node_t*) (((uint64_t) val) - offsetof(rb_int_node_t, val));
}

static int int_less(rb_node_t* a, rb_node_t* b) {
	return ((rb_int_node_t*) a)->val < ((rb_int_node_t*) b)->val;
}

static int uint_less(rb_node_t* a, rb_node_t* b) {
	return ((rb_uint_node_t*) a)->val < ((rb_uint_node_t*) b)->val;
}

RB_DEFINE_SCALAR_TYPE(int, int64_t, int_less);
RB_DEFINE_SCALAR_TYPE(uint, uint64_t, uint_less);


/*#ifdef __cplusplus


template<typename T>
class rb_tree {
private:

	struct __int_rb_tree _tree;

public:

	rb_tree();
	~rb_tree();

	// TODO implement this when I need it

};


#else*/

typedef struct __int_rb_tree rb_tree_t;

//#endif /* __cplusplus */



#endif /* _RB_TREE_H */
