#ifndef _INDEXED_RB_TREE_H_
#define _INDEXED_RB_TREE_H_

#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>



#define IRB_ASSERT(expr, tree) \
    if (__builtin_expect(!(expr), 0)) { \
        printf("tree %p:\n", (tree));   \
        irb_print(tree);                 \
    }                                   \
    assert(expr)

#ifdef DEBUG
#define IRB_DBG_ASSERT(...) IRB_ASSERT(__VA_ARGS__)
#else
#define IRB_DBG_ASSERT(...)
#endif /* DEBUG */


/*
 * same as the normal red-black tree, with the ability to find the index of
 * a node in log(n) time, with no affect on the runtime of any other ops
 */


typedef ssize_t irb_idx_t;


// declare red-black nodes early for usage in this struct
typedef struct irb_node {
    struct irb_node *left;
    struct irb_node *right;
    struct irb_node *parent;
    // offset of right subtree from 0 (i.e. size of the left subtree + 1)
    irb_idx_t r_off;
} irb_node;



struct __int_irb_tree {
    struct irb_node *root;
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

#define ILEAF ((irb_node*) BLACK)



static irb_node* irb_get_root(struct __int_irb_tree *t) {
    return t->root;
}

static void irb_set_parent(irb_node *n, irb_node *p) {
    n->parent = (irb_node*) (
            (((unsigned long) n->parent) & PTR_MASK) | ((unsigned long) p));
}

static irb_node* irb_get_left(irb_node *n) {
    return (irb_node*) (((unsigned long) n->left) & ~PTR_MASK);
}

static void irb_set_left(irb_node *n, irb_node *l) {
    n->left = (irb_node*) ((((unsigned long) n->left) & PTR_MASK)
            | (unsigned long) l);
    if (l != ILEAF) {
        irb_set_parent(l, n);
    }
}

static irb_node* irb_get_right(irb_node *n) {
    return n->right;
}

static void irb_set_right(irb_node *n, irb_node *r) {
    n->right = r;
    if (r != ILEAF) {
        irb_set_parent(r, n);
    }
}


/*
 * Initialize the red black tree. Called only once during the initialization
 * of the state struct.
 *
 */
static void irb_init(struct __int_irb_tree* tree) {
    tree->root = ILEAF;
}


/*
 * macro for defining the find function for rb nodes, which essentially
 * determines the way in which the red-black tree sorts its elements.
 *
 * Find will return the leftmost node of tree which could be a parent of node
 * without violating the BST property of the tree
 */
#define IRB_DEFINE_FIND_LOC(name, less_fn) \
static irb_node* irb_find_ ## name ## _loc(struct __int_irb_tree *tree, irb_node *node) { \
    irb_node *prev_node = ILEAF;                                  \
    irb_node *root = irb_get_root(tree);                          \
    while (root != ILEAF) {                                      \
        prev_node = root;                                       \
        root = (less_fn(root, node) ?                           \
                irb_get_right(root) : irb_get_left(root));        \
    }                                                           \
    return prev_node;                                           \
}

/*
 * same as rb_find, but also adjusts r_off on the way down, anticipating that
 * node will be inserted
 */
#define IRB_DEFINE_FIND_INC(name, less_fn) \
static irb_node* __irb_find_ ## name ## _inc(struct __int_irb_tree *tree, irb_node *node) { \
    irb_node *prev_node = ILEAF;                                \
    irb_node *root = irb_get_root(tree);                        \
    while (root != ILEAF) {                                     \
        prev_node = root;                                       \
        if (less_fn(root, node)) {                              \
            root = irb_get_right(root);                         \
        }                                                       \
        else {                                                  \
            root->r_off++;                                      \
            root = irb_get_left(root);                          \
        }                                                       \
    }                                                           \
    return prev_node;                                           \
}


/*
 * returns the largest node which is less than or equal to the supplied node
 */
