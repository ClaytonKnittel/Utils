
#include <cassert>
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

        util::const_sort<int, N>(vals);
        for (int j = 0; j < N; j++) {
            assert(vals[j] == j + 1);
        }
    }
    return true;
}


template <size_t N>
struct ForEach {

    template <size_t I>
    static void item() {

        printf("testing %zu\n", I);
        check_correctness<I>();

        // recurse upwards
        if constexpr (I+1 < N) ForEach<N>::item<I+1>();

    }

};



int main(int argc, char * argv[]) {

    ForEach<16>::item<2>();

    return 0;
}

