#ifndef _M_VEC3_H
#define _M_VEC3_H

#include <math.h>

typedef union vec3 {
  float __m[3];
  struct {
    float x, y, z;
  };
} vec3_t;

static void init_vec3(vec3_t* v, float x, float y, float z) {
  v->x = x;
  v->y = y;
  v->z = z;
}

static float vec3_dot(vec3_t* a, vec3_t* b) {
  return a->x * b->x + a->y * b->y + a->z * b->z;
}

static float vec3_mag2(vec3_t* a) {
  return vec3_dot(a, a);
}

static float vec3_mag(vec3_t* a) {
  return sqrt(vec3_mag2(a));
}

#endif /* _M_VEC3_H */
