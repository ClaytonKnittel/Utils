
#include <assert.h>

#include <math/prime_factor_list.h>

int
main(int argc, char* argv[])
{
	const uint64_t n = 500000;
	prime_factor_list_t list;
	prime_factor_list_init(&list, n);

	for (uint64_t i = 2; i <= n; i++) {
		uint64_t smallest_factor = list.factors[i];
		assert(i % smallest_factor == 0);

		for (uint64_t j = 2; j < smallest_factor; j++) {
			assert(i % j != 0);
		}
	}

	for (uint64_t i = 2; i <= n; i++) {
		uint64_t val = 1;
		uint64_t prev_factor = 1;

		FOR_EACH_PRIME_FACTOR(list, i, factor, repeats) {
			assert(prev_factor < factor);

			for (uint64_t j = 0; j < repeats; j++) {
				val *= factor;
			}

			prev_factor = factor;
		}
		FOR_EACH_PRIME_FACTOR_END

		assert(val == i);
	}

	prime_factor_list_free(&list);

	return 0;
}

