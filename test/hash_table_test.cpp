
#include <cstdio>

#include <data_structs/flat_hash_map.h>

#include <timing/timing.h>

int main(int argc, char * argv[]) {

    struct timespec t1, t2;

    clock_gettime(CLOCK_MONOTONIC, &t1);

    //fht_table<uint64_t, uint64_t> table;
    ska::flat_hash_map<uint64_t, uint64_t> table;

    table[10] = 20;
    table[15] = 31;
    table[20] = 11;
    table[24] = 12;
    table[25] = 13;

    clock_gettime(CLOCK_MONOTONIC, &t2);

    for (auto it = table.begin(); it != table.end(); it++) {
        printf("%llu -> %llu\n", it->first, it->second);
    }

    double diff = timespec_diff(&t2, &t1);
    printf("Diff: %lf\n", diff);

    return 0;
}

