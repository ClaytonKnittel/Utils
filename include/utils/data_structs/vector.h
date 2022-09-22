#ifndef _VECTOR_H
#define _VECTOR_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct vector {
  void* data;
  uint64_t el_size;

  uint64_t capacity;
  uint64_t len;
} vector_t;

int vector_init(vector_t*, uint64_t el_size, uint64_t capacity);

void vector_free(vector_t*);

/*
 * Returns the size of the vector in terms of the number of elements.
 */
uint64_t vector_size(const vector_t*);

/*
 * Pushes the given element to the vector, memcpy'ing the element poined to into
 * the vector.
 */
int vector_push(vector_t*, void* el);

/*
 * Reserves space for another vector element and returns a pointer to the
 * beginning of the reserved space.
 */
void* vector_reserve(vector_t*);

/*
 * Removes the last element of the vector, with undefined results if the vector
 * is empty.
 */
void vector_pop(vector_t*);

/*
 * Pops an element off the end of the vector, with undefined results if the
 * vector is empty.
 */
void vector_pop_el(vector_t*, void* dst_el);

/*
 * Returns a pointer to a vector element at position i, with undefined results
 * if i is outside the range of the vector.
 */
void* vector_get(vector_t*, uint64_t i);

/*
 * Sets the vector value at index i to val without bounds checking.
 */
void vector_set(vector_t*, uint64_t i, void* val);

/*
 * Removes the element from position i in the vector.
 */
void vector_remove(vector_t*, uint64_t i);

/*
 * Empties the vector.
 */
void vector_clear(vector_t*);

#endif /* _VECTOR_H */
