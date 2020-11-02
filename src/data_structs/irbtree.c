
#include <data_structs/irbtree.h>


#define set_parent irb_set_parent
#define get_left irb_get_left
#define set_left irb_set_left
#define get_right irb_get_right
#define set_right irb_set_right
#define get_root irb_get_root

#define color_proxy parent

static int is_red(irb_node *n) {
    return (n != ILEAF) && (((unsigned long) n->color_proxy) & COLOR_MASK) == RED;
}
static int is_black(irb_node *n) {
    return (n == ILEAF) || (((unsigned long) n->color_proxy) & COLOR_MASK) == BLACK;
}

static void set_red(irb_node *n) {
    n->color_proxy = (irb_node*) (((unsigned long) n->color_proxy) | RED);
}
static void set_black(irb_node *n) {
    n->color_proxy = (irb_node*) (((unsigned long) n->color_proxy) & ~RED);
}

static void copy_color(irb_node *dst, irb_node *src) {
    dst->color_proxy = (irb_node*) ((((unsigned long) dst->color_proxy) & ~COLOR_MASK) |
                       (((unsigned long) src->color_proxy) & COLOR_MASK));
}



/*
 * red-black tree op helper methods
 */

static int is_root(irb_node *n) {
    return (((unsigned long) n->left) & ROOT) == ROOT;
}

static void mark_as_root(irb_node *n) {
    n->left = (irb_node*) (((unsigned long) n->left) | ROOT);
}

static void set_root(struct __int_irb_tree *t, irb_node* node) {
    mark_as_root(node);
    t->root = node;
    node->parent = (irb_node*) t;
}

static irb_node* get_parent(irb_node *n) {
    return (irb_node*) (((unsigned long) n->parent) & ~PTR_MASK);
}

// sets left child to node known not to be a leaf
static void set_left_noleaf(irb_node *n, irb_node *l) {
    n->left = (irb_node*) ((((unsigned long) n->left) & PTR_MASK)
            | (unsigned long) l);
    set_parent(l, n);
}

// sets right child to node known not to be a leaf
static void set_right_noleaf(irb_node *n, irb_node *r) {
    n->right = r;
    set_parent(r, n);
}

/*
 * transfers root mark from old_root to new_root, which will mark the ROOT
 * bit of the left child of new_root and unmark old_root as the root if
 * old_root was the root, otherwise it will do nothing
 */
static void transfer_root_mark(irb_node *new_root, irb_node *old_root) {
    size_t root_mark = ((size_t) old_root->left) & ROOT;
    old_root->left = (irb_node*) (((unsigned long) old_root->left) ^ root_mark);
    new_root->left = (irb_node*) (((unsigned long) new_root->left) | root_mark);
}

// sets n to be the new child of the parent of par (gp)
static void set_parent_pointer(irb_node *n, irb_node *par) {
    irb_node *gp = get_parent(par);
    transfer_root_mark(n, par);
    if (get_left(gp) == par) {
        set_left(gp, n);
    }
    else {
        set_right(gp, n);
    }
}


/*
 *
 *           p
 *        /    \
 *      l       c
 *    /   \
 *  a      b
 *
 * to
 *       l
 *    /    \
 *  a       p
 *        /   \
 *       b     c
 *
 */
// right rotate about p, with l = left(p)
static void irb_rotate_right(irb_node *p, irb_node *l) {
    set_parent_pointer(l, p);
    set_left(p, get_right(l));
    set_right_noleaf(l, p);

    p->r_off -= l->r_off;
}


/*
 *
 *       p
 *    /    \
 *  a       r
 *        /   \
 *       b     c
 *
 * to
 *           r
 *        /    \
 *      p       c
 *    /   \
 *  a      b
 *
 */
// left rotate about p, with r = right(p)
static void irb_rotate_left(irb_node *p, irb_node *r) {
    set_parent_pointer(r, p);
    set_right(p, get_left(r));
    set_left_noleaf(r, p);

    r->r_off += p->r_off;
}


/*
 *
 *           p
 *        /    \
 *      l        d
 *    /   \
 *  a     lr
 *       /   \
 *      b     c
 *
 * to
 *            lr
 *        /       \
 *      l           p
 *    /  \        /   \
 *  a     b     c      d
 *
 */
