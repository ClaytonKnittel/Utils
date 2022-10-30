
#include <vector>

#include <utils/math/random.h>
#include <utils/memory/arena.h>

#include "test_utils.h"

using namespace util::memory;
using util::math::Random;

START_TEST(test_uint64_one) {
  Arena<uint64_t> a;
  uint64_t* start = a.start();

  ArenaPtr<uint64_t> ptr = a.alloc(100);
  ck_assert(ptr != ArenaPtr<uint64_t>::null());
  ck_assert_ptr_eq(ptr.get(a), start);
  ck_assert_uint_eq(*ptr.get(a), 100);
}
END_TEST

// T must have a constructor T(uint64_t) and define operator==
template <class T>
static void test_uint64_pages(uint32_t n_pages) {
  uint64_t n_ptrs = n_pages * 2 * 1024 * 1024 / sizeof(T);
  Arena<T> a;
  const T* start = a.start();
  std::vector<ArenaPtr<T>> ptr_list;
  ptr_list.reserve(n_ptrs);

  for (uint64_t i = 0; i < n_ptrs; i++) {
    ArenaPtr<T> ptr = a.alloc(i);
    ck_assert(ptr != ArenaPtr<T>::null());
    ck_assert_ptr_eq(ptr.get(a), start + i);
    ck_assert(*ptr.get(a) == T(i));

    ptr_list.push_back(std::move(ptr));
  }

  for (uint64_t i = 0; i < n_ptrs; i++) {
    ck_assert(ptr_list[i] != ArenaPtr<T>::null());
    ck_assert_ptr_eq(ptr_list[i].get(a), start + i);
    ck_assert(*ptr_list[i].get(a) == T(i));
  }
}

START_TEST(test_uint64_single_page) {
  test_uint64_pages<uint64_t>(1);
}
END_TEST

START_TEST(test_uint64_two_pages) {
  test_uint64_pages<uint64_t>(2);
}
END_TEST

START_TEST(test_uint64_ten_pages) {
  test_uint64_pages<uint64_t>(10);
}
END_TEST

class Misaligned {
 private:
  uint16_t b_[19];

 public:
  Misaligned(uint64_t i) {
    (void) i;
    for (uint64_t i = 0; i < 19; i++) {
      b_[i] = static_cast<uint16_t>(i);
    }
  }

  bool operator==(const Misaligned& other) {
    return memcmp(b_, other.b_, sizeof(b_)) == 0;
  }
};

static_assert(sizeof(Misaligned) == 38);

START_TEST(test_misaligned_single_page) {
  test_uint64_pages<Misaligned>(1);
}
END_TEST

START_TEST(test_misaligned_two_pages) {
  test_uint64_pages<Misaligned>(2);
}
END_TEST

START_TEST(test_misaligned_ten_pages) {
  test_uint64_pages<Misaligned>(10);
}
END_TEST

Suite* test_arena_cc() {
  TCase* tc_simple;
  TCase* tc_misaligned;

  Suite* s = suite_create("Arena");

  tc_simple = tcase_create("Simple");
  tcase_set_timeout(tc_simple, 0);
  tcase_add_test(tc_simple, test_uint64_one);
  tcase_add_test(tc_simple, test_uint64_single_page);
  tcase_add_test(tc_simple, test_uint64_two_pages);
  tcase_add_test(tc_simple, test_uint64_ten_pages);
  suite_add_tcase(s, tc_simple);

  tc_misaligned = tcase_create("Misaligned");
  tcase_set_timeout(tc_misaligned, 0);
  tcase_add_test(tc_misaligned, test_misaligned_single_page);
  tcase_add_test(tc_misaligned, test_misaligned_two_pages);
  tcase_add_test(tc_misaligned, test_misaligned_ten_pages);
  suite_add_tcase(s, tc_misaligned);

  return s;
}
