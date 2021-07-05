#ifndef _ALG_SORT_H
#define _ALG_SORT_H

#include <stdint.h>


#ifdef DEBUG
# include <assert.h>
# define TEST_ASSERT(...) assert(__VA_ARGS__)
#else
# define TEST_ASSERT(...)
#endif

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



template<typename T, size_t N>
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


#define CONST_SORT_MAX 32
#define SMALL_SORT_MAX 32


#define __sort_swap(T, t1, t2) \
	do { \
		T tmp = (t1); \
		(t1) = (t2); \
		(t2) = tmp; \
	} while(0)

/*
 * if t1 <= t2, does nothing, otherwise swaps t1 and t2
 */
#define __default_sort_cswap(T, t1, t2) \
	do { \
		T m = (t1 < t2 ? t2 : t1); \
		T n = (t1 < t2 ? t1 : t2); \
		t1 = n; \
		t2 = m; \
	} while (0)

/*
 * does t1 < t2
 */
#define __default_sort_cmp(t1, t2) \
	((t1) < (t2))


/*
 * base-case bitonic sorts for array sizes 2 - 32, using the best known sorting
 * networks
 *
 * 2 - 16 taken from https://pages.ripco.net/~jgamble/nw.html
 * 17 - 32 taken from http://users.telenet.be/bertdobbelaere/SorterHunter/sorting_networks.html
 */

#define DEFINE_BITONIC_SORT2(T, name, __sort_cswap_fn) \
void __bitonic_sort2_ ## name(T els[2]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
}

#define DEFINE_BITONIC_SORT3(T, name, __sort_cswap_fn) \
void __bitonic_sort3_ ## name(T els[3]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[0], els[1]); \
}

#define DEFINE_BITONIC_SORT4(T, name, __sort_cswap_fn) \
void __bitonic_sort4_ ## name(T els[4]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[3], els[2]); \
	\
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
}

#define DEFINE_BITONIC_SORT5(T, name, __sort_cswap_fn) \
void __bitonic_sort5_ ## name(T els[5]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[0], els[3]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[1], els[2]); \
}

#define DEFINE_BITONIC_SORT6(T, name, __sort_cswap_fn) \
void __bitonic_sort6_ ## name(T els[6]) { \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[0], els[3]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[2], els[3]); \
}

#define DEFINE_BITONIC_SORT7(T, name, __sort_cswap_fn) \
void __bitonic_sort7_ ## name(T els[7]) { \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[0], els[3]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[2], els[3]); \
}

#define DEFINE_BITONIC_SORT8(T, name, __sort_cswap_fn) \
void __bitonic_sort8_ ## name(T els[8]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[3], els[6]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[3], els[4]); \
}

#define DEFINE_BITONIC_SORT9(T, name, __sort_cswap_fn) \
void __bitonic_sort9_ ## name(T els[9]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[0], els[3]); \
	__sort_cswap_fn(T, els[3], els[6]); \
	__sort_cswap_fn(T, els[0], els[3]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[4], els[7]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[2], els[3]); \
}

#define DEFINE_BITONIC_SORT10(T, name, __sort_cswap_fn) \
void __bitonic_sort10_ ## name(T els[10]) { \
	__sort_cswap_fn(T, els[4], els[9]); \
	__sort_cswap_fn(T, els[3], els[8]); \
	__sort_cswap_fn(T, els[2], els[7]); \
	__sort_cswap_fn(T, els[1], els[6]); \
	__sort_cswap_fn(T, els[0], els[5]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[0], els[3]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[3], els[6]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[4], els[7]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[4], els[5]); \
}

#define DEFINE_BITONIC_SORT11(T, name, __sort_cswap_fn) \
void __bitonic_sort11_ ## name(T els[11]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[6], els[10]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[6], els[10]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[7], els[10]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[3], els[8]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
}

#define DEFINE_BITONIC_SORT12(T, name, __sort_cswap_fn) \
void __bitonic_sort12_ ## name(T els[12]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[6], els[10]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[6], els[10]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[7], els[10]); \
	__sort_cswap_fn(T, els[3], els[8]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
}

#define DEFINE_BITONIC_SORT13(T, name, __sort_cswap_fn) \
void __bitonic_sort13_ ## name(T els[13]) { \
	__sort_cswap_fn(T, els[1], els[7]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[0], els[12]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[8], els[11]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[7], els[12]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[6], els[12]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[4], els[9]); \
	__sort_cswap_fn(T, els[6], els[10]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[1], els[7]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[4], els[7]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[0], els[5]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
}

#define DEFINE_BITONIC_SORT14(T, name, __sort_cswap_fn) \
void __bitonic_sort14_ ## name(T els[14]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[8], els[12]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[9], els[13]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[0], els[8]); \
	__sort_cswap_fn(T, els[1], els[9]); \
	__sort_cswap_fn(T, els[2], els[10]); \
	__sort_cswap_fn(T, els[3], els[11]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[4], els[12]); \
	__sort_cswap_fn(T, els[5], els[13]); \
	__sort_cswap_fn(T, els[5], els[10]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[3], els[12]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[7], els[13]); \
	__sort_cswap_fn(T, els[2], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[3], els[8]); \
	__sort_cswap_fn(T, els[7], els[12]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
}

#define DEFINE_BITONIC_SORT15(T, name, __sort_cswap_fn) \
void __bitonic_sort15_ ## name(T els[15]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[8], els[12]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[9], els[13]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[10], els[14]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[0], els[8]); \
	__sort_cswap_fn(T, els[1], els[9]); \
	__sort_cswap_fn(T, els[2], els[10]); \
	__sort_cswap_fn(T, els[3], els[11]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[4], els[12]); \
	__sort_cswap_fn(T, els[5], els[13]); \
	__sort_cswap_fn(T, els[6], els[14]); \
	__sort_cswap_fn(T, els[5], els[10]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[3], els[12]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[7], els[13]); \
	__sort_cswap_fn(T, els[2], els[8]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[3], els[8]); \
	__sort_cswap_fn(T, els[7], els[12]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
}

#define DEFINE_BITONIC_SORT16(T, name, __sort_cswap_fn) \
void __bitonic_sort16_ ## name(T els[16]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[8], els[12]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[9], els[13]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[10], els[14]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[11], els[15]); \
	__sort_cswap_fn(T, els[0], els[8]); \
	__sort_cswap_fn(T, els[1], els[9]); \
	__sort_cswap_fn(T, els[2], els[10]); \
	__sort_cswap_fn(T, els[3], els[11]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[4], els[12]); \
	__sort_cswap_fn(T, els[5], els[13]); \
	__sort_cswap_fn(T, els[6], els[14]); \
	__sort_cswap_fn(T, els[7], els[15]); \
	__sort_cswap_fn(T, els[5], els[10]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[3], els[12]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[7], els[13]); \
	__sort_cswap_fn(T, els[2], els[8]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[3], els[8]); \
	__sort_cswap_fn(T, els[7], els[12]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
}

#define DEFINE_BITONIC_SORT17(T, name, __sort_cswap_fn) \
void __bitonic_sort17_ ## name(T els[17]) { \
	__sort_cswap_fn(T, els[0], els[11]); \
	__sort_cswap_fn(T, els[1], els[15]); \
	__sort_cswap_fn(T, els[2], els[10]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[8], els[12]); \
	__sort_cswap_fn(T, els[9], els[16]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[0], els[6]); \
	__sort_cswap_fn(T, els[1], els[13]); \
	__sort_cswap_fn(T, els[2], els[8]); \
	__sort_cswap_fn(T, els[4], els[14]); \
	__sort_cswap_fn(T, els[5], els[15]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[0], els[8]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[4], els[9]); \
	__sort_cswap_fn(T, els[6], els[16]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[13]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[0], els[3]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[6], els[11]); \
	__sort_cswap_fn(T, els[7], els[10]); \
	__sort_cswap_fn(T, els[9], els[13]); \
	__sort_cswap_fn(T, els[12], els[15]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[10]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[11], els[15]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[6], els[12]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[2], els[7]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
}

#define DEFINE_BITONIC_SORT18(T, name, __sort_cswap_fn) \
void __bitonic_sort18_ ## name(T els[18]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[4], els[10]); \
	__sort_cswap_fn(T, els[8], els[16]); \
	__sort_cswap_fn(T, els[9], els[17]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[0], els[8]); \
	__sort_cswap_fn(T, els[1], els[10]); \
	__sort_cswap_fn(T, els[2], els[12]); \
	__sort_cswap_fn(T, els[3], els[14]); \
	__sort_cswap_fn(T, els[6], els[13]); \
	__sort_cswap_fn(T, els[7], els[15]); \
	__sort_cswap_fn(T, els[9], els[16]); \
	__sort_cswap_fn(T, els[11], els[17]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[1], els[9]); \
	__sort_cswap_fn(T, els[5], els[17]); \
	__sort_cswap_fn(T, els[8], els[11]); \
	__sort_cswap_fn(T, els[10], els[16]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[1], els[6]); \
	__sort_cswap_fn(T, els[4], els[10]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[10]); \
	__sort_cswap_fn(T, els[4], els[12]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[6], els[14]); \
	__sort_cswap_fn(T, els[9], els[13]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[3], els[8]); \
	__sort_cswap_fn(T, els[5], els[12]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[7], els[14]); \
	__sort_cswap_fn(T, els[9], els[12]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[8], els[12]); \
	__sort_cswap_fn(T, els[11], els[15]); \
	__sort_cswap_fn(T, els[13], els[16]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
}

