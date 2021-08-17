#ifndef _VECTOR_H
#define _VECTOR_H

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct vector {
	void* data;
	uint64_t el_size;

	uint64_t capacity;
	uint64_t len;
} vector_t;


int vector_init(vector_t*, uint64_t el_size, uint64_t capacity);

void vector_free(vector_t*);


int vector_push(vector_t*, void* el);

/*
 * pops an element off the end of the vector, with undefined results if the
 * vector is empty
 */
void vector_pop(vector_t*, void* dst_el);

/*
 * returns a pointer to a vector element at position i, with undefined results
 * if i is outside the range of the vector
 */
void* vector_get(vector_t*, uint64_t i);

/*
 * removes the element from position i in the vector
 */
void vector_remove(vector_t*, uint64_t i);


#endif /* _VECTOR_H */
