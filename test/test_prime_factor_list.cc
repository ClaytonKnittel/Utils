
#include <math/prime_factor_list.h>

#include "test_utils.h"


START_TEST(test_basic)
{
	const constexpr uint64_t n = 1000;
	PrimeFactorList primes(n);

	const std::vector<uint64_t>& factors = primes.get_factors();
	for (uint64_t i = 2; i <= n; i++) {
		uint64_t smallest_factor = factors[i];
		ck_assert(i % smallest_factor == 0);

		for (uint64_t j = 2; j < smallest_factor; j++) {
			ck_assert(i % j != 0);
		}
	}

	for (uint64_t i = 2; i <= n; i++) {
		uint64_t val = 1;
		uint64_t prev_factor = 1;

		for (PrimeFactorList::factor_iterator it = primes.factor_begin(i); it != primes.factor_end(); ++it) {
			const std::pair<uint64_t, uint64_t>& f_p = *it;
			ck_assert(prev_factor < f_p.first);

			for (uint64_t j = 0; j < f_p.second; j++) {
				val *= f_p.first;
			}

			prev_factor = f_p.first;
		}

		ck_assert(val == i);
	}
}
END_TEST


Suite*
test_prime_factor_list_cc()
{
	TCase* tc_basic;

	Suite* s = suite_create("Prime Factor List C++");

	tc_basic = tcase_create("Basic");
	tcase_add_test(tc_basic, test_basic);
	suite_add_tcase(s, tc_basic);

	return s;
}

