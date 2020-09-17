#ifndef _ALG_SORT_H
#define _ALG_SORT_H

#include <stdint.h>

#include <type_traits>
#include <algorithm>


#ifdef __cplusplus

namespace util {


static constexpr const int CONST_SORT_MAX = 16;



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


/*
 * base-case bitonic sorts for array sizes 2 - 16, using the best known sorting
 * networks, taken from https://pages.ripco.net/~jgamble/nw.html
 */

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

template<typename T>
void __bitonic_sort5(T els[5]) {
    __sort_swap(els[0], els[1]);
    __sort_swap(els[3], els[4]);
    __sort_swap(els[2], els[4]);
    __sort_swap(els[2], els[3]);
    __sort_swap(els[1], els[4]);
    __sort_swap(els[0], els[3]);
    __sort_swap(els[0], els[2]);
    __sort_swap(els[1], els[3]);
    __sort_swap(els[1], els[2]);
}

template<typename T>
void __bitonic_sort6(T els[6]) {
    __sort_swap(els[1], els[2]);
    __sort_swap(els[4], els[5]);
    __sort_swap(els[0], els[2]);
    __sort_swap(els[3], els[5]);
    __sort_swap(els[0], els[1]);
    __sort_swap(els[3], els[4]);
    __sort_swap(els[2], els[5]);
    __sort_swap(els[0], els[3]);
    __sort_swap(els[1], els[4]);
    __sort_swap(els[2], els[4]);
    __sort_swap(els[1], els[3]);
    __sort_swap(els[2], els[3]);
}

template<typename T>
void __bitonic_sort7(T els[7]) {
    __sort_swap(els[1], els[2]);
    __sort_swap(els[3], els[4]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[0], els[2]);
    __sort_swap(els[3], els[5]);
    __sort_swap(els[0], els[1]);
    __sort_swap(els[4], els[6]);
    __sort_swap(els[4], els[5]);
    __sort_swap(els[0], els[4]);
    __sort_swap(els[0], els[3]);
    __sort_swap(els[1], els[5]);
    __sort_swap(els[2], els[6]);
    __sort_swap(els[2], els[5]);
    __sort_swap(els[1], els[3]);
    __sort_swap(els[2], els[4]);
    __sort_swap(els[2], els[3]);
}

template<typename T>
void __bitonic_sort8(T els[8]) {
    __sort_swap(els[0], els[1]);
    __sort_swap(els[2], els[3]);
    __sort_swap(els[4], els[5]);
    __sort_swap(els[6], els[7]);
    __sort_swap(els[0], els[2]);
    __sort_swap(els[4], els[6]);
    __sort_swap(els[1], els[3]);
    __sort_swap(els[5], els[7]);
    __sort_swap(els[1], els[2]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[0], els[4]);
    __sort_swap(els[1], els[5]);
    __sort_swap(els[1], els[4]);
    __sort_swap(els[2], els[6]);
    __sort_swap(els[3], els[7]);
    __sort_swap(els[3], els[6]);
    __sort_swap(els[2], els[4]);
    __sort_swap(els[3], els[5]);
    __sort_swap(els[3], els[4]);
}

template<typename T>
void __bitonic_sort9(T els[9]) {
    __sort_swap(els[0], els[1]);
    __sort_swap(els[3], els[4]);
    __sort_swap(els[6], els[7]);
    __sort_swap(els[1], els[2]);
    __sort_swap(els[4], els[5]);
    __sort_swap(els[7], els[8]);
    __sort_swap(els[0], els[1]);
    __sort_swap(els[3], els[4]);
    __sort_swap(els[6], els[7]);
    __sort_swap(els[0], els[3]);
    __sort_swap(els[3], els[6]);
    __sort_swap(els[0], els[3]);
    __sort_swap(els[1], els[4]);
    __sort_swap(els[4], els[7]);
    __sort_swap(els[1], els[4]);
    __sort_swap(els[2], els[5]);
    __sort_swap(els[5], els[8]);
    __sort_swap(els[2], els[5]);
    __sort_swap(els[1], els[3]);
    __sort_swap(els[5], els[7]);
    __sort_swap(els[2], els[6]);
    __sort_swap(els[4], els[6]);
    __sort_swap(els[2], els[4]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[2], els[3]);
}

template<typename T>
void __bitonic_sort10(T els[10]) {
    __sort_swap(els[4], els[9]);
    __sort_swap(els[3], els[8]);
    __sort_swap(els[2], els[7]);
    __sort_swap(els[1], els[6]);
    __sort_swap(els[0], els[5]);
    __sort_swap(els[6], els[9]);
    __sort_swap(els[1], els[4]);
    __sort_swap(els[5], els[8]);
    __sort_swap(els[0], els[3]);
    __sort_swap(els[7], els[9]);
    __sort_swap(els[0], els[2]);
    __sort_swap(els[3], els[6]);
    __sort_swap(els[8], els[9]);
    __sort_swap(els[0], els[1]);
    __sort_swap(els[2], els[4]);
    __sort_swap(els[5], els[7]);
    __sort_swap(els[1], els[2]);
    __sort_swap(els[4], els[6]);
    __sort_swap(els[7], els[8]);
    __sort_swap(els[3], els[5]);
    __sort_swap(els[6], els[8]);
    __sort_swap(els[2], els[5]);
    __sort_swap(els[1], els[3]);
    __sort_swap(els[4], els[7]);
    __sort_swap(els[2], els[3]);
    __sort_swap(els[6], els[7]);
    __sort_swap(els[3], els[4]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[4], els[5]);
}

template<typename T>
void __bitonic_sort11(T els[11]) {
    __sort_swap(els[0], els[1]);
    __sort_swap(els[2], els[3]);
    __sort_swap(els[4], els[5]);
    __sort_swap(els[6], els[7]);
    __sort_swap(els[8], els[9]);
    __sort_swap(els[1], els[3]);
    __sort_swap(els[5], els[7]);
    __sort_swap(els[8], els[10]);
    __sort_swap(els[0], els[2]);
    __sort_swap(els[4], els[6]);
    __sort_swap(els[9], els[10]);
    __sort_swap(els[1], els[2]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[1], els[5]);
    __sort_swap(els[6], els[10]);
    __sort_swap(els[5], els[9]);
    __sort_swap(els[2], els[6]);
    __sort_swap(els[1], els[5]);
    __sort_swap(els[6], els[10]);
    __sort_swap(els[0], els[4]);
    __sort_swap(els[3], els[7]);
    __sort_swap(els[4], els[8]);
    __sort_swap(els[0], els[4]);
    __sort_swap(els[7], els[10]);
    __sort_swap(els[1], els[4]);
    __sort_swap(els[3], els[8]);
    __sort_swap(els[2], els[3]);
    __sort_swap(els[8], els[9]);
    __sort_swap(els[2], els[4]);
    __sort_swap(els[7], els[9]);
    __sort_swap(els[3], els[5]);
    __sort_swap(els[6], els[8]);
    __sort_swap(els[3], els[4]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[7], els[8]);
}

template<typename T>
void __bitonic_sort12(T els[12]) {
    __sort_swap(els[0], els[1]);
    __sort_swap(els[2], els[3]);
    __sort_swap(els[4], els[5]);
    __sort_swap(els[6], els[7]);
    __sort_swap(els[8], els[9]);
    __sort_swap(els[10], els[11]);
    __sort_swap(els[1], els[3]);
    __sort_swap(els[5], els[7]);
    __sort_swap(els[9], els[11]);
    __sort_swap(els[0], els[2]);
    __sort_swap(els[4], els[6]);
    __sort_swap(els[8], els[10]);
    __sort_swap(els[1], els[2]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[9], els[10]);
    __sort_swap(els[1], els[5]);
    __sort_swap(els[6], els[10]);
    __sort_swap(els[5], els[9]);
    __sort_swap(els[2], els[6]);
    __sort_swap(els[1], els[5]);
    __sort_swap(els[6], els[10]);
    __sort_swap(els[0], els[4]);
    __sort_swap(els[7], els[11]);
    __sort_swap(els[3], els[7]);
    __sort_swap(els[4], els[8]);
    __sort_swap(els[0], els[4]);
    __sort_swap(els[7], els[11]);
    __sort_swap(els[1], els[4]);
    __sort_swap(els[7], els[10]);
    __sort_swap(els[3], els[8]);
    __sort_swap(els[2], els[3]);
    __sort_swap(els[8], els[9]);
    __sort_swap(els[2], els[4]);
    __sort_swap(els[7], els[9]);
    __sort_swap(els[3], els[5]);
    __sort_swap(els[6], els[8]);
    __sort_swap(els[3], els[4]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[7], els[8]);
}

template<typename T>
void __bitonic_sort13(T els[13]) {
    __sort_swap(els[1], els[7]);
    __sort_swap(els[9], els[11]);
    __sort_swap(els[3], els[4]);
    __sort_swap(els[5], els[8]);
    __sort_swap(els[0], els[12]);
    __sort_swap(els[2], els[6]);
    __sort_swap(els[0], els[1]);
    __sort_swap(els[8], els[11]);
    __sort_swap(els[2], els[3]);
    __sort_swap(els[4], els[6]);
    __sort_swap(els[7], els[12]);
    __sort_swap(els[5], els[9]);
    __sort_swap(els[0], els[2]);
    __sort_swap(els[10], els[11]);
    __sort_swap(els[3], els[7]);
    __sort_swap(els[1], els[4]);
    __sort_swap(els[6], els[12]);
    __sort_swap(els[7], els[8]);
    __sort_swap(els[11], els[12]);
    __sort_swap(els[4], els[9]);
    __sort_swap(els[6], els[10]);
    __sort_swap(els[3], els[4]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[8], els[9]);
    __sort_swap(els[10], els[11]);
    __sort_swap(els[1], els[7]);
    __sort_swap(els[9], els[11]);
    __sort_swap(els[2], els[6]);
    __sort_swap(els[8], els[10]);
    __sort_swap(els[1], els[3]);
    __sort_swap(els[4], els[7]);
    __sort_swap(els[9], els[10]);
    __sort_swap(els[0], els[5]);
    __sort_swap(els[6], els[8]);
    __sort_swap(els[2], els[5]);
    __sort_swap(els[7], els[8]);
    __sort_swap(els[1], els[2]);
    __sort_swap(els[3], els[5]);
    __sort_swap(els[8], els[9]);
    __sort_swap(els[4], els[6]);
    __sort_swap(els[2], els[3]);
    __sort_swap(els[4], els[5]);
    __sort_swap(els[6], els[7]);
    __sort_swap(els[3], els[4]);
    __sort_swap(els[5], els[6]);
}

template<typename T>
void __bitonic_sort14(T els[14]) {
    __sort_swap(els[0], els[1]);
    __sort_swap(els[2], els[3]);
    __sort_swap(els[4], els[5]);
    __sort_swap(els[6], els[7]);
    __sort_swap(els[8], els[9]);
    __sort_swap(els[10], els[11]);
    __sort_swap(els[12], els[13]);
    __sort_swap(els[0], els[2]);
    __sort_swap(els[4], els[6]);
    __sort_swap(els[8], els[10]);
    __sort_swap(els[1], els[3]);
    __sort_swap(els[5], els[7]);
    __sort_swap(els[9], els[11]);
    __sort_swap(els[0], els[4]);
    __sort_swap(els[8], els[12]);
    __sort_swap(els[1], els[5]);
    __sort_swap(els[9], els[13]);
    __sort_swap(els[2], els[6]);
    __sort_swap(els[3], els[7]);
    __sort_swap(els[0], els[8]);
    __sort_swap(els[1], els[9]);
    __sort_swap(els[2], els[10]);
    __sort_swap(els[3], els[11]);
    __sort_swap(els[1], els[2]);
    __sort_swap(els[4], els[12]);
    __sort_swap(els[5], els[13]);
    __sort_swap(els[5], els[10]);
    __sort_swap(els[6], els[9]);
    __sort_swap(els[3], els[12]);
    __sort_swap(els[7], els[11]);
    __sort_swap(els[4], els[8]);
    __sort_swap(els[1], els[4]);
    __sort_swap(els[7], els[13]);
    __sort_swap(els[2], els[8]);
    __sort_swap(els[9], els[10]);
    __sort_swap(els[11], els[13]);
    __sort_swap(els[2], els[4]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[3], els[8]);
    __sort_swap(els[7], els[12]);
    __sort_swap(els[3], els[5]);
    __sort_swap(els[6], els[8]);
    __sort_swap(els[10], els[12]);
    __sort_swap(els[3], els[4]);
    __sort_swap(els[7], els[9]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[11], els[12]);
    __sort_swap(els[7], els[8]);
    __sort_swap(els[9], els[10]);
    __sort_swap(els[6], els[7]);
    __sort_swap(els[8], els[9]);
}

template<typename T>
void __bitonic_sort15(T els[15]) {
    __sort_swap(els[0], els[1]);
    __sort_swap(els[2], els[3]);
    __sort_swap(els[4], els[5]);
    __sort_swap(els[6], els[7]);
    __sort_swap(els[8], els[9]);
    __sort_swap(els[10], els[11]);
    __sort_swap(els[12], els[13]);
    __sort_swap(els[0], els[2]);
    __sort_swap(els[4], els[6]);
    __sort_swap(els[8], els[10]);
    __sort_swap(els[12], els[14]);
    __sort_swap(els[1], els[3]);
    __sort_swap(els[5], els[7]);
    __sort_swap(els[9], els[11]);
    __sort_swap(els[0], els[4]);
    __sort_swap(els[8], els[12]);
    __sort_swap(els[1], els[5]);
    __sort_swap(els[9], els[13]);
    __sort_swap(els[2], els[6]);
    __sort_swap(els[10], els[14]);
    __sort_swap(els[3], els[7]);
    __sort_swap(els[0], els[8]);
    __sort_swap(els[1], els[9]);
    __sort_swap(els[2], els[10]);
    __sort_swap(els[3], els[11]);
    __sort_swap(els[1], els[2]);
    __sort_swap(els[4], els[12]);
    __sort_swap(els[5], els[13]);
    __sort_swap(els[6], els[14]);
    __sort_swap(els[5], els[10]);
    __sort_swap(els[13], els[14]);
    __sort_swap(els[6], els[9]);
    __sort_swap(els[3], els[12]);
    __sort_swap(els[7], els[11]);
    __sort_swap(els[4], els[8]);
    __sort_swap(els[1], els[4]);
    __sort_swap(els[7], els[13]);
    __sort_swap(els[2], els[8]);
    __sort_swap(els[11], els[14]);
    __sort_swap(els[9], els[10]);
    __sort_swap(els[2], els[4]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[11], els[13]);
    __sort_swap(els[3], els[8]);
    __sort_swap(els[7], els[12]);
    __sort_swap(els[3], els[5]);
    __sort_swap(els[6], els[8]);
    __sort_swap(els[10], els[12]);
    __sort_swap(els[3], els[4]);
    __sort_swap(els[7], els[9]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[11], els[12]);
    __sort_swap(els[7], els[8]);
    __sort_swap(els[9], els[10]);
    __sort_swap(els[6], els[7]);
    __sort_swap(els[8], els[9]);
}

template<typename T>
void __bitonic_sort16(T els[16]) {
    __sort_swap(els[0], els[1]);
    __sort_swap(els[2], els[3]);
    __sort_swap(els[4], els[5]);
    __sort_swap(els[6], els[7]);
    __sort_swap(els[8], els[9]);
    __sort_swap(els[10], els[11]);
    __sort_swap(els[12], els[13]);
    __sort_swap(els[14], els[15]);
    __sort_swap(els[0], els[2]);
    __sort_swap(els[4], els[6]);
    __sort_swap(els[8], els[10]);
    __sort_swap(els[12], els[14]);
    __sort_swap(els[1], els[3]);
    __sort_swap(els[5], els[7]);
    __sort_swap(els[9], els[11]);
    __sort_swap(els[13], els[15]);
    __sort_swap(els[0], els[4]);
    __sort_swap(els[8], els[12]);
    __sort_swap(els[1], els[5]);
    __sort_swap(els[9], els[13]);
    __sort_swap(els[2], els[6]);
    __sort_swap(els[10], els[14]);
    __sort_swap(els[3], els[7]);
    __sort_swap(els[11], els[15]);
    __sort_swap(els[0], els[8]);
    __sort_swap(els[1], els[9]);
    __sort_swap(els[2], els[10]);
    __sort_swap(els[3], els[11]);
    __sort_swap(els[1], els[2]);
    __sort_swap(els[4], els[12]);
    __sort_swap(els[5], els[13]);
    __sort_swap(els[6], els[14]);
    __sort_swap(els[7], els[15]);
    __sort_swap(els[5], els[10]);
    __sort_swap(els[13], els[14]);
    __sort_swap(els[6], els[9]);
    __sort_swap(els[3], els[12]);
    __sort_swap(els[7], els[11]);
    __sort_swap(els[4], els[8]);
    __sort_swap(els[1], els[4]);
    __sort_swap(els[7], els[13]);
    __sort_swap(els[2], els[8]);
    __sort_swap(els[11], els[14]);
    __sort_swap(els[9], els[10]);
    __sort_swap(els[2], els[4]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[11], els[13]);
    __sort_swap(els[3], els[8]);
    __sort_swap(els[7], els[12]);
    __sort_swap(els[3], els[5]);
    __sort_swap(els[6], els[8]);
    __sort_swap(els[10], els[12]);
    __sort_swap(els[3], els[4]);
    __sort_swap(els[7], els[9]);
    __sort_swap(els[5], els[6]);
    __sort_swap(els[11], els[12]);
    __sort_swap(els[7], els[8]);
    __sort_swap(els[9], els[10]);
    __sort_swap(els[6], els[7]);
    __sort_swap(els[8], els[9]);
}



template<typename T, uint32_t N>
void const_sort(T els[N]) {
    static_assert(N <= CONST_SORT_MAX);
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
        case 5:
            __bitonic_sort5(els);
            break;
        case 6:
            __bitonic_sort6(els);
            break;
        case 7:
            __bitonic_sort7(els);
            break;
        case 8:
            __bitonic_sort8(els);
            break;
        case 9:
            __bitonic_sort9(els);
            break;
        case 10:
            __bitonic_sort10(els);
            break;
        case 11:
            __bitonic_sort11(els);
            break;
        case 12:
            __bitonic_sort12(els);
            break;
        case 13:
            __bitonic_sort13(els);
            break;
        case 14:
            __bitonic_sort14(els);
            break;
        case 15:
            __bitonic_sort15(els);
            break;
        case 16:
            __bitonic_sort16(els);
            break;
    }
}



}

#else


#endif


#endif /* _ALG_SORT_H */
