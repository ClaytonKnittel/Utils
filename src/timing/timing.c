
#include <timing/timing.h>



double timespec_diff(struct timespec * t1, struct timespec * t2) {
    return (t1->tv_sec - t2->tv_sec)
        + (((double) (t1->tv_nsec - t2->tv_nsec)) / 1000000000.);
}
