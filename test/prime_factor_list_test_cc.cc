
#include <math/prime_factor_list.h>

#include "test_utils.h"


int
main(int argc, char* argv[])
{
	const constexpr uint64_t n = 100000;
	PrimeFactorList primes(n);

	const std::vector<uint64_t>& factors = primes.get_factors();
	for (uint64_t i = 2; i <= n; i++) {
		uint64_t smallest_factor = factors[i];
		test_assert(i % smallest_factor == 0);

		for (uint64_t j = 2; j < smallest_factor; j++) {
			test_assert(i % j != 0);
		}
	}

	for (uint64_t i = 2; i <= n; i++) {
		uint64_t val = 1;
		uint64_t prev_factor = 1;

		for (PrimeFactorList::factor_iterator it = primes.factor_begin(i); it != primes.factor_end(); ++it) {
			const std::pair<uint64_t, uint64_t>& f_p = *it;
			test_assert(prev_factor < f_p.first);

			for (uint64_t j = 0; j < f_p.second; j++) {
				val *= f_p.first;
			}

			prev_factor = f_p.first;
		}

		test_assert(val == i);
	}

	return 0;
}
