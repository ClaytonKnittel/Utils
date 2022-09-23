
/**********************************************************
 *                       Includes                         *
 **********************************************************/

#include <fcntl.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <utils/algorithms/sort.h>
#include <utils/data_structs/rtree.h>
#include <utils/math/random.h>
#include <utils/utils.h>

#include "test_utils.h"

/**********************************************************
 *                 Silence Test Fixtures                  *
 **********************************************************/

static int stderr_tmp;
static int dev_null_fd;

static void silence_stderr_setup(void) {
  stderr_tmp = dup(STDERR_FILENO);
  dev_null_fd = open("/dev/null", O_WRONLY);
  dup2(dev_null_fd, STDERR_FILENO);
}

static void silence_stderr_teardown(void) {
  dup2(stderr_tmp, STDERR_FILENO);
  close(stderr_tmp);
  close(dev_null_fd);
}

/**********************************************************
 *                      Test Utils                        *
 **********************************************************/

#define INIT_RTREE(m_min, m_max) \
  rtree_t tree;                  \
  ck_assert_int_eq(rtree_init(&tree, m_min, m_max), 0)

#define ASSERT_RECT_EQ(r1, r2)          \
  ck_assert_int_eq((r1)->lx, (r2)->lx); \
  ck_assert_int_eq((r1)->ly, (r2)->ly); \
  ck_assert_int_eq((r1)->ux, (r2)->ux); \
  ck_assert_int_eq((r1)->uy, (r2)->uy)

/**********************************************************
 *                       Test Init                        *
 **********************************************************/

START_TEST(test_init_half_min) {
  INIT_RTREE(2, 4);
  rtree_validate(&tree);
  rtree_free(&tree);
}
END_TEST

START_TEST(test_init_large_max) {
  INIT_RTREE(5, 100);
  rtree_validate(&tree);
  rtree_free(&tree);
}
END_TEST

START_TEST(test_init_over_half_min) {
  rtree_t tree;
  ck_assert_int_ne(rtree_init(&tree, 4, 7), 0);
}
END_TEST

START_TEST(test_init_0_min) {
  rtree_t tree;
  ck_assert_int_ne(rtree_init(&tree, 0, 5), 0);
}
END_TEST

START_TEST(test_init_1_min) {
  rtree_t tree;
  ck_assert_int_ne(rtree_init(&tree, 1, 5), 0);
}
END_TEST

/**********************************************************
 *                      Test Insert                       *
 **********************************************************/

START_TEST(test_insert_1) {
  INIT_RTREE(5, 10);

  rtree_el_t el = { .bb = { .lx = 0, .ly = 0, .ux = 5, .uy = 5 } };
  ck_assert_int_eq(rtree_insert(&tree, &el), 0);
  rtree_validate(&tree);
  rtree_free(&tree);
}
END_TEST

START_TEST(test_insert_100) {
  INIT_RTREE(5, 10);

  rtree_el_t els[100];

  for (uint32_t i = 0; i < 100; i++) {
    els[i] = (rtree_el_t){ .bb = { .lx = (i % 10) * 10,
                                   .ly = (i / 10) * 10,
                                   .ux = (i % 10) * 10 + 5,
                                   .uy = (i / 10) * 10 + 5 } };
    ck_assert_int_eq(rtree_insert(&tree, &els[i]), 0);
    rtree_validate(&tree);
  }
  rtree_free(&tree);
}
END_TEST

START_TEST(test_insert_10000_random) {
  seed_rand(15, 0);
  INIT_RTREE(10, 30);

  rtree_el_t* els = (rtree_el_t*) malloc(10000 * sizeof(rtree_el_t));

  for (uint32_t i = 0; i < 10000; i++) {
    uint64_t x = gen_rand_r(65536);
    uint64_t y = gen_rand_r(65536);

    uint64_t wx = gen_rand_r(32);
    uint64_t wy = gen_rand_r(32);

    els[i] =
        (rtree_el_t){ .bb = { .lx = x, .ly = y, .ux = x + wx, .uy = y + wy } };
    ck_assert_int_eq(rtree_insert(&tree, &els[i]), 0);
  }
  rtree_validate(&tree);
  free(els);
  rtree_free(&tree);
}
END_TEST

/**********************************************************
 *                     Test For Each                      *
 **********************************************************/

