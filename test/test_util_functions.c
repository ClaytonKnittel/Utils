
#include <utils/utils.h>

#include "test_utils.h"

START_TEST(test_align_up_pow2) {
  ck_assert_int_eq(ALIGN_UP(0x100, 0x10), 0x100);
}
END_TEST

START_TEST(test_align_up_pow2_minus_1) {
  ck_assert_int_eq(ALIGN_UP(0x0ff, 0x10), 0x100);
}
END_TEST

START_TEST(test_align_up_pow2_plus_1) {
  ck_assert_int_eq(ALIGN_UP(0x0f1, 0x10), 0x100);
}
END_TEST

START_TEST(test_align_down_pow2) {
  ck_assert_int_eq(ALIGN_DOWN(0x100, 0x10), 0x100);
}
END_TEST

START_TEST(test_align_down_pow2_minus_1) {
  ck_assert_int_eq(ALIGN_DOWN(0x10f, 0x10), 0x100);
}
END_TEST

START_TEST(test_align_down_pow2_plus_1) {
  ck_assert_int_eq(ALIGN_DOWN(0x101, 0x10), 0x100);
}
END_TEST

#define DEFINE_UNARY_TEST(fn, in, out) \
  START_TEST(test_##fn##_##in) {       \
    ck_assert_int_eq(fn(in), out);     \
  }                                    \
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

DEFINE_UNARY_TEST(next_pow2_unsafe, 0x1, 0x1)
DEFINE_UNARY_TEST(next_pow2_unsafe, 0x2, 0x2)
DEFINE_UNARY_TEST(next_pow2_unsafe, 0x3, 0x4)
DEFINE_UNARY_TEST(next_pow2_unsafe, 0x70, 0x80)
DEFINE_UNARY_TEST(next_pow2_unsafe, 0x100, 0x100)
DEFINE_UNARY_TEST(next_pow2_unsafe, 0x1ff, 0x200)
DEFINE_UNARY_TEST(next_pow2_unsafe, 0x7fffffff, 0x80000000)

DEFINE_UNARY_TEST(next_pow2l_unsafe, 0x1, 0x1)
DEFINE_UNARY_TEST(next_pow2l_unsafe, 0x2, 0x2)
DEFINE_UNARY_TEST(next_pow2l_unsafe, 0x3, 0x4)
DEFINE_UNARY_TEST(next_pow2l_unsafe, 0x70, 0x80)
DEFINE_UNARY_TEST(next_pow2l_unsafe, 0x100, 0x100)
DEFINE_UNARY_TEST(next_pow2l_unsafe, 0x1ff, 0x200)
DEFINE_UNARY_TEST(next_pow2l_unsafe, 0x7fffffff, 0x80000000)
DEFINE_UNARY_TEST(next_pow2l_unsafe, 0x7fffffffffffffff, 0x8000000000000000)

DEFINE_UNARY_TEST(next_pow2, 0x0, 0x0)
DEFINE_UNARY_TEST(next_pow2, 0x1, 0x1)
DEFINE_UNARY_TEST(next_pow2, 0x2, 0x2)
DEFINE_UNARY_TEST(next_pow2, 0x3, 0x4)
DEFINE_UNARY_TEST(next_pow2, 0x7fffffff, 0x80000000)

DEFINE_UNARY_TEST(next_pow2l, 0x0, 0x0)
DEFINE_UNARY_TEST(next_pow2l, 0x1, 0x1)
DEFINE_UNARY_TEST(next_pow2l, 0x2, 0x2)
DEFINE_UNARY_TEST(next_pow2l, 0x3, 0x4)
DEFINE_UNARY_TEST(next_pow2l, 0x7fffffff, 0x80000000)
DEFINE_UNARY_TEST(next_pow2l, 0x7fffffffffffffff, 0x8000000000000000)

