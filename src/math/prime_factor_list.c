
#include <stdlib.h>

#include <utils/math/prime_factor_list.h>

static void _calc_factor_list(prime_factor_list_t* l) {
  uint64_t max = l->max;
  l->factors[1] = 1;
  for (uint64_t i = 2; i <= l->max; i++) {
    if (l->factors[i] == 0) {
      for (uint64_t idx = i; idx <= max; idx += i) {
        if (l->factors[idx] == 0) {
          l->factors[idx] = i;
        }
      }
    }
  }
}

int prime_factor_list_init(prime_factor_list_t* l, uint64_t max) {
  l->factors = (uint64_t*)calloc((max + 1), sizeof(uint64_t));
  if (l->factors == NULL) {
    return -1;
  }
  l->max = max;

  _calc_factor_list(l);

  return 0;
}

void prime_factor_list_free(prime_factor_list_t* l) {
  free(l->factors);
}