#define IRB_DEFINE_UPPER_BOUND(name, less_fn) \
static irb_node* irb_upper_bound_ ## name(struct __int_irb_tree *tree, irb_node *node) { \
    irb_node * prev_less_node = ILEAF;                            \
    irb_node * root = irb_get_root(tree);                         \
    while (root != ILEAF) {                                      \
        if (!less_fn(node, root)) {                             \
            prev_less_node = root;                              \
            root = irb_get_right(root);                          \
        }                                                       \
        else {                                                  \
            root = irb_get_left(root);                           \
        }                                                       \
    }                                                           \
    return prev_less_node;                                      \
}

/*
 * returns the smallest node which is greater than or equal to the supplied node
 */
#define IRB_DEFINE_LOWER_BOUND(name, less_fn) \
static irb_node* irb_lower_bound_ ## name(struct __int_irb_tree *tree, irb_node *node) { \
    irb_node * prev_ge_node = ILEAF;                              \
    irb_node * root = irb_get_root(tree);                         \
    while (root != ILEAF) {                                      \
        if (less_fn(root, node)) {                              \
            root = irb_get_right(root);                          \
        }                                                       \
        else {                                                  \
            prev_ge_node = root;                               \
            root = irb_get_left(root);                           \
        }                                                       \
    }                                                           \
    return prev_ge_node;                                        \
}



#define IRB_DEFINE_CONTAINS_HELPER(name, less_fn) \
static int _irb_contains_ ## name ## _helper(irb_node *root, irb_node *node) {     \
    while (root != ILEAF) {                                                      \
        if (root == node) return 1;                                             \
        if (!less_fn(root, node) && !less_fn(node, root)) {                     \
            return _irb_contains_ ## name ## _helper(irb_get_left(root), node) || \
                _irb_contains_ ## name ## _helper(irb_get_right(root), node);     \
        }                                                                       \
        root = less_fn(root, node) ? irb_get_right(root) : irb_get_left(root);    \
    }                                                                           \
    return 0;                                                                   \
}


#define IRB_DEFINE_CONTAINS(name, less_fn) \
static int irb_contains_ ## name(struct __int_irb_tree *tree, irb_node *node) { \
    irb_node *root;                                              \
    root = irb_get_root(tree);                                   \
    return _irb_contains_ ## name ## _helper(root, node);        \
}



int _irb_insert_helper(struct __int_irb_tree *tree, irb_node *node, irb_node* p);

#define IRB_DEFINE_INSERT(name, less_fn) \
static int irb_insert_ ## name(struct __int_irb_tree *tree, irb_node* node) {   \
    irb_node *p;                                                 \
    memset(node, 0, sizeof(irb_node));                           \
    p = __irb_find_ ## name ## _inc(tree, node);                 \
    if (p != ILEAF) {                                            \
        if (less_fn(p, node)) {                                  \
            irb_set_right(p, node);                              \
        } else {                                                 \
            irb_set_left(p, node);                               \
        }                                                        \
    }                                                            \
    return _irb_insert_helper(tree, node, p);                    \
}


void _irb_remove_helper(struct __int_irb_tree *tree, irb_node *node);

#define IRB_DEFINE_REMOVE(name) \
static void irb_remove_ ## name(struct __int_irb_tree *tree, irb_node *node) {  \
    IRB_DBG_ASSERT(irb_contains_ ## name(tree, node), tree);     \
    _irb_remove_helper(tree, node);                              \
}


/*
 * returns the index of node, which must be in a valid rb tree
 */
irb_idx_t irb_get_idx_unsafe(struct irb_node *node);

/*
 * returns the index of node, if in the tree, otherwise the index node would
 * have were it inserted in the tree
 */
#define IRB_DEFINE_GET_IDX(name, less_fn) \
static irb_idx_t irb_get_idx_ ## name(struct __int_irb_tree *tree, irb_node * n) { \
    irb_node *root = irb_get_root(tree);                    \
    irb_idx_t idx = 0;                                      \
    while (root != ILEAF) {                                 \
        if (less_fn(root, n)) {                             \
            idx += root->r_off;                             \
            root = irb_get_right(root);                     \
        }                                                   \
        else {                                              \
            root = irb_get_left(root);                      \
        }                                                   \
    }                                                       \
    return idx;                                             \
}

