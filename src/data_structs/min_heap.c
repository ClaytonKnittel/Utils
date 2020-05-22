
#include <assert.h>

#include <data_structs/min_heap.h>


#define LEFT_CHILD 0x1

// pointers must be aligned by 2 bytes for this to work (need 1 bit in rsib)
#define ALIGNMENT_REQUIREMENT 2


#define IS_LEFT_CHILD(heap_node) \
    ((((uint64_t) (heap_node)->rsib) & LEFT_CHILD) != 0)

#define IS_RIGHT_CHILD(heap_node) (!IS_LEFT_CHILD(heap_node))


#define SET_LEFT_CHILD(node) \
    ((node)->rsib = (heap_node *) (((uint64_t) (node)->rsib) | LEFT_CHILD))

#define SET_RIGHT_CHILD(node) \
    ((node)->rsib = (heap_node *) (((uint64_t) (node)->rsib) & ~LEFT_CHILD))


// this node has a parent (i.e. is not the root) if it has a right sibling.
// Note that the only child bits will not be set for the root, meaning rsib
// having value (heap_node*) 0x1 or 0x2 is not possible
#define HAS_PARENT(heap_node) \
    (((heap_node)->rsib) != NULL)

#define RSIB(node) \
    ((heap_node*) (((uint64_t) (node)->rsib) & ~LEFT_CHILD))


// returns the right child of node if is has one, NULL otherwise
static heap_node * _right_child(heap_node * node) {
    heap_node * child = node->lchild;
    if (child != NULL) {
        heap_node * rsib = RSIB(child);
        if (rsib != node) {
            return rsib;
        }
        else if (IS_RIGHT_CHILD(child)) {
            return child;
        }
    }
    return NULL;
}



int heap_init(heap_t *h) {
    h->root = NULL;
    return 0;
}


void heap_destroy(heap_t *h) {
}



/*
 * links heap node larger onto heap node smaller's tree, without checking any
 * conditions
 *
 * safe to call this with smaller = pointer to heap struct, as lchild is the
 * only field accessed in smaller (which is aliased by root field of heap
 * struct)
 */
static void _link_int(heap_node * smaller, heap_node * larger) {
    // link n2 as leftmost child of n1. Because n1->lchild = n1 for a node with
    // no children, we do not need any sort of condition here
    heap_node * lchild = smaller->lchild;
    larger->rsib = (heap_node *) (((uint64_t) lchild) | LEFT_CHILD);
    smaller->lchild = larger;

    if (lchild != NULL) {
        // lchild is now the right child of n2
        SET_RIGHT_CHILD(lchild);
    }
}


/*
 * links the two subtrees rooted at n1 and n2 by making the node with smaller
 * key the new root, and making the other tree the leftmost child of the new
 * root. Returns the root of the resultant tree
 */
