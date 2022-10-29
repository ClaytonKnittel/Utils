
#include <array>

#include <utils/memory/arena.h>

#include "test_utils.h"

using namespace util::memory;

START_TEST(test_one) {
  Arena<uint64_t> a;
  uint64_t* start = a.start();

  ArenaPtr<uint64_t> ptr = a.malloc(100);
  ck_assert(ptr != ArenaPtr<uint64_t>::null());
  ck_assert_ptr_eq(ptr.get(a), start);
  ck_assert_uint_eq(*ptr.get(a), 100);
}
END_TEST

template <uint32_t n_pages>
static void test_uint64_pages() {
  constexpr uint64_t n_ptrs = n_pages * 256 * 1024;
  Arena<uint64_t> a;
  uint64_t* start = a.start();
  std::array<ArenaPtr<uint64_t>, n_ptrs> ptr_list;

  for (uint64_t i = 0; i < n_ptrs; i++) {
    ArenaPtr<uint64_t> ptr = a.malloc(i);
    ck_assert_ptr_eq(ptr.get(a), start + i);
    ck_assert_uint_eq(*ptr.get(a), i);

    ptr_list[i] = ptr;
  }

  for (uint64_t i = 0; i < n_ptrs; i++) {
    ck_assert_uint_eq(*ptr_list[i].get(a), i);
  }
}

START_TEST(test_single_page) {
  test_uint64_pages<1>();
}
END_TEST

START_TEST(test_two_pages) {
  test_uint64_pages<2>();
}
END_TEST

START_TEST(test_ten_pages) {
  test_uint64_pages<10>();
}
END_TEST

Suite* test_arena_cc() {
  TCase* tc_simple;

  Suite* s = suite_create("Arena");

  tc_simple = tcase_create("Simple");
  tcase_set_timeout(tc_simple, 0);
  tcase_add_test(tc_simple, test_one);
  tcase_add_test(tc_simple, test_single_page);
  tcase_add_test(tc_simple, test_two_pages);
  tcase_add_test(tc_simple, test_ten_pages);
  suite_add_tcase(s, tc_simple);

  return s;
}
