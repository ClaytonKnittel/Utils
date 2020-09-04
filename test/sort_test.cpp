

#include <cstdio>
#include <cstdlib>

#include <algorithms/sort.h>



constexpr uint64_t factorial(uint64_t n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}


int nth_num(uint16_t & bitm, int n) {
    uint16_t mask = 1;
    int cnt = 0;
    while (1) {
        cnt++;
        while (!(bitm & mask)) {
            mask <<= 1;
            cnt++;
        }

        if (n == 0) {
            break;
        }
        n--;
        mask <<= 1;
    }
    bitm &= ~mask;
    return cnt;
}


template<int N>
bool check_correctness() {
    int vals[N];

    for (uint64_t i = 0; i < factorial(N); i++) {
        uint16_t mask = 0xffffu;

        uint64_t perm = i;
        for (int j = 0; j < N; j++) {
            int idx = N - 1 - j;
            uint64_t fact = factorial(idx);
            uint64_t n = perm / fact;
            vals[j] = nth_num(mask, n);
            perm -= n * fact;
        }

        /*
        printf("(");
        for (int j = 0; j < N; j++) {
            printf("%d", vals[j]);
            if (j != N - 1) {
                printf(", ");
            }
        }
        printf(")\n");*/

        util::bitonic_sort<int, N>(vals);
        for (int j = 0; j < N; j++) {
            assert(vals[j] == j + 1);
        }
    }
    return true;
}



int main(int argc, char * argv[]) {

#define NUM_ELS 4

    /*
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

    util::bitonic_sort<int, NUM_ELS>(nums);

    printf("nums: %d, %d, %d, %d\n", nums[0], nums[1], nums[2], nums[3]);*/

    check_correctness<NUM_ELS>();

    return 0;
}

