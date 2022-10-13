#ifndef _RANDOM_H
#define _RANDOM_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rand_state {
  // tracks state of RNG
  uint64_t state;
  // sequence number for RNG (will determine how to get from one state
  // to the next, generates unique sequences for different initial states)
  uint64_t seq_num;
} rand_state_t;

/*
 * Seeds the random number generator using cryptographically secure RNG from the
 * kernel.
 *
 * Returns 0 on success and -1 on failure.
 */
int rand_init(struct rand_state*);

// seeds random number generator with given value
void seed_rand(struct rand_state*, uint64_t init_seed, uint64_t seq_num);

// generates next random number in sequence
uint32_t gen_rand(struct rand_state*);

// same as gen_rand, but gives a 64-bit number
uint64_t gen_rand64(struct rand_state*);

// generates a random number from 0 to max - 1
uint32_t gen_rand_r(struct rand_state*, uint32_t max);

// generates a random number from 0 to max - 1
uint64_t gen_rand_r64(struct rand_state*, uint64_t max);

#ifdef __cplusplus
}

namespace util {

class Random {
 public:
  Random() {
    rand_init(&state_);
  }

  Random(uint64_t seed, uint64_t seq_num) : state_() {
    seed_rand(&state_, seed, seq_num);
  }

  uint32_t rand() {
    return gen_rand(&state_);
  }

  uint64_t rand64() {
    return gen_rand64(&state_);
  }

  uint32_t rand_r(uint32_t max) {
    return gen_rand_r(&state_, max);
  }

  uint64_t rand_r64(uint64_t max) {
    return gen_rand_r64(&state_, max);
  }

 private:
  rand_state_t state_;
};

}  // namespace util

#endif

#endif /* _RANDOM_H */
