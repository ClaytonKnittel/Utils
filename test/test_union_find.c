
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <utils/data_structs/union_find.h>
#include <utils/math/random.h>
#include <utils/timing/timing.h>

#include "test_utils.h"

// returns time taken to execute test
double test_alg_1(uint32_t w, uint32_t h) {
  union_find uf;

  char* board = (char*)malloc(w * h * sizeof(char));

  for (uint32_t y = 0; y < h; y++) {
    for (uint32_t x = 0; x < w; x++) {
      uint32_t rand = gen_rand_r(4);
      switch (rand) {
        case 0:
          board[y * w + x] = ' ';
          break;
        case 1:
          board[y * w + x] = '/';
          break;
        case 2:
          board[y * w + x] = '\\';
          break;
        case 3:
          board[y * w + x] = 'X';
          break;
        default:
          // rand range can't be outside the range
          ck_assert(0);
      }
    }
  }

  // time union find algorithm parts
  struct timespec start, end;

  clock_gettime(CLOCK_MONOTONIC, &start);

  /*
   * each tile of borad is partitioned into four segments, which may or may
   * not be connected to each other, depending on the type of tile
   *
   *  partition of tile:
   *   \  0  /
   *    \   /
   *     \ /
   *   3  X   1
   *     / \
   *    /   \
   *   /  2  \
   *
   */
  uf_init(&uf, 4 * w * h);

  for (uint32_t y = 0; y < h; y++) {
    for (uint32_t x = 0; x < w; x++) {
      uint32_t idx = y * w + x;
      char tile = board[idx];
      // 4 segments per tile
      idx *= 4;

      if (tile == ' ' || tile == '\\') {
        // join 0 to 1 and 2 to 3
        uf_union(&uf, idx + 0, idx + 1);
        uf_union(&uf, idx + 2, idx + 3);
      }
      if (tile == ' ' || tile == '/') {
        // join 0 to 3 and 1 to 2
        uf_union(&uf, idx + 0, idx + 3);
        uf_union(&uf, idx + 1, idx + 2);
      }

      // also need to join cell with neighboring cells
      if (x > 0) {
        // join left of this cell with right of left cell
        uf_union(&uf, idx + 3, (idx - 4) + 1);
      }
      if (y > 0) {
        // join top of this cell with bottom of above cell
        uf_union(&uf, idx + 0, (idx - 4 * w) + 2);
      }
    }
  }

  uf_destroy(&uf);

  clock_gettime(CLOCK_MONOTONIC, &end);

  double time = timespec_diff(&end, &start);

  return time;
}

START_TEST(test_basic) {
  union_find uf;

  uf_init(&uf, 10);

  for (uf_node_t i = 0; i < 10; i++) {
    ck_assert(uf_find(&uf, i) == i);
  }

  uf_union(&uf, 1, 3);
  uf_union(&uf, 4, 5);
  uf_union(&uf, 1, 5);

  ck_assert(uf_find(&uf, 1) == uf_find(&uf, 3));
  ck_assert(uf_find(&uf, 1) == uf_find(&uf, 4));
  ck_assert(uf_find(&uf, 1) == uf_find(&uf, 5));
  ck_assert(uf_find(&uf, 0) == 0);
  ck_assert(uf_find(&uf, 2) == 2);
  ck_assert(uf_find(&uf, 6) == 6);
  ck_assert(uf_find(&uf, 7) == 7);
  ck_assert(uf_find(&uf, 8) == 8);
  ck_assert(uf_find(&uf, 9) == 9);

  uf_destroy(&uf);

#define NUM_TRIALS 10
  uint32_t widths[NUM_TRIALS] = { 1000, 1000, 1500, 2000, 2000,
                                  2000, 2500, 2500, 3000, 2500 };
  uint32_t heights[NUM_TRIALS] = { 1000, 2000, 2000, 2000, 2500,
                                   3000, 2800, 3200, 3000, 4000 };

  double times[NUM_TRIALS];

  for (int i = 0; i < NUM_TRIALS; i++) {
    times[i] = test_alg_1(widths[i], heights[i]);
    (void)times[i];
  }

  /*
printf("{");
for (int i = 0; i < NUM_TRIALS; i++) {
  printf("{%u,%f}", widths[i] * heights[i], times[i]);
  if (i != NUM_TRIALS - 1) {
      printf(",");
  }
}
printf("}\n");
  */
}
END_TEST

Suite* test_union_find() {
  TCase* tc_basic;

  Suite* s = suite_create("Union Find");

  tc_basic = tcase_create("Basic");
  tcase_add_test(tc_basic, test_basic);
  suite_add_tcase(s, tc_basic);

  return s;
}
