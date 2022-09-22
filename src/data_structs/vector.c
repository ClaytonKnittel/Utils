
#include <string.h>

#include <utils/data_structs/vector.h>

int vector_init(vector_t* v, uint64_t el_size, uint64_t capacity) {
  void* data = malloc(el_size * capacity);
  if (data == NULL) {
    return -1;
  }

  v->data = data;
  v->el_size = el_size;
  v->capacity = capacity;
  v->len = 0;

  return 0;
}

void vector_free(vector_t* v) {
  free(v->data);
}

uint64_t vector_size(const vector_t* v) {
  return v->len;
}

static inline int _increase_capacity(vector_t* v) {
  uint64_t new_cap = v->capacity * 2;
  void* new_data = realloc(v->data, v->el_size * new_cap);
  if (new_data == NULL) {
    return -1;
  }

  v->data = new_data;
  v->capacity = new_cap;
  return 0;
}

int vector_push(vector_t* v, void* el) {
  if (v->len == v->capacity) {
    int res = _increase_capacity(v);
    if (res != 0) {
      return res;
    }
  }

  memcpy((((uint8_t*)v->data) + v->el_size * v->len), el, v->el_size);
  v->len++;
  return 0;
}

void* vector_reserve(vector_t* v) {
  if (v->len == v->capacity) {
    int res = _increase_capacity(v);
    if (res != 0) {
      return NULL;
    }
  }

  void* el = (void*)(((uint8_t*)v->data) + v->el_size * v->len);
  v->len++;
  return el;
}

void vector_pop(vector_t* v) {
  v->len--;
}

void vector_pop_el(vector_t* v, void* dst_el) {
  v->len--;
  memcpy(dst_el, (((uint8_t*)v->data) + v->el_size * v->len), v->el_size);
}

void* vector_get(vector_t* v, uint64_t i) {
  return ((uint8_t*)v->data) + i * v->el_size;
}

void vector_set(vector_t* v, uint64_t i, void* val) {
  memcpy((((uint8_t*)v->data) + v->el_size * i), val, v->el_size);
}

void vector_remove(vector_t* v, uint64_t i) {
  v->len--;
  memmove(((uint8_t*)v->data) + i * v->el_size,
          ((uint8_t*)v->data) + (i + 1) * v->el_size,
          (v->len - i) * v->el_size);
}

void vector_clear(vector_t* v) {
  v->len = 0;
}
