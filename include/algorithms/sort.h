#ifndef _ALG_SORT_H
#define _ALG_SORT_H

#include <stdint.h>


#ifdef __cplusplus

#include <type_traits>
#include <algorithm>

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


#define CONST_SORT_MAX 16


/*
 * if t1 <= t2, does nothing, otherwise swaps t1 and t2
 */
#define __sort_swap(T, t1, t2) \
	do { \
		T m = (t1 < t2 ? t2 : t1); \
		T n = (t1 < t2 ? t1 : t2); \
		t1 = n; \
		t2 = m; \
	} while (0)


/*
 * base-case bitonic sorts for array sizes 2 - 16, using the best known sorting
 * networks, taken from https://pages.ripco.net/~jgamble/nw.html
 */

#define DEFINE_BITONIC_SORT2(T) \
void __bitonic_sort2_ ## T(T els[2]) { \
    __sort_swap(T, els[0], els[1]); \
}

#define DEFINE_BITONIC_SORT3(T) \
void __bitonic_sort3_ ## T(T els[3]) { \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[1], els[2]); \
    __sort_swap(T, els[0], els[1]); \
}

#define DEFINE_BITONIC_SORT4(T) \
void __bitonic_sort4_ ## T(T els[4]) { \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[3], els[2]); \
	\
    __sort_swap(T, els[0], els[2]); \
    __sort_swap(T, els[1], els[3]); \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[2], els[3]); \
}

#define DEFINE_BITONIC_SORT5(T) \
void __bitonic_sort5_ ## T(T els[5]) { \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[3], els[4]); \
    __sort_swap(T, els[2], els[4]); \
    __sort_swap(T, els[2], els[3]); \
    __sort_swap(T, els[1], els[4]); \
    __sort_swap(T, els[0], els[3]); \
    __sort_swap(T, els[0], els[2]); \
    __sort_swap(T, els[1], els[3]); \
    __sort_swap(T, els[1], els[2]); \
}

#define DEFINE_BITONIC_SORT6(T) \
void __bitonic_sort6_ ## T(T els[6]) { \
    __sort_swap(T, els[1], els[2]); \
    __sort_swap(T, els[4], els[5]); \
    __sort_swap(T, els[0], els[2]); \
    __sort_swap(T, els[3], els[5]); \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[3], els[4]); \
    __sort_swap(T, els[2], els[5]); \
    __sort_swap(T, els[0], els[3]); \
    __sort_swap(T, els[1], els[4]); \
    __sort_swap(T, els[2], els[4]); \
    __sort_swap(T, els[1], els[3]); \
    __sort_swap(T, els[2], els[3]); \
}

#define DEFINE_BITONIC_SORT7(T) \
void __bitonic_sort7_ ## T(T els[7]) { \
    __sort_swap(T, els[1], els[2]); \
    __sort_swap(T, els[3], els[4]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[0], els[2]); \
    __sort_swap(T, els[3], els[5]); \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[4], els[6]); \
    __sort_swap(T, els[4], els[5]); \
    __sort_swap(T, els[0], els[4]); \
    __sort_swap(T, els[0], els[3]); \
    __sort_swap(T, els[1], els[5]); \
    __sort_swap(T, els[2], els[6]); \
    __sort_swap(T, els[2], els[5]); \
    __sort_swap(T, els[1], els[3]); \
    __sort_swap(T, els[2], els[4]); \
    __sort_swap(T, els[2], els[3]); \
}

#define DEFINE_BITONIC_SORT8(T) \
void __bitonic_sort8_ ## T(T els[8]) { \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[2], els[3]); \
    __sort_swap(T, els[4], els[5]); \
    __sort_swap(T, els[6], els[7]); \
    __sort_swap(T, els[0], els[2]); \
    __sort_swap(T, els[4], els[6]); \
    __sort_swap(T, els[1], els[3]); \
    __sort_swap(T, els[5], els[7]); \
    __sort_swap(T, els[1], els[2]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[0], els[4]); \
    __sort_swap(T, els[1], els[5]); \
    __sort_swap(T, els[1], els[4]); \
    __sort_swap(T, els[2], els[6]); \
    __sort_swap(T, els[3], els[7]); \
    __sort_swap(T, els[3], els[6]); \
    __sort_swap(T, els[2], els[4]); \
    __sort_swap(T, els[3], els[5]); \
    __sort_swap(T, els[3], els[4]); \
}