#define DEFINE_BITONIC_SORT19(T, name, __sort_cswap_fn) \
void __bitonic_sort19_ ## name(T els[19]) { \
	__sort_cswap_fn(T, els[0], els[12]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[2], els[8]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[6], els[17]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[9], els[14]); \
	__sort_cswap_fn(T, els[10], els[13]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[1], els[7]); \
	__sort_cswap_fn(T, els[3], els[6]); \
	__sort_cswap_fn(T, els[4], els[11]); \
	__sort_cswap_fn(T, els[5], els[17]); \
	__sort_cswap_fn(T, els[8], els[12]); \
	__sort_cswap_fn(T, els[10], els[15]); \
	__sort_cswap_fn(T, els[13], els[16]); \
	__sort_cswap_fn(T, els[14], els[18]); \
	__sort_cswap_fn(T, els[3], els[10]); \
	__sort_cswap_fn(T, els[4], els[14]); \
	__sort_cswap_fn(T, els[5], els[15]); \
	__sort_cswap_fn(T, els[6], els[13]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[11], els[17]); \
	__sort_cswap_fn(T, els[16], els[18]); \
	__sort_cswap_fn(T, els[0], els[7]); \
	__sort_cswap_fn(T, els[1], els[10]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[9], els[15]); \
	__sort_cswap_fn(T, els[11], els[16]); \
	__sort_cswap_fn(T, els[12], els[17]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[0], els[3]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[8], els[11]); \
	__sort_cswap_fn(T, els[12], els[16]); \
	__sort_cswap_fn(T, els[1], els[8]); \
	__sort_cswap_fn(T, els[2], els[9]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[6], els[15]); \
	__sort_cswap_fn(T, els[7], els[13]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[18]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[7], els[12]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[6], els[10]); \
	__sort_cswap_fn(T, els[9], els[12]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[10], els[13]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[3], els[6]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
}

#define DEFINE_BITONIC_SORT20(T, name, __sort_cswap_fn) \
void __bitonic_sort20_ ## name(T els[20]) { \
	__sort_cswap_fn(T, els[0], els[3]); \
	__sort_cswap_fn(T, els[1], els[7]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[10], els[13]); \
	__sort_cswap_fn(T, els[11], els[15]); \
	__sort_cswap_fn(T, els[12], els[18]); \
	__sort_cswap_fn(T, els[14], els[17]); \
	__sort_cswap_fn(T, els[16], els[19]); \
	__sort_cswap_fn(T, els[0], els[14]); \
	__sort_cswap_fn(T, els[1], els[11]); \
	__sort_cswap_fn(T, els[2], els[16]); \
	__sort_cswap_fn(T, els[3], els[17]); \
	__sort_cswap_fn(T, els[4], els[12]); \
	__sort_cswap_fn(T, els[5], els[19]); \
	__sort_cswap_fn(T, els[6], els[10]); \
	__sort_cswap_fn(T, els[7], els[15]); \
	__sort_cswap_fn(T, els[8], els[18]); \
	__sort_cswap_fn(T, els[9], els[13]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[8]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[11], els[16]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[15], els[19]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[1], els[6]); \
	__sort_cswap_fn(T, els[2], els[12]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[4], els[11]); \
	__sort_cswap_fn(T, els[7], els[17]); \
	__sort_cswap_fn(T, els[8], els[15]); \
	__sort_cswap_fn(T, els[13], els[18]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[7], els[10]); \
	__sort_cswap_fn(T, els[9], els[12]); \
	__sort_cswap_fn(T, els[13], els[17]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[1], els[6]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[8], els[12]); \
	__sort_cswap_fn(T, els[10], els[14]); \
	__sort_cswap_fn(T, els[13], els[18]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[4], els[7]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[12], els[15]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[6], els[10]); \
	__sort_cswap_fn(T, els[9], els[13]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[16], els[18]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[7], els[10]); \
	__sort_cswap_fn(T, els[9], els[12]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
}

#define DEFINE_BITONIC_SORT21(T, name, __sort_cswap_fn) \
void __bitonic_sort21_ ## name(T els[21]) { \
	__sort_cswap_fn(T, els[0], els[7]); \
	__sort_cswap_fn(T, els[1], els[10]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[6], els[13]); \
	__sort_cswap_fn(T, els[9], els[19]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[12], els[17]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[0], els[11]); \
	__sort_cswap_fn(T, els[1], els[15]); \
	__sort_cswap_fn(T, els[2], els[12]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[7], els[14]); \
	__sort_cswap_fn(T, els[10], els[16]); \
	__sort_cswap_fn(T, els[13], els[19]); \
	__sort_cswap_fn(T, els[17], els[20]); \
	__sort_cswap_fn(T, els[0], els[6]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[2], els[18]); \
	__sort_cswap_fn(T, els[4], els[15]); \
	__sort_cswap_fn(T, els[5], els[10]); \
	__sort_cswap_fn(T, els[8], els[16]); \
	__sort_cswap_fn(T, els[11], els[17]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[20]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[5], els[12]); \
	__sort_cswap_fn(T, els[7], els[18]); \
	__sort_cswap_fn(T, els[8], els[14]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[10], els[17]); \
	__sort_cswap_fn(T, els[13], els[19]); \
	__sort_cswap_fn(T, els[16], els[20]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[4], els[7]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[6], els[17]); \
	__sort_cswap_fn(T, els[10], els[13]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[14], els[19]); \
	__sort_cswap_fn(T, els[15], els[18]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[3], els[6]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[7], els[10]); \
	__sort_cswap_fn(T, els[8], els[11]); \
	__sort_cswap_fn(T, els[9], els[15]); \
	__sort_cswap_fn(T, els[12], els[16]); \
	__sort_cswap_fn(T, els[13], els[18]); \
	__sort_cswap_fn(T, els[14], els[17]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[6], els[12]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[16], els[19]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[9]); \
	__sort_cswap_fn(T, els[6], els[13]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[6], els[10]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[10], els[13]); \
	__sort_cswap_fn(T, els[12], els[15]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
}

#define DEFINE_BITONIC_SORT22(T, name, __sort_cswap_fn) \
void __bitonic_sort22_ ## name(T els[22]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[0], els[12]); \
	__sort_cswap_fn(T, els[1], els[13]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[4], els[10]); \
	__sort_cswap_fn(T, els[8], els[20]); \
	__sort_cswap_fn(T, els[9], els[21]); \
	__sort_cswap_fn(T, els[11], els[17]); \
	__sort_cswap_fn(T, els[14], els[18]); \
	__sort_cswap_fn(T, els[15], els[19]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[1], els[6]); \
	__sort_cswap_fn(T, els[3], els[12]); \
	__sort_cswap_fn(T, els[4], els[16]); \
	__sort_cswap_fn(T, els[5], els[17]); \
	__sort_cswap_fn(T, els[7], els[13]); \
	__sort_cswap_fn(T, els[8], els[14]); \
	__sort_cswap_fn(T, els[9], els[18]); \
	__sort_cswap_fn(T, els[15], els[20]); \
	__sort_cswap_fn(T, els[19], els[21]); \
	__sort_cswap_fn(T, els[0], els[8]); \
	__sort_cswap_fn(T, els[1], els[15]); \
	__sort_cswap_fn(T, els[2], els[14]); \
	__sort_cswap_fn(T, els[3], els[9]); \
	__sort_cswap_fn(T, els[5], els[11]); \
	__sort_cswap_fn(T, els[6], els[20]); \
	__sort_cswap_fn(T, els[7], els[19]); \
	__sort_cswap_fn(T, els[10], els[16]); \
	__sort_cswap_fn(T, els[12], els[18]); \
	__sort_cswap_fn(T, els[13], els[21]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[1], els[10]); \
	__sort_cswap_fn(T, els[3], els[8]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[7], els[14]); \
	__sort_cswap_fn(T, els[11], els[20]); \
	__sort_cswap_fn(T, els[12], els[16]); \
	__sort_cswap_fn(T, els[13], els[18]); \
	__sort_cswap_fn(T, els[17], els[21]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[7], els[10]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[12], els[15]); \
	__sort_cswap_fn(T, els[13], els[17]); \
	__sort_cswap_fn(T, els[16], els[19]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[3], els[12]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[6], els[11]); \
	__sort_cswap_fn(T, els[9], els[18]); \
	__sort_cswap_fn(T, els[10], els[15]); \
	__sort_cswap_fn(T, els[13], els[16]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[6], els[12]); \
	__sort_cswap_fn(T, els[8], els[11]); \
	__sort_cswap_fn(T, els[9], els[15]); \
	__sort_cswap_fn(T, els[10], els[13]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[7], els[12]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[9], els[14]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[13], els[16]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
}

