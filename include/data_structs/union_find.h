#ifndef _UNION_FIND_H
#define _UNION_FIND_H


#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>


/***
 *
 * Implementation of union find data structure based on Princeton lecture
 * slides at https://www.cs.princeton.edu/~rs/AlgsDS07/01UnionFind.pdf
 *
 *
 * Called "weighted quick-union with path compression", the basic idea is to
 * track parents of each element, forming trees of elements. Each disjoint tree
 * is a different union of elements, so two elements are in the same set iff
 * their roots are the same (follow parents up until parent = el (root))
 *
 * When performing union op, we only need to find the root of both elements
 * to be unioned, and assign one's parent as the other. This will join the two
 * element's sets by joining their trees
 *
 * An optimization on this is "weighting" in which we track the size of each
 * tree at the root, and always attach the shorter tree to the larger (thus
 * increasing the height of the tallest tree by at most 1). This prevents
 * the trees from ever becoming too tall.
 *
 * A second optimization is to update the parent of each visited element to the
 * root on each call to find, which still avoids redundancies with updating
 * roots over and over while not having any redundant calculations of paths up
 * a tree
 *
 *
 * For the sake of efficiency, the set of elements of every union find struct
 * is the integers 0 - (n-1), and any mapping between these id's and the actual
 * elements being stored in the union find must be done by the user
 *
 */


// contains metadata about each element of union find
typedef struct union_node union_node;

// union find elements are nonnegative id's
typedef uint64_t uf_node_t;


typedef struct union_find {
    uint64_t size;

    // tracks total number of unique sets
    uint64_t num_sets;

    // array of elements
    union_node *arr;
} union_find;


/*
 * initializes union find struct with given size (and elements 0 - (size-1)),
 * starting with each element in their own set
 *
 * returns 0 on success and nonzero on failure
 */
int uf_init(union_find *uf, uint64_t size);


void uf_destroy(union_find *uf);

/*
 * deep copies src into dst
 */
int uf_copy(union_find *dst, const union_find *src);


// gives root of tree that node is in
uf_node_t uf_find(union_find *uf, uf_node_t node);


// unions the two sets that a and b are in (noop if are already in the same
// set)
void uf_union(union_find *uf, uf_node_t a, uf_node_t b);


static uint64_t uf_num_sets(union_find *uf) {
    return uf->num_sets;
}


#ifdef __cplusplus
}
#endif

#endif /* _UNION_FIND_H */
