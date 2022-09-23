
#include <inttypes.h>
#include <stdlib.h>

#include <utils/data_structs/union_find.h>
#include <utils/utils.h>

/*
 * stores metadata for each union find node.
 */
struct union_node {
  // id of parent of this node (self if root)
  uf_node_t parent;
  // size of the tree under this element if this is a root, otherwise
  // this value is undefined
  uint64_t size;
};

int uf_init(union_find *uf, uint64_t size) {
  union_node *arr = (union_node *) malloc(size * sizeof(union_node));

  if (arr == NULL) {
    printerr(stderr, "Unable to malloc %" PRIu64 " bytes\n",
             size * sizeof(union_node));
    return -1;
  }

  for (uint64_t i = 0; i < size; i++) {
    // each element is initially isolated
    arr[i].parent = i;
    // and thus its the root of a tree of size 1
    arr[i].size = 1lu;
  }

  uf->arr = arr;
  uf->size = size;
  uf->num_sets = size;
  return 0;
}

void uf_destroy(union_find *uf) {
  if (uf->arr != NULL) {
    free(uf->arr);
  }
}

int uf_copy(union_find *dst, const union_find *src) {
  dst->size = src->size;
  dst->num_sets = src->num_sets;
  dst->arr = (union_node *) malloc(dst->size * sizeof(union_node));

  if (dst->arr == NULL) {
    printerr(stderr, "Unable to malloc %" PRIu64 " bytes\n",
             dst->size * sizeof(union_node));
    return -1;
  }

  __builtin_memcpy(dst->arr, src->arr, dst->size * sizeof(union_node));
  return 0;
}

static uf_node_t _uf_root(union_find *uf, uf_node_t node) {
  union_node *n = &uf->arr[node];

  uf_node_t parent;
  while ((parent = n->parent) != node) {
    node = parent;
    union_node *new_n = &uf->arr[parent];
    // assign parent of n to its grandparent (slowly compresses tree)
    n->parent = new_n->parent;
    n = new_n;
  }
  return node;
}

uf_node_t uf_find(union_find *uf, uf_node_t node) {
  return _uf_root(uf, node);
}

uf_node_t uf_union(union_find *uf, uf_node_t a, uf_node_t b) {
  union_node *an, *bn;

  uf_node_t ar = _uf_root(uf, a);
  uf_node_t br = _uf_root(uf, b);

  if (ar != br) {
    an = &uf->arr[ar];
    bn = &uf->arr[br];

    // attach smaller tree to larger tree
    if (an->size < bn->size) {
      an->parent = br;
      bn->size += an->size;
      ar = br;
    } else {
      bn->parent = ar;
      an->size += bn->size;
    }

    // two sets have joined, meaning there is 1 less set
    uf->num_sets--;
  }
  return ar;
}

void uf_disjoin_unsafe(union_find *uf, uf_node_t a) {
  uf->arr[a].parent = a;
  uf->arr[a].size = 1lu;
}