// left-right rotate about p, with
// l = left(p), lr = right(l)
static void irb_rotate_left_right(irb_node *p, irb_node *l, irb_node *lr) {
    set_parent_pointer(lr, p);

    set_right(l, get_left(lr));
    set_left(p, get_right(lr));
    set_left_noleaf(lr, l);
    set_right_noleaf(lr, p);

    p->r_off -= l->r_off + lr->r_off;
    lr->r_off += l->r_off;
}


/*
 *
 *       p
 *    /    \
 *  a        r
 *         /   \
 *       rl     d
 *     /   \
 *    b     c
 *
 * to
 *            rl
 *        /       \
 *      p           r
 *    /  \        /   \
 *  a     b     c      d
 *
 */
// right-left rotate about p, with
// r = right(p), rl = left(r)
static void irb_rotate_right_left(irb_node *p, irb_node *r, irb_node *rl) {
    set_parent_pointer(rl, p);

    set_left(r, get_right(rl));
    set_right(p, get_left(rl));
    set_right_noleaf(rl, r);
    set_left_noleaf(rl, p);

    r->r_off -= rl->r_off;
    rl->r_off += p->r_off;
}




/*
 * -------------------------------- irb_insert --------------------------------
 */

static void irb_insert_fix(irb_node *node) {
    // parent, grandparent, and uncle (parent's siblin)
    irb_node *p, *gp, *u;
    while (!is_root(node) && is_red(p = get_parent(node))) {
        if (p == get_left(gp = get_parent(p))) {
            u = get_right(gp);
            if (is_black(u)) {
                // rotate
                if (get_right(p) == node) {
                    irb_rotate_left_right(gp, p, node);
                    set_red(gp);
                    set_black(node);
                    node = p; // so the loop terminates
                }
                else {
                    irb_rotate_right(gp, p);
                    set_red(gp);
                    set_black(p);
                }
            }
            else {
                // recolor
                set_red(gp);
                set_black(p);
                set_black(u);
                // we still haven't fixed the imbalance
                // in black height, so propogate upwards
                node = gp;
            }
        }
        else {
            u = get_left(gp);
            if (is_black(u)) {
                // rotate
                if (get_left(p) == node) {
                    irb_rotate_right_left(gp, p, node);
                    set_red(gp);
                    set_black(node);
                    node = p; // so the loop terminates
                }
                else {
                    irb_rotate_left(gp, p);
                    set_red(gp);
                    set_black(p);
                }
            }
            else {
                // recolor
                set_red(gp);
                set_black(p);
                set_black(u);

                node = gp;
            }
        }
    }
    if (is_root(node)) {
        set_black(node);
    }
}

/*
 * Inserts an already mallocced irb_node into the tree.
 */
int _irb_insert_helper(struct __int_irb_tree *tree, irb_node *node, irb_node *p) {
    set_left(node, ILEAF);
    set_right(node, ILEAF);
    node->r_off = 1;

    if (p != ILEAF) {
        set_red(node);
        irb_insert_fix(node);
    }
    else {
        set_root(tree, node);
        set_black(node);
    }

    return 1; // success
}



/*
 * -------------------------------- irb_remove --------------------------------
 */


