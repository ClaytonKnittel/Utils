#ifndef _PRIME_FACTOR_LIST_H
#define _PRIME_FACTOR_LIST_H

#ifndef __cplusplus

#include <stdint.h>

typedef struct prime_factor_list {
  uint64_t* factors;
  uint64_t max;
} prime_factor_list_t;

int prime_factor_list_init(prime_factor_list_t*, uint64_t max);

void prime_factor_list_free(prime_factor_list_t*);

// clang-format off
#define FOR_EACH_PRIME_FACTOR(pf_list, n, factor, pow) \
  for (uint64_t __i = n; __i > 1;) {                   \
    uint64_t factor = (pf_list).factors[__i];          \
    uint64_t pow = 0;                                  \
    do {                                               \
      __i /= factor;                                   \
      pow++;                                           \
    } while ((pf_list).factors[__i] == factor);

#define FOR_EACH_PRIME_FACTOR_END \
  }

#define FOR_EACH_PRIME(pf_list, prime)                        \
  for (uint64_t prime = 2; prime <= (pf_list).max; prime++) { \
    if ((pf_list).factors[prime] == prime) {
#define FOR_EACH_PRIME_END \
    }                      \
  }
// clang-format on

#else /* __cplusplus */

#include <cstdint>
#include <vector>

class PrimeFactorList {
 private:
  // list of smallest factors of each number >= 1
  std::vector<uint64_t> factors;
  uint64_t max;

  void _calc_factor_list();

 public:
  PrimeFactorList(uint64_t max) : factors(max + 1), max(max) {
    this->_calc_factor_list();
  }

  ~PrimeFactorList() {}

  const std::vector<uint64_t>& get_factors() const {
    return factors;
  }

  class factor_iterator {
   private:
    uint64_t i;
    std::pair<uint64_t, uint64_t> factor_repeats;

    const std::vector<uint64_t>* factors;

    void _calc_next_factor();

   public:
    factor_iterator(uint64_t n, const std::vector<uint64_t>* factors)
        : i(n), factors(factors) {
      _calc_next_factor();
    }

    // used only for factor_end()
    constexpr factor_iterator(const uint64_t n)
        : i(n), factor_repeats({1, 0}), factors(nullptr) {}

    factor_iterator& operator++() {
      _calc_next_factor();
      return *this;
    }

    bool operator==(const factor_iterator& f) const {
      return factor_repeats == f.factor_repeats;
    }

    bool operator!=(const factor_iterator& f) const {
      return factor_repeats != f.factor_repeats;
    }

    const std::pair<uint64_t, uint64_t>& operator*() const {
      return factor_repeats;
    }
  };

  factor_iterator factor_begin(uint64_t n) const {
    return factor_iterator(n, &factors);
  }

  constexpr const factor_iterator factor_end() const {
    return factor_iterator(1);
  }
};

#endif /* __cplusplus */

#endif /* _PRIME_FACTOR_LIST_H */
