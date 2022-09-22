
#include <utils/math/prime_factor_list.h>

void PrimeFactorList::_calc_factor_list() {
  factors[1] = 1;
  for (uint64_t i = 2; i <= max; i++) {
    if (factors[i] == 0) {
      for (uint64_t idx = i; idx <= max; idx += i) {
        if (factors[idx] == 0) {
          factors[idx] = i;
        }
      }
    }
  }
}

void PrimeFactorList::factor_iterator::_calc_next_factor() {
  factor_repeats.first = (*factors)[i];
  factor_repeats.second = 0;
  if (factor_repeats.first != 1) {
    do {
      i /= factor_repeats.first;
      factor_repeats.second++;
    } while ((*factors)[i] == factor_repeats.first);
  }
}
