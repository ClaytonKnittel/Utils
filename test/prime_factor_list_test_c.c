
#include <assert.h>

#include <math/prime_factor_list.h>

int
main(int argc, char* argv[])
{
	const uint64_t n = 100000;
	prime_factor_list_t list;
	prime_factor_list_init(&list, n);

	for (uint64_t i = 2; i <= n; i++) {
		assert(list.factors[i] > 1);
	}

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


	const uint64_t n_primes = 168;

	uint64_t primes[n_primes] = {
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
		67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137,
		139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211,
		223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283,
		293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379,
		383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461,
		463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563,
		569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,
		647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739,
		743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829,
		839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937,
		941, 947, 953, 967, 971, 977, 983, 991, 997
	};

	uint64_t i = 0;
	FOR_EACH_PRIME(list, prime) {
		assert(prime == primes[i]);
		i++;
		if (i == n_primes) {
			break;
		}
	}
	FOR_EACH_PRIME_END

	prime_factor_list_free(&list);

	return 0;
}

