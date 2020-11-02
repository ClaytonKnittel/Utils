
#include <stdlib.h>

#include <data_structs/irbtree.h>



int main(int argc, char * argv[]) {
    irb_tree tree;

    irb_init(&tree);

#define N_NODES 1000

    irb_node * nodes = (irb_node *) malloc(N_NODES * sizeof(irb_node));

    for (int i = 1; i < N_NODES; i += 2) {
        irb_insert_ptr(&tree, &nodes[i]);
        irb_validate_ptr(&tree);
    }

    for (int i = 0; i < N_NODES; i += 2) {
        irb_insert_ptr(&tree, &nodes[i]);
        irb_validate_ptr(&tree);
    }

    for (int i = 0; i < N_NODES; i++) {
        assert(irb_get_idx(&nodes[i]) == i);
    }

    for (int i = 0; i < N_NODES - 1; i++) {
        assert(irb_find_succ(&nodes[i]) == &nodes[i + 1]);
    }

    for (int i = 1; i < N_NODES; i++) {
        assert(irb_find_pred(&nodes[i]) == &nodes[i - 1]);
    }

    for (uint64_t addr = (uint64_t) &nodes[0];
         addr < (uint64_t) &nodes[N_NODES];
         addr += 8) {
        uint64_t upper_bound = ((uint64_t) &nodes[0])
                + ((addr - ((uint64_t) &nodes[0])) / sizeof(irb_node))
                    * sizeof(irb_node);
        uint64_t lower_bound = addr > ((uint64_t) &nodes[N_NODES - 1])
            ? 0
            : ((uint64_t) &nodes[0])
                + ((addr - ((uint64_t) &nodes[0]) + sizeof(irb_node) - 1)
                      / sizeof(irb_node))
                    * sizeof(irb_node);
        assert(irb_upper_bound_ptr(&tree, (irb_node *) addr)
            == (irb_node *) upper_bound);
        assert(irb_lower_bound_ptr(&tree, (irb_node *) addr)
            == (irb_node *) lower_bound);
    }

    // delete some nodes
    for (int i = 1; i < N_NODES; i += 3) {
        irb_remove_ptr(&tree, &nodes[i]);
        irb_validate_ptr(&tree);
    }

    free(nodes);

    return 0;
}