#define DEFINE_BITONIC_SORT23(T, name, __sort_cswap_fn) \
void __bitonic_sort23_ ## name(T els[23]) { \
	__sort_cswap_fn(T, els[0], els[20]); \
	__sort_cswap_fn(T, els[1], els[12]); \
	__sort_cswap_fn(T, els[2], els[16]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[5], els[10]); \
	__sort_cswap_fn(T, els[7], els[21]); \
	__sort_cswap_fn(T, els[8], els[14]); \
	__sort_cswap_fn(T, els[9], els[15]); \
	__sort_cswap_fn(T, els[11], els[22]); \
	__sort_cswap_fn(T, els[13], els[18]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[0], els[3]); \
	__sort_cswap_fn(T, els[1], els[11]); \
	__sort_cswap_fn(T, els[2], els[7]); \
	__sort_cswap_fn(T, els[4], els[17]); \
	__sort_cswap_fn(T, els[5], els[13]); \
	__sort_cswap_fn(T, els[6], els[19]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[18]); \
	__sort_cswap_fn(T, els[12], els[22]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[21]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[3], els[12]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[7], els[10]); \
	__sort_cswap_fn(T, els[11], els[20]); \
	__sort_cswap_fn(T, els[13], els[16]); \
	__sort_cswap_fn(T, els[14], els[17]); \
	__sort_cswap_fn(T, els[15], els[18]); \
	__sort_cswap_fn(T, els[19], els[21]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[6], els[11]); \
	__sort_cswap_fn(T, els[7], els[14]); \
	__sort_cswap_fn(T, els[9], els[16]); \
	__sort_cswap_fn(T, els[12], els[17]); \
	__sort_cswap_fn(T, els[15], els[19]); \
	__sort_cswap_fn(T, els[18], els[21]); \
	__sort_cswap_fn(T, els[1], els[8]); \
	__sort_cswap_fn(T, els[3], els[14]); \
	__sort_cswap_fn(T, els[4], els[7]); \
	__sort_cswap_fn(T, els[9], els[20]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[15], els[22]); \
	__sort_cswap_fn(T, els[16], els[19]); \
	__sort_cswap_fn(T, els[0], els[7]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[6], els[11]); \
	__sort_cswap_fn(T, els[8], els[15]); \
	__sort_cswap_fn(T, els[9], els[14]); \
	__sort_cswap_fn(T, els[10], els[13]); \
	__sort_cswap_fn(T, els[12], els[17]); \
	__sort_cswap_fn(T, els[18], els[22]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[1], els[6]); \
	__sort_cswap_fn(T, els[4], els[7]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[14], els[18]); \
	__sort_cswap_fn(T, els[16], els[19]); \
	__sort_cswap_fn(T, els[17], els[22]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[6]); \
	__sort_cswap_fn(T, els[4], els[10]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[13], els[19]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[20]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[5], els[10]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[13], els[18]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[16], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[9], els[12]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[18]); \
}

#define DEFINE_BITONIC_SORT24(T, name, __sort_cswap_fn) \
void __bitonic_sort24_ ## name(T els[24]) { \
	__sort_cswap_fn(T, els[0], els[20]); \
	__sort_cswap_fn(T, els[1], els[12]); \
	__sort_cswap_fn(T, els[2], els[16]); \
	__sort_cswap_fn(T, els[3], els[23]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[5], els[10]); \
	__sort_cswap_fn(T, els[7], els[21]); \
	__sort_cswap_fn(T, els[8], els[14]); \
	__sort_cswap_fn(T, els[9], els[15]); \
	__sort_cswap_fn(T, els[11], els[22]); \
	__sort_cswap_fn(T, els[13], els[18]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[0], els[3]); \
	__sort_cswap_fn(T, els[1], els[11]); \
	__sort_cswap_fn(T, els[2], els[7]); \
	__sort_cswap_fn(T, els[4], els[17]); \
	__sort_cswap_fn(T, els[5], els[13]); \
	__sort_cswap_fn(T, els[6], els[19]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[18]); \
	__sort_cswap_fn(T, els[12], els[22]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[21]); \
	__sort_cswap_fn(T, els[20], els[23]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[3], els[12]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[7], els[10]); \
	__sort_cswap_fn(T, els[11], els[20]); \
	__sort_cswap_fn(T, els[13], els[16]); \
	__sort_cswap_fn(T, els[14], els[17]); \
	__sort_cswap_fn(T, els[15], els[18]); \
	__sort_cswap_fn(T, els[19], els[21]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[6], els[11]); \
	__sort_cswap_fn(T, els[7], els[14]); \
	__sort_cswap_fn(T, els[9], els[16]); \
	__sort_cswap_fn(T, els[12], els[17]); \
	__sort_cswap_fn(T, els[15], els[19]); \
	__sort_cswap_fn(T, els[18], els[21]); \
	__sort_cswap_fn(T, els[1], els[8]); \
	__sort_cswap_fn(T, els[3], els[14]); \
	__sort_cswap_fn(T, els[4], els[7]); \
	__sort_cswap_fn(T, els[9], els[20]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[15], els[22]); \
	__sort_cswap_fn(T, els[16], els[19]); \
	__sort_cswap_fn(T, els[0], els[7]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[6], els[11]); \
	__sort_cswap_fn(T, els[8], els[15]); \
	__sort_cswap_fn(T, els[9], els[14]); \
	__sort_cswap_fn(T, els[10], els[13]); \
	__sort_cswap_fn(T, els[12], els[17]); \
	__sort_cswap_fn(T, els[16], els[23]); \
	__sort_cswap_fn(T, els[18], els[22]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[1], els[6]); \
	__sort_cswap_fn(T, els[4], els[7]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[14], els[18]); \
	__sort_cswap_fn(T, els[16], els[19]); \
	__sort_cswap_fn(T, els[17], els[22]); \
	__sort_cswap_fn(T, els[21], els[23]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[6]); \
	__sort_cswap_fn(T, els[4], els[10]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[13], els[19]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[20]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[5], els[10]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[13], els[18]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[16], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[9], els[12]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[18]); \
}

#define DEFINE_BITONIC_SORT25(T, name, __sort_cswap_fn) \
void __bitonic_sort25_ ## name(T els[25]) { \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[1], els[8]); \
	__sort_cswap_fn(T, els[3], els[18]); \
	__sort_cswap_fn(T, els[4], els[17]); \
	__sort_cswap_fn(T, els[5], els[20]); \
	__sort_cswap_fn(T, els[6], els[19]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[15], els[22]); \
	__sort_cswap_fn(T, els[21], els[23]); \
	__sort_cswap_fn(T, els[0], els[3]); \
	__sort_cswap_fn(T, els[1], els[15]); \
	__sort_cswap_fn(T, els[2], els[18]); \
	__sort_cswap_fn(T, els[4], els[12]); \
	__sort_cswap_fn(T, els[5], els[21]); \
	__sort_cswap_fn(T, els[6], els[10]); \
	__sort_cswap_fn(T, els[7], els[14]); \
	__sort_cswap_fn(T, els[8], els[22]); \
	__sort_cswap_fn(T, els[9], els[16]); \
	__sort_cswap_fn(T, els[11], els[19]); \
	__sort_cswap_fn(T, els[13], els[17]); \
	__sort_cswap_fn(T, els[20], els[23]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[1], els[7]); \
	__sort_cswap_fn(T, els[2], els[13]); \
	__sort_cswap_fn(T, els[3], els[12]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[8], els[14]); \
	__sort_cswap_fn(T, els[9], els[15]); \
	__sort_cswap_fn(T, els[10], els[21]); \
	__sort_cswap_fn(T, els[11], els[20]); \
	__sort_cswap_fn(T, els[16], els[22]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[23]); \
	__sort_cswap_fn(T, els[0], els[5]); \
	__sort_cswap_fn(T, els[2], els[11]); \
	__sort_cswap_fn(T, els[3], els[6]); \
	__sort_cswap_fn(T, els[4], els[10]); \
	__sort_cswap_fn(T, els[7], els[16]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[12], els[21]); \
	__sort_cswap_fn(T, els[13], els[19]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[17], els[20]); \
	__sort_cswap_fn(T, els[18], els[23]); \
	__sort_cswap_fn(T, els[2], els[7]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[8], els[11]); \
	__sort_cswap_fn(T, els[14], els[24]); \
	__sort_cswap_fn(T, els[18], els[21]); \
	__sort_cswap_fn(T, els[3], els[8]); \
	__sort_cswap_fn(T, els[7], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[21]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[22], els[24]); \
	__sort_cswap_fn(T, els[4], els[13]); \
	__sort_cswap_fn(T, els[10], els[16]); \
	__sort_cswap_fn(T, els[11], els[15]); \
	__sort_cswap_fn(T, els[18], els[24]); \
	__sort_cswap_fn(T, els[19], els[22]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[8], els[11]); \
	__sort_cswap_fn(T, els[9], els[19]); \
	__sort_cswap_fn(T, els[13], els[17]); \
	__sort_cswap_fn(T, els[14], els[18]); \
	__sort_cswap_fn(T, els[16], els[20]); \
	__sort_cswap_fn(T, els[23], els[24]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[13]); \
	__sort_cswap_fn(T, els[9], els[14]); \
	__sort_cswap_fn(T, els[10], els[17]); \
	__sort_cswap_fn(T, els[12], els[16]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[13]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[12], els[18]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[16], els[19]); \
	__sort_cswap_fn(T, els[20], els[22]); \
	__sort_cswap_fn(T, els[21], els[23]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[17], els[20]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[13]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[9], els[12]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[16], els[18]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[14], els[17]); \
	__sort_cswap_fn(T, els[16], els[19]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[18], els[19]); \
}