DEFINE_UNARY_TEST(ceil_log10, 0, 0)
DEFINE_UNARY_TEST(ceil_log10, 1, 1)
DEFINE_UNARY_TEST(ceil_log10, 9, 1)
DEFINE_UNARY_TEST(ceil_log10, 10, 2)
DEFINE_UNARY_TEST(ceil_log10, 99, 2)
DEFINE_UNARY_TEST(ceil_log10, 100, 3)
DEFINE_UNARY_TEST(ceil_log10, 999, 3)
DEFINE_UNARY_TEST(ceil_log10, 1000, 4)
DEFINE_UNARY_TEST(ceil_log10, 9999, 4)
DEFINE_UNARY_TEST(ceil_log10, 10000, 5)
DEFINE_UNARY_TEST(ceil_log10, 99999, 5)
DEFINE_UNARY_TEST(ceil_log10, 100000, 6)
DEFINE_UNARY_TEST(ceil_log10, 999999, 6)
DEFINE_UNARY_TEST(ceil_log10, 1000000, 7)
DEFINE_UNARY_TEST(ceil_log10, 9999999, 7)
DEFINE_UNARY_TEST(ceil_log10, 10000000, 8)
DEFINE_UNARY_TEST(ceil_log10, 99999999, 8)
DEFINE_UNARY_TEST(ceil_log10, 100000000, 9)
DEFINE_UNARY_TEST(ceil_log10, 999999999, 9)
DEFINE_UNARY_TEST(ceil_log10, 1000000000, 10)
DEFINE_UNARY_TEST(ceil_log10, 4294967295, 10)

DEFINE_UNARY_TEST(ceil_log10l, 0, 0)
DEFINE_UNARY_TEST(ceil_log10l, 1, 1)
DEFINE_UNARY_TEST(ceil_log10l, 9, 1)
DEFINE_UNARY_TEST(ceil_log10l, 10, 2)
DEFINE_UNARY_TEST(ceil_log10l, 99, 2)
DEFINE_UNARY_TEST(ceil_log10l, 100, 3)
DEFINE_UNARY_TEST(ceil_log10l, 999, 3)
DEFINE_UNARY_TEST(ceil_log10l, 1000, 4)
DEFINE_UNARY_TEST(ceil_log10l, 9999, 4)
DEFINE_UNARY_TEST(ceil_log10l, 10000, 5)
DEFINE_UNARY_TEST(ceil_log10l, 99999, 5)
DEFINE_UNARY_TEST(ceil_log10l, 100000, 6)
DEFINE_UNARY_TEST(ceil_log10l, 999999, 6)
DEFINE_UNARY_TEST(ceil_log10l, 1000000, 7)
DEFINE_UNARY_TEST(ceil_log10l, 9999999, 7)
DEFINE_UNARY_TEST(ceil_log10l, 10000000, 8)
DEFINE_UNARY_TEST(ceil_log10l, 99999999, 8)
DEFINE_UNARY_TEST(ceil_log10l, 100000000, 9)
DEFINE_UNARY_TEST(ceil_log10l, 999999999, 9)
DEFINE_UNARY_TEST(ceil_log10l, 1000000000, 10)
DEFINE_UNARY_TEST(ceil_log10l, 9999999999, 10)
DEFINE_UNARY_TEST(ceil_log10l, 10000000000, 11)
DEFINE_UNARY_TEST(ceil_log10l, 99999999999, 11)
DEFINE_UNARY_TEST(ceil_log10l, 100000000000, 12)
DEFINE_UNARY_TEST(ceil_log10l, 999999999999, 12)
DEFINE_UNARY_TEST(ceil_log10l, 1000000000000, 13)
DEFINE_UNARY_TEST(ceil_log10l, 9999999999999, 13)
DEFINE_UNARY_TEST(ceil_log10l, 10000000000000, 14)
DEFINE_UNARY_TEST(ceil_log10l, 99999999999999, 14)
DEFINE_UNARY_TEST(ceil_log10l, 100000000000000, 15)
DEFINE_UNARY_TEST(ceil_log10l, 999999999999999, 15)
DEFINE_UNARY_TEST(ceil_log10l, 1000000000000000, 16)
DEFINE_UNARY_TEST(ceil_log10l, 9999999999999999, 16)
DEFINE_UNARY_TEST(ceil_log10l, 10000000000000000, 17)
DEFINE_UNARY_TEST(ceil_log10l, 99999999999999999, 17)
DEFINE_UNARY_TEST(ceil_log10l, 100000000000000000, 18)
DEFINE_UNARY_TEST(ceil_log10l, 999999999999999999, 18)
DEFINE_UNARY_TEST(ceil_log10l, 1000000000000000000, 19)
DEFINE_UNARY_TEST(ceil_log10l, 9999999999999999999u, 19)
DEFINE_UNARY_TEST(ceil_log10l, 10000000000000000000u, 20)
DEFINE_UNARY_TEST(ceil_log10l, 18446744073709551615u, 20)

