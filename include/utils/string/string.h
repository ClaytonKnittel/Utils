/*
 * A library of highly optimized, useful string functions
 */

#include <stdint.h>

#ifndef __APPLE__
// For strchrnul on Linux
#include <string.h>
#endif /* __APPLE__ */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef AVX_SUPPORTED

extern void to_upper_avx(char* str, uint64_t len) __asm__("_to_upper_avx");
extern void to_lower_avx(char* str, uint64_t len) __asm__("_to_lower_avx");

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

#ifdef __APPLE__

/*
 * The strchrnul() function returns a pointer to the matched character, or a
 * pointer to the null byte at the end of s (i.e., s+strlen(s)) if the character
 * is not found.
 */
char* strchrnul(const char* s, int c);

#endif /* __APPLE__ */

#ifdef __cplusplus
}
#endif /* __cplusplus */
