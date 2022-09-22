
#include <stdlib.h>

#include <utils/data_structs/irbtree.h>

#include "test_utils.h"

START_TEST(test_basic) {
  irb_tree tree;
  irb_init(&tree);

#define N_NODES 1000
  irb_node *nodes = (irb_node *)malloc(N_NODES * sizeof(irb_node));

  for (int i = 1; i < N_NODES; i += 2) {
    irb_insert_ptr(&tree, &nodes[i]);
    irb_validate_ptr(&tree);
  }

  for (int i = 0; i < N_NODES; i += 2) {
    irb_insert_ptr(&tree, &nodes[i]);
    irb_validate_ptr(&tree);
  }

  ck_assert(irb_get_idx_ptr(&tree, (irb_node *)(((uint64_t)&nodes[0]) - 1)) ==
            0);
  for (int i = 0; i < N_NODES; i++) {
    ck_assert(irb_get_idx_unsafe(&nodes[i]) == i);
    ck_assert(irb_get_idx_ptr(&tree, &nodes[i]) == i);
    ck_assert(irb_get_idx_ptr(&tree, (irb_node *)(((uint64_t)&nodes[i]) + 1)) ==
              i + 1);
  }

  for (int i = 0; i < N_NODES - 1; i++) {
    ck_assert(irb_find_succ(&nodes[i]) == &nodes[i + 1]);
  }

  for (int i = 1; i < N_NODES; i++) {
    ck_assert(irb_find_pred(&nodes[i]) == &nodes[i - 1]);
  }

  for (uint64_t addr = (uint64_t)&nodes[0]; addr < (uint64_t)&nodes[N_NODES];
       addr += 8) {
    uint64_t upper_bound =
        ((uint64_t)&nodes[0]) +
        ((addr - ((uint64_t)&nodes[0])) / sizeof(irb_node)) * sizeof(irb_node);
    uint64_t lower_bound =
        addr > ((uint64_t)&nodes[N_NODES - 1])
            ? 0
            : ((uint64_t)&nodes[0]) +
                  ((addr - ((uint64_t)&nodes[0]) + sizeof(irb_node) - 1) /
                   sizeof(irb_node)) *
                      sizeof(irb_node);
    ck_assert(irb_upper_bound_ptr(&tree, (irb_node *)addr) ==
              (irb_node *)upper_bound);
    ck_assert(irb_lower_bound_ptr(&tree, (irb_node *)addr) ==
              (irb_node *)lower_bound);
  }

  // delete some nodes
  for (int i = 1; i < N_NODES; i += 3) {
    irb_remove_ptr(&tree, &nodes[i]);
    irb_validate_ptr(&tree);
  }

  free(nodes);
}
END_TEST

Suite *test_irbtree() {
  TCase *tc_basic;

  Suite *s = suite_create("Indexed red-black tree");

  tc_basic = tcase_create("Basic");
  tcase_add_test(tc_basic, test_basic);
  suite_add_tcase(s, tc_basic);

  return s;
}