#define DEFINE_BITONIC_SORT26(T, name, __sort_cswap_fn) \
void __bitonic_sort26_ ## name(T els[26]) { \
	__sort_cswap_fn(T, els[0], els[25]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[2], els[9]); \
	__sort_cswap_fn(T, els[4], els[19]); \
	__sort_cswap_fn(T, els[5], els[18]); \
	__sort_cswap_fn(T, els[6], els[21]); \
	__sort_cswap_fn(T, els[7], els[20]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[16], els[23]); \
	__sort_cswap_fn(T, els[22], els[24]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[2], els[16]); \
	__sort_cswap_fn(T, els[3], els[19]); \
	__sort_cswap_fn(T, els[5], els[13]); \
	__sort_cswap_fn(T, els[6], els[22]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[8], els[15]); \
	__sort_cswap_fn(T, els[9], els[23]); \
	__sort_cswap_fn(T, els[10], els[17]); \
	__sort_cswap_fn(T, els[12], els[20]); \
	__sort_cswap_fn(T, els[14], els[18]); \
	__sort_cswap_fn(T, els[21], els[24]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[2], els[8]); \
	__sort_cswap_fn(T, els[3], els[14]); \
	__sort_cswap_fn(T, els[4], els[13]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[9], els[15]); \
	__sort_cswap_fn(T, els[10], els[16]); \
	__sort_cswap_fn(T, els[11], els[22]); \
	__sort_cswap_fn(T, els[12], els[21]); \
	__sort_cswap_fn(T, els[17], els[23]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[20], els[24]); \
	__sort_cswap_fn(T, els[0], els[10]); \
	__sort_cswap_fn(T, els[1], els[6]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[4], els[11]); \
	__sort_cswap_fn(T, els[5], els[12]); \
	__sort_cswap_fn(T, els[13], els[20]); \
	__sort_cswap_fn(T, els[14], els[21]); \
	__sort_cswap_fn(T, els[15], els[25]); \
	__sort_cswap_fn(T, els[18], els[22]); \
	__sort_cswap_fn(T, els[19], els[24]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[21], els[25]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[17], els[21]); \
	__sort_cswap_fn(T, els[23], els[25]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[8], els[14]); \
	__sort_cswap_fn(T, els[9], els[13]); \
	__sort_cswap_fn(T, els[11], els[17]); \
	__sort_cswap_fn(T, els[12], els[16]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[24], els[25]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[3], els[10]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[7], els[13]); \
	__sort_cswap_fn(T, els[8], els[11]); \
	__sort_cswap_fn(T, els[12], els[18]); \
	__sort_cswap_fn(T, els[14], els[17]); \
	__sort_cswap_fn(T, els[15], els[22]); \
	__sort_cswap_fn(T, els[16], els[19]); \
	__sort_cswap_fn(T, els[21], els[24]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[3], els[8]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[9], els[12]); \
	__sort_cswap_fn(T, els[13], els[16]); \
	__sort_cswap_fn(T, els[17], els[22]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[19], els[23]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[7], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[18]); \
	__sort_cswap_fn(T, els[16], els[20]); \
	__sort_cswap_fn(T, els[19], els[21]); \
	__sort_cswap_fn(T, els[23], els[24]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[7], els[13]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[14]); \
	__sort_cswap_fn(T, els[11], els[15]); \
	__sort_cswap_fn(T, els[12], els[18]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[20], els[22]); \
	__sort_cswap_fn(T, els[21], els[23]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[14], els[18]); \
	__sort_cswap_fn(T, els[16], els[19]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[9], els[13]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[16]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[20], els[21]); \
}

#define DEFINE_BITONIC_SORT27(T, name, __sort_cswap_fn) \
void __bitonic_sort27_ ## name(T els[27]) { \
	__sort_cswap_fn(T, els[0], els[9]); \
	__sort_cswap_fn(T, els[1], els[6]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[11], els[24]); \
	__sort_cswap_fn(T, els[12], els[23]); \
	__sort_cswap_fn(T, els[13], els[26]); \
	__sort_cswap_fn(T, els[14], els[25]); \
	__sort_cswap_fn(T, els[15], els[19]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[18], els[22]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[4], els[10]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[11], els[16]); \
	__sort_cswap_fn(T, els[12], els[18]); \
	__sort_cswap_fn(T, els[13], els[20]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[17], els[24]); \
	__sort_cswap_fn(T, els[19], els[25]); \
	__sort_cswap_fn(T, els[21], els[26]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[4], els[7]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[23], els[24]); \
	__sort_cswap_fn(T, els[25], els[26]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[15], els[21]); \
	__sort_cswap_fn(T, els[16], els[22]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[23], els[25]); \
	__sort_cswap_fn(T, els[24], els[26]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[23]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[16], els[18]); \
	__sort_cswap_fn(T, els[19], els[21]); \
	__sort_cswap_fn(T, els[20], els[22]); \
	__sort_cswap_fn(T, els[24], els[25]); \
	__sort_cswap_fn(T, els[0], els[11]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[3], els[6]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[12], els[15]); \
	__sort_cswap_fn(T, els[13], els[17]); \
	__sort_cswap_fn(T, els[16], els[19]); \
	__sort_cswap_fn(T, els[18], els[21]); \
	__sort_cswap_fn(T, els[20], els[24]); \
	__sort_cswap_fn(T, els[22], els[25]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[14], els[17]); \
	__sort_cswap_fn(T, els[20], els[23]); \
	__sort_cswap_fn(T, els[22], els[24]); \
	__sort_cswap_fn(T, els[1], els[12]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[21], els[23]); \
	__sort_cswap_fn(T, els[2], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[3], els[14]); \
	__sort_cswap_fn(T, els[4], els[15]); \
	__sort_cswap_fn(T, els[5], els[16]); \
	__sort_cswap_fn(T, els[10], els[21]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[6], els[17]); \
	__sort_cswap_fn(T, els[7], els[18]); \
	__sort_cswap_fn(T, els[8], els[19]); \
	__sort_cswap_fn(T, els[9], els[20]); \
	__sort_cswap_fn(T, els[10], els[13]); \
	__sort_cswap_fn(T, els[14], els[22]); \
	__sort_cswap_fn(T, els[15], els[23]); \
	__sort_cswap_fn(T, els[16], els[24]); \
	__sort_cswap_fn(T, els[6], els[10]); \
	__sort_cswap_fn(T, els[7], els[14]); \
	__sort_cswap_fn(T, els[8], els[11]); \
	__sort_cswap_fn(T, els[9], els[12]); \
	__sort_cswap_fn(T, els[17], els[25]); \
	__sort_cswap_fn(T, els[18], els[26]); \
	__sort_cswap_fn(T, els[19], els[23]); \
	__sort_cswap_fn(T, els[20], els[24]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[11], els[15]); \
	__sort_cswap_fn(T, els[12], els[16]); \
	__sort_cswap_fn(T, els[13], els[17]); \
	__sort_cswap_fn(T, els[18], els[22]); \
	__sort_cswap_fn(T, els[21], els[25]); \
	__sort_cswap_fn(T, els[24], els[26]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[16], els[18]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[20], els[22]); \
	__sort_cswap_fn(T, els[21], els[23]); \
	__sort_cswap_fn(T, els[25], els[26]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[23], els[24]); \
}

#define DEFINE_BITONIC_SORT28(T, name, __sort_cswap_fn) \
void __bitonic_sort28_ ## name(T els[28]) { \
	__sort_cswap_fn(T, els[0], els[9]); \
	__sort_cswap_fn(T, els[1], els[20]); \
	__sort_cswap_fn(T, els[2], els[21]); \
	__sort_cswap_fn(T, els[3], els[22]); \
	__sort_cswap_fn(T, els[4], els[19]); \
	__sort_cswap_fn(T, els[5], els[24]); \
	__sort_cswap_fn(T, els[6], els[25]); \
	__sort_cswap_fn(T, els[7], els[26]); \
	__sort_cswap_fn(T, els[8], els[23]); \
	__sort_cswap_fn(T, els[10], els[15]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[12], els[17]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[18], els[27]); \
	__sort_cswap_fn(T, els[0], els[18]); \
	__sort_cswap_fn(T, els[1], els[7]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[9], els[27]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[13], els[16]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[19], els[23]); \
	__sort_cswap_fn(T, els[20], els[26]); \
	__sort_cswap_fn(T, els[21], els[25]); \
	__sort_cswap_fn(T, els[22], els[24]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[19]); \
	__sort_cswap_fn(T, els[6], els[20]); \
	__sort_cswap_fn(T, els[7], els[21]); \
	__sort_cswap_fn(T, els[8], els[22]); \
	__sort_cswap_fn(T, els[9], els[18]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[23], els[24]); \
	__sort_cswap_fn(T, els[25], els[26]); \
	__sort_cswap_fn(T, els[0], els[3]); \
	__sort_cswap_fn(T, els[1], els[10]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[17], els[26]); \
	__sort_cswap_fn(T, els[19], els[22]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[24], els[27]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[7]); \
	__sort_cswap_fn(T, els[3], els[10]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[17], els[24]); \
	__sort_cswap_fn(T, els[19], els[23]); \
	__sort_cswap_fn(T, els[20], els[25]); \
	__sort_cswap_fn(T, els[26], els[27]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[7], els[19]); \
	__sort_cswap_fn(T, els[8], els[20]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[21], els[25]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[24], els[26]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[5], els[12]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[10], els[14]); \
	__sort_cswap_fn(T, els[13], els[17]); \
	__sort_cswap_fn(T, els[15], els[22]); \
	__sort_cswap_fn(T, els[16], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[23], els[25]); \
	__sort_cswap_fn(T, els[2], els[9]); \
	__sort_cswap_fn(T, els[4], els[11]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[13]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[14], els[20]); \
	__sort_cswap_fn(T, els[16], els[23]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[18], els[25]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[16]); \
	__sort_cswap_fn(T, els[4], els[9]); \
	__sort_cswap_fn(T, els[6], els[12]); \
	__sort_cswap_fn(T, els[10], els[14]); \
	__sort_cswap_fn(T, els[11], els[24]); \
	__sort_cswap_fn(T, els[13], els[17]); \
	__sort_cswap_fn(T, els[15], els[21]); \
	__sort_cswap_fn(T, els[18], els[23]); \
	__sort_cswap_fn(T, els[25], els[26]); \
	__sort_cswap_fn(T, els[2], els[8]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[4], els[7]); \
	__sort_cswap_fn(T, els[6], els[16]); \
	__sort_cswap_fn(T, els[9], els[15]); \
	__sort_cswap_fn(T, els[11], els[21]); \
	__sort_cswap_fn(T, els[12], els[18]); \
	__sort_cswap_fn(T, els[19], els[25]); \
	__sort_cswap_fn(T, els[20], els[23]); \
	__sort_cswap_fn(T, els[22], els[24]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[11], els[15]); \
	__sort_cswap_fn(T, els[12], els[16]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[19], els[22]); \
	__sort_cswap_fn(T, els[24], els[25]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[19], els[21]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[18]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[23], els[24]); \
}

