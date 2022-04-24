
#include <utils/math/mat2.h>
#include <utils/math/mat3.h>

#include "test_utils.h"

START_TEST(test_mat2_init)
{
	mat2_t m;

	init_mat2(&m, 4.5, 1.2, 0.7, 10.1);
	ck_assert_float_eq(m.m00, 4.5);
	ck_assert_float_eq(m.m01, 1.2);
	ck_assert_float_eq(m.m10, 0.7);
	ck_assert_float_eq(m.m11, 10.1);
}
END_TEST

START_TEST(test_mat3_init)
{
	mat3_t m;

	init_mat3(&m, 4.5, 1.2, 0.7, 10.1, 8.8, 4.8, 9.9, 1.1, 30.2);
	ck_assert_float_eq(m.m00, 4.5);
	ck_assert_float_eq(m.m01, 1.2);
	ck_assert_float_eq(m.m02, 0.7);
	ck_assert_float_eq(m.m10, 10.1);
	ck_assert_float_eq(m.m11, 8.8);
	ck_assert_float_eq(m.m12, 4.8);
	ck_assert_float_eq(m.m20, 9.9);
	ck_assert_float_eq(m.m21, 1.1);
	ck_assert_float_eq(m.m22, 30.2);
}
END_TEST

Suite* test_mat()
{
	TCase* tc_init;

	Suite* s = suite_create("Mat");

	tc_init = tcase_create("Init");
	tcase_add_test(tc_init, test_mat2_init);
	tcase_add_test(tc_init, test_mat3_init);
	suite_add_tcase(s, tc_init);

	return s;
}

