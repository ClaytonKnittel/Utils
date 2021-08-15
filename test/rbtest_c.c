
#include <data_structs/rbtree.h>


int main(int argc, char * argv[]) {
    rb_tree_t tree;

    rb_init(&tree);

#define N_NODES 100

    rb_node_t nodes[N_NODES];

    for (int i = 1; i < N_NODES; i += 2) {
        rb_insert_ptr(&tree, &nodes[i]);
        rb_validate_ptr(&tree);
    }

    for (int i = 0; i < N_NODES; i += 2) {
        rb_insert_ptr(&tree, &nodes[i]);
        rb_validate_ptr(&tree);
    }

    for (int i = 0; i < N_NODES - 1; i++) {
        assert(rb_find_succ(&nodes[i]) == &nodes[i + 1]);
    }

    for (int i = 1; i < N_NODES; i++) {
        assert(rb_find_pred(&nodes[i]) == &nodes[i - 1]);
    }

    for (uint64_t addr = (uint64_t) &nodes[0];
         addr < (uint64_t) &nodes[N_NODES];
         addr += 8) {
        uint64_t upper_bound = ((uint64_t) &nodes[0])
                + ((addr - ((uint64_t) &nodes[0])) / sizeof(rb_node_t))
                    * sizeof(rb_node_t);
        uint64_t lower_bound = addr > ((uint64_t) &nodes[N_NODES - 1])
            ? 0
            : ((uint64_t) &nodes[0])
                + ((addr - ((uint64_t) &nodes[0]) + sizeof(rb_node_t) - 1)
                      / sizeof(rb_node_t))
                    * sizeof(rb_node_t);
        assert(rb_upper_bound_ptr(&tree, (rb_node_t *) addr)
            == (rb_node_t *) upper_bound);
        assert(rb_lower_bound_ptr(&tree, (rb_node_t *) addr)
            == (rb_node_t *) lower_bound);
    }

    // delete some nodes
    for (int i = 1; i < N_NODES; i += 3) {
        rb_remove_ptr(&tree, &nodes[i]);
        rb_validate_ptr(&tree);
    }

    return 0;
}