static bool _foreach_1_cb(const rtree_el_t* el, void* udata,
                          const rtree_t* tree) {
  (void) udata;
  (void) tree;

  rtree_rect_t expected_bb = { .lx = 0, .ly = 0, .ux = 5, .uy = 5 };

  ASSERT_RECT_EQ(&expected_bb, &el->bb);
  (*((int*) udata))++;

  return true;
}

START_TEST(test_foreach_1) {
  INIT_RTREE(5, 10);

  rtree_el_t el = { .bb = { .lx = 0, .ly = 0, .ux = 5, .uy = 5 } };
  ck_assert_int_eq(rtree_insert(&tree, &el), 0);
  rtree_validate(&tree);

  int cnt = 0;
  rtree_foreach(&tree, _foreach_1_cb, &cnt);
  ck_assert_int_eq(cnt, 1);
  rtree_free(&tree);
}
END_TEST

static bool _foreach_100_cb(const rtree_el_t* el, void* udata,
                            const rtree_t* tree) {
  (void) udata;
  (void) tree;

  int i = el->bb.lx / 10 + 10 * (el->bb.ly / 10);
  ck_assert_int_ge(i, 0);
  ck_assert_int_lt(i, 100);

  rtree_rect_t expected_bb = { .lx = (i % 10) * 10,
                               .ly = (i / 10) * 10,
                               .ux = (i % 10) * 10 + 5,
                               .uy = (i / 10) * 10 + 5 };

  ASSERT_RECT_EQ(&expected_bb, &el->bb);

  uint8_t* found_els = (uint8_t*) udata;
  ck_assert_int_eq(found_els[i], 0);
  found_els[i] = 0xff;

  return true;
}

START_TEST(test_foreach_100) {
  INIT_RTREE(5, 10);

  rtree_el_t els[100];

  for (uint32_t i = 0; i < 100; i++) {
    els[i] = (rtree_el_t){ .bb = { .lx = (i % 10) * 10,
                                   .ly = (i / 10) * 10,
                                   .ux = (i % 10) * 10 + 5,
                                   .uy = (i / 10) * 10 + 5 } };
    ck_assert_int_eq(rtree_insert(&tree, &els[i]), 0);
    rtree_validate(&tree);
  }

  uint8_t found_els[100] = { 0 };
  rtree_foreach(&tree, _foreach_100_cb, found_els);
  for (uint32_t i = 0; i < 100; i++) {
    ck_assert_int_eq(found_els[i], 0xff);
  }

  rtree_free(&tree);
}
END_TEST

struct foreach_10000_data {
  rtree_el_t** el_ptrs;
  uint8_t* found_els;
};

// sort by y-coordinates, then by x
#define foreach_10000_els_sort_cmp(a, b) \
  ((a)->bb.ly < (b)->bb.ly ||            \
   ((a)->bb.ly == (b)->bb.ly &&          \
    ((a)->bb.uy < (b)->bb.uy ||          \
     ((a)->bb.uy == (b)->bb.uy &&        \
      ((a)->bb.lx < (b)->bb.lx ||        \
       ((a)->bb.lx == (b)->bb.lx && (a)->bb.ux < (b)->bb.ux))))))

static int foreach_10000_els_cmp(const void* _a, const void* _b) {
  const rtree_el_t* a = (const rtree_el_t*) _a;
  const rtree_el_t* b = *(const rtree_el_t**) _b;

  /*printf("<(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")> cmp ",
                  a->bb.lx, a->bb.ly,
                  a->bb.ux, a->bb.uy);
  printf("<(%" PRId64 ", %" PRId64 "), (%" PRId64 ", %" PRId64 ")>\n",
                  b->bb.lx, b->bb.ly,
                  b->bb.ux, b->bb.uy);*/

  if (a->bb.ly < b->bb.ly) {
    return -1;
  } else if (a->bb.ly == b->bb.ly) {
    if (a->bb.uy < b->bb.uy) {
      return -1;
    } else if (a->bb.uy == b->bb.uy) {
      if (a->bb.lx < b->bb.lx) {
        return -1;
      } else if (a->bb.lx == b->bb.lx) {
        if (a->bb.ux < b->bb.ux) {
          return -1;
        } else if (a->bb.ux == b->bb.ux) {
          return 0;
        }
      }
    }
  }
  return 1;
}

#define foreach_10000_els_sort_cswap(T, a, b) \
  do {                                        \
    if (!foreach_10000_els_sort_cmp(a, b)) {  \
      T tmp = (a);                            \
      (a) = (b);                              \
      (b) = tmp;                              \
    }                                         \
  } while (0)