#define DEFINE_BITONIC_SORT9(T) \
void __bitonic_sort9_ ## T(T els[9]) { \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[3], els[4]); \
    __sort_swap(T, els[6], els[7]); \
    __sort_swap(T, els[1], els[2]); \
    __sort_swap(T, els[4], els[5]); \
    __sort_swap(T, els[7], els[8]); \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[3], els[4]); \
    __sort_swap(T, els[6], els[7]); \
    __sort_swap(T, els[0], els[3]); \
    __sort_swap(T, els[3], els[6]); \
    __sort_swap(T, els[0], els[3]); \
    __sort_swap(T, els[1], els[4]); \
    __sort_swap(T, els[4], els[7]); \
    __sort_swap(T, els[1], els[4]); \
    __sort_swap(T, els[2], els[5]); \
    __sort_swap(T, els[5], els[8]); \
    __sort_swap(T, els[2], els[5]); \
    __sort_swap(T, els[1], els[3]); \
    __sort_swap(T, els[5], els[7]); \
    __sort_swap(T, els[2], els[6]); \
    __sort_swap(T, els[4], els[6]); \
    __sort_swap(T, els[2], els[4]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[2], els[3]); \
}

#define DEFINE_BITONIC_SORT10(T) \
void __bitonic_sort10_ ## T(T els[10]) { \
    __sort_swap(T, els[4], els[9]); \
    __sort_swap(T, els[3], els[8]); \
    __sort_swap(T, els[2], els[7]); \
    __sort_swap(T, els[1], els[6]); \
    __sort_swap(T, els[0], els[5]); \
    __sort_swap(T, els[6], els[9]); \
    __sort_swap(T, els[1], els[4]); \
    __sort_swap(T, els[5], els[8]); \
    __sort_swap(T, els[0], els[3]); \
    __sort_swap(T, els[7], els[9]); \
    __sort_swap(T, els[0], els[2]); \
    __sort_swap(T, els[3], els[6]); \
    __sort_swap(T, els[8], els[9]); \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[2], els[4]); \
    __sort_swap(T, els[5], els[7]); \
    __sort_swap(T, els[1], els[2]); \
    __sort_swap(T, els[4], els[6]); \
    __sort_swap(T, els[7], els[8]); \
    __sort_swap(T, els[3], els[5]); \
    __sort_swap(T, els[6], els[8]); \
    __sort_swap(T, els[2], els[5]); \
    __sort_swap(T, els[1], els[3]); \
    __sort_swap(T, els[4], els[7]); \
    __sort_swap(T, els[2], els[3]); \
    __sort_swap(T, els[6], els[7]); \
    __sort_swap(T, els[3], els[4]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[4], els[5]); \
}

#define DEFINE_BITONIC_SORT11(T) \
void __bitonic_sort11_ ## T(T els[11]) { \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[2], els[3]); \
    __sort_swap(T, els[4], els[5]); \
    __sort_swap(T, els[6], els[7]); \
    __sort_swap(T, els[8], els[9]); \
    __sort_swap(T, els[1], els[3]); \
    __sort_swap(T, els[5], els[7]); \
    __sort_swap(T, els[8], els[10]); \
    __sort_swap(T, els[0], els[2]); \
    __sort_swap(T, els[4], els[6]); \
    __sort_swap(T, els[9], els[10]); \
    __sort_swap(T, els[1], els[2]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[1], els[5]); \
    __sort_swap(T, els[6], els[10]); \
    __sort_swap(T, els[5], els[9]); \
    __sort_swap(T, els[2], els[6]); \
    __sort_swap(T, els[1], els[5]); \
    __sort_swap(T, els[6], els[10]); \
    __sort_swap(T, els[0], els[4]); \
    __sort_swap(T, els[3], els[7]); \
    __sort_swap(T, els[4], els[8]); \
    __sort_swap(T, els[0], els[4]); \
    __sort_swap(T, els[7], els[10]); \
    __sort_swap(T, els[1], els[4]); \
    __sort_swap(T, els[3], els[8]); \
    __sort_swap(T, els[2], els[3]); \
    __sort_swap(T, els[8], els[9]); \
    __sort_swap(T, els[2], els[4]); \
    __sort_swap(T, els[7], els[9]); \
    __sort_swap(T, els[3], els[5]); \
    __sort_swap(T, els[6], els[8]); \
    __sort_swap(T, els[3], els[4]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[7], els[8]); \
}

