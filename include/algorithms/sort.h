#ifndef _ALG_SORT_H
#define _ALG_SORT_H

#include <stdint.h>

#include <type_traits>
#include <algorithm>


#ifdef __cplusplus

namespace util {


static constexpr const int BITONIC_SORT_MAX = 8;



/*
 * if t1 <= t2, does nothing, otherwise swaps t1 and t2
 */
template<typename T>
void __sort_swap(T & t1, T & t2) {
    T m = std::max(t1, t2);
    T n = std::min(t1, t2);
    t1 = n;
    t2 = m;
}


template<typename T>
void __bitonic_sort2(T els[2]) {
    __sort_swap(els[0], els[1]);
}

template<typename T>
void __bitonic_sort3(T els[3]) {
    __sort_swap(els[0], els[1]);
    __sort_swap(els[1], els[2]);
    __sort_swap(els[0], els[1]);
}

template<typename T>
void __bitonic_sort4(T els[4]) {
    __sort_swap(els[0], els[1]);
    __sort_swap(els[3], els[2]);

    __sort_swap(els[0], els[2]);
    __sort_swap(els[1], els[3]);
    __sort_swap(els[0], els[1]);
    __sort_swap(els[2], els[3]);
}



template<typename T, uint32_t N>
void __attribute__((noinline)) bitonic_sort(T els[N]) {
    static_assert(N <= BITONIC_SORT_MAX);
    switch (N) {
        case 0:
        case 1:
            break;
        case 2:
            __bitonic_sort2(els);
            break;
        case 3:
            __bitonic_sort3(els);
            break;
        case 4:
            __bitonic_sort4(els);
            break;
    }
}



}

#else


#endif


#endif /* _ALG_SORT_H */
