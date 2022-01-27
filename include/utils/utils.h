#ifndef _UTIL_UTIL_H
#define _UTIL_UTIL_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>


#ifdef DEBUG
#define dbg_assert(expr) assert(expr)
#else
#define dbg_assert(expr) (void) (expr)
#endif

#define printerr(f, fmt, ...) \
    fprintf((f), __FILE__ ":%d " fmt, __LINE__, __VA_ARGS__)


#define _STR(expr) #expr
#define STR(expr) _STR(expr)


#ifdef __LP64__
typedef uint64_t ptr_int_t;
#else
typedef uint32_t ptr_int_t;
#endif


// log10 values for powers of 2
static const uint8_t log10_pow2_guess[65] = {
    // 1 to 512
    0,  0,  0,  0,  1,  1,  1,  2,  2,  2,
    // 1024 to 524288
    3,  3,  3,  3,  4,  4,  4,  5,  5,  5,
    // 1048576 to 536870912
    6,  6,  6,  6,  7,  7,  7,  8,  8,  8,
    // 1073741824 to 549755813888
    9,  9,  9,  9,  10, 10, 10, 11, 11, 11,
    // 1099511627776 to 562949953421312
    12, 12, 12, 12, 13, 13, 13, 14, 14, 14,
    // 1125899906842624 to 576460752303423488
    15, 15, 15, 15, 16, 16, 16, 17, 17, 17,
    // 1152921504606846976 to 18446744073709551616
    18, 18, 18, 18, 19
};
static const uint64_t log10_ten_to[] = {
    1lu, 10lu, 100lu, 1000lu, 10000lu, 100000lu, 1000000lu,
    10000000lu, 100000000lu, 1000000000lu, 10000000000lu,
    100000000000lu, 1000000000000lu, 10000000000000lu,
    100000000000000lu, 1000000000000000lu,
    10000000000000000lu, 100000000000000000lu,
    1000000000000000000lu, 10000000000000000000lu
};


#ifdef __cplusplus

namespace util {

template<typename T, typename U>
constexpr T align_up(const U & val, const T & algn) {
    return (val + algn - 1) & ~(algn - 1);
}

template<typename T, typename U>
constexpr T align_down(const U & val, const T & algn) {
    return val & ~(algn - 1);
}


/*
 * returns 1 + index of the first set bit of val, or undefined if val is 0
 */
template<typename T>
constexpr int ffs_unsafe(const T & val) {
    if constexpr (sizeof(val) > sizeof(uint32_t)) {
        return 1 + __builtin_ctzl(val);
    }
    else {
        return 1 + __builtin_ctz((uint32_t) val);
    }
}

/*
 * returns 1 + index of the first set bit of val, or 0 if val is 0
 */
template<typename T>
constexpr int ffs(const T & val) {
    if constexpr (sizeof(val) > sizeof(uint32_t)) {
        return __builtin_ffsl(val);
    }
    else {
        return __builtin_ffs((int32_t) val);
    }
}

/*
 * returns 1 + index of the last set bit of val, or undefined if val is 0
 */
template<typename T>
constexpr T fls_unsafe(const T & val) {
    if constexpr (sizeof(val) > sizeof(uint32_t)) {
        return 8 * sizeof(uint64_t) - __builtin_clzl(val);
    }
    else {
        return 8 * sizeof(uint32_t) - __builtin_clz((uint32_t) val);
    }
}


/*
 * returns 1 + index of the last set bit of val, or 0 if val is 0
 */
template<typename T>
constexpr T fls(const T & val) {
    if (val == 0) {
        return 0;
    }
    else {
        return fls_unsafe(val);
    }
}


/*
 * returns smallest power of 2 greater than or equal to val, or undefined if
 * val is 0
 */
template<typename T>
constexpr T next_pow2_unsafe(const T & val) {
    return T(1) << (fls(val - 1));
}

/*
 * returns smallest power of 2 greater than or equal to val, returning 0 if
 * val is 0
 */
template<typename T>
constexpr T next_pow2(const T & val) {
    if (val == 0) {
        return 0;
    }
    else {
        return next_pow2_unsafe(val);
    }
}


/*
 * returns ceil(log_10(val)), i.e. the number of digits in the base-10
 * representation of val
 */
template<typename T>
constexpr T ceil_log10(const T & val) {

    uint32_t width = fls(val);
    uint32_t guess = log10_pow2_guess[width];
    return guess + (val >= log10_ten_to[guess]);
}

} /* end namespace util */

#else /* __cplusplus */

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

#define ALIGN_UP(val, algn) (((val) + ((algn) - 1)) & ~((algn) - 1))
#define ALIGN_DOWN(val, algn) ((val) & ~((algn) - 1))


/*
 * returns 1 + index of the first set bit of val, or undefined if val is 0
 */
#define ffs32_unsafe(val) (1 + __builtin_ctz(val))
#define ffs64_unsafe(val) (1 + __builtin_ctzl(val))

/*
 * returns 1 + index of the first set bit of val, or 0 if val is 0
 */
#define ffs32(val) (__builtin_ffs(val))
#define ffs64(val) (__builtin_ffsl(val))

/*
 * returns 1 + index of the last set bit of val, or undefined if val is 0
 */
#define fls32_unsafe(val) (32 - __builtin_clz(val))
#define fls64_unsafe(val) (64 - __builtin_clzl(val))

/*
 * returns 1 + index of the last set bit of val, or 0 if val is 0
 */
static inline int
fls32(uint32_t val)
{
	return val == 0 ? 0 : fls32_unsafe(val);
}

static inline int
fls64(uint64_t val)
{
	return val == 0 ? 0 : fls64_unsafe(val);
}


/*
 * returns smallest power of 2 greater than or equal to val, or undefined if
 * val is 0
 */
static inline uint32_t
next_pow2_unsafe(uint32_t val)
{
    return 1u << (fls32(val - 1));
}

static inline uint64_t
next_pow2l_unsafe(uint64_t val)
{
    return 1lu << (fls64(val - 1));
}

/*
 * returns smallest power of 2 greater than or equal to val, returning 0 if
 * val is 0
 */
static inline uint32_t
next_pow2(uint32_t val)
{
	return val == 0 ? 0 : next_pow2_unsafe(val);
}

static inline uint64_t
next_pow2l(uint64_t val)
{
	return val == 0 ? 0 : next_pow2l_unsafe(val);
}


/*
 * returns ceil(log_10(val)), i.e. the number of digits in the base-10
 * representation of val
 */
static inline uint32_t
ceil_log10(uint32_t val)
{
    uint32_t width = fls32(val);
    uint32_t guess = log10_pow2_guess[width];
    return guess + (val >= log10_ten_to[guess]);
}

static inline uint64_t
ceil_log10l(uint64_t val)
{
    uint32_t width = fls64(val);
    uint32_t guess = log10_pow2_guess[width];
    return guess + (val >= log10_ten_to[guess]);
}


static inline const char*
boolstr(bool b)
{
	extern const char* bools[2];
	return bools[!b];
}

#endif /* __cplusplus */


#endif /* _UTIL_UTIL_H */
