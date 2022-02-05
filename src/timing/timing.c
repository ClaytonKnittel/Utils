
#include <stdint.h>

#include <utils/timing/timing.h>


double timespec_diff(struct timespec* start, struct timespec* end) {
    return (end->tv_sec - start->tv_sec)
        + (((double) (end->tv_nsec - start->tv_nsec)) / 1000000000.);
}

void timespec_add(struct timespec* dst, struct timespec* t)
{
	dst->tv_nsec += t->tv_nsec;
	uint64_t secs = dst->tv_nsec / 1000000000lu;
	dst->tv_nsec %= 1000000000lu;
	dst->tv_sec += t->tv_sec + secs;
}

#include <assert.h>
void timespec_sub(struct timespec* dst, struct timespec* t)
{
	dst->tv_nsec += 1000000000lu - t->tv_nsec;
	uint64_t secs = (dst->tv_nsec / 1000000000lu) - 1;
	dst->tv_nsec %= 1000000000lu;
	dst->tv_sec -= t->tv_sec - secs;
}

