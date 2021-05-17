
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithms/sort.h>
#include <math/random.h>
#include <timing/timing.h>


#define SORT_NAME test
#define SORT_TYPE uint32_t

#define SORT_CMP(x, y) ((int32_t) ((x) - (y)))
#define MAX(x,y) (((x) > (y) ? (x) : (y)))
#define MIN(x,y) (((x) < (y) ? (x) : (y)))
#define SORT_CSWAP(x, y) {SORT_TYPE _sort_swap_temp = MAX((x), (y)); (x) = MIN((x),(y)); (y) = _sort_swap_temp;}

#include "../../OptimizedProxMapSearch/sort/sort.h"


//DEFINE_CONST_SORT_DEFAULT_SWAP(uint32_t);

uint64_t factorial(uint64_t n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}


int nth_num(uint16_t* bitm, int n) {
	uint16_t mask = 1;
	int      cnt  = 0;
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

int check_correctness(int N) {
	uint32_t* vals = (uint32_t*) malloc(N * sizeof(uint32_t));

	uint64_t n_fact = factorial(N);

	if (N <= 8) {
		for (uint64_t i = 0; i < n_fact; i++) {
			uint16_t mask = 0xffffu;

			uint64_t perm = i;
			for (int j = 0; j < N; j++) {
				int      idx  = N - 1 - j;
				uint64_t fact = factorial(idx);
				uint64_t k    = perm / fact;
				vals[j]       = nth_num(&mask, k);
				perm -= k * fact;
			}

			const_sort_uint32_t(N, vals);
			for (int j = 0; j < N; j++) {
				assert(vals[j] == j + 1);
			}
		}
	}
	else {
		for (uint64_t i = 0; i < 65536; i++) {
			uint16_t mask = 0xffffu;

			uint64_t perm = gen_rand_r64(n_fact);
			for (int j = 0; j < N; j++) {
				int      idx  = N - 1 - j;
				uint64_t fact = factorial(idx);
				uint64_t n    = perm / fact;
				vals[j]       = nth_num(&mask, n);
				perm -= n * fact;
			}

			const_sort_uint32_t(N, vals);
			for (int j = 0; j < N; j++) {
				assert(vals[j] == j + 1);
			}
		}
	}

	free(vals);
	return 1;
}


void naive_sort(uint32_t N, uint32_t els[N]) {
	for (uint32_t i = 1; i < N; i++) {
		for (uint32_t j = i; j > 0; j--) {
			if (els[j - 1] > els[j]) {
				uint32_t tmp = els[j];
				els[j] = els[j - 1];
				els[j - 1] = tmp;
			}
			else {
				break;
			}
		}
	}
}


static inline uint64_t bench_insert_sort(int N, void (*sort_alg)(size_t,uint32_t*), uint64_t n_trials) {
	uint32_t* vals = (uint32_t*) malloc(N * sizeof(uint32_t));
	uint32_t* all  = (uint32_t*) malloc(N * sizeof(uint32_t));

	struct timespec total_time = {
		.tv_sec = 0,
		.tv_nsec = 0
	};

	for (uint64_t i = 0; i < n_trials; i++) {
		for (uint32_t j = 0; j < N; j++) {
			vals[j] = gen_rand_r(0x7ffffffflu);
			//vals[j] = gen_rand_r(64);
			all[j] = vals[j];
		}
		naive_sort(N, all);

		struct timespec start, end;
		clock_gettime(CLOCK_MONOTONIC, &start);
		sort_alg(N, vals);
		clock_gettime(CLOCK_MONOTONIC, &end);

		for (int j = 0; j < N; j++) {
			assert(vals[j] == all[j]);
		}

		timespec_sub(&end, &start);
		timespec_add(&total_time, &end);
	}

	uint64_t total_ns = total_time.tv_sec * 1000000000lu + total_time.tv_nsec;
	return total_ns;
}


void call_quick_sort(size_t N, uint32_t els[N]) {
	test_quick_sort(els, N);
}

void call_tim_sort(size_t N, uint32_t els[N]) {
	test_tim_sort(els, N);
}

int main(int argc, char * argv[]) {
	/*
	for (int N = 2; N <= 16; N++) {
		printf("(C) testing %d\n", N);
		check_correctness(N);
	}
	*/
	uint32_t trials = 50000;

	for (uint32_t n = 128; n <= 512; n += 128) {
		uint64_t total_ns;
		//total_ns = bench_insert_sort(n, linear_insertion_sort, trials);
		//printf("lin: size %" PRIu32 ":\tavg (ns) %.0f\n", n, total_ns / ((double) trials));
		total_ns = bench_insert_sort(n, csort_uint32_t, trials);
		printf("c: size %" PRIu32 ":\tavg (ns) %.0f\n", n, total_ns / ((double) trials));
		total_ns = bench_insert_sort(n, call_quick_sort, trials);
		printf("q: size %" PRIu32 ":\tavg (ns) %.0f\n\n", n, total_ns / ((double) trials));
	}

	return 0;
}