static void irb_remove_fix(irb_node *node) {
    // parent, sibling (of p), and a placeholder for rotations
    irb_node *p, *s, *slr;
    
    while (!is_root(node) && is_black(node)) {
        p = get_parent(node);
        if (node == get_left(p)) {
            s = get_right(p);
            if (is_red(s)) {
                irb_rotate_left(p, s);
                set_red(p);
                set_black(s);

                s = get_right(p);
            }
            // now s is guarenteed to be black
            if (is_black(get_left(s)) && is_black(get_right(s))) {
                set_red(s);
                // if p is already red, loop terminates and p is set
                // to black. Else, p was black and is now double black,
                // so we need to propogate the fix up through with p
                node = p;
            } else {
                if (is_red(get_left(s))) {
                    // right-left rotate about p, making
                    // left(s) (slr) the new root
                    slr = get_left(s);
                    irb_rotate_right_left(p, s, slr);

                    copy_color(slr, p);
                    set_black(p);
                    set_black(s);

                    break;
                    //node = get_root(m); // so the loop terminates
                } else {
                    // left rotate about p
                    irb_rotate_left(p, s);

                    copy_color(s, p);
                    set_black(p);
                    set_black(get_right(s));

                    break;
                    //node = get_root(m);
                }
            }
        } else {
            s = get_left(p);
            if (is_red(s)) {
                // right rotate about p
                irb_rotate_right(p, s);
                set_red(p);
                set_black(s);

                s = get_left(p);
            }
            // now s is guarenteed to be black
            if (is_black(get_right(s)) && is_black(get_left(s))) {
                set_red(s);
                node = p;
            } else {
                if (is_red(get_right(s))) {
                    // left-right rotate about p, making
                    // right(s) (slr) the new root
                    slr = get_right(s);
                    irb_rotate_left_right(p, s, slr);

                    copy_color(slr, p);
                    set_black(p);
                    set_black(s);

                    break;
                    //node = get_root(m);
                } else {
                    // right rotate about p
                    irb_rotate_right(p, s);

                    copy_color(s, p);
                    set_black(p);
                    set_black(get_left(s));

                    break;
                    //node = get_root(m);
                }
            }
        }
    }
    set_black(node);
}


/*
 * updates the r_off field of all of node's ancestors
 */
static void _irb_update_roff_remove(irb_node * node) {
    irb_node * parent;

    while (!is_root(node)) {
        parent = get_parent(node);
        if (get_right(parent) != node) {
            parent->r_off--;
        }
        node = parent;
    }
}


/*
 * Remove irb_node from the tree. This does not free the
 * memory.
 */
void _irb_remove_helper(struct __int_irb_tree *tree, irb_node *node) {
    irb_node *replacer, *child, *par;

    // if this node is internal (has 2 children), then we want to
    // swap it with its successor and then delete the node, which
    // now has at most 1 non-leaf child
    if (get_left(node) == ILEAF || get_right(node) == ILEAF) {
        replacer = node;
    } else {
        // find successor of node
        replacer = get_right(node);
        while (get_left(replacer) != ILEAF) {
            replacer = get_left(replacer);
        }
    }


    // traverse upward and fix r_off's of all parent nodes
    _irb_update_roff_remove(replacer);

    // if we removed a red node, the black height of the tree clearly
    // couldn't have changed, so we're good. Otherwise, we have to 
    // fix any rb tree violations we may have incurred
    if (is_black(replacer)) {
        irb_remove_fix(replacer);
    }

    // proceed to remove replacer from the graph, which
    // is guarenteed to have at most 1 non-leaf child

    child = (get_right(replacer) == ILEAF ?
            get_left(replacer) : get_right(replacer));
    if (child != ILEAF && is_root(replacer)) {
        mark_as_root(child);
        set_black(child);
    }

    par = get_parent(replacer);
    if (get_left(par) == replacer) {
        set_left(par, child);
    } else {
        set_right(par, child);
    }

    // now put replacer where node is, if they are not the same
    if (node != replacer) {
        // we want to preserve the color of node when replacing
        // with replacer, so we can directly copy fields
        set_left(replacer, get_left(node));
        set_right(replacer, get_right(node));
        set_parent(replacer, get_parent(node));
        replacer->r_off = node->r_off;
        copy_color(replacer, node);
        transfer_root_mark(replacer, node);
        if (get_left(get_parent(node)) == node) {
            set_left(get_parent(node), replacer);
        } else {
            set_right(get_parent(node), replacer);
        }
    }
}



irb_idx_t irb_get_idx(struct irb_node *node) {
    irb_idx_t idx = node->r_off - 1;
    irb_node * prev;
    goto cond;

    for (;;) {
        idx += get_right(node) == prev ? node->r_off : 0;
cond:
        if (is_root(node)) {
            break;
        }
        prev = node;
        node = get_parent(node);
    }
    return idx;
}



static irb_node* irb_find_leftmost_child(irb_node *node) {
    if (node != ILEAF) {
        while (get_left(node) != ILEAF) {
            node = get_left(node);
        }
    }
    return node;
}

static irb_node* irb_find_rightmost_child(irb_node *node) {
    if (node != ILEAF) {
        while (get_right(node) != ILEAF) {
            node = get_right(node);
        }
    }
    return node;
}