START_TEST(test_boolstr_false) {
  ck_assert_str_eq(boolstr(false), "false");
}
END_TEST

START_TEST(test_boolstr_true) {
  ck_assert_str_eq(boolstr(true), "true");
}
END_TEST

START_TEST(test_boolstr_large) {
  ck_assert_str_eq(boolstr(1234), "true");
}
END_TEST

Suite* test_utils() {
  TCase* tc_align;
  TCase* tc_ffs;
  TCase* tc_next_pow2;
  TCase* tc_ceil_log10;
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

  tc_next_pow2 = tcase_create("Next power of 2");
  tcase_add_test(tc_next_pow2, test_next_pow2_unsafe_0x1);
  tcase_add_test(tc_next_pow2, test_next_pow2_unsafe_0x2);
  tcase_add_test(tc_next_pow2, test_next_pow2_unsafe_0x3);
  tcase_add_test(tc_next_pow2, test_next_pow2_unsafe_0x70);
  tcase_add_test(tc_next_pow2, test_next_pow2_unsafe_0x100);
  tcase_add_test(tc_next_pow2, test_next_pow2_unsafe_0x1ff);
  tcase_add_test(tc_next_pow2, test_next_pow2_unsafe_0x7fffffff);

  tcase_add_test(tc_next_pow2, test_next_pow2l_unsafe_0x1);
  tcase_add_test(tc_next_pow2, test_next_pow2l_unsafe_0x2);
  tcase_add_test(tc_next_pow2, test_next_pow2l_unsafe_0x3);
  tcase_add_test(tc_next_pow2, test_next_pow2l_unsafe_0x70);
  tcase_add_test(tc_next_pow2, test_next_pow2l_unsafe_0x100);
  tcase_add_test(tc_next_pow2, test_next_pow2l_unsafe_0x1ff);
  tcase_add_test(tc_next_pow2, test_next_pow2l_unsafe_0x7fffffff);
  tcase_add_test(tc_next_pow2, test_next_pow2l_unsafe_0x7fffffffffffffff);

  tcase_add_test(tc_next_pow2, test_next_pow2_0x0);
  tcase_add_test(tc_next_pow2, test_next_pow2_0x1);
  tcase_add_test(tc_next_pow2, test_next_pow2_0x2);
  tcase_add_test(tc_next_pow2, test_next_pow2_0x3);
  tcase_add_test(tc_next_pow2, test_next_pow2_0x7fffffff);

  tcase_add_test(tc_next_pow2, test_next_pow2l_0x0);
  tcase_add_test(tc_next_pow2, test_next_pow2l_0x1);
  tcase_add_test(tc_next_pow2, test_next_pow2l_0x2);
  tcase_add_test(tc_next_pow2, test_next_pow2l_0x3);
  tcase_add_test(tc_next_pow2, test_next_pow2l_0x7fffffff);
  tcase_add_test(tc_next_pow2, test_next_pow2l_0x7fffffffffffffff);
  suite_add_tcase(s, tc_next_pow2);

  tc_ceil_log10 = tcase_create("ceil(log10(x))");
  tcase_add_test(tc_ceil_log10, test_ceil_log10_0);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_1);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_9);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_10);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_99);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_100);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_1000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_9999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_10000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_99999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_100000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_1000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_9999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_10000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_99999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_100000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_999999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_1000000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10_4294967295);

  tcase_add_test(tc_ceil_log10, test_ceil_log10l_0);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_1);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_9);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_10);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_99);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_100);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_1000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_9999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_10000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_99999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_100000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_1000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_9999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_10000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_99999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_100000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_999999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_1000000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_9999999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_10000000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_99999999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_100000000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_999999999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_1000000000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_9999999999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_10000000000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_99999999999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_100000000000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_999999999999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_1000000000000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_9999999999999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_10000000000000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_99999999999999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_100000000000000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_999999999999999999);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_1000000000000000000);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_9999999999999999999u);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_10000000000000000000u);
  tcase_add_test(tc_ceil_log10, test_ceil_log10l_18446744073709551615u);
  suite_add_tcase(s, tc_ceil_log10);

  tc_boolstr = tcase_create("boolstr");
  tcase_add_test(tc_boolstr, test_boolstr_false);
  tcase_add_test(tc_boolstr, test_boolstr_true);
  tcase_add_test(tc_boolstr, test_boolstr_large);
  suite_add_tcase(s, tc_boolstr);

  return s;
}
