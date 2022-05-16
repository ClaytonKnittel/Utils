
#include <utils/data_structs/rbtree.h>
#include <utils/data_structs/rbtree_defaults.h>

#include "test_utils.h"


START_TEST(test_basic)
{
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
        ck_assert(rb_find_succ(&nodes[i]) == &nodes[i + 1]);
    }

    for (int i = 1; i < N_NODES; i++) {
        ck_assert(rb_find_pred(&nodes[i]) == &nodes[i - 1]);
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
        ck_assert(rb_upper_bound_ptr(&tree, (rb_node_t *) addr)
            == (rb_node_t *) upper_bound);
        ck_assert(rb_lower_bound_ptr(&tree, (rb_node_t *) addr)
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

	rb_node_t* _node;
	uint64_t idx = 0;
	rb_for_each(&tree, _node) {
		rb_int_node_t* node = (rb_int_node_t*) _node;
		ck_assert(inodes[idx] == node);
		ck_assert(vals[idx] == node->val);

		idx++;
	}

    for (int i = 0; i < N_NODES; i++) {
		rb_node_t* res = rb_find_int(&tree, vals[i]);
		ck_assert(res == &inodes[i]->base);
		ck_assert(((rb_int_node_t*) res)->val == vals[i]);

		rb_node_t* pred = rb_upper_bound_int(&tree, vals[i]);
		ck_assert(pred == &inodes[i]->base);
		rb_node_t* succ = rb_lower_bound_int(&tree, vals[i]);
		ck_assert(succ == &inodes[i]->base);

		pred = rb_upper_bound_int(&tree, vals[i] - 1);
		succ = rb_lower_bound_int(&tree, vals[i] + 1);
		if (i > 0) {
			ck_assert(pred == &inodes[i - 1]->base);
		}
		else {
			ck_assert(pred == NULL);
		}
		if (i < N_NODES - 1) {
			ck_assert(succ == &inodes[i + 1]->base);
		}
		else {
			ck_assert(succ == NULL);
		}
    }

    // delete some nodes
    for (int i = 1; i < N_NODES; i += 3) {
        rb_remove_int(&tree, vals[i]);
        rb_validate_int(&tree);
    }

	idx = 0;
	rb_for_each_mod(&tree, _node) {
		rb_int_node_t* node = (rb_int_node_t*) _node;

		uint64_t true_idx = idx + (idx + 1) / 2;
		ck_assert(inodes[true_idx] == node);
		ck_assert(vals[true_idx] == node->val);

		rb_remove_int(&tree, vals[true_idx]);

		idx++;
	}
	rb_for_each_mod_fin();

	ck_assert_int_eq(tree.size, 0);

	rb_free(&tree);
}
END_TEST

Suite*
test_rbtree()
{
	TCase* tc_basic;

	Suite* s = suite_create("Red-black tree");

	tc_basic = tcase_create("Basic");
	tcase_add_test(tc_basic, test_basic);
	suite_add_tcase(s, tc_basic);

	return s;
}