DEFINE_CSORT_DEFAULT_FNS_NAMED_16(rtree_el_t*, foreach_10000_els,
                                  foreach_10000_els_sort_cmp,
                                  foreach_10000_els_sort_cswap)

static bool _foreach_10000_cb(const rtree_el_t* el, void* udata,
                              const rtree_t* tree) {
  (void) udata;
  (void) tree;

  struct foreach_10000_data* data = (struct foreach_10000_data*) udata;
  rtree_el_t** el_ptrs = data->el_ptrs;
  uint8_t* found_els = data->found_els;

  const rtree_el_t** found_el = (const rtree_el_t**) bsearch(
      el, el_ptrs, 10000, sizeof(rtree_el_t*), foreach_10000_els_cmp);

  ck_assert_ptr_ne(found_el, NULL);
  ASSERT_RECT_EQ(&(*found_el)->bb, &el->bb);

  uint64_t idx =
      (((intptr_t) found_el) - ((intptr_t) el_ptrs)) / sizeof(rtree_el_t*);
  ck_assert_int_eq(found_els[idx], 0);
  found_els[idx] = 0xff;

  return true;
}

START_TEST(test_foreach_10000_random) {
  seed_rand(157, 0);
  INIT_RTREE(10, 30);

  rtree_el_t* els = (rtree_el_t*) malloc(10000 * sizeof(rtree_el_t));

  for (uint32_t i = 0; i < 10000; i++) {
    uint64_t x = gen_rand_r(65536);
    uint64_t y = gen_rand_r(65536);

    uint64_t wx = gen_rand_r(32);
    uint64_t wy = gen_rand_r(32);

    els[i] =
        (rtree_el_t){ .bb = { .lx = x, .ly = y, .ux = x + wx, .uy = y + wy } };
    ck_assert_int_eq(rtree_insert(&tree, &els[i]), 0);
  }
  rtree_validate(&tree);

  rtree_el_t** el_ptrs = (rtree_el_t**) malloc(10000 * sizeof(rtree_el_t*));
  for (uint64_t i = 0; i < 10000; i++) {
    el_ptrs[i] = &els[i];
  }
  csort_foreach_10000_els(el_ptrs, 10000);
  for (uint64_t i = 0; i < 9999; i++) {
    ck_assert(foreach_10000_els_cmp(el_ptrs[i], &el_ptrs[i + 1]) < 0);
  }

  uint8_t* found_els = (uint8_t*) calloc(10000, sizeof(uint8_t));
  struct foreach_10000_data data = { .el_ptrs = el_ptrs,
                                     .found_els = found_els };
  rtree_foreach(&tree, _foreach_10000_cb, &data);
  for (uint32_t i = 0; i < 10000; i++) {
    ck_assert_int_eq(found_els[i], 0xff);
  }

  free(found_els);
  free(el_ptrs);
  free(els);
  rtree_free(&tree);
}
END_TEST

/**********************************************************
 *                       Test Find                        *
 **********************************************************/

START_TEST(test_find_single) {
  INIT_RTREE(5, 10);

  rtree_el_t el = { .bb = { .lx = 0, .ly = 0, .ux = 5, .uy = 5 } };
  ck_assert_int_eq(rtree_insert(&tree, &el), 0);
  rtree_validate(&tree);

  rtree_el_t* el_ptr = rtree_find_exact(&tree, &el.bb);
  ck_assert_ptr_eq(el_ptr, &el);

  rtree_free(&tree);
}
END_TEST

START_TEST(test_find_single_fail) {
  INIT_RTREE(5, 10);

  rtree_el_t el = { .bb = { .lx = 0, .ly = 0, .ux = 5, .uy = 5 } };
  ck_assert_int_eq(rtree_insert(&tree, &el), 0);
  rtree_validate(&tree);

  rtree_rect_t wrong_rect = { .lx = 1, .ly = 0, .ux = 5, .uy = 5 };

  ck_assert_ptr_eq(rtree_find_exact(&tree, &wrong_rect), NULL);

  rtree_free(&tree);
}
END_TEST

