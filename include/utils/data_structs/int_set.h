#ifndef _INT_SET_H
#define _INT_SET_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

/*
 * a set of integers which may range from 0 to (max-1)
 */
typedef uint64_t* int_set_t;

#define INT_SET_MAX_SIZE (0xfffffffffffffffflu - INT_SET_ENTRY_BITS + 1)

#define INT_SET_ENTRY_BITS (8 * sizeof(uint64_t))

#define INT_SET_GET_SIZE(max) \
	(((max) + INT_SET_ENTRY_BITS - 1) / INT_SET_ENTRY_BITS)


int int_set_init(int_set_t*, uint64_t max);

/*
 * initializes an int set on the stack
 *
 * warning: do not call int_set_free on int_sets initialized this way
 */
#define int_set_inita(int_set, max) \
	do { \
		uint64_t size = INT_SET_GET_SIZE(max) * sizeof(uint64_t); \
		(int_set) = alloca(size); \
		memset(int_set, 0, size); \
	} while(0)

void int_set_free(int_set_t);

/*
 * removes all elements from the int set
 */
void int_set_clear(int_set_t, uint64_t max);

/*
 * returns true if val is contained in the int set
 *
 * undefined behavior if val is >= max
 */
bool int_set_contains(int_set_t, uint64_t val);

/*
 * inserts val into the int set
 *
 * this is a no-op if val is already in the int set
 */
void int_set_insert(int_set_t, uint64_t val);

/*
 * removes val from the int set
 *
 * this is a no-op if val was not in the int set
 */
void int_set_remove(int_set_t, uint64_t val);


#define INT_SET_FOREACH(iset, max, i) \
	do { \
		uint64_t __iset_off = 0; \
		uint64_t __iset_max = INT_SET_GET_SIZE(max); \
		while (__iset_off < __iset_max) { \
			uint64_t bitv = (iset)[__iset_off]; \
			uint64_t __iset_idx = 0; \
			while (bitv != 0) { \
				__iset_idx = __builtin_ctzl(bitv); \
				bitv ^= 1lu << __iset_idx; \
				uint64_t i = __iset_idx + (__iset_off * INT_SET_ENTRY_BITS);

#define INT_SET_FOREACH_END \
			} \
			__iset_off++; \
		} \
	} while(0)


#endif /* _INT_SET_H */