#define DEFINE_BITONIC_SORT12(T) \
void __bitonic_sort12_ ## T(T els[12]) { \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[2], els[3]); \
    __sort_swap(T, els[4], els[5]); \
    __sort_swap(T, els[6], els[7]); \
    __sort_swap(T, els[8], els[9]); \
    __sort_swap(T, els[10], els[11]); \
    __sort_swap(T, els[1], els[3]); \
    __sort_swap(T, els[5], els[7]); \
    __sort_swap(T, els[9], els[11]); \
    __sort_swap(T, els[0], els[2]); \
    __sort_swap(T, els[4], els[6]); \
    __sort_swap(T, els[8], els[10]); \
    __sort_swap(T, els[1], els[2]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[9], els[10]); \
    __sort_swap(T, els[1], els[5]); \
    __sort_swap(T, els[6], els[10]); \
    __sort_swap(T, els[5], els[9]); \
    __sort_swap(T, els[2], els[6]); \
    __sort_swap(T, els[1], els[5]); \
    __sort_swap(T, els[6], els[10]); \
    __sort_swap(T, els[0], els[4]); \
    __sort_swap(T, els[7], els[11]); \
    __sort_swap(T, els[3], els[7]); \
    __sort_swap(T, els[4], els[8]); \
    __sort_swap(T, els[0], els[4]); \
    __sort_swap(T, els[7], els[11]); \
    __sort_swap(T, els[1], els[4]); \
    __sort_swap(T, els[7], els[10]); \
    __sort_swap(T, els[3], els[8]); \
    __sort_swap(T, els[2], els[3]); \
    __sort_swap(T, els[8], els[9]); \
    __sort_swap(T, els[2], els[4]); \
    __sort_swap(T, els[7], els[9]); \
    __sort_swap(T, els[3], els[5]); \
    __sort_swap(T, els[6], els[8]); \
    __sort_swap(T, els[3], els[4]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[7], els[8]); \
}

#define DEFINE_BITONIC_SORT13(T) \
void __bitonic_sort13_ ## T(T els[13]) { \
    __sort_swap(T, els[1], els[7]); \
    __sort_swap(T, els[9], els[11]); \
    __sort_swap(T, els[3], els[4]); \
    __sort_swap(T, els[5], els[8]); \
    __sort_swap(T, els[0], els[12]); \
    __sort_swap(T, els[2], els[6]); \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[8], els[11]); \
    __sort_swap(T, els[2], els[3]); \
    __sort_swap(T, els[4], els[6]); \
    __sort_swap(T, els[7], els[12]); \
    __sort_swap(T, els[5], els[9]); \
    __sort_swap(T, els[0], els[2]); \
    __sort_swap(T, els[10], els[11]); \
    __sort_swap(T, els[3], els[7]); \
    __sort_swap(T, els[1], els[4]); \
    __sort_swap(T, els[6], els[12]); \
    __sort_swap(T, els[7], els[8]); \
    __sort_swap(T, els[11], els[12]); \
    __sort_swap(T, els[4], els[9]); \
    __sort_swap(T, els[6], els[10]); \
    __sort_swap(T, els[3], els[4]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[8], els[9]); \
    __sort_swap(T, els[10], els[11]); \
    __sort_swap(T, els[1], els[7]); \
    __sort_swap(T, els[9], els[11]); \
    __sort_swap(T, els[2], els[6]); \
    __sort_swap(T, els[8], els[10]); \
    __sort_swap(T, els[1], els[3]); \
    __sort_swap(T, els[4], els[7]); \
    __sort_swap(T, els[9], els[10]); \
    __sort_swap(T, els[0], els[5]); \
    __sort_swap(T, els[6], els[8]); \
    __sort_swap(T, els[2], els[5]); \
    __sort_swap(T, els[7], els[8]); \
    __sort_swap(T, els[1], els[2]); \
    __sort_swap(T, els[3], els[5]); \
    __sort_swap(T, els[8], els[9]); \
    __sort_swap(T, els[4], els[6]); \
    __sort_swap(T, els[2], els[3]); \
    __sort_swap(T, els[4], els[5]); \
    __sort_swap(T, els[6], els[7]); \
    __sort_swap(T, els[3], els[4]); \
    __sort_swap(T, els[5], els[6]); \
}