START_TEST(test_find_100_grid) {
  INIT_RTREE(3, 6);

  rtree_el_t els[10 * 10];

  for (uint32_t i = 0; i < 10 * 10; i++) {
    els[i] = (rtree_el_t){ .bb = { .lx = (i % 10) * 10,
                                   .ly = (i / 10) * 10,
                                   .ux = (i % 10) * 10 + (10 / 2),
                                   .uy = (i / 10) * 10 + (10 / 2) } };
    ck_assert_int_eq(rtree_insert(&tree, &els[i]), 0);
    rtree_validate(&tree);
  }

  for (uint32_t i = 0; i < 10 * 10; i++) {
    rtree_rect_t rect = { .lx = (i % 10) * 10,
                          .ly = (i / 10) * 10,
                          .ux = (i % 10) * 10 + (10 / 2),
                          .uy = (i / 10) * 10 + (10 / 2) };
    rtree_el_t* el = rtree_find_exact(&tree, &rect);
    ck_assert_ptr_eq(el, &els[i]);
    ASSERT_RECT_EQ(&el->bb, &rect);
  }

  rtree_free(&tree);
}
END_TEST

static void _run_randomized_find_test(uint64_t n_rects, uint32_t m_min,
                                      uint32_t m_max, uint64_t seed) {
  seed_rand(seed, 0);
  INIT_RTREE(m_min, m_max);

  rtree_el_t* els = (rtree_el_t*) malloc(n_rects * sizeof(rtree_el_t));

  for (uint32_t i = 0; i < n_rects; i++) {
    uint64_t x = gen_rand_r(65536);
    uint64_t y = gen_rand_r(65536);

    uint64_t wx = gen_rand_r(32);
    uint64_t wy = gen_rand_r(32);
    els[i].bb = (rtree_rect_t){ .lx = x, .ly = y, .ux = x + wx, .uy = y + wy };
    ck_assert_int_eq(rtree_insert(&tree, &els[i]), 0);
  }
  rtree_validate(&tree);

  // reset the seed so we see the same sequence of rectangles
  seed_rand(seed, 0);
  for (uint32_t i = 0; i < n_rects; i++) {
    uint64_t x = gen_rand_r(65536);
    uint64_t y = gen_rand_r(65536);

    uint64_t wx = gen_rand_r(32);
    uint64_t wy = gen_rand_r(32);
    rtree_rect_t rect = { .lx = x, .ly = y, .ux = x + wx, .uy = y + wy };
    rtree_el_t* el = rtree_find_exact(&tree, &rect);
    ck_assert_ptr_eq(el, &els[i]);
    ASSERT_RECT_EQ(&el->bb, &rect);
  }

  free(els);

  rtree_free(&tree);
}

START_TEST(test_find_100_random) {
  _run_randomized_find_test(100, 3, 6, 16);
}
END_TEST

START_TEST(test_find_10000_random) {
  _run_randomized_find_test(10000, 3, 6, 23);
}
END_TEST

/**********************************************************
 *                      Test Delete                       *
 **********************************************************/

START_TEST(test_delete_1) {
  INIT_RTREE(5, 10);

  rtree_el_t el = { .bb = { .lx = 0, .ly = 0, .ux = 5, .uy = 5 } };
  ck_assert_int_eq(rtree_insert(&tree, &el), 0);
  rtree_validate(&tree);

  ck_assert_int_eq(rtree_delete(&tree, &el), 0);
  rtree_validate(&tree);

  rtree_free(&tree);
}
END_TEST

