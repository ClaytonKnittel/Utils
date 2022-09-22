#ifndef _TIMING_H
#define _TIMING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>

// returns the difference of two timespecs in seconds
double timespec_diff(struct timespec* start, struct timespec* end);

// adds t to dst
void timespec_add(struct timespec* dst, struct timespec* t);

// subtracts t from dst
void timespec_sub(struct timespec* dst, struct timespec* t);

#ifdef __cplusplus
}
#endif

#endif /* _TIMING_H */
