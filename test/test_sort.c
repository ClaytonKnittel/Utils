
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <utils/algorithms/sort.h>
#include <utils/math/random.h>
#include <utils/timing/timing.h>

#include "test_utils.h"

DEFINE_CSORT_DEFAULT_FNS_NAMED(uint32_t, uint32_t, __default_sort_cmp,
                               __default_sort_cswap)

static uint64_t factorial(uint64_t n) {
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

static int nth_num(uint16_t* bitm, int n) {
  uint16_t mask = 1;
  int cnt = 0;
  while (1) {
    cnt++;
    while (!((*bitm) & mask)) {
      mask <<= 1;
      cnt++;
    }

    if (n == 0) {
      break;
    }
    n--;
    mask <<= 1;
  }
  *bitm &= ~mask;
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

static int run_csort_test(int N) {
  rand_state_t r_state;
  rand_init(&r_state);

  uint32_t* vals = (uint32_t*) malloc(N * sizeof(uint32_t));

  for (uint64_t i = 0; i < 128; i++) {
    for (uint32_t j = 0; j < (uint32_t) N; j++) {
      vals[j] = j;
    }

    for (uint32_t j = 1; j < (uint32_t) N; j++) {
      uint32_t rand_idx = gen_rand_r(&r_state, j + 1);

      uint32_t tmp = vals[j];
      vals[j] = vals[rand_idx];
      vals[rand_idx] = tmp;
    }

    csort_uint32_t(vals, N);
    for (uint32_t j = 0; j < (uint32_t) N; j++) {
      ck_assert_int_eq(vals[j], j);
    }
  }

  free(vals);
  return 1;
}

#if 0
static inline uint64_t bench_insert_sort(int N, void (*sort_alg)(uint32_t*,size_t), uint64_t n_trials, bool check) {
	uint32_t* vals = (uint32_t*) malloc(N * sizeof(uint32_t));
	uint32_t* all  = (uint32_t*) malloc(N * sizeof(uint32_t));

	struct timespec total_time = {
		.tv_sec = 0,
		.tv_nsec = 0
	};

	for (uint64_t i = 0; i < n_trials; i++) {
		for (uint32_t j = 0; j < (uint32_t) N; j++) {
			vals[j] = gen_rand_r(0x7ffffffflu);
			if (check) {
				all[j] = vals[j];
			}
		}
		if (check) {
			naive_sort(all, N);
		}

		struct timespec start, end;
		clock_gettime(CLOCK_MONOTONIC, &start);
		sort_alg(vals, N);
		clock_gettime(CLOCK_MONOTONIC, &end);

		if (check) {
			for (int j = 0; j < N; j++) {
				ck_assert(vals[j] == all[j]);
			}
		}

		timespec_sub(&end, &start);
		timespec_add(&total_time, &end);
	}

	free(all);
	free(vals);

	uint64_t total_ns = total_time.tv_sec * 1000000000lu + total_time.tv_nsec;
	return total_ns;
}
#endif

static void run_const_sort_test(int N) {
  rand_state_t r_state;
  rand_init(&r_state);

  uint32_t* vals = (uint32_t*) malloc(N * sizeof(uint32_t));

  uint64_t n_fact = factorial(N);

  if (N <= 8) {
    for (uint64_t i = 0; i < n_fact; i++) {
      uint16_t mask = 0xffffu;

      uint64_t perm = i;
      for (int j = 0; j < N; j++) {
        int idx = N - 1 - j;
        uint64_t fact = factorial(idx);
        uint64_t k = perm / fact;
        vals[j] = nth_num(&mask, k);
        perm -= k * fact;
      }

      const_sort_uint32_t(vals, N);
      for (int j = 0; j < N; j++) {
        ck_assert(vals[j] == (uint32_t) (j + 1));
      }
    }
  } else if (N <= 16) {
    for (uint64_t i = 0; i < 512; i++) {
      uint16_t mask = 0xffffu;

      uint64_t perm = gen_rand_r64(&r_state, n_fact);
      for (int j = 0; j < N; j++) {
        int idx = N - 1 - j;
        uint64_t fact = factorial(idx);
        uint64_t n = perm / fact;
        vals[j] = nth_num(&mask, n);
        perm -= n * fact;
      }

      const_sort_uint32_t(vals, N);
      for (int j = 0; j < N; j++) {
        ck_assert(vals[j] == (uint32_t) (j + 1));
      }
    }
  }
}

START_TEST(test_const_sort_2) {
  run_const_sort_test(2);
}
END_TEST

START_TEST(test_const_sort_3) {
  run_const_sort_test(3);
}
END_TEST

START_TEST(test_const_sort_4) {
  run_const_sort_test(4);
}
END_TEST

START_TEST(test_const_sort_5) {
  run_const_sort_test(5);
}
END_TEST

START_TEST(test_const_sort_6) {
  run_const_sort_test(6);
}
END_TEST

START_TEST(test_const_sort_7) {
  run_const_sort_test(7);
}
END_TEST

START_TEST(test_const_sort_8) {
  run_const_sort_test(8);
}
END_TEST

START_TEST(test_const_sort_9) {
  run_const_sort_test(9);
}
END_TEST

START_TEST(test_const_sort_10) {
  run_const_sort_test(10);
}
END_TEST

START_TEST(test_const_sort_11) {
  run_const_sort_test(11);
}
END_TEST

START_TEST(test_const_sort_12) {
  run_const_sort_test(12);
}
END_TEST

START_TEST(test_const_sort_13) {
  run_const_sort_test(13);
}
END_TEST

START_TEST(test_const_sort_14) {
  run_const_sort_test(14);
}
END_TEST

START_TEST(test_const_sort_15) {
  run_const_sort_test(15);
}
END_TEST

START_TEST(test_const_sort_16) {
  run_const_sort_test(16);
}
END_TEST

#if 0
START_TEST(test_sort)
{
	uint32_t trials = 50;

	for (uint32_t n = 128000; n <= 512000; n += 128000) {
		uint64_t total_ns;
		total_ns = bench_insert_sort(n, csort_uint32_t, trials, false);
		printf("csort: size %" PRIu32 ":\tavg (ns) %.0f\n", n, total_ns / ((double) trials));
	}
}
END_TEST
#endif

START_TEST(test_64) {
  run_csort_test(64);
}
END_TEST

START_TEST(test_1024) {
  run_csort_test(1024);
}
END_TEST

START_TEST(test_10000) {
  run_csort_test(10000);
}
END_TEST

Suite* test_sort() {
  TCase* tc_const;
  TCase* tc_large;

  Suite* s = suite_create("Sort");

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

  tc_large = tcase_create("Large");
  tcase_add_test(tc_large, test_64);
  tcase_add_test(tc_large, test_1024);
  tcase_add_test(tc_large, test_10000);
  // Disable test timeout
  tcase_set_timeout(tc_large, 0);
  suite_add_tcase(s, tc_large);

  return s;
}