static void _run_randomized_delete_test(uint64_t n_rects, uint32_t m_min,
                                        uint32_t m_max, uint64_t seed,
                                        bool full_check) {
  seed_rand(seed, 0);
  INIT_RTREE(m_min, m_max);

  rtree_el_t* els = (rtree_el_t*) malloc(n_rects * sizeof(rtree_el_t));
  uint32_t* delete_order = (uint32_t*) malloc(n_rects * sizeof(uint32_t));

  for (uint32_t i = 0; i < n_rects; i++) {
    uint64_t x = gen_rand_r(65536);
    uint64_t y = gen_rand_r(65536);

    uint64_t wx = gen_rand_r(32);
    uint64_t wy = gen_rand_r(32);

    els[i] =
        (rtree_el_t){ .bb = { .lx = x, .ly = y, .ux = x + wx, .uy = y + wy } };
    ck_assert_int_eq(rtree_insert(&tree, &els[i]), 0);
  }
  rtree_validate(&tree);

  for (uint32_t i = 0; i < n_rects; i++) {
    delete_order[i] = i;
  }
  for (uint32_t i = 1; i < n_rects; i++) {
    uint32_t loc = gen_rand_r(i + 1);
    uint32_t tmp = delete_order[loc];
    delete_order[loc] = delete_order[i];
    delete_order[i] = tmp;
  }

  // make sure all rects were inserted properly
  for (uint32_t j = 0; j < n_rects; j++) {
    rtree_el_t* el = rtree_find_exact(&tree, &els[j].bb);
    ck_assert_ptr_eq(el, &els[j]);
  }

  for (uint32_t i = 0; i < n_rects; i++) {
    rtree_el_t* el = &els[delete_order[i]];
    ck_assert_int_eq(rtree_delete(&tree, el), 0);

    if (full_check) {
      // after each deletion, make sure all previously deleted elements don't
      // exist and all ones that haven't been deleted still do
      for (uint32_t j = 0; j <= i; j++) {
        rtree_el_t* el = rtree_find_exact(&tree, &els[delete_order[j]].bb);
        ck_assert_ptr_eq(el, NULL);
      }
      for (uint32_t j = i + 1; j < n_rects; j++) {
        rtree_el_t* el = rtree_find_exact(&tree, &els[delete_order[j]].bb);
        ck_assert_ptr_eq(el, &els[delete_order[j]]);
      }
      rtree_validate(&tree);
    } else {
      rtree_el_t* el1 = rtree_find_exact(&tree, &els[delete_order[i]].bb);
      ck_assert_ptr_eq(el1, NULL);

      if (i < n_rects - 1) {
        rtree_el_t* el2 = rtree_find_exact(&tree, &els[delete_order[i + 1]].bb);
        ck_assert_ptr_eq(el2, &els[delete_order[i + 1]]);
      }
    }
  }

  if (!full_check) {
    rtree_validate(&tree);
  }

  ck_assert_int_eq(tree.depth, 0);
  ck_assert_int_eq(tree.root->n, 0);

  rtree_free(&tree);
}

START_TEST(test_delete_100_random) {
  _run_randomized_delete_test(100, 5, 10, 87, true);
}
END_TEST

START_TEST(test_delete_1000_random) {
  _run_randomized_delete_test(1000, 4, 12, 101, true);
}
END_TEST

START_TEST(test_delete_10000_random) {
  _run_randomized_delete_test(1000, 4, 12, 113, false);
}
END_TEST

START_TEST(test_delete_100000_random) {
  _run_randomized_delete_test(10000, 4, 12, 117, false);
}
END_TEST

START_TEST(test_delete_1000000_random) {
  _run_randomized_delete_test(100000, 5, 15, 123, false);
}
END_TEST

/**********************************************************
 *                    Test Intersects                     *
 **********************************************************/

static volatile int intersects_single_cnt = 0;
static bool _intersects_single_cb(const rtree_el_t* el, void* expected_rtree_el,
                                  const rtree_rect_t* rect,
                                  const rtree_t* tree) {
  (void) tree;
  rtree_el_t* expected_el = (rtree_el_t*) expected_rtree_el;

  ASSERT_RECT_EQ(rect, &expected_el->bb);
  ASSERT_RECT_EQ(rect, &el->bb);

  intersects_single_cnt++;

  return true;
}

START_TEST(test_intersects_single) {
  INIT_RTREE(5, 10);

  rtree_el_t el = { .bb = { .lx = 0, .ly = 0, .ux = 5, .uy = 5 } };
  ck_assert_int_eq(rtree_insert(&tree, &el), 0);

  rtree_el_t expected_el = { .bb = { .lx = 0, .ly = 0, .ux = 5, .uy = 5 } };

  intersects_single_cnt = 0;
  rtree_intersects_foreach(&tree, &expected_el.bb, _intersects_single_cb,
                           &expected_el);
  ck_assert_int_eq(intersects_single_cnt, 1);

  rtree_free(&tree);
}
END_TEST

