
#include <util/util.h>
#include <timing/timing.h>

using namespace util;


int main(int argc, char * argv[]) {
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 30; i++) {
        //int fs = fls(i);
        //printf("%x -> %d (%d)\n", i, fs, next_pow2(fs));

        printf("floor(log10(%d)) = %d\n", i, log10(i));
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("Time: %lf s\n", timespec_diff(&end, &start));

    return 0;
}