#define DEFINE_BITONIC_SORT14(T) \
void __bitonic_sort14_ ## T(T els[14]) { \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[2], els[3]); \
    __sort_swap(T, els[4], els[5]); \
    __sort_swap(T, els[6], els[7]); \
    __sort_swap(T, els[8], els[9]); \
    __sort_swap(T, els[10], els[11]); \
    __sort_swap(T, els[12], els[13]); \
    __sort_swap(T, els[0], els[2]); \
    __sort_swap(T, els[4], els[6]); \
    __sort_swap(T, els[8], els[10]); \
    __sort_swap(T, els[1], els[3]); \
    __sort_swap(T, els[5], els[7]); \
    __sort_swap(T, els[9], els[11]); \
    __sort_swap(T, els[0], els[4]); \
    __sort_swap(T, els[8], els[12]); \
    __sort_swap(T, els[1], els[5]); \
    __sort_swap(T, els[9], els[13]); \
    __sort_swap(T, els[2], els[6]); \
    __sort_swap(T, els[3], els[7]); \
    __sort_swap(T, els[0], els[8]); \
    __sort_swap(T, els[1], els[9]); \
    __sort_swap(T, els[2], els[10]); \
    __sort_swap(T, els[3], els[11]); \
    __sort_swap(T, els[1], els[2]); \
    __sort_swap(T, els[4], els[12]); \
    __sort_swap(T, els[5], els[13]); \
    __sort_swap(T, els[5], els[10]); \
    __sort_swap(T, els[6], els[9]); \
    __sort_swap(T, els[3], els[12]); \
    __sort_swap(T, els[7], els[11]); \
    __sort_swap(T, els[4], els[8]); \
    __sort_swap(T, els[1], els[4]); \
    __sort_swap(T, els[7], els[13]); \
    __sort_swap(T, els[2], els[8]); \
    __sort_swap(T, els[9], els[10]); \
    __sort_swap(T, els[11], els[13]); \
    __sort_swap(T, els[2], els[4]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[3], els[8]); \
    __sort_swap(T, els[7], els[12]); \
    __sort_swap(T, els[3], els[5]); \
    __sort_swap(T, els[6], els[8]); \
    __sort_swap(T, els[10], els[12]); \
    __sort_swap(T, els[3], els[4]); \
    __sort_swap(T, els[7], els[9]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[11], els[12]); \
    __sort_swap(T, els[7], els[8]); \
    __sort_swap(T, els[9], els[10]); \
    __sort_swap(T, els[6], els[7]); \
    __sort_swap(T, els[8], els[9]); \
}