static void _run_grid_intersects_single_test(uint64_t sqrt_n_rects,
                                             uint32_t m_min, uint32_t m_max) {
  INIT_RTREE(m_min, m_max);

  uint64_t n_rects = sqrt_n_rects * sqrt_n_rects;

  rtree_el_t* els = (rtree_el_t*) malloc(n_rects * sizeof(rtree_el_t));

  for (uint32_t i = 0; i < n_rects; i++) {
    els[i].bb = (rtree_rect_t){
      .lx = (i % sqrt_n_rects) * sqrt_n_rects,
      .ly = (i / sqrt_n_rects) * sqrt_n_rects,
      .ux = (i % sqrt_n_rects) * sqrt_n_rects + (sqrt_n_rects / 2),
      .uy = (i / sqrt_n_rects) * sqrt_n_rects + (sqrt_n_rects / 2)
    };
    ck_assert_int_eq(rtree_insert(&tree, &els[i]), 0);
  }
  rtree_validate(&tree);

  for (uint32_t i = 0; i < n_rects; i++) {
    rtree_el_t expected_el = {
      .bb = { .lx = (i % sqrt_n_rects) * sqrt_n_rects,
              .ly = (i / sqrt_n_rects) * sqrt_n_rects,
              .ux = (i % sqrt_n_rects) * sqrt_n_rects + (sqrt_n_rects / 2),
              .uy = (i / sqrt_n_rects) * sqrt_n_rects + (sqrt_n_rects / 2) }
    };

    intersects_single_cnt = 0;
    rtree_intersects_foreach(&tree, &expected_el.bb, _intersects_single_cb,
                             &expected_el);
    ck_assert_int_eq(intersects_single_cnt, 1);
  }

  free(els);

  rtree_free(&tree);
}

START_TEST(test_intersects_grid_single_100) {
  _run_grid_intersects_single_test(10, 5, 10);
}
END_TEST

START_TEST(test_intersects_grid_single_10000) {
  _run_grid_intersects_single_test(100, 3, 6);
}
END_TEST

typedef struct grid_neighbors {
  const uint64_t sqrt_n_rects;
  const uint32_t i;

  uint32_t neighbors;

  rtree_el_t* els;
} grid_neighbors_t;

#define RECT_W 10

/*
 * Checks whether idx is one of the neighbors of this square.
 */
static bool expected_neighbor(const grid_neighbors_t* gn, uint32_t idx) {
  uint64_t x = gn->i % gn->sqrt_n_rects;
  uint64_t y = gn->i / gn->sqrt_n_rects;

  uint64_t _x = idx % gn->sqrt_n_rects;
  uint64_t _y = idx / gn->sqrt_n_rects;

  return (_x - x + 1 <= 2) && (_y - y + 1 <= 2);
}

static uint32_t neighbor_idx(const grid_neighbors_t* gn, uint32_t idx) {
  uint64_t x = gn->i % gn->sqrt_n_rects;
  uint64_t y = gn->i / gn->sqrt_n_rects;

  uint64_t _x = idx % gn->sqrt_n_rects;
  uint64_t _y = idx / gn->sqrt_n_rects;

  return (_x - x + 1) + 3 * (_y - y + 1);
}

static bool mark_neighbor(grid_neighbors_t* gn, uint32_t idx) {
  uint32_t n_idx = neighbor_idx(gn, idx);
  if (((gn->neighbors >> n_idx) & 1) != 0) {
    return false;
  }

  gn->neighbors |= (1u << n_idx);
  return true;
}

static void all_neighbors_marked(grid_neighbors_t* gn) {
  uint64_t x = gn->i % gn->sqrt_n_rects;
  uint64_t y = gn->i / gn->sqrt_n_rects;
  uint32_t n_mask = 0x1ffu;

  if (x == 0) {
    n_mask &= 0x1b6u;
  }
  if (x == gn->sqrt_n_rects - 1) {
    n_mask &= 0x0dbu;
  }
  if (y == 0) {
    n_mask &= 0x1f8u;
  }
  if (y == gn->sqrt_n_rects - 1) {
    n_mask &= 0x03fu;
  }

  ck_assert_msg(n_mask == gn->neighbors,
                "Unexpected neighbor list, expected "
                "0x%03x, but got 0x%03x at index %u",
                n_mask, gn->neighbors, gn->i);
  ck_assert_int_eq(n_mask, gn->neighbors);
}

static bool _intersects_all_neighbors_cb(const rtree_el_t* el, void* gn_ptr,
                                         const rtree_rect_t* rect,
                                         const rtree_t* tree) {
  (void) tree;
  grid_neighbors_t* gn = (grid_neighbors_t*) gn_ptr;

  uint32_t i = gn->i;
  uint64_t sqrt_n_rects = gn->sqrt_n_rects;
  rtree_rect_t expected_rect = {
    .lx = (i % sqrt_n_rects) * RECT_W,
    .ly = (i / sqrt_n_rects) * RECT_W,
    .ux = (i % sqrt_n_rects) * RECT_W + (3 * RECT_W / 2),
    .uy = (i / sqrt_n_rects) * RECT_W + (3 * RECT_W / 2)
  };

  ck_assert_int_eq(el->bb.ux - el->bb.lx, expected_rect.ux - expected_rect.lx);
  ck_assert_int_eq(el->bb.uy - el->bb.ly, expected_rect.uy - expected_rect.ly);

  ck_assert_int_eq(el->bb.lx % RECT_W, 0);
  ck_assert_int_eq(el->bb.ly % RECT_W, 0);

  ASSERT_RECT_EQ(rect, &expected_rect);

  uint32_t el_idx = (el->bb.lx / RECT_W) + sqrt_n_rects * (el->bb.ly / RECT_W);
  ck_assert_ptr_eq(el, &gn->els[el_idx]);

  ck_assert(expected_neighbor(gn, el_idx));
  ck_assert(mark_neighbor(gn, el_idx));

  return true;
}

