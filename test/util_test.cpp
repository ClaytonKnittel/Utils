
#include <util/util.h>
#include <timing/timing.h>


int main(int argc, char * argv[]) {
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 30; i++) {
        int fs = fls_safe(i);
        printf("%x -> %d (%d)\n", i, fs, next_pow2(fs));
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("Time: %lf s\n", timespec_diff(&end, &start));

    return 0;
}

