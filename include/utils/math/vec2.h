#ifndef _M_VEC2_H
#define _M_VEC2_H

#include <math.h>

typedef union vec2 {
  float __m[2];
  struct {
    float x, y;
  };
} vec2_t;

static void init_vec2(vec2_t* v, float x, float y) {
  v->x = x;
  v->y = y;
}

static float vec2_dot(vec2_t* a, vec2_t* b) {
  return a->x * b->x + a->y * b->y;
}

static float vec2_mag2(vec2_t* a) {
  return vec2_dot(a, a);
}

static float vec2_mag(vec2_t* a) {
  return sqrt(vec2_mag2(a));
}

#endif /* _M_VEC2_H */