static void _run_grid_intersects_all_neighbors_test(uint64_t sqrt_n_rects,
                                                    uint32_t m_min,
                                                    uint32_t m_max) {
  INIT_RTREE(m_min, m_max);

  uint64_t n_rects = sqrt_n_rects * sqrt_n_rects;

  rtree_el_t* els = (rtree_el_t*) malloc(n_rects * sizeof(rtree_el_t));

  for (uint32_t i = 0; i < n_rects; i++) {
    els[i].bb =
        (rtree_rect_t){ .lx = (i % sqrt_n_rects) * RECT_W,
                        .ly = (i / sqrt_n_rects) * RECT_W,
                        .ux = (i % sqrt_n_rects) * RECT_W + (3 * RECT_W / 2),
                        .uy = (i / sqrt_n_rects) * RECT_W + (3 * RECT_W / 2) };

    ck_assert_int_eq(rtree_insert(&tree, &els[i]), 0);
  }
  rtree_validate(&tree);

  for (uint32_t i = 0; i < n_rects; i++) {
    rtree_rect_t rect = { .lx = (i % sqrt_n_rects) * RECT_W,
                          .ly = (i / sqrt_n_rects) * RECT_W,
                          .ux = (i % sqrt_n_rects) * RECT_W + (3 * RECT_W / 2),
                          .uy =
                              (i / sqrt_n_rects) * RECT_W + (3 * RECT_W / 2) };

    grid_neighbors_t gn = {
      .sqrt_n_rects = sqrt_n_rects, .i = i, .neighbors = 0x000u, .els = els
    };
    rtree_intersects_foreach(&tree, &rect, _intersects_all_neighbors_cb, &gn);
    all_neighbors_marked(&gn);
  }

  free(els);

  rtree_free(&tree);
}

START_TEST(test_intersects_grid_all_neighbors_100) {
  _run_grid_intersects_all_neighbors_test(10, 5, 10);
}
END_TEST

START_TEST(test_intersects_grid_all_neighbors_10000) {
  _run_grid_intersects_all_neighbors_test(100, 4, 12);
}
END_TEST

/**********************************************************
 *                       Test Move                        *
 **********************************************************/

START_TEST(test_move_single) {
  INIT_RTREE(5, 10);

  rtree_el_t el = { .bb = { .lx = 0, .ly = 0, .ux = 5, .uy = 5 } };
  rtree_rect_t bb2 = { .lx = 5, .ly = 5, .ux = 10, .uy = 10 };

  ck_assert_int_eq(rtree_insert(&tree, &el), 0);
  rtree_validate(&tree);

  ck_assert_int_eq(rtree_move(&tree, &el, &bb2), 0);
  rtree_validate(&tree);
  ASSERT_RECT_EQ(&el.bb, &bb2);

  rtree_free(&tree);
}
END_TEST

