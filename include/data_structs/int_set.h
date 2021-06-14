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


#endif /* _INT_SET_H */
