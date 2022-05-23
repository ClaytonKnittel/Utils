
#include <stdlib.h>

#include "test_utils.h"

extern "C" {

Suite* test_int_set();
Suite* test_irbtree();
Suite* test_min_heap();
Suite* test_prime_factor_list();
Suite* test_rbtree();
Suite* test_rect_packing();
Suite* test_rtree();
Suite* test_sort();
Suite* test_to_upper_lower();
Suite* test_union_find();
Suite* test_utils();
Suite* test_vector();
Suite* test_vec();
Suite* test_mat();

}

Suite* test_prime_factor_list_cc();
Suite* test_rbtree_cc();
Suite* test_rtree_cc();
Suite* test_sort_cc();

int main()
{
	int number_failed;
	SRunner *sr;

	sr = srunner_create(test_int_set());
	srunner_add_suite(sr, test_irbtree());
	srunner_add_suite(sr, test_min_heap());
	srunner_add_suite(sr, test_prime_factor_list());
	srunner_add_suite(sr, test_rbtree());
	srunner_add_suite(sr, test_rect_packing());
	srunner_add_suite(sr, test_rtree());
	srunner_add_suite(sr, test_sort());
	srunner_add_suite(sr, test_to_upper_lower());
	srunner_add_suite(sr, test_union_find());
	srunner_add_suite(sr, test_utils());
	srunner_add_suite(sr, test_vector());
	srunner_add_suite(sr, test_vec());
	srunner_add_suite(sr, test_mat());
	srunner_add_suite(sr, test_prime_factor_list_cc());
	srunner_add_suite(sr, test_rbtree_cc());
	srunner_add_suite(sr, test_rtree_cc());
	srunner_add_suite(sr, test_sort_cc());

	srunner_set_fork_status(sr, CK_NOFORK);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