#define DEFINE_BITONIC_SORT15(T) \
void __bitonic_sort15_ ## T(T els[15]) { \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[2], els[3]); \
    __sort_swap(T, els[4], els[5]); \
    __sort_swap(T, els[6], els[7]); \
    __sort_swap(T, els[8], els[9]); \
    __sort_swap(T, els[10], els[11]); \
    __sort_swap(T, els[12], els[13]); \
    __sort_swap(T, els[0], els[2]); \
    __sort_swap(T, els[4], els[6]); \
    __sort_swap(T, els[8], els[10]); \
    __sort_swap(T, els[12], els[14]); \
    __sort_swap(T, els[1], els[3]); \
    __sort_swap(T, els[5], els[7]); \
    __sort_swap(T, els[9], els[11]); \
    __sort_swap(T, els[0], els[4]); \
    __sort_swap(T, els[8], els[12]); \
    __sort_swap(T, els[1], els[5]); \
    __sort_swap(T, els[9], els[13]); \
    __sort_swap(T, els[2], els[6]); \
    __sort_swap(T, els[10], els[14]); \
    __sort_swap(T, els[3], els[7]); \
    __sort_swap(T, els[0], els[8]); \
    __sort_swap(T, els[1], els[9]); \
    __sort_swap(T, els[2], els[10]); \
    __sort_swap(T, els[3], els[11]); \
    __sort_swap(T, els[1], els[2]); \
    __sort_swap(T, els[4], els[12]); \
    __sort_swap(T, els[5], els[13]); \
    __sort_swap(T, els[6], els[14]); \
    __sort_swap(T, els[5], els[10]); \
    __sort_swap(T, els[13], els[14]); \
    __sort_swap(T, els[6], els[9]); \
    __sort_swap(T, els[3], els[12]); \
    __sort_swap(T, els[7], els[11]); \
    __sort_swap(T, els[4], els[8]); \
    __sort_swap(T, els[1], els[4]); \
    __sort_swap(T, els[7], els[13]); \
    __sort_swap(T, els[2], els[8]); \
    __sort_swap(T, els[11], els[14]); \
    __sort_swap(T, els[9], els[10]); \
    __sort_swap(T, els[2], els[4]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[11], els[13]); \
    __sort_swap(T, els[3], els[8]); \
    __sort_swap(T, els[7], els[12]); \
    __sort_swap(T, els[3], els[5]); \
    __sort_swap(T, els[6], els[8]); \
    __sort_swap(T, els[10], els[12]); \
    __sort_swap(T, els[3], els[4]); \
    __sort_swap(T, els[7], els[9]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[11], els[12]); \
    __sort_swap(T, els[7], els[8]); \
    __sort_swap(T, els[9], els[10]); \
    __sort_swap(T, els[6], els[7]); \
    __sort_swap(T, els[8], els[9]); \
}

#define DEFINE_BITONIC_SORT16(T) \
void __bitonic_sort16_ ## T(T els[16]) { \
    __sort_swap(T, els[0], els[1]); \
    __sort_swap(T, els[2], els[3]); \
    __sort_swap(T, els[4], els[5]); \
    __sort_swap(T, els[6], els[7]); \
    __sort_swap(T, els[8], els[9]); \
    __sort_swap(T, els[10], els[11]); \
    __sort_swap(T, els[12], els[13]); \
    __sort_swap(T, els[14], els[15]); \
    __sort_swap(T, els[0], els[2]); \
    __sort_swap(T, els[4], els[6]); \
    __sort_swap(T, els[8], els[10]); \
    __sort_swap(T, els[12], els[14]); \
    __sort_swap(T, els[1], els[3]); \
    __sort_swap(T, els[5], els[7]); \
    __sort_swap(T, els[9], els[11]); \
    __sort_swap(T, els[13], els[15]); \
    __sort_swap(T, els[0], els[4]); \
    __sort_swap(T, els[8], els[12]); \
    __sort_swap(T, els[1], els[5]); \
    __sort_swap(T, els[9], els[13]); \
    __sort_swap(T, els[2], els[6]); \
    __sort_swap(T, els[10], els[14]); \
    __sort_swap(T, els[3], els[7]); \
    __sort_swap(T, els[11], els[15]); \
    __sort_swap(T, els[0], els[8]); \
    __sort_swap(T, els[1], els[9]); \
    __sort_swap(T, els[2], els[10]); \
    __sort_swap(T, els[3], els[11]); \
    __sort_swap(T, els[1], els[2]); \
    __sort_swap(T, els[4], els[12]); \
    __sort_swap(T, els[5], els[13]); \
    __sort_swap(T, els[6], els[14]); \
    __sort_swap(T, els[7], els[15]); \
    __sort_swap(T, els[5], els[10]); \
    __sort_swap(T, els[13], els[14]); \
    __sort_swap(T, els[6], els[9]); \
    __sort_swap(T, els[3], els[12]); \
    __sort_swap(T, els[7], els[11]); \
    __sort_swap(T, els[4], els[8]); \
    __sort_swap(T, els[1], els[4]); \
    __sort_swap(T, els[7], els[13]); \
    __sort_swap(T, els[2], els[8]); \
    __sort_swap(T, els[11], els[14]); \
    __sort_swap(T, els[9], els[10]); \
    __sort_swap(T, els[2], els[4]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[11], els[13]); \
    __sort_swap(T, els[3], els[8]); \
    __sort_swap(T, els[7], els[12]); \
    __sort_swap(T, els[3], els[5]); \
    __sort_swap(T, els[6], els[8]); \
    __sort_swap(T, els[10], els[12]); \
    __sort_swap(T, els[3], els[4]); \
    __sort_swap(T, els[7], els[9]); \
    __sort_swap(T, els[5], els[6]); \
    __sort_swap(T, els[11], els[12]); \
    __sort_swap(T, els[7], els[8]); \
    __sort_swap(T, els[9], els[10]); \
    __sort_swap(T, els[6], els[7]); \
    __sort_swap(T, els[8], els[9]); \
}

