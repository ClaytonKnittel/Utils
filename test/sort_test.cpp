

#include <cstdio>
#include <cstdlib>

#include <algorithms/sort.h>

int main(int argc, char * argv[]) {

#define NUM_ELS 4

    int nums[NUM_ELS];
    
    if (argc < NUM_ELS + 1) {
        fprintf(stderr, "must supply %d numbers\n", NUM_ELS);
        return -1;
    }

    for (int i = 1; i <= NUM_ELS; i++) {
        char * end;
        nums[i - 1] = (int) strtol(argv[i], &end, 10);
        if (argv[i][0] == '\0' || *end != '\0') {
            fprintf(stderr, "input \"%s\" is not a valid number\n", argv[i]);
            return -1;
        }
    }

    util::bitonic_sort<int, 4>(nums);

    printf("nums: %d, %d, %d, %d\n", nums[0], nums[1], nums[2], nums[3]);

    return 0;
}