static void _run_randomized_wiggle_test(uint64_t n_rects, uint32_t m_min,
                                        uint32_t m_max, uint64_t seed) {
  seed_rand(seed, 0);
  INIT_RTREE(m_min, m_max);

  rtree_el_t* els = (rtree_el_t*) malloc(n_rects * sizeof(rtree_el_t));

  for (uint32_t i = 0; i < n_rects; i++) {
    uint64_t x = gen_rand_r(65536);
    uint64_t y = gen_rand_r(65536);

    uint64_t wx = gen_rand_r(32);
    uint64_t wy = gen_rand_r(32);
    els[i].bb = (rtree_rect_t){ .lx = x, .ly = y, .ux = x + wx, .uy = y + wy };
    ck_assert_int_eq(rtree_insert(&tree, &els[i]), 0);
  }
  rtree_validate(&tree);

  for (uint32_t i = 0; i < n_rects; i++) {
    // dx, dy are chosen from {-1, 0, 1}
    uint64_t dx = gen_rand_r(3) - 1;
    uint64_t dy = gen_rand_r(3) - 1;

    rtree_rect_t new_rect = {
      .lx = els[i].bb.lx + dx,
      .ly = els[i].bb.ly + dy,
      .ux = els[i].bb.ux + dx,
      .uy = els[i].bb.uy + dy,
    };
    rtree_rect_t new_rect_cpy = new_rect;

    ck_assert_int_eq(rtree_move(&tree, &els[i], &new_rect), 0);
    ASSERT_RECT_EQ(&new_rect, &new_rect_cpy);
    ASSERT_RECT_EQ(&els[i].bb, &new_rect_cpy);

    if (dx != 0 || dy != 0) {
      rtree_rect_t old_rect = {
        .lx = new_rect.lx - dx,
        .ly = new_rect.ly - dy,
        .ux = new_rect.ux - dx,
        .uy = new_rect.uy - dy,
      };

      ck_assert_ptr_eq(rtree_find_exact(&tree, &old_rect), NULL);
    }
  }

  free(els);

  rtree_free(&tree);
}

START_TEST(test_wiggle_100) {
  _run_randomized_wiggle_test(100, 3, 6, 151);
}
END_TEST

START_TEST(test_wiggle_10000) {
  _run_randomized_wiggle_test(10000, 3, 6, 157);
}
END_TEST

/**********************************************************
 *                      Test Suite                        *
 **********************************************************/

Suite* test_rtree() {
  TCase* tc_init;
  TCase* tc_insert;
  TCase* tc_foreach;
  TCase* tc_find_exact;
  TCase* tc_delete;
  TCase* tc_intersects;
  TCase* tc_move;

  Suite* s = suite_create("R* tree");

  tc_init = tcase_create("Init");
  tcase_add_checked_fixture(tc_init, silence_stderr_setup,
                            silence_stderr_teardown);
  tcase_add_test(tc_init, test_init_half_min);
  tcase_add_test(tc_init, test_init_large_max);
  tcase_add_test(tc_init, test_init_over_half_min);
  tcase_add_test(tc_init, test_init_0_min);
  tcase_add_test(tc_init, test_init_1_min);
  suite_add_tcase(s, tc_init);

  tc_insert = tcase_create("Insert");
  tcase_add_test(tc_insert, test_insert_1);
  tcase_add_test(tc_insert, test_insert_100);
  tcase_add_test(tc_insert, test_insert_10000_random);
  suite_add_tcase(s, tc_insert);

  tc_foreach = tcase_create("For Each");
  tcase_add_test(tc_foreach, test_foreach_1);
  tcase_add_test(tc_foreach, test_foreach_100);
  tcase_add_test(tc_foreach, test_foreach_10000_random);
  suite_add_tcase(s, tc_foreach);

  tc_find_exact = tcase_create("Find Exact");
  tcase_add_test(tc_find_exact, test_find_single);
  tcase_add_test(tc_find_exact, test_find_single_fail);
  tcase_add_test(tc_find_exact, test_find_100_grid);
  tcase_add_test(tc_find_exact, test_find_100_random);
  tcase_add_test(tc_find_exact, test_find_10000_random);
  suite_add_tcase(s, tc_find_exact);

  tc_delete = tcase_create("Delete");
  tcase_add_test(tc_delete, test_delete_1);
  tcase_add_test(tc_delete, test_delete_100_random);
  tcase_add_test(tc_delete, test_delete_1000_random);
  tcase_add_test(tc_delete, test_delete_10000_random);
  tcase_add_test(tc_delete, test_delete_100000_random);
  tcase_add_test(tc_delete, test_delete_1000000_random);
  suite_add_tcase(s, tc_delete);

  tc_intersects = tcase_create("Intersects");
  tcase_add_test(tc_intersects, test_intersects_single);
  tcase_add_test(tc_intersects, test_intersects_grid_single_100);
  tcase_add_test(tc_intersects, test_intersects_grid_single_10000);
  tcase_add_test(tc_intersects, test_intersects_grid_all_neighbors_100);
  tcase_add_test(tc_intersects, test_intersects_grid_all_neighbors_10000);
  suite_add_tcase(s, tc_intersects);

  tc_move = tcase_create("Move");
  tcase_add_test(tc_move, test_move_single);
  tcase_add_test(tc_move, test_wiggle_100);
  tcase_add_test(tc_move, test_wiggle_10000);
  suite_add_tcase(s, tc_move);

  return s;
}