#define DEFINE_BITONIC_SORT29(T, name, __sort_cswap_fn) \
void __bitonic_sort29_ ## name(T els[29]) { \
	__sort_cswap_fn(T, els[0], els[12]); \
	__sort_cswap_fn(T, els[1], els[10]); \
	__sort_cswap_fn(T, els[2], els[9]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[5], els[11]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[13], els[26]); \
	__sort_cswap_fn(T, els[14], els[25]); \
	__sort_cswap_fn(T, els[15], els[28]); \
	__sort_cswap_fn(T, els[16], els[27]); \
	__sort_cswap_fn(T, els[17], els[21]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[20], els[24]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[1], els[6]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[11]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[13], els[18]); \
	__sort_cswap_fn(T, els[14], els[20]); \
	__sort_cswap_fn(T, els[15], els[22]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[19], els[26]); \
	__sort_cswap_fn(T, els[21], els[27]); \
	__sort_cswap_fn(T, els[23], els[28]); \
	__sort_cswap_fn(T, els[24], els[25]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[21]); \
	__sort_cswap_fn(T, els[20], els[22]); \
	__sort_cswap_fn(T, els[23], els[24]); \
	__sort_cswap_fn(T, els[25], els[26]); \
	__sort_cswap_fn(T, els[27], els[28]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[8], els[11]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[17], els[23]); \
	__sort_cswap_fn(T, els[18], els[24]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[25], els[27]); \
	__sort_cswap_fn(T, els[26], els[28]); \
	__sort_cswap_fn(T, els[0], els[5]); \
	__sort_cswap_fn(T, els[3], els[8]); \
	__sort_cswap_fn(T, els[4], els[7]); \
	__sort_cswap_fn(T, els[6], els[11]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[25]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[21], els[23]); \
	__sort_cswap_fn(T, els[22], els[24]); \
	__sort_cswap_fn(T, els[26], els[27]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[14], els[17]); \
	__sort_cswap_fn(T, els[15], els[19]); \
	__sort_cswap_fn(T, els[18], els[21]); \
	__sort_cswap_fn(T, els[20], els[23]); \
	__sort_cswap_fn(T, els[22], els[26]); \
	__sort_cswap_fn(T, els[24], els[27]); \
	__sort_cswap_fn(T, els[0], els[13]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[16], els[19]); \
	__sort_cswap_fn(T, els[22], els[25]); \
	__sort_cswap_fn(T, els[24], els[26]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[16], els[18]); \
	__sort_cswap_fn(T, els[19], els[21]); \
	__sort_cswap_fn(T, els[20], els[22]); \
	__sort_cswap_fn(T, els[23], els[25]); \
	__sort_cswap_fn(T, els[1], els[14]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[24], els[25]); \
	__sort_cswap_fn(T, els[2], els[15]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[10], els[23]); \
	__sort_cswap_fn(T, els[11], els[24]); \
	__sort_cswap_fn(T, els[12], els[25]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[3], els[16]); \
	__sort_cswap_fn(T, els[4], els[17]); \
	__sort_cswap_fn(T, els[5], els[18]); \
	__sort_cswap_fn(T, els[6], els[19]); \
	__sort_cswap_fn(T, els[7], els[20]); \
	__sort_cswap_fn(T, els[8], els[21]); \
	__sort_cswap_fn(T, els[9], els[22]); \
	__sort_cswap_fn(T, els[10], els[15]); \
	__sort_cswap_fn(T, els[6], els[10]); \
	__sort_cswap_fn(T, els[8], els[13]); \
	__sort_cswap_fn(T, els[9], els[14]); \
	__sort_cswap_fn(T, els[11], els[16]); \
	__sort_cswap_fn(T, els[12], els[17]); \
	__sort_cswap_fn(T, els[18], els[26]); \
	__sort_cswap_fn(T, els[19], els[27]); \
	__sort_cswap_fn(T, els[20], els[28]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[18]); \
	__sort_cswap_fn(T, els[15], els[19]); \
	__sort_cswap_fn(T, els[16], els[20]); \
	__sort_cswap_fn(T, els[17], els[21]); \
	__sort_cswap_fn(T, els[22], els[26]); \
	__sort_cswap_fn(T, els[23], els[27]); \
	__sort_cswap_fn(T, els[24], els[28]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[16], els[18]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[20], els[22]); \
	__sort_cswap_fn(T, els[21], els[23]); \
	__sort_cswap_fn(T, els[24], els[26]); \
	__sort_cswap_fn(T, els[25], els[27]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[23], els[24]); \
	__sort_cswap_fn(T, els[25], els[26]); \
	__sort_cswap_fn(T, els[27], els[28]); \
}

#define DEFINE_BITONIC_SORT30(T, name, __sort_cswap_fn) \
void __bitonic_sort30_ ## name(T els[30]) { \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[10]); \
	__sort_cswap_fn(T, els[4], els[14]); \
	__sort_cswap_fn(T, els[5], els[8]); \
	__sort_cswap_fn(T, els[6], els[13]); \
	__sort_cswap_fn(T, els[7], els[12]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[18], els[25]); \
	__sort_cswap_fn(T, els[19], els[29]); \
	__sort_cswap_fn(T, els[20], els[23]); \
	__sort_cswap_fn(T, els[21], els[28]); \
	__sort_cswap_fn(T, els[22], els[27]); \
	__sort_cswap_fn(T, els[24], els[26]); \
	__sort_cswap_fn(T, els[0], els[14]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[2], els[8]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[15], els[29]); \
	__sort_cswap_fn(T, els[16], els[20]); \
	__sort_cswap_fn(T, els[17], els[23]); \
	__sort_cswap_fn(T, els[18], els[22]); \
	__sort_cswap_fn(T, els[21], els[24]); \
	__sort_cswap_fn(T, els[25], els[27]); \
	__sort_cswap_fn(T, els[26], els[28]); \
	__sort_cswap_fn(T, els[0], els[7]); \
	__sort_cswap_fn(T, els[1], els[6]); \
	__sort_cswap_fn(T, els[2], els[9]); \
	__sort_cswap_fn(T, els[4], els[10]); \
	__sort_cswap_fn(T, els[5], els[11]); \
	__sort_cswap_fn(T, els[8], els[13]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[15], els[22]); \
	__sort_cswap_fn(T, els[16], els[21]); \
	__sort_cswap_fn(T, els[17], els[24]); \
	__sort_cswap_fn(T, els[19], els[25]); \
	__sort_cswap_fn(T, els[20], els[26]); \
	__sort_cswap_fn(T, els[23], els[28]); \
	__sort_cswap_fn(T, els[27], els[29]); \
	__sort_cswap_fn(T, els[0], els[6]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[9], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[21]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[22], els[26]); \
	__sort_cswap_fn(T, els[23], els[25]); \
	__sort_cswap_fn(T, els[24], els[27]); \
	__sort_cswap_fn(T, els[28], els[29]); \
	__sort_cswap_fn(T, els[0], els[3]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[4], els[7]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[29]); \
	__sort_cswap_fn(T, els[15], els[18]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[19], els[22]); \
	__sort_cswap_fn(T, els[20], els[24]); \
	__sort_cswap_fn(T, els[21], els[23]); \
	__sort_cswap_fn(T, els[25], els[26]); \
	__sort_cswap_fn(T, els[27], els[28]); \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[21]); \
	__sort_cswap_fn(T, els[22], els[24]); \
	__sort_cswap_fn(T, els[25], els[27]); \
	__sort_cswap_fn(T, els[26], els[28]); \
	__sort_cswap_fn(T, els[0], els[15]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[28]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[23], els[25]); \
	__sort_cswap_fn(T, els[26], els[27]); \
	__sort_cswap_fn(T, els[1], els[16]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[12], els[27]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[24], els[25]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[23], els[24]); \
	__sort_cswap_fn(T, els[25], els[26]); \
	__sort_cswap_fn(T, els[2], els[17]); \
	__sort_cswap_fn(T, els[3], els[18]); \
	__sort_cswap_fn(T, els[4], els[19]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[24]); \
	__sort_cswap_fn(T, els[10], els[25]); \
	__sort_cswap_fn(T, els[11], els[26]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[5], els[20]); \
	__sort_cswap_fn(T, els[6], els[21]); \
	__sort_cswap_fn(T, els[7], els[22]); \
	__sort_cswap_fn(T, els[8], els[23]); \
	__sort_cswap_fn(T, els[9], els[16]); \
	__sort_cswap_fn(T, els[10], els[17]); \
	__sort_cswap_fn(T, els[11], els[18]); \
	__sort_cswap_fn(T, els[12], els[19]); \
	__sort_cswap_fn(T, els[5], els[9]); \
	__sort_cswap_fn(T, els[6], els[10]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[8], els[15]); \
	__sort_cswap_fn(T, els[13], els[20]); \
	__sort_cswap_fn(T, els[14], els[21]); \
	__sort_cswap_fn(T, els[18], els[22]); \
	__sort_cswap_fn(T, els[19], els[23]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[12], els[15]); \
	__sort_cswap_fn(T, els[13], els[16]); \
	__sort_cswap_fn(T, els[14], els[17]); \
	__sort_cswap_fn(T, els[20], els[24]); \
	__sort_cswap_fn(T, els[21], els[25]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[6], els[8]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[18]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[20], els[22]); \
	__sort_cswap_fn(T, els[21], els[23]); \
	__sort_cswap_fn(T, els[24], els[26]); \
	__sort_cswap_fn(T, els[25], els[27]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[23], els[24]); \
	__sort_cswap_fn(T, els[25], els[26]); \
	__sort_cswap_fn(T, els[27], els[28]); \
}

