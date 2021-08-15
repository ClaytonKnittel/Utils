
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include <data_structs/int_set.h>

int
main(int argc, char* argv[])
{
	uint64_t n = 1000;
	uint64_t max = 0x1000000;

	uint64_t* nums = (uint64_t*) malloc(n * sizeof(uint64_t));
	assert(nums != NULL);

	int_set_t set;
	assert(int_set_init(&set, max) == 0);

	for (uint64_t i = 0; i < n; i++) {
		nums[i] = rand() % max;
		int_set_insert(set, nums[i]);
	}

	INT_SET_FOREACH(set, max, i) {
		int found = 0;
		for (uint64_t j = 0; j < n; j++) {
			if (nums[j] == i) {
				nums[j] = -1;
				found = 1;
			}
		}
		assert(found);
	}
	INT_SET_FOREACH_END;

	free(nums);
	int_set_free(set);

	return 0;
}

