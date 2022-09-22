
#include <stdlib.h>

#include <utils/data_structs/int_set.h>

#include "test_utils.h"

START_TEST(test_large) {
  uint64_t n = 1000;
  uint64_t max = 0x1000000;

  uint64_t* nums = (uint64_t*)malloc(n * sizeof(uint64_t));
  ck_assert(nums != NULL);

  int_set_t set;
  ck_assert(int_set_init(&set, max) == 0);

  for (uint64_t i = 0; i < n; i++) {
    nums[i] = rand() % max;
    int_set_insert(set, nums[i]);
  }

  INT_SET_FOREACH(set, max, i) {
    int found = 0;
    for (uint64_t j = 0; j < n; j++) {
      if (nums[j] == i) {
        nums[j] = -1;
        found = 1;
      }
    }
    ck_assert(found);
  }
  INT_SET_FOREACH_END;

  free(nums);
  int_set_free(set);
}
END_TEST

Suite* test_int_set() {
  TCase* tc_basic;

  Suite* s = suite_create("Int set");

  tc_basic = tcase_create("Basic");
  tcase_add_test(tc_basic, test_large);
  suite_add_tcase(s, tc_basic);

  return s;
}