#define DEFINE_BITONIC_SORT31(T, name, __sort_cswap_fn) \
void __bitonic_sort31_ ## name(T els[31]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[24], els[25]); \
	__sort_cswap_fn(T, els[26], els[27]); \
	__sort_cswap_fn(T, els[28], els[29]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[16], els[18]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[20], els[22]); \
	__sort_cswap_fn(T, els[21], els[23]); \
	__sort_cswap_fn(T, els[24], els[26]); \
	__sort_cswap_fn(T, els[25], els[27]); \
	__sort_cswap_fn(T, els[28], els[30]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[8], els[12]); \
	__sort_cswap_fn(T, els[9], els[13]); \
	__sort_cswap_fn(T, els[10], els[14]); \
	__sort_cswap_fn(T, els[11], els[15]); \
	__sort_cswap_fn(T, els[16], els[20]); \
	__sort_cswap_fn(T, els[17], els[21]); \
	__sort_cswap_fn(T, els[18], els[22]); \
	__sort_cswap_fn(T, els[19], els[23]); \
	__sort_cswap_fn(T, els[24], els[28]); \
	__sort_cswap_fn(T, els[25], els[29]); \
	__sort_cswap_fn(T, els[26], els[30]); \
	__sort_cswap_fn(T, els[0], els[8]); \
	__sort_cswap_fn(T, els[1], els[9]); \
	__sort_cswap_fn(T, els[2], els[10]); \
	__sort_cswap_fn(T, els[3], els[11]); \
	__sort_cswap_fn(T, els[4], els[12]); \
	__sort_cswap_fn(T, els[5], els[13]); \
	__sort_cswap_fn(T, els[6], els[14]); \
	__sort_cswap_fn(T, els[7], els[15]); \
	__sort_cswap_fn(T, els[16], els[24]); \
	__sort_cswap_fn(T, els[17], els[25]); \
	__sort_cswap_fn(T, els[18], els[26]); \
	__sort_cswap_fn(T, els[19], els[27]); \
	__sort_cswap_fn(T, els[20], els[28]); \
	__sort_cswap_fn(T, els[21], els[29]); \
	__sort_cswap_fn(T, els[22], els[30]); \
	__sort_cswap_fn(T, els[0], els[16]); \
	__sort_cswap_fn(T, els[1], els[8]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[3], els[12]); \
	__sort_cswap_fn(T, els[5], els[10]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[7], els[14]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[17], els[24]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[19], els[28]); \
	__sort_cswap_fn(T, els[21], els[26]); \
	__sort_cswap_fn(T, els[22], els[25]); \
	__sort_cswap_fn(T, els[23], els[30]); \
	__sort_cswap_fn(T, els[27], els[29]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[6], els[22]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[9], els[25]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[21]); \
	__sort_cswap_fn(T, els[20], els[24]); \
	__sort_cswap_fn(T, els[23], els[27]); \
	__sort_cswap_fn(T, els[26], els[28]); \
	__sort_cswap_fn(T, els[29], els[30]); \
	__sort_cswap_fn(T, els[1], els[17]); \
	__sort_cswap_fn(T, els[2], els[18]); \
	__sort_cswap_fn(T, els[3], els[19]); \
	__sort_cswap_fn(T, els[4], els[20]); \
	__sort_cswap_fn(T, els[5], els[10]); \
	__sort_cswap_fn(T, els[7], els[23]); \
	__sort_cswap_fn(T, els[8], els[24]); \
	__sort_cswap_fn(T, els[11], els[27]); \
	__sort_cswap_fn(T, els[12], els[28]); \
	__sort_cswap_fn(T, els[13], els[29]); \
	__sort_cswap_fn(T, els[14], els[30]); \
	__sort_cswap_fn(T, els[21], els[26]); \
	__sort_cswap_fn(T, els[3], els[17]); \
	__sort_cswap_fn(T, els[4], els[16]); \
	__sort_cswap_fn(T, els[5], els[21]); \
	__sort_cswap_fn(T, els[6], els[18]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[8], els[20]); \
	__sort_cswap_fn(T, els[10], els[26]); \
	__sort_cswap_fn(T, els[11], els[23]); \
	__sort_cswap_fn(T, els[13], els[25]); \
	__sort_cswap_fn(T, els[14], els[28]); \
	__sort_cswap_fn(T, els[15], els[27]); \
	__sort_cswap_fn(T, els[22], els[24]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[3], els[8]); \
	__sort_cswap_fn(T, els[5], els[16]); \
	__sort_cswap_fn(T, els[7], els[17]); \
	__sort_cswap_fn(T, els[9], els[21]); \
	__sort_cswap_fn(T, els[10], els[22]); \
	__sort_cswap_fn(T, els[11], els[19]); \
	__sort_cswap_fn(T, els[12], els[20]); \
	__sort_cswap_fn(T, els[14], els[24]); \
	__sort_cswap_fn(T, els[15], els[26]); \
	__sort_cswap_fn(T, els[23], els[28]); \
	__sort_cswap_fn(T, els[27], els[30]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[18]); \
	__sort_cswap_fn(T, els[11], els[17]); \
	__sort_cswap_fn(T, els[12], els[16]); \
	__sort_cswap_fn(T, els[13], els[22]); \
	__sort_cswap_fn(T, els[14], els[20]); \
	__sort_cswap_fn(T, els[15], els[19]); \
	__sort_cswap_fn(T, els[23], els[24]); \
	__sort_cswap_fn(T, els[26], els[29]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[6], els[12]); \
	__sort_cswap_fn(T, els[9], els[16]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[13], els[17]); \
	__sort_cswap_fn(T, els[14], els[18]); \
	__sort_cswap_fn(T, els[15], els[22]); \
	__sort_cswap_fn(T, els[19], els[25]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[27], els[29]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[8], els[12]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[19], els[23]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[25], els[26]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[13], els[16]); \
	__sort_cswap_fn(T, els[15], els[18]); \
	__sort_cswap_fn(T, els[17], els[20]); \
	__sort_cswap_fn(T, els[19], els[21]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[24], els[25]); \
	__sort_cswap_fn(T, els[26], els[28]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[23], els[24]); \
	__sort_cswap_fn(T, els[25], els[26]); \
	__sort_cswap_fn(T, els[27], els[28]); \
}

