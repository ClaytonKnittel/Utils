
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <algorithms/sort.h>
#include <math/random.h>


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

DEFINE_CONST_SORT(uint32_t);

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


int main(int argc, char * argv[]) {
	for (int N = 2; N <= 16; N++) {
		printf("(C) testing %d\n", N);
		check_correctness(N);
	}

	return 0;
}
