
#include <cassert>
#include <cstdio>
#include <cstdlib>

#include <utils/algorithms/sort.h>
#include <utils/math/random.h>

#include "test_utils.h"

static constexpr uint64_t factorial(uint64_t n) {
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

static int nth_num(uint16_t& bitm, int n) {
  uint16_t mask = 1;
  int cnt = 0;
  while (1) {
    cnt++;
    while (!(bitm & mask)) {
      mask <<= 1;
      cnt++;
    }

    if (n == 0) {
      break;
    }
    n--;
    mask <<= 1;
  }
  bitm &= ~mask;
  return cnt;
}

static void naive_sort(uint32_t* els, uint32_t N) {
  for (uint32_t i = 1; i < N; i++) {
    for (uint32_t j = i; j > 0; j--) {
      if (els[j - 1] > els[j]) {
        uint32_t tmp = els[j];
        els[j] = els[j - 1];
        els[j - 1] = tmp;
      } else {
        break;
      }
    }
  }
}

template <int N>
bool run_const_sort_test() {
  uint32_t vals[N];

  uint64_t n_fact = factorial(N);

  if constexpr (N <= 8) {
    for (uint64_t i = 0; i < n_fact; i++) {
      uint16_t mask = 0xffffu;

      uint64_t perm = i;
      for (int j = 0; j < N; j++) {
        int idx = N - 1 - j;
        uint64_t fact = factorial(idx);
        uint64_t k = perm / fact;
        vals[j] = nth_num(mask, k);
        perm -= k * fact;
      }

      util::const_sort<uint32_t, N>(vals);
      for (uint32_t j = 0; j < N; j++) {
        assert(vals[j] == j + 1);
      }
    }
  } else {
    for (uint64_t i = 0; i < 512; i++) {
      uint16_t mask = 0xffffu;

      uint64_t perm = gen_rand_r64(n_fact);
      for (int j = 0; j < N; j++) {
        int idx = N - 1 - j;
        uint64_t fact = factorial(idx);
        uint64_t n = perm / fact;
        vals[j] = nth_num(mask, n);
        perm -= n * fact;
      }

      util::const_sort<uint32_t, N>(vals);
      for (uint32_t j = 0; j < N; j++) {
        assert(vals[j] == j + 1);
      }
    }
  }
  return true;
}

static int run_csort_test(int N) {
  uint32_t* vals = (uint32_t*) malloc(N * sizeof(uint32_t));
  uint32_t* all = (uint32_t*) malloc(N * sizeof(uint32_t));

  for (uint64_t i = 0; i < 1024; i++) {
    for (uint32_t j = 0; j < (uint32_t) N; j++) {
      vals[j] = gen_rand_r(0x7ffffffflu);
      all[j] = vals[j];
    }
    naive_sort(all, N);
    // TODO implement
    // util::csort<uint32_t>(vals, N);
    for (uint32_t j = 0; j < (uint32_t) N; j++) {
      ck_assert(vals[j] == all[j]);
    }
  }

  free(all);
  free(vals);
  return 1;
}

START_TEST(test_const_sort_2) {
  run_const_sort_test<2>();
}
END_TEST

START_TEST(test_const_sort_3) {
  run_const_sort_test<3>();
}
END_TEST

START_TEST(test_const_sort_4) {
  run_const_sort_test<4>();
}
END_TEST

START_TEST(test_const_sort_5) {
  run_const_sort_test<5>();
}
END_TEST

START_TEST(test_const_sort_6) {
  run_const_sort_test<6>();
}
END_TEST

START_TEST(test_const_sort_7) {
  run_const_sort_test<7>();
}
END_TEST

START_TEST(test_const_sort_8) {
  run_const_sort_test<8>();
}
END_TEST

START_TEST(test_const_sort_9) {
  run_const_sort_test<9>();
}
END_TEST

START_TEST(test_const_sort_10) {
  run_const_sort_test<10>();
}
END_TEST

START_TEST(test_const_sort_11) {
  run_const_sort_test<11>();
}
END_TEST

START_TEST(test_const_sort_12) {
  run_const_sort_test<12>();
}
END_TEST

START_TEST(test_const_sort_13) {
  run_const_sort_test<13>();
}
END_TEST

START_TEST(test_const_sort_14) {
  run_const_sort_test<14>();
}
END_TEST

START_TEST(test_const_sort_15) {
  run_const_sort_test<15>();
}
END_TEST

START_TEST(test_const_sort_16) {
  run_const_sort_test<16>();
}
END_TEST

/*START_TEST(test_64)
{
        run_csort_test(64);
}
END_TEST*/

Suite* test_sort_cc() {
  TCase* tc_const;
  // TCase* tc_large;

  Suite* s = suite_create("Sort C++");

  tc_const = tcase_create("Const");
  tcase_add_test(tc_const, test_const_sort_2);
  tcase_add_test(tc_const, test_const_sort_3);
  tcase_add_test(tc_const, test_const_sort_4);
  tcase_add_test(tc_const, test_const_sort_5);
  tcase_add_test(tc_const, test_const_sort_6);
  tcase_add_test(tc_const, test_const_sort_7);
  tcase_add_test(tc_const, test_const_sort_8);
  tcase_add_test(tc_const, test_const_sort_9);
  tcase_add_test(tc_const, test_const_sort_10);
  tcase_add_test(tc_const, test_const_sort_11);
  tcase_add_test(tc_const, test_const_sort_12);
  tcase_add_test(tc_const, test_const_sort_13);
  tcase_add_test(tc_const, test_const_sort_14);
  tcase_add_test(tc_const, test_const_sort_15);
  tcase_add_test(tc_const, test_const_sort_16);
  suite_add_tcase(s, tc_const);

  /*tc_large = tcase_create("Large");
  tcase_add_test(tc_const, test_64);
  suite_add_tcase(s, tc_large);*/

  return s;
}
