#ifndef _RANDOM_H
#define _RANDOM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h>
#include <stdint.h>


// seeds random number generator with given value
void seed_rand(uint64_t init_seed, uint64_t seq_num);


// generates next random number in sequence
uint64_t gen_rand();

// generates a random number from 0 to max - 1
uint32_t gen_rand_r(uint32_t max);


#ifdef __cplusplus
}
#endif

#endif /* _RANDOM_H */
