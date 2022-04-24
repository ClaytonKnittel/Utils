
#include <utils/math/vec2.h>
#include <utils/math/vec3.h>
#include <utils/math/vec4.h>

#include "test_utils.h"

START_TEST(test_vec2_init)
{
	vec2_t v;

	init_vec2(&v, 4.5, 1.2);
	ck_assert_float_eq(v.x, 4.5);
	ck_assert_float_eq(v.y, 1.2);
}
END_TEST

START_TEST(test_vec3_init)
{
	vec3_t v;

	init_vec3(&v, 4.5, 1.2, 0.7);
	ck_assert_float_eq(v.x, 4.5);
	ck_assert_float_eq(v.y, 1.2);
	ck_assert_float_eq(v.z, 0.7);
}
END_TEST

START_TEST(test_vec4_init)
{
	vec4_t v;

	init_vec4(&v, 4.5, 1.2, 0.7, 10.1);
	ck_assert_float_eq(v.x, 4.5);
	ck_assert_float_eq(v.y, 1.2);
	ck_assert_float_eq(v.z, 0.7);
	ck_assert_float_eq(v.w, 10.1);
}
END_TEST

Suite* test_vec()
{
	TCase* tc_init;

	Suite* s = suite_create("Vec");

	tc_init = tcase_create("Init");
	tcase_add_test(tc_init, test_vec2_init);
	tcase_add_test(tc_init, test_vec3_init);
	tcase_add_test(tc_init, test_vec4_init);
	suite_add_tcase(s, tc_init);

	return s;
}