static heap_node * _link(heap_node * n1, heap_node * n2) {

    assert(n1 != NULL);
    assert(n2 != NULL);

    if (n2->key < n1->key) {
        heap_node * tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    // n1 is tree with smaller root

    // can only be joining single trees, not a chain of trees
    assert(n1->rsib == NULL);
    assert(n2->rsib == NULL);

    _link_int(n1, n2);

    // return new tree
    return n1;
}



/*
 * removes the right child from the tree rooted at node and returns that
 * right child
 */
static heap_node * __unlink_from_rchild(heap_node * node) {
    heap_node * lchild = node->lchild;

    if (lchild != NULL) {
        // this node has at least one child

        // l_rsib is rsib of lchild
        heap_node * l_rsib = RSIB(lchild);

        if (l_rsib != lchild) {
            // l_rsib is the right child

            // need to unlink lchild from l_rsib (lchild now an only child, so
            // need to set LEFT_CHILD bit)
            lchild->rsib = (heap_node *) (((uint64_t) node) | LEFT_CHILD);
            return l_rsib;
        }
        else if (IS_RIGHT_CHILD(lchild)) {
            // lchild is an only child and is the right child
            return lchild;
        }
    }

    // otherwise, this node does not have a right child and no work needs to
    // be done
    return NULL;
}


/*
 * removes node from the heap
 */
static void _unlink(heap_node * node) {

    // even the root has a parent (the base of the heap)
    assert(HAS_PARENT(node));

    // cut the edge connecting node to its parent and link that subtree with
    // the rest of the heap
    heap_node * rsib = RSIB(node);

    // regardless of where node is in the heap, we have to unlink it from
    // its right child chain
    heap_node * rchild = __unlink_from_rchild(node);

    if (rsib->lchild == node) {
        // node is an only child, so rsib is actually parent
        heap_node * parent = rsib;

        if (rchild != NULL) {
            // if there was a right child, then it replaces node
            parent->lchild = rchild;
            rchild->rsib = parent; // keep LEFT_CHILD bit unset
        }
        else {
            // otherwise, if this node has no right child, then we need
            // to set lchild of parent to self (meaning it has no
            // children)
            parent->lchild = parent;
        }
    }
    else {
        // node has a sibling, so first need to figure out if it is a left
        // or right sibling

        if (IS_LEFT_CHILD(node)) {
            // we know LEFT_CHILD bit of rsib is not set, so we can just
            // access rsib directly without masking
            heap_node * parent = rsib->rsib;

            // now replace node with rchild
            if (rchild != NULL) {
                parent->lchild = rchild;
                rchild->rsib = (heap_node *) (((uint64_t) rsib) | LEFT_CHILD);
            }
            else {
                // if there was no replacement for node, then rsib is now
                // the only child
                parent->lchild = rsib;
            }
        }
        else /* IS_RIGHT_CHILD(node) */ {
            // if node is a right child, then rsib is actually the parent
            heap_node * parent = rsib;
            heap_node * lsib = parent->lchild;

            // now replace node with rchild
            if (rchild != NULL) {
                lsib->rsib = (heap_node *) (((uint64_t) rchild) | LEFT_CHILD);
                rchild->rsib = parent;
            }
            else {
                // if there was no replacement for node, then lsib is now
                // the only child
                lsib->rsib = (heap_node *) (((uint64_t) parent) | LEFT_CHILD);
            }
        }
    }
}



/*
 * returns a pointer to the heap node at the top of the heap (having minimum
 * key value of all heap nodes)
 */
heap_node * heap_find_min(heap_t *h) {
    return h->root;
}


/*
 * deletes the min heap node from the heap
 */
void heap_delete_min(heap_t *h) {

}

/*
 * combines the effect of find_min and delete_min, returning the deleted min
 */
heap_node * heap_extract_min(heap_t *h) {
    heap_node * min = heap_find_min(h);
    heap_delete_min(h);
    return min;
}




/*
 * inserts a node into the tree. The node must already be initialized, i.e. its
 * key must be set
 *
 * returns 0 on success, nonzero if fails
 */
int heap_insert(heap_t *h, heap_node * node) {
    // make node a one-node tree, then link it with the current root
    node->lchild = node;
    node->rsib = NULL;

    heap_node * root = h->root;

    if (root != NULL) {
        // pass node as second argument, as it is less likely for node < root
        root = _link(root, node);
        h->root = root;
    }
    else {
        // if the heap is empty, we want to set the node we are inserting as
        // the left child of the heap struct (which acts like a node that isn't
        // actually part of the heap)
        _link_int((heap_node *) h, node);
    }

    return 0;
}


/*
 * decreases key value of node to the new key value
 */
int heap_decrease_key(heap_t *h, heap_node * node, heap_key_t new_key) {

    heap_key_t old_key = node->key;

    // this must strictly decrease the key
    assert(old_key > new_key);

    node->key = new_key;

    // remove the subtree rooted at node from the tree, then link it with the
    // root of the tree
    _unlink(node);

    heap_node * root = h->root;
    if (root != NULL) {
        root = _link(root, node);
        h->root = root;
    }
    else {
        // if the heap is now empty, then node was the root
        assert(IS_LEFT_CHILD(node));
        h->root = node;
    }

    return 0;
}



/*
 * validates half-ordered bst property of tree rooted at node, where node
 * is no greater than any node in left subtree
 *
 * min is min value allowed in subtree
 */
static void _validate_half_bst(heap_node * node, heap_key_t min) {
    assert(node->key <= min);
    
    heap_node * child = node->lchild;

    if (child != node) {
        if (IS_LEFT_CHILD(child)) {
            // check left subtree
            _validate_half_bst(child, node->key);

            heap_node * rchild = RSIB(child);
            if (rchild != node) {
                // check right subtree
                _validate_half_bst(child, min);
            }
        }
        else {
            // check right subtree
            _validate_half_bst(child, min);
        }
    }
}

/*
 * validates the heap, aborting on failure and returning on success
 */
void heap_validate(heap_t *h) {

    if (h->root != NULL) {
        // root cannot have a right sibling
        assert(h->root->rsib == (heap_node *) (((uint64_t) h) | LEFT_CHILD));

        _validate_half_bst(h->root, 0x7fffffffffffffffL);
    }
}