/*
 * returns the index that node would have were it inserted in the tree,
 * assuming it will be placed after all copies of it which are already in the
 * tree
 */
#define IRB_DEFINE_GET_INS_IDX(name, less_fn) \
static irb_idx_t irb_get_ins_idx_ ## name(struct __int_irb_tree *tree, irb_node * n) { \
    irb_node *root = irb_get_root(tree);                    \
    irb_idx_t idx = 0;                                      \
    while (root != ILEAF) {                                 \
        if (less_fn(n, root)) {                             \
            root = irb_get_left(root);                      \
        }                                                   \
        else {                                              \
            idx += root->r_off;                             \
            root = irb_get_right(root);                     \
        }                                                   \
    }                                                       \
    return idx;                                             \
}



/*
 * does generic consistency checks (all besides BST property, which must
 * be generated with macros)
 */
void _irb_validate_helper(struct __int_irb_tree *tree);


#define IRB_DEFINE_BST_CHECK(name, less_fn) \
static void _bst_check_ ## name(irb_node *node) {             \
    if (irb_get_left(node) != ILEAF) {                        \
        assert(!less_fn(node, irb_get_left(node)));           \
        _bst_check_ ## name(irb_get_left(node));              \
    }                                                         \
    if (irb_get_right(node) != ILEAF) {                       \
        assert(!less_fn(irb_get_right(node), node));          \
        _bst_check_ ## name(irb_get_right(node));             \
    }                                                         \
}


#define IRB_DEFINE_VALIDATE(name) \
static void irb_validate_ ## name(struct __int_irb_tree *tree) {   \
    irb_node *root = irb_get_root(tree);              \
    _irb_validate_helper(tree);                       \
    if(root != ILEAF) {                               \
        _bst_check_ ## name(root);                    \
    }                                                 \
}



#define IRB_DEFINE_TYPE(name, less_fn) \
    IRB_DEFINE_FIND_LOC(name, less_fn) \
    IRB_DEFINE_FIND_INC(name, less_fn) \
    IRB_DEFINE_UPPER_BOUND(name, less_fn) \
    IRB_DEFINE_LOWER_BOUND(name, less_fn) \
    IRB_DEFINE_CONTAINS_HELPER(name, less_fn) \
    IRB_DEFINE_CONTAINS(name, less_fn) \
    IRB_DEFINE_INSERT(name, less_fn) \
    IRB_DEFINE_REMOVE(name)  \
    IRB_DEFINE_BST_CHECK(name, less_fn) \
    IRB_DEFINE_GET_IDX(name, less_fn) \
    IRB_DEFINE_GET_INS_IDX(name, less_fn) \
    IRB_DEFINE_VALIDATE(name)



static int irb_is_empty(struct __int_irb_tree *tree) {
    return irb_get_root(tree) == ILEAF;
}



irb_node* irb_find_leftmost(struct __int_irb_tree *tree);

irb_node* irb_find_succ(irb_node *node);
irb_node* irb_find_pred(irb_node *node);


#define irb_for_each(tree, node) \
    for ((node) = irb_find_leftmost((tree)); (node) != ILEAF; \
            (node) = irb_find_succ(node))



void irb_print(struct __int_irb_tree *tree);



static int ptr_less(irb_node* a, irb_node* b) {
    return ((uint64_t) a) < ((uint64_t) b);
}

IRB_DEFINE_TYPE(ptr, ptr_less)



/*#ifdef __cplusplus


template<typename T>
class irb_tree {
private:

    struct __int_irb_tree _tree;

public:

    irb_tree();
    ~irb_tree();

    // TODO implement this when I need it

};


#else*/

typedef struct __int_irb_tree irb_tree;

//#endif /* __cplusplus */




#endif /* _INDEXED_RB_TREE_H */