#define DEFINE_CONST_SORT_MAIN(T) \
void const_sort_ ## T(uint32_t N, T els[N]) { \
	assert(N <= CONST_SORT_MAX); \
    switch (N) { \
        case 0: \
        case 1: \
            break; \
        case 2: \
            __bitonic_sort2_ ## T(els); \
            break; \
        case 3: \
            __bitonic_sort3_ ## T(els); \
            break; \
        case 4: \
            __bitonic_sort4_ ## T(els); \
            break; \
        case 5: \
            __bitonic_sort5_ ## T(els); \
            break; \
        case 6: \
            __bitonic_sort6_ ## T(els); \
            break; \
        case 7: \
            __bitonic_sort7_ ## T(els); \
            break; \
        case 8: \
            __bitonic_sort8_ ## T(els); \
            break; \
        case 9: \
            __bitonic_sort9_ ## T(els); \
            break; \
        case 10: \
            __bitonic_sort10_ ## T(els); \
            break; \
        case 11: \
            __bitonic_sort11_ ## T(els); \
            break; \
        case 12: \
            __bitonic_sort12_ ## T(els); \
            break; \
        case 13: \
            __bitonic_sort13_ ## T(els); \
            break; \
        case 14: \
            __bitonic_sort14_ ## T(els); \
            break; \
        case 15: \
            __bitonic_sort15_ ## T(els); \
            break; \
        case 16: \
            __bitonic_sort16_ ## T(els); \
            break; \
    } \
}


#define DEFINE_CONST_SORT(T) \
	DEFINE_BITONIC_SORT2(T) \
	DEFINE_BITONIC_SORT3(T) \
	DEFINE_BITONIC_SORT4(T) \
	DEFINE_BITONIC_SORT5(T) \
	DEFINE_BITONIC_SORT6(T) \
	DEFINE_BITONIC_SORT7(T) \
	DEFINE_BITONIC_SORT8(T) \
	DEFINE_BITONIC_SORT9(T) \
	DEFINE_BITONIC_SORT10(T) \
	DEFINE_BITONIC_SORT11(T) \
	DEFINE_BITONIC_SORT12(T) \
	DEFINE_BITONIC_SORT13(T) \
	DEFINE_BITONIC_SORT14(T) \
	DEFINE_BITONIC_SORT15(T) \
	DEFINE_BITONIC_SORT16(T) \
	DEFINE_CONST_SORT_MAIN(T)


#endif


#endif /* _ALG_SORT_H */