#define DEFINE_BITONIC_SORT32(T, name, __sort_cswap_fn) \
void __bitonic_sort32_ ## name(T els[32]) { \
	__sort_cswap_fn(T, els[0], els[1]); \
	__sort_cswap_fn(T, els[2], els[3]); \
	__sort_cswap_fn(T, els[4], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[12], els[13]); \
	__sort_cswap_fn(T, els[14], els[15]); \
	__sort_cswap_fn(T, els[16], els[17]); \
	__sort_cswap_fn(T, els[18], els[19]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[24], els[25]); \
	__sort_cswap_fn(T, els[26], els[27]); \
	__sort_cswap_fn(T, els[28], els[29]); \
	__sort_cswap_fn(T, els[30], els[31]); \
	__sort_cswap_fn(T, els[0], els[2]); \
	__sort_cswap_fn(T, els[1], els[3]); \
	__sort_cswap_fn(T, els[4], els[6]); \
	__sort_cswap_fn(T, els[5], els[7]); \
	__sort_cswap_fn(T, els[8], els[10]); \
	__sort_cswap_fn(T, els[9], els[11]); \
	__sort_cswap_fn(T, els[12], els[14]); \
	__sort_cswap_fn(T, els[13], els[15]); \
	__sort_cswap_fn(T, els[16], els[18]); \
	__sort_cswap_fn(T, els[17], els[19]); \
	__sort_cswap_fn(T, els[20], els[22]); \
	__sort_cswap_fn(T, els[21], els[23]); \
	__sort_cswap_fn(T, els[24], els[26]); \
	__sort_cswap_fn(T, els[25], els[27]); \
	__sort_cswap_fn(T, els[28], els[30]); \
	__sort_cswap_fn(T, els[29], els[31]); \
	__sort_cswap_fn(T, els[0], els[4]); \
	__sort_cswap_fn(T, els[1], els[5]); \
	__sort_cswap_fn(T, els[2], els[6]); \
	__sort_cswap_fn(T, els[3], els[7]); \
	__sort_cswap_fn(T, els[8], els[12]); \
	__sort_cswap_fn(T, els[9], els[13]); \
	__sort_cswap_fn(T, els[10], els[14]); \
	__sort_cswap_fn(T, els[11], els[15]); \
	__sort_cswap_fn(T, els[16], els[20]); \
	__sort_cswap_fn(T, els[17], els[21]); \
	__sort_cswap_fn(T, els[18], els[22]); \
	__sort_cswap_fn(T, els[19], els[23]); \
	__sort_cswap_fn(T, els[24], els[28]); \
	__sort_cswap_fn(T, els[25], els[29]); \
	__sort_cswap_fn(T, els[26], els[30]); \
	__sort_cswap_fn(T, els[27], els[31]); \
	__sort_cswap_fn(T, els[0], els[8]); \
	__sort_cswap_fn(T, els[1], els[9]); \
	__sort_cswap_fn(T, els[2], els[10]); \
	__sort_cswap_fn(T, els[3], els[11]); \
	__sort_cswap_fn(T, els[4], els[12]); \
	__sort_cswap_fn(T, els[5], els[13]); \
	__sort_cswap_fn(T, els[6], els[14]); \
	__sort_cswap_fn(T, els[7], els[15]); \
	__sort_cswap_fn(T, els[16], els[24]); \
	__sort_cswap_fn(T, els[17], els[25]); \
	__sort_cswap_fn(T, els[18], els[26]); \
	__sort_cswap_fn(T, els[19], els[27]); \
	__sort_cswap_fn(T, els[20], els[28]); \
	__sort_cswap_fn(T, els[21], els[29]); \
	__sort_cswap_fn(T, els[22], els[30]); \
	__sort_cswap_fn(T, els[23], els[31]); \
	__sort_cswap_fn(T, els[0], els[16]); \
	__sort_cswap_fn(T, els[1], els[8]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[3], els[12]); \
	__sort_cswap_fn(T, els[5], els[10]); \
	__sort_cswap_fn(T, els[6], els[9]); \
	__sort_cswap_fn(T, els[7], els[14]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[15], els[31]); \
	__sort_cswap_fn(T, els[17], els[24]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[19], els[28]); \
	__sort_cswap_fn(T, els[21], els[26]); \
	__sort_cswap_fn(T, els[22], els[25]); \
	__sort_cswap_fn(T, els[23], els[30]); \
	__sort_cswap_fn(T, els[27], els[29]); \
	__sort_cswap_fn(T, els[1], els[2]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[4], els[8]); \
	__sort_cswap_fn(T, els[6], els[22]); \
	__sort_cswap_fn(T, els[7], els[11]); \
	__sort_cswap_fn(T, els[9], els[25]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[21]); \
	__sort_cswap_fn(T, els[20], els[24]); \
	__sort_cswap_fn(T, els[23], els[27]); \
	__sort_cswap_fn(T, els[26], els[28]); \
	__sort_cswap_fn(T, els[29], els[30]); \
	__sort_cswap_fn(T, els[1], els[17]); \
	__sort_cswap_fn(T, els[2], els[18]); \
	__sort_cswap_fn(T, els[3], els[19]); \
	__sort_cswap_fn(T, els[4], els[20]); \
	__sort_cswap_fn(T, els[5], els[10]); \
	__sort_cswap_fn(T, els[7], els[23]); \
	__sort_cswap_fn(T, els[8], els[24]); \
	__sort_cswap_fn(T, els[11], els[27]); \
	__sort_cswap_fn(T, els[12], els[28]); \
	__sort_cswap_fn(T, els[13], els[29]); \
	__sort_cswap_fn(T, els[14], els[30]); \
	__sort_cswap_fn(T, els[21], els[26]); \
	__sort_cswap_fn(T, els[3], els[17]); \
	__sort_cswap_fn(T, els[4], els[16]); \
	__sort_cswap_fn(T, els[5], els[21]); \
	__sort_cswap_fn(T, els[6], els[18]); \
	__sort_cswap_fn(T, els[7], els[9]); \
	__sort_cswap_fn(T, els[8], els[20]); \
	__sort_cswap_fn(T, els[10], els[26]); \
	__sort_cswap_fn(T, els[11], els[23]); \
	__sort_cswap_fn(T, els[13], els[25]); \
	__sort_cswap_fn(T, els[14], els[28]); \
	__sort_cswap_fn(T, els[15], els[27]); \
	__sort_cswap_fn(T, els[22], els[24]); \
	__sort_cswap_fn(T, els[1], els[4]); \
	__sort_cswap_fn(T, els[3], els[8]); \
	__sort_cswap_fn(T, els[5], els[16]); \
	__sort_cswap_fn(T, els[7], els[17]); \
	__sort_cswap_fn(T, els[9], els[21]); \
	__sort_cswap_fn(T, els[10], els[22]); \
	__sort_cswap_fn(T, els[11], els[19]); \
	__sort_cswap_fn(T, els[12], els[20]); \
	__sort_cswap_fn(T, els[14], els[24]); \
	__sort_cswap_fn(T, els[15], els[26]); \
	__sort_cswap_fn(T, els[23], els[28]); \
	__sort_cswap_fn(T, els[27], els[30]); \
	__sort_cswap_fn(T, els[2], els[5]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[18]); \
	__sort_cswap_fn(T, els[11], els[17]); \
	__sort_cswap_fn(T, els[12], els[16]); \
	__sort_cswap_fn(T, els[13], els[22]); \
	__sort_cswap_fn(T, els[14], els[20]); \
	__sort_cswap_fn(T, els[15], els[19]); \
	__sort_cswap_fn(T, els[23], els[24]); \
	__sort_cswap_fn(T, els[26], els[29]); \
	__sort_cswap_fn(T, els[2], els[4]); \
	__sort_cswap_fn(T, els[6], els[12]); \
	__sort_cswap_fn(T, els[9], els[16]); \
	__sort_cswap_fn(T, els[10], els[11]); \
	__sort_cswap_fn(T, els[13], els[17]); \
	__sort_cswap_fn(T, els[14], els[18]); \
	__sort_cswap_fn(T, els[15], els[22]); \
	__sort_cswap_fn(T, els[19], els[25]); \
	__sort_cswap_fn(T, els[20], els[21]); \
	__sort_cswap_fn(T, els[27], els[29]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[8], els[12]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[13]); \
	__sort_cswap_fn(T, els[14], els[16]); \
	__sort_cswap_fn(T, els[15], els[17]); \
	__sort_cswap_fn(T, els[18], els[20]); \
	__sort_cswap_fn(T, els[19], els[23]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[25], els[26]); \
	__sort_cswap_fn(T, els[3], els[5]); \
	__sort_cswap_fn(T, els[6], els[7]); \
	__sort_cswap_fn(T, els[8], els[9]); \
	__sort_cswap_fn(T, els[10], els[12]); \
	__sort_cswap_fn(T, els[11], els[14]); \
	__sort_cswap_fn(T, els[13], els[16]); \
	__sort_cswap_fn(T, els[15], els[18]); \
	__sort_cswap_fn(T, els[17], els[20]); \
	__sort_cswap_fn(T, els[19], els[21]); \
	__sort_cswap_fn(T, els[22], els[23]); \
	__sort_cswap_fn(T, els[24], els[25]); \
	__sort_cswap_fn(T, els[26], els[28]); \
	__sort_cswap_fn(T, els[3], els[4]); \
	__sort_cswap_fn(T, els[5], els[6]); \
	__sort_cswap_fn(T, els[7], els[8]); \
	__sort_cswap_fn(T, els[9], els[10]); \
	__sort_cswap_fn(T, els[11], els[12]); \
	__sort_cswap_fn(T, els[13], els[14]); \
	__sort_cswap_fn(T, els[15], els[16]); \
	__sort_cswap_fn(T, els[17], els[18]); \
	__sort_cswap_fn(T, els[19], els[20]); \
	__sort_cswap_fn(T, els[21], els[22]); \
	__sort_cswap_fn(T, els[23], els[24]); \
	__sort_cswap_fn(T, els[25], els[26]); \
	__sort_cswap_fn(T, els[27], els[28]); \
}


#define DEFINE_CONST_SORT_MAIN16(T, name) \
void const_sort_ ## name(T* els, size_t N) { \
	TEST_ASSERT(N <= 16); \
	switch (N) { \
		case 0: \
		case 1: \
			break; \
		case 2: \
			__bitonic_sort2_ ## name(els); \
			break; \
		case 3: \
			__bitonic_sort3_ ## name(els); \
			break; \
		case 4: \
			__bitonic_sort4_ ## name(els); \
			break; \
		case 5: \
			__bitonic_sort5_ ## name(els); \
			break; \
		case 6: \
			__bitonic_sort6_ ## name(els); \
			break; \
		case 7: \
			__bitonic_sort7_ ## name(els); \
			break; \
		case 8: \
			__bitonic_sort8_ ## name(els); \
			break; \
		case 9: \
			__bitonic_sort9_ ## name(els); \
			break; \
		case 10: \
			__bitonic_sort10_ ## name(els); \
			break; \
		case 11: \
			__bitonic_sort11_ ## name(els); \
			break; \
		case 12: \
			__bitonic_sort12_ ## name(els); \
			break; \
		case 13: \
			__bitonic_sort13_ ## name(els); \
			break; \
		case 14: \
			__bitonic_sort14_ ## name(els); \
			break; \
		case 15: \
			__bitonic_sort15_ ## name(els); \
			break; \
		case 16: \
			__bitonic_sort16_ ## name(els); \
			break; \
	} \
}


