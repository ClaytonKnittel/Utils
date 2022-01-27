
#include <utils/utils.h>

#include "test_utils.h"

START_TEST(test_align_up_pow2)
{
	ck_assert_int_eq(ALIGN_UP(0x100, 0x10), 0x100);
}
END_TEST

START_TEST(test_align_up_pow2_minus_1)
{
	ck_assert_int_eq(ALIGN_UP(0x0ff, 0x10), 0x100);
}
END_TEST

START_TEST(test_align_up_pow2_plus_1)
{
	ck_assert_int_eq(ALIGN_UP(0x0f1, 0x10), 0x100);
}
END_TEST

START_TEST(test_align_down_pow2)
{
	ck_assert_int_eq(ALIGN_DOWN(0x100, 0x10), 0x100);
}
END_TEST

START_TEST(test_align_down_pow2_minus_1)
{
	ck_assert_int_eq(ALIGN_DOWN(0x10f, 0x10), 0x100);
}
END_TEST

START_TEST(test_align_down_pow2_plus_1)
{
	ck_assert_int_eq(ALIGN_DOWN(0x101, 0x10), 0x100);
}
END_TEST


#define DEFINE_UNARY_TEST(fn, in, out) \
START_TEST(test_ ## fn ## _ ## in) \
{ \
	ck_assert_int_eq(fn(in), out); \
} \
END_TEST

DEFINE_UNARY_TEST(ffs32_unsafe, 0x1, 1)
DEFINE_UNARY_TEST(ffs32_unsafe, 0x2, 2)
DEFINE_UNARY_TEST(ffs32_unsafe, 0x4, 3)
DEFINE_UNARY_TEST(ffs32_unsafe, 0x8, 4)
DEFINE_UNARY_TEST(ffs32_unsafe, 0x80, 8)
DEFINE_UNARY_TEST(ffs32_unsafe, 0x81, 1)
DEFINE_UNARY_TEST(ffs32_unsafe, 0x82, 2)
DEFINE_UNARY_TEST(ffs32_unsafe, 0x84, 3)
DEFINE_UNARY_TEST(ffs32_unsafe, 0x1000, 13)
DEFINE_UNARY_TEST(ffs32_unsafe, 0x80000000, 32)

DEFINE_UNARY_TEST(ffs64_unsafe, 0x1, 1)
DEFINE_UNARY_TEST(ffs64_unsafe, 0x2, 2)
DEFINE_UNARY_TEST(ffs64_unsafe, 0x4, 3)
DEFINE_UNARY_TEST(ffs64_unsafe, 0x8, 4)
DEFINE_UNARY_TEST(ffs64_unsafe, 0x80, 8)
DEFINE_UNARY_TEST(ffs64_unsafe, 0x1000, 13)
DEFINE_UNARY_TEST(ffs64_unsafe, 0x80000000, 32)
DEFINE_UNARY_TEST(ffs64_unsafe, 0x8000000000000000, 64)

DEFINE_UNARY_TEST(ffs32, 0x0, 0)
DEFINE_UNARY_TEST(ffs32, 0x80001000, 13)
DEFINE_UNARY_TEST(ffs32, 0x80000000, 32)

DEFINE_UNARY_TEST(ffs64, 0x0, 0)
DEFINE_UNARY_TEST(ffs64, 0x80001000, 13)
DEFINE_UNARY_TEST(ffs64, 0x80000000, 32)
DEFINE_UNARY_TEST(ffs64, 0x8000000000000000, 64)

DEFINE_UNARY_TEST(fls32_unsafe, 0x1, 1)
DEFINE_UNARY_TEST(fls32_unsafe, 0x2, 2)
DEFINE_UNARY_TEST(fls32_unsafe, 0x4, 3)
DEFINE_UNARY_TEST(fls32_unsafe, 0x8, 4)
DEFINE_UNARY_TEST(fls32_unsafe, 0x80, 8)
DEFINE_UNARY_TEST(fls32_unsafe, 0x81, 8)
DEFINE_UNARY_TEST(fls32_unsafe, 0x82, 8)
DEFINE_UNARY_TEST(fls32_unsafe, 0x84, 8)
DEFINE_UNARY_TEST(fls32_unsafe, 0x80000000, 32)
DEFINE_UNARY_TEST(fls32_unsafe, 0x80000001, 32)

DEFINE_UNARY_TEST(fls64_unsafe, 0x1, 1)
DEFINE_UNARY_TEST(fls64_unsafe, 0x2, 2)
DEFINE_UNARY_TEST(fls64_unsafe, 0x4, 3)
DEFINE_UNARY_TEST(fls64_unsafe, 0x8, 4)
DEFINE_UNARY_TEST(fls64_unsafe, 0x80, 8)
DEFINE_UNARY_TEST(fls64_unsafe, 0x81, 8)
DEFINE_UNARY_TEST(fls64_unsafe, 0x80000000, 32)
DEFINE_UNARY_TEST(fls64_unsafe, 0x80000001, 32)
DEFINE_UNARY_TEST(fls64_unsafe, 0x8000000000000000, 64)
DEFINE_UNARY_TEST(fls64_unsafe, 0x8000000000000001, 64)

DEFINE_UNARY_TEST(fls32, 0x0, 0)
DEFINE_UNARY_TEST(fls32, 0x1001, 13)
DEFINE_UNARY_TEST(fls32, 0x80000001, 32)

DEFINE_UNARY_TEST(fls64, 0x0, 0)
DEFINE_UNARY_TEST(fls64, 0x1001, 13)
DEFINE_UNARY_TEST(fls64, 0x80000001, 32)
DEFINE_UNARY_TEST(fls64, 0x8000000000000001, 64)

Suite*
test_utils()
{
	TCase* tc_align;
	TCase* tc_ffs;
	TCase* tc_next_pow2;
	TCase* tc_log10;
	TCase* tc_boolstr;

	Suite* s = suite_create("utils.h");

	tc_align = tcase_create("Align");
	tcase_add_test(tc_align, test_align_up_pow2);
	tcase_add_test(tc_align, test_align_up_pow2_minus_1);
	tcase_add_test(tc_align, test_align_up_pow2_plus_1);
	tcase_add_test(tc_align, test_align_down_pow2);
	tcase_add_test(tc_align, test_align_down_pow2_minus_1);
	tcase_add_test(tc_align, test_align_down_pow2_plus_1);
	suite_add_tcase(s, tc_align);

	tc_ffs = tcase_create("Find set bit");
	tcase_add_test(tc_ffs, test_ffs32_unsafe_0x1);
	tcase_add_test(tc_ffs, test_ffs32_unsafe_0x2);
	tcase_add_test(tc_ffs, test_ffs32_unsafe_0x4);
	tcase_add_test(tc_ffs, test_ffs32_unsafe_0x8);
	tcase_add_test(tc_ffs, test_ffs32_unsafe_0x80);
	tcase_add_test(tc_ffs, test_ffs32_unsafe_0x81);
	tcase_add_test(tc_ffs, test_ffs32_unsafe_0x82);
	tcase_add_test(tc_ffs, test_ffs32_unsafe_0x84);
	tcase_add_test(tc_ffs, test_ffs32_unsafe_0x1000);
	tcase_add_test(tc_ffs, test_ffs32_unsafe_0x80000000);

	tcase_add_test(tc_ffs, test_ffs64_unsafe_0x1);
	tcase_add_test(tc_ffs, test_ffs64_unsafe_0x2);
	tcase_add_test(tc_ffs, test_ffs64_unsafe_0x4);
	tcase_add_test(tc_ffs, test_ffs64_unsafe_0x8);
	tcase_add_test(tc_ffs, test_ffs64_unsafe_0x80);
	tcase_add_test(tc_ffs, test_ffs64_unsafe_0x1000);
	tcase_add_test(tc_ffs, test_ffs64_unsafe_0x80000000);
	tcase_add_test(tc_ffs, test_ffs64_unsafe_0x8000000000000000);

	tcase_add_test(tc_ffs, test_ffs32_0x0);
	tcase_add_test(tc_ffs, test_ffs32_0x80001000);
	tcase_add_test(tc_ffs, test_ffs32_0x80000000);

	tcase_add_test(tc_ffs, test_ffs64_0x0);
	tcase_add_test(tc_ffs, test_ffs64_0x80001000);
	tcase_add_test(tc_ffs, test_ffs64_0x80000000);
	tcase_add_test(tc_ffs, test_ffs64_0x8000000000000000);

	tcase_add_test(tc_ffs, test_fls32_unsafe_0x1);
	tcase_add_test(tc_ffs, test_fls32_unsafe_0x2);
	tcase_add_test(tc_ffs, test_fls32_unsafe_0x4);
	tcase_add_test(tc_ffs, test_fls32_unsafe_0x8);
	tcase_add_test(tc_ffs, test_fls32_unsafe_0x80);
	tcase_add_test(tc_ffs, test_fls32_unsafe_0x81);
	tcase_add_test(tc_ffs, test_fls32_unsafe_0x82);
	tcase_add_test(tc_ffs, test_fls32_unsafe_0x84);
	tcase_add_test(tc_ffs, test_fls32_unsafe_0x80000000);
	tcase_add_test(tc_ffs, test_fls32_unsafe_0x80000001);

	tcase_add_test(tc_ffs, test_fls64_unsafe_0x1);
	tcase_add_test(tc_ffs, test_fls64_unsafe_0x2);
	tcase_add_test(tc_ffs, test_fls64_unsafe_0x4);
	tcase_add_test(tc_ffs, test_fls64_unsafe_0x8);
	tcase_add_test(tc_ffs, test_fls64_unsafe_0x80);
	tcase_add_test(tc_ffs, test_fls64_unsafe_0x81);
	tcase_add_test(tc_ffs, test_fls64_unsafe_0x80000000);
	tcase_add_test(tc_ffs, test_fls64_unsafe_0x80000001);
	tcase_add_test(tc_ffs, test_fls64_unsafe_0x8000000000000000);
	tcase_add_test(tc_ffs, test_fls64_unsafe_0x8000000000000001);

	tcase_add_test(tc_ffs, test_fls32_0x0);
	tcase_add_test(tc_ffs, test_fls32_0x1001);
	tcase_add_test(tc_ffs, test_fls32_0x80000001);

	tcase_add_test(tc_ffs, test_fls64_0x0);
	tcase_add_test(tc_ffs, test_fls64_0x1001);
	tcase_add_test(tc_ffs, test_fls64_0x80000001);
	tcase_add_test(tc_ffs, test_fls64_0x8000000000000001);
	suite_add_tcase(s, tc_ffs);

	return s;
}

