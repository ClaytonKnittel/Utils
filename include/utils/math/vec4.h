#ifndef _M_VEC4_H
#define _M_VEC4_H

#include <math.h>

typedef union vec4 {
  float __m[4];
  struct {
    float x, y, z, w;
  };
} vec4_t;

static void init_vec4(vec4_t* v, float x, float y, float z, float w) {
  v->x = x;
  v->y = y;
  v->z = z;
  v->w = w;
}

static float vec4_dot(vec4_t* a, vec4_t* b) {
  return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}

static float vec4_mag2(vec4_t* a) {
  return vec4_dot(a, a);
}

static float vec4_mag(vec4_t* a) {
  return sqrt(vec4_mag2(a));
}

#endif /* _M_VEC4_H */
