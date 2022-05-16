
#include <utils/algorithms/rect_packing.h>

#include "test_utils.h"

START_TEST(test_init)
{
	rect_packing_t packing;
	ck_assert_int_eq(rect_packing_init(&packing, 10, 10), 0);
	rect_packing_free(&packing);
}
END_TEST

Suite*
test_rect_packing()
{
	TCase* tc_init;

	Suite* s = suite_create("Rectangle Bin Packing");

	tc_init = tcase_create("Init");
	tcase_add_test(tc_init, test_init);
	suite_add_tcase(s, tc_init);

	return s;
}

