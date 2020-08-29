#ifndef _TIMING_H
#define _TIMING_H

#ifdef __cplusplus
extern "C" {
#endif


#include <time.h>


double timespec_diff(struct timespec * t1, struct timespec * t2);


#ifdef __cplusplus
}
#endif

#endif /* _TIMING_H */
