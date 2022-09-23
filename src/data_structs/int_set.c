
#include <stdlib.h>
#include <string.h>

#include <utils/data_structs/int_set.h>

int int_set_init(int_set_t* iset, uint64_t max) {
  if (max > INT_SET_MAX_SIZE) {
    return -1;
  }
  *iset = (int_set_t) calloc(INT_SET_GET_SIZE(max), sizeof(uint64_t));

  if (*iset == NULL) {
    return -1;
  }
  return 0;
}

void int_set_free(int_set_t iset) {
  free(iset);
}

void int_set_clear(int_set_t iset, uint64_t max) {
  memset(iset, 0, INT_SET_GET_SIZE(max) * sizeof(uint64_t));
}

bool int_set_contains(int_set_t iset, uint64_t val) {
  uint64_t idx = val / INT_SET_ENTRY_BITS;
  uint64_t bit_idx = val % INT_SET_ENTRY_BITS;

  return (iset[idx] & (1LU << bit_idx)) != 0;
}

void int_set_insert(int_set_t iset, uint64_t val) {
  uint64_t idx = val / INT_SET_ENTRY_BITS;
  uint64_t bit_idx = val % INT_SET_ENTRY_BITS;

  iset[idx] |= (1LU << bit_idx);
}

void int_set_remove(int_set_t iset, uint64_t val) {
  uint64_t idx = val / INT_SET_ENTRY_BITS;
  uint64_t bit_idx = val % INT_SET_ENTRY_BITS;

  iset[idx] &= ~(1LU << bit_idx);
}
