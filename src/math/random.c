
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>

#include <utils/math/random.h>

#define RAND_FILE_PATH "/dev/urandom"

uint32_t __rand_hash(uint32_t seed) {
  uint64_t v = (uint64_t) seed;
  v = (~v) + (v << 18);
  v ^= v >> 31;
  v *= 21;
  v &= v >> 11;
  v += v << 6;
  v ^= v >> 22;
  return (uint32_t) v;
}

int rand_init(struct rand_state* state) {
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

void seed_rand(struct rand_state* state, uint64_t init_seed, uint64_t seq_num) {
  // hash seed 3 times for maximal randomness!
  state->state = 0LU;
  // sequence number must be odd
  state->seq_num = (seq_num << 1LU) | 1LU;

  gen_rand(state);
  state->state += init_seed;
  gen_rand(state);
}

uint32_t gen_rand(struct rand_state* state) {
  uint64_t prev = state->state;
  state->state = prev * 6364136223846793005ULL + state->seq_num;

  // do some xor stuff
  uint32_t xor = ((prev >> 18U) ^ prev) >> 27U;
  uint32_t rot = prev >> 59U;

  // rotate result by "rot"
  return (xor >> rot) | (xor << ((-rot) & 0x1f));
}

uint64_t gen_rand64(struct rand_state* state) {
  uint32_t r1 = gen_rand(state);
  uint32_t r2 = gen_rand(state);
  return (((uint64_t) r1) << 32) | ((uint64_t) r2);
}

uint32_t gen_rand_r(struct rand_state* state, uint32_t max) {
  // equivalent to 0x100000000lu % max, but is done with 32-bit numbers so
  // it's faster
  uint32_t thresh = -max % max;

  // range is limited to thresh and above, to eliminate any bias (i.e. if
  // max is 3, then 0 is not allowed to be chosen, as 0xffffffffffffffff
  // would also give 0 as a result, meaning 0 is slightly more likely to
  // be chosen)
  uint32_t res;
  do {
    res = gen_rand(state);
  } while (__builtin_expect(res < thresh, 0));

  return res % max;
}

uint64_t gen_rand_r64(struct rand_state* state, uint64_t max) {
  // mathematically equivalent to 0x10000000000000000lu % max
  uint64_t thresh = -max % max;

  // range is limited to thresh and above, to eliminate any bias (i.e. if
  // max is 3, then 0 is not allowed to be chosen, as 0xffffffffffffffff
  // would also give 0 as a result, meaning 0 is slightly more likely to
  // be chosen)
  uint64_t res;
  do {
    res = gen_rand64(state);
  } while (__builtin_expect(res < thresh, 0));

  return res % max;
}
