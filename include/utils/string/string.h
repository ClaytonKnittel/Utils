/*
 * A library of highly optimized, useful string functions
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef AVX_SUPPORTED
extern void to_upper_avx(char* str, uint64_t len);
extern void to_lower_avx(char* str, uint64_t len);

#define to_upper to_upper_avx
#define to_lower to_lower_avx

#else

static void to_upper(char* s, uint64_t len) {
	for (uint64_t i = 0; i < len; i++) {
		s[i] = (s[i] >= 'a' && s[i] <= 'z') ? (s[i] + ('A' - 'a')) : s[i];
	}
}

static void to_lower(char* s, uint64_t len) {
	for (uint64_t i = 0; i < len; i++) {
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? (s[i] + ('a' - 'A')) : s[i];
	}
}

#endif /* AVX_SUPPORTED */

#ifdef __cplusplus
}
#endif /* __cplusplus */

