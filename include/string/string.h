/*
 * A library of highly optimized, useful string functions
 */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef __APPLE__
extern void to_upper_osx(char* str, uint64_t len);
extern void to_lower_osx(char* str, uint64_t len);

#define to_upper to_upper_osx
#define to_lower to_lower_osx
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

