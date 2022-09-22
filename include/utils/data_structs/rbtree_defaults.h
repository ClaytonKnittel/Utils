#ifndef _RB_TREE_DEFAULTS_H_
#define _RB_TREE_DEFAULTS_H_

#include <utils/data_structs/rbtree.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * ptr rb trees: sorted by location of nodes in memory
 */

static int ptr_cmp(rb_node_t* a, rb_node_t* b) {
  return ((uint64_t)a) < ((uint64_t)b)    ? -1
         : ((uint64_t)a) == ((uint64_t)b) ? 0
                                          : 1;
}

RB_DEFINE_TYPE(ptr, ptr_cmp)

/*
 * int rb trees: sorted by an int value stored immediately after the node in
 * memory
 */

typedef struct rb_int_node {
  rb_node_t base;
  int64_t val;
} rb_int_node_t;

typedef struct rb_uint_node {
  rb_node_t base;
  uint64_t val;
} rb_uint_node_t;

RB_DEFINE_SCALAR_TYPE(int, int64_t)
RB_DEFINE_SCALAR_TYPE(uint, uint64_t)

#ifdef __cplusplus
}
#endif

#endif /* _RB_TREE_DEFAULTS_H_ */