irb_node* irb_find_leftmost(struct __int_irb_tree *tree) {
    irb_node* l = irb_get_root(tree);
    return irb_find_leftmost_child(l);
}

irb_node* irb_find_succ(irb_node *node) {
    irb_node *p;

    if (get_right(node) != ILEAF) {
        return irb_find_leftmost_child(get_right(node));
    }
    else {
        while (!is_root(node) && get_right((p = get_parent(node))) == node) {
            node = p;
        }
        if (is_root(node)) {
            return ILEAF;
        }
        else {
            return p;
        }
    }
}

irb_node* irb_find_pred(irb_node *node) {
    irb_node *p;

    if (get_left(node) != ILEAF) {
        return irb_find_rightmost_child(get_left(node));
    }
    else {
        while (!is_root(node) && get_left((p = get_parent(node))) == node) {
            node = p;
        }
        if (is_root(node)) {
            return ILEAF;
        }
        else {
            return p;
        }
    }
}



static void _irb_print(irb_node *node, int depth, int l) {
    static const char *colstr[2] = {"black", "red"};
    if (!node) return;

    const char * pref;
    if (depth == 0) pref = "";
    else if (l) pref = "L: ";
    else pref = "R: ";

    printf("%*.*s%s%p (%s, r_off=%zd)\n", depth, depth, "", pref, node, colstr[is_red(node)], node->r_off);
    _irb_print(get_left(node), depth + 1, 1);
    _irb_print(get_right(node), depth + 1, 0);
}


void irb_print(struct __int_irb_tree *tree) {
    _irb_print(get_root(tree), 0, 0);
}






/*
 * rb tree validation
 */

static size_t black_depth(irb_node *node) {
    if (node == ILEAF)
        return 0;
    size_t l, r;
    l = black_depth(get_left(node));
    r = black_depth(get_right(node));
    if (l == -1LU || r == -1LU || l != r)
        return -1LU;
    return l + (is_black(node) ? 1 : 0);
}


static char no_red_red(irb_node *node) {
    if (node == ILEAF)
        return 1;
    if (is_red(node)) {
        if (is_red(get_left(node)) || is_red(get_right(node))) {
            return 0;
        }
    }
    return no_red_red(get_left(node)) && no_red_red(get_right(node));
}


static char parents_valid(irb_node *node) {
    if (node == ILEAF)
        return 1;
    if (get_left(node) != ILEAF) {
        if (get_parent(get_left(node)) != node)
            return 0;
        if (!parents_valid(get_left(node)))
            return 0;
    }
    if (get_right(node) != ILEAF) {
        if (get_parent(get_right(node)) != node)
            return 0;
        if (!parents_valid(get_right(node)))
            return 0;
    }
    return 1;
}

static char no_other_roots(irb_node *node) {
    if (node == ILEAF) return 1;
    if (is_root(node)) return 0;
    return no_other_roots(get_left(node)) && no_other_roots(get_right(node));
}

static irb_idx_t validate_idxs(irb_node * node) {
    irb_idx_t lsize, rsize;
    if (get_left(node) != ILEAF) {
        lsize = validate_idxs(get_left(node));
    }
    else {
        lsize = 0;
    }
    if (get_right(node) != ILEAF) {
        rsize = validate_idxs(get_right(node));
    }
    else {
        rsize = 0;
    }

    if (lsize == -1l || rsize == -1l) {
        return -1l;
    }
    if (node->r_off != lsize + 1) {
        return -1l;
    }
    return lsize + rsize + 1;
}


void _irb_validate_helper(struct __int_irb_tree *tree) {
    irb_node *root;

    root = get_root(tree);

    IRB_ASSERT(!is_red(root), tree);
    IRB_ASSERT(black_depth(root) != -1LU, tree);
    IRB_ASSERT(no_red_red(root), tree);
    IRB_ASSERT(parents_valid(root), tree);

    if (root != ILEAF) {
        IRB_ASSERT(is_root(root), tree);
        IRB_ASSERT(get_parent(root) == (irb_node*) tree, tree);
        IRB_ASSERT(no_other_roots(get_left(root)) &&
                no_other_roots(get_right(root)), tree);
        IRB_ASSERT(validate_idxs(root) != -1l, tree);
    }
}

