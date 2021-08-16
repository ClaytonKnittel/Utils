
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


	// now do int test
	rb_init(&tree);

	int64_t vals[N_NODES];
    rb_int_node_t* inodes[N_NODES];

	for (int i = 0; i < N_NODES; i++) {
		vals[i] = rand();
	}

    for (int i = 0; i < N_NODES; i++) {
        inodes[i] = (rb_int_node_t*) rb_insert_int(&tree, vals[i]);
        rb_validate_int(&tree);
    }

	// insertion sort
	for (int i = 1; i < N_NODES; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (vals[j] > vals[j + 1]) {
				int64_t tmp = vals[j];
				vals[j] = vals[j + 1];
				vals[j + 1] = tmp;

				rb_int_node_t* tmp2 = inodes[j];
				inodes[j] = inodes[j + 1];
				inodes[j + 1] = tmp2;
			}
			else {
				break;
			}
		}
	}

    for (int i = 0; i < N_NODES; i++) {
		rb_node_t* res = rb_find_int(&tree, vals[i]);
		assert(res == &inodes[i]->base);
		assert(((rb_int_node_t*) res)->val == vals[i]);

		rb_node_t* pred = rb_upper_bound_int(&tree, vals[i]);
		assert(pred == &inodes[i]->base);
		rb_node_t* succ = rb_lower_bound_int(&tree, vals[i]);
		assert(succ == &inodes[i]->base);

		pred = rb_upper_bound_int(&tree, vals[i] - 1);
		succ = rb_lower_bound_int(&tree, vals[i] + 1);
		if (i > 0) {
			assert(pred == &inodes[i - 1]->base);
		}
		else {
			assert(pred == NULL);
		}
		if (i < N_NODES - 1) {
			assert(succ == &inodes[i + 1]->base);
		}
		else {
			assert(succ == NULL);
		}
    }

    // delete some nodes
    for (int i = 1; i < N_NODES; i += 3) {
        rb_remove_int(&tree, vals[i]);
        rb_validate_int(&tree);
    }

	rb_free(&tree);

    return 0;
}
