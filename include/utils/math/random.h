#ifndef _RANDOM_H
#define _RANDOM_H

#include <fcntl.h>
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>

#define RAND_FILE_PATH "/dev/urandom"

#ifdef __cplusplus
extern "C" {

#define CXX_CONSTEXPR constexpr
#else
#define CXX_CONSTEXPR
#endif

typedef struct rand_state {
  // tracks state of RNG
  uint64_t state;
  // sequence number for RNG (will determine how to get from one state
  // to the next, generates unique sequences for different initial states)
  uint64_t seq_num;
} rand_state_t;

CXX_CONSTEXPR static uint32_t __rand_hash(uint32_t seed) {
  uint64_t v = (uint64_t) seed;
  v = (~v) + (v << 18);
  v ^= v >> 31;
  v *= 21;
  v &= v >> 11;
  v += v << 6;
  v ^= v >> 22;
  return (uint32_t) v;
}

CXX_CONSTEXPR static uint32_t gen_rand(rand_state_t* state);

// seeds random number generator with given value
CXX_CONSTEXPR static void seed_rand(rand_state_t* state, uint64_t init_seed,
                                    uint64_t seq_num) {
  // hash seed 3 times for maximal randomness!
  state->state = 0LU;
  // sequence number must be odd
  state->seq_num = (seq_num << 1LU) | 1LU;

  gen_rand(state);
  state->state += init_seed;
  gen_rand(state);
}

/*
 * Seeds the random number generator using cryptographically secure RNG from the
 * kernel.
 *
 * Returns 0 on success and -1 on failure.
 */
static int rand_init(rand_state_t* state) {
  uint64_t rand_seed[2];

  int rand_fd = open(RAND_FILE_PATH, O_RDONLY);
  if (rand_fd < 0) {
    return -1;
  }

  ssize_t n_bytes = read(rand_fd, (void*) &rand_seed, sizeof(rand_seed));
  if (n_bytes != sizeof(rand_seed)) {
    return -1;
  }

  close(rand_fd);

  seed_rand(state, rand_seed[0], rand_seed[1]);
  return 0;
}

// generates next random number in sequence
CXX_CONSTEXPR static uint32_t gen_rand(rand_state_t* state) {
  uint64_t prev = state->state;
  state->state = prev * 6364136223846793005ULL + state->seq_num;

  // do some xor stuff
  uint32_t _xor = ((prev >> 18U) ^ prev) >> 27U;
  uint32_t _rot = prev >> 59U;

  // rotate result by "rot"
  return (_xor >> _rot) | (_xor << ((-_rot) & 0x1f));
}

// same as gen_rand, but gives a 64-bit number
CXX_CONSTEXPR static uint64_t gen_rand64(rand_state_t* state) {
  uint32_t r1 = gen_rand(state);
  uint32_t r2 = gen_rand(state);
  return (((uint64_t) r1) << 32) | ((uint64_t) r2);
}

// generates a random number from 0 to max - 1
CXX_CONSTEXPR static uint32_t gen_rand_r(rand_state_t* state, uint32_t max) {
  // equivalent to 0x100000000lu % max, but is done with 32-bit numbers so
  // it's faster
  uint32_t thresh = -max % max;

  // range is limited to thresh and above, to eliminate any bias (i.e. if
  // max is 3, then 0 is not allowed to be chosen, as 0xffffffffffffffff
  // would also give 0 as a result, meaning 0 is slightly more likely to
  // be chosen)
  uint32_t res = 0;
  do {
    res = gen_rand(state);
  } while (__builtin_expect(res < thresh, 0));

  return res % max;
}

// generates a random number from 0 to max - 1
CXX_CONSTEXPR static uint64_t gen_rand_r64(rand_state_t* state, uint64_t max) {
  // mathematically equivalent to 0x10000000000000000lu % max
  uint64_t thresh = -max % max;

  // range is limited to thresh and above, to eliminate any bias (i.e. if
  // max is 3, then 0 is not allowed to be chosen, as 0xffffffffffffffff
  // would also give 0 as a result, meaning 0 is slightly more likely to
  // be chosen)
  uint64_t res = 0;
  do {
    res = gen_rand64(state);
  } while (__builtin_expect(res < thresh, 0));

  return res % max;
}

#ifdef __cplusplus
}

namespace util {

namespace math {

class Random {
 public:
  Random() {
    rand_init(&state_);
  }

  constexpr Random(uint64_t seed, uint64_t seq_num) : state_() {
    seed_rand(&state_, seed, seq_num);
  }

  constexpr uint32_t rand() {
    return gen_rand(&state_);
  }

  constexpr uint64_t rand64() {
    return gen_rand64(&state_);
  }

  constexpr uint32_t rand_r(uint32_t max) {
    return gen_rand_r(&state_, max);
  }

  constexpr uint64_t rand_r64(uint64_t max) {
    return gen_rand_r64(&state_, max);
  }

 private:
  rand_state_t state_;
};

}  // namespace math

}  // namespace util

#endif

#endif /* _RANDOM_H */
