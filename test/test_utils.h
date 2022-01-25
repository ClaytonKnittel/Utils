#ifndef _TEST_UTILS_H
#define _TEST_UTILS_H

#include <stdlib.h>
#include <unistd.h>

#include <check.h>

#include <util.h>

#define test_assert0(expr) \
	if (__builtin_expect(!(expr), 0)) { \
		const char err_msg[] = "Assertion \"" STR(expr) "\" failed\n"; \
		write(STDERR_FILENO, err_msg, sizeof(err_msg) - 1); \
		exit(-1); \
	}

#endif /* _TEST_UTILS_H */
