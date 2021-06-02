
#include <stdlib.h>

#include <data_structs/int_set.h>


int
int_set_init(int_set_t* iset, uint64_t max)
{
	*iset = (int_set_t) calloc(INT_SET_GET_SIZE(max), sizeof(uint64_t));
	return 0;
}

void
int_set_free(int_set_t iset)
{
	free(iset);
}

bool
int_set_contains(int_set_t iset, uint64_t val)
{
	uint64_t idx = val / INT_SET_ENTRY_BITS;
	uint64_t bit_idx = val % INT_SET_ENTRY_BITS;

	return (iset[idx] & (1LU << bit_idx)) != 0;
}

void
int_set_insert(int_set_t iset, uint64_t val)
{
	uint64_t idx = val / INT_SET_ENTRY_BITS;
	uint64_t bit_idx = val % INT_SET_ENTRY_BITS;

	iset[idx] |= (1LU << bit_idx);
}

void
int_set_remove(int_set_t iset, uint64_t val)
{
	uint64_t idx = val / INT_SET_ENTRY_BITS;
	uint64_t bit_idx = val % INT_SET_ENTRY_BITS;

	iset[idx] &= ~(1LU << bit_idx);
}


