
#include <stdio.h>

#include <data_structs/vector.h>

#include "test_utils.h"


int
main(int argc, char* argv[])
{
	vector_t v;
	vector_init(&v, sizeof(uint64_t), 8);

	uint64_t lowb = 1022;
	uint64_t uppb = 3086;

	for (uint64_t j = lowb; j < uppb; j++) {
		vector_push(&v, &j);
	}

	for (uint64_t i = 0; i < uppb - lowb; i++) {
		test_assert(*(uint64_t*) vector_get(&v, i) == i + lowb);
	}

	for (uint64_t j = 0; j < (uppb - lowb) * 10 / 11; j += 10) {
		vector_remove(&v, j);
	}

	for (uint64_t i = 0; i < (uppb - lowb) * 10 / 11; i++) {
		test_assert(*(uint64_t*) vector_get(&v, i) == (i * 11 / 10) + lowb + 1);
	}

	vector_free(&v);

	return 0;
}

