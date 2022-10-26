
#include <utils/memory/arena.h>

#include "test_utils.h"

using namespace util::memory;

START_TEST(test_one) {
  Arena<uint64_t> a;
  uint64_t* start = a.start();

  ArenaPtr<uint64_t> ptr = a.malloc(100);
  ck_assert_ptr_eq(ptr.get(a), start);
  ck_assert_uint_eq(*ptr.get(a), 100);
}
END_TEST

START_TEST(test_single_page) {
  Arena<uint64_t> a;
  uint64_t* start = a.start();

  for (uint64_t i = 0; i < 256 * 1024; i++) {
    ArenaPtr<uint64_t> ptr = a.malloc(i);
    ck_assert_ptr_eq(ptr.get(a), start + i);
    ck_assert_uint_eq(*ptr.get(a), i);
  }
}
END_TEST

START_TEST(test_two_pages) {
  Arena<uint64_t> a;
  uint64_t* start = a.start();

  for (uint64_t i = 0; i < 512 * 1024; i++) {
    ArenaPtr<uint64_t> ptr = a.malloc(i);
    ck_assert_ptr_eq(ptr.get(a), start + i);
    ck_assert_uint_eq(*ptr.get(a), i);
  }
}
END_TEST

Suite* test_arena_cc() {
  TCase* tc_simple;

  Suite* s = suite_create("Arena");

  tc_simple = tcase_create("Simple");
  tcase_add_test(tc_simple, test_one);
  tcase_add_test(tc_simple, test_single_page);
  tcase_add_test(tc_simple, test_two_pages);
  suite_add_tcase(s, tc_simple);

  return s;
}