#define DEFINE_CONST_SORT_MAIN(T, name) \
void const_sort_ ## name(T* els, size_t N) { \
	TEST_ASSERT(N <= CONST_SORT_MAX); \
	switch (N) { \
		case 0: \
		case 1: \
			break; \
		case 2: \
			__bitonic_sort2_ ## name(els); \
			break; \
		case 3: \
			__bitonic_sort3_ ## name(els); \
			break; \
		case 4: \
			__bitonic_sort4_ ## name(els); \
			break; \
		case 5: \
			__bitonic_sort5_ ## name(els); \
			break; \
		case 6: \
			__bitonic_sort6_ ## name(els); \
			break; \
		case 7: \
			__bitonic_sort7_ ## name(els); \
			break; \
		case 8: \
			__bitonic_sort8_ ## name(els); \
			break; \
		case 9: \
			__bitonic_sort9_ ## name(els); \
			break; \
		case 10: \
			__bitonic_sort10_ ## name(els); \
			break; \
		case 11: \
			__bitonic_sort11_ ## name(els); \
			break; \
		case 12: \
			__bitonic_sort12_ ## name(els); \
			break; \
		case 13: \
			__bitonic_sort13_ ## name(els); \
			break; \
		case 14: \
			__bitonic_sort14_ ## name(els); \
			break; \
		case 15: \
			__bitonic_sort15_ ## name(els); \
			break; \
		case 16: \
			__bitonic_sort16_ ## name(els); \
			break; \
		case 17: \
			__bitonic_sort17_ ## name(els); \
			break; \
		case 18: \
			__bitonic_sort18_ ## name(els); \
			break; \
		case 19: \
			__bitonic_sort19_ ## name(els); \
			break; \
		case 20: \
			__bitonic_sort20_ ## name(els); \
			break; \
		case 21: \
			__bitonic_sort21_ ## name(els); \
			break; \
		case 22: \
			__bitonic_sort22_ ## name(els); \
			break; \
		case 23: \
			__bitonic_sort23_ ## name(els); \
			break; \
		case 24: \
			__bitonic_sort24_ ## name(els); \
			break; \
		case 25: \
			__bitonic_sort25_ ## name(els); \
			break; \
		case 26: \
			__bitonic_sort26_ ## name(els); \
			break; \
		case 27: \
			__bitonic_sort27_ ## name(els); \
			break; \
		case 28: \
			__bitonic_sort28_ ## name(els); \
			break; \
		case 29: \
			__bitonic_sort29_ ## name(els); \
			break; \
		case 30: \
			__bitonic_sort30_ ## name(els); \
			break; \
		case 31: \
			__bitonic_sort31_ ## name(els); \
			break; \
		case 32: \
			__bitonic_sort32_ ## name(els); \
			break; \
	} \
}


/*
 * finds the index in els that key should be placed at, i.e. the index of the
 * smallest element of els greater than key (or N if key is larger than all
 * elements of els)
 */
#define DEFINE_BINARY_INSERTION_FIND(T, name, __sort_cmp) \
static inline size_t \
binary_insertion_find_ ## name(T* els, size_t N, T key) \
{ \
	size_t l = 0; \
	size_t r = N -  1; \
	\
	/* check for our of bounds above r */ \
	if (__sort_cmp(els[r], key)) { \
		return N; \
	} \
	/* don't check for below els[0], since that is less likely for nearly */ \
	/* sorted arrays */ \
	\
	while (l < r) { \
		size_t m = (l + r) >> 1; \
		\
		if (__sort_cmp(key, els[m])) { \
			r = m; \
		} \
		else { \
			l = m + 1; \
		} \
	} \
	\
	return l; \
}

#define DEFINE_BINARY_INSERTION_SORT(T, name) \
void \
binary_insertion_sort_ ## name(T* els, size_t N) \
{ \
	T el; \
	size_t loc; \
	size_t j; \
	\
	for (size_t i = 1; i < N; i++) { \
		el = els[i]; \
		\
		loc = binary_insertion_find_ ## name(els, i, el); \
		for (j = i; j > loc; j--) { \
			els[j] = els[j - 1]; \
		} \
		els[j] = el; \
	} \
}

#define DEFINE_LINEAR_INSERTION_SORT(T, name, __sort_cmp) \
void \
linear_insertion_sort_ ## name(T* els, size_t N) \
{ \
	T el; \
	size_t j; \
	\
	for (size_t i = 1; i < N; i++) { \
		el = els[i]; \
		\
		for (j = i - 1; j < i && __sort_cmp(el, els[j]); j--) { \
			els[j + 1] = els[j]; \
		} \
		els[j + 1] = el; \
	} \
}

#define DEFINE_SMALL_SORT(T, name, const_sort_max) \
void small_sort_ ## name(T* els, size_t N) \
{ \
	if (N <= const_sort_max) { \
		const_sort_ ## name(els, N); \
	} \
	else { \
		linear_insertion_sort_ ## name(els, N); \
	} \
}

#define DEFINE_QUICK_SORT_PARTITION(T, name, __sort_cmp) \
static size_t \
quick_sort_partition_ ## name(T* els, size_t N, size_t pivot) \
{ \
	/*
	size_t l = 0;
	size_t r = N - 1;
	uint8_t do_l = 0;

	// swap pivot with end
	__sort_swap(T, els[pivot], els[r]);

	do {
		do_l ^= (els[l] >= els[r]);
		__sort_cswap(T, els[l], els[r]);

		l += do_l;
		r += do_l - 1;
	} while (l < r);

	// the pivot is at either l or r, but since they are now the same, we can
	// return just l
	return l;
	*/ \
	\
	size_t idx = 0; \
	T p_val = els[pivot]; \
	\
	__sort_swap(T, els[pivot], els[N - 1]); \
	\
	for (size_t i = 0; i < N - 1; i++) { \
		if (__sort_cmp(els[i], p_val)) { \
			__sort_swap(T, els[i], els[idx]); \
			idx++; \
		} \
	} \
	__sort_swap(T, els[idx], els[N - 1]); \
	return idx; \
}

#define DEFINE_QUICK_SORT_RECURSIVE(T, name) \
static void \
quick_sort_recursive_ ## name(T* els, size_t N) \
{ \
	if (N <= SMALL_SORT_MAX) { \
		small_sort_ ## name(els, N); \
		return; \
	} \
	\
	size_t pivot = (N >> 1); \
	pivot = quick_sort_partition_ ## name(els, N, pivot); \
	\
	quick_sort_recursive_ ## name(els, pivot); \
	quick_sort_recursive_ ## name(els + pivot + 1, N - (pivot + 1)); \
}

#define DEFINE_QUICK_SORT(T, name) \
void \
quick_sort_ ## name(T* els, size_t N) \
{ \
	quick_sort_recursive_ ## name(els, N); \
}


#define DEFINE_CSORT(T, name) \
void \
csort_ ## name(T* els, size_t N) \
{ \
	quick_sort_ ## name(els, N); \
}


#define DEFINE_CONST_SORT16(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT2(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT3(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT4(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT5(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT6(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT7(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT8(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT9(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT10(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT11(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT12(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT13(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT14(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT15(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT16(T, name, __sort_cswap_fn) \
	DEFINE_CONST_SORT_MAIN16(T, name)


#define DEFINE_CONST_SORT(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT2(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT3(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT4(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT5(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT6(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT7(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT8(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT9(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT10(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT11(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT12(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT13(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT14(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT15(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT16(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT17(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT18(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT19(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT20(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT21(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT22(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT23(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT24(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT25(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT26(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT27(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT28(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT29(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT30(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT31(T, name, __sort_cswap_fn) \
	DEFINE_BITONIC_SORT32(T, name, __sort_cswap_fn) \
	DEFINE_CONST_SORT_MAIN(T, name)

#define DEFINE_BINARY_INSERTION_SORT_FNS(T, name, __sort_cmp_fn) \
	DEFINE_BINARY_INSERTION_FIND(T, name, __sort_cmp_fn) \
	DEFINE_BINARY_INSERTION_SORT(T, name)

#define DEFINE_QUICK_SORT_FNS(T, name, __sort_cmp_fn) \
	DEFINE_QUICK_SORT_PARTITION(T, name, __sort_cmp_fn) \
	DEFINE_QUICK_SORT_RECURSIVE(T, name) \
	DEFINE_QUICK_SORT(T, name)

#define DEFINE_CSORT_DEFAULT_FNS_NAMED_16(T, name, sort_cmp, sort_cswap) \
	DEFINE_CONST_SORT16(T, name, sort_cswap) \
	DEFINE_BINARY_INSERTION_SORT_FNS(T, name, sort_cmp) \
	DEFINE_LINEAR_INSERTION_SORT(T, name, sort_cmp) \
	DEFINE_SMALL_SORT(T, name, 16) \
	DEFINE_QUICK_SORT_FNS(T, name, sort_cmp) \
	DEFINE_CSORT(T, name)

#define DEFINE_CSORT_DEFAULT_FNS_16(T) \
	DEFINE_COSRT_DEFAULT_FNS_NAMED_16(T, T, __default_sort_cmp, __default_sort_cswap)

#define DEFINE_CSORT_DEFAULT_FNS_NAMED(T, name, sort_cmp, sort_cswap) \
	DEFINE_CONST_SORT(T, name, sort_cswap) \
	DEFINE_BINARY_INSERTION_SORT_FNS(T, name, sort_cmp) \
	DEFINE_LINEAR_INSERTION_SORT(T, name, sort_cmp) \
	DEFINE_SMALL_SORT(T, name, 32) \
	DEFINE_QUICK_SORT_FNS(T, name, sort_cmp) \
	DEFINE_CSORT(T, name)

#define DEFINE_CSORT_DEFAULT_FNS(T) \
	DEFINE_COSRT_DEFAULT_FNS_NAMED(T, T, __default_sort_cmp, __default_sort_cswap)

#endif /* __cplusplus */


#endif /* _ALG_SORT_H */
