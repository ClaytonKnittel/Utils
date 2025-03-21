
#include <errno.h>
#include <fcntl.h>
#include <time.h>

#include <utils/math/random.h>
#include <utils/os/dircntl.h>

#include "test_utils.h"

/*
 * Generates a random file name, changing every 'X' to a random alphanumeric
 * value.
 */
static void random_file_name(char* path, rand_state_t* r_state) {
  static const char alphanum[] =
      "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv";
  size_t path_len = strlen(path);

  for (size_t i = 0; i < path_len; i++) {
    if (path[i] == 'X') {
      path[i] = alphanum[gen_rand_r(r_state, sizeof(alphanum) - 1)];
    }
  }
}

static void assert_is_dir(const char* path) {
  struct stat dir_st;

  ck_assert_int_eq(stat(path, &dir_st), 0);
  ck_assert(S_ISDIR(dir_st.st_mode));
}

static void assert_dne(const char* path) {
  struct stat dir_st;

  ck_assert_int_eq(stat(path, &dir_st), -1);
}

START_TEST(test_mkdirp_empty) {
  errno = 0;
  ck_assert_int_eq(mkdirp("", S_IRUSR | S_IWUSR), -1);
  ck_assert_int_eq(errno, ENOENT);
}
END_TEST

START_TEST(test_mkdirp_self) {
  ck_assert_int_eq(mkdirp(".", S_IRUSR | S_IWUSR), 0);
}
END_TEST

START_TEST(test_mkdirp_parent) {
  ck_assert_int_eq(mkdirp("..", S_IRUSR | S_IWUSR), 0);
}
END_TEST

START_TEST(test_mkdirp_exists) {
  ck_assert_int_eq(mkdirp("../test", S_IRUSR | S_IWUSR), 0);
}
END_TEST

START_TEST(test_mkdirp_tmp_one_lvl) {
  rand_state_t state;
  seed_rand(&state, 13, time(NULL));

  char tmp_dir[] = "/tmp/XXXXXX";
  random_file_name(tmp_dir, &state);

  ck_assert_int_eq(mkdirp(tmp_dir, S_IRUSR | S_IWUSR), 0);
  assert_is_dir(tmp_dir);
}
END_TEST

START_TEST(test_mkdirp_tmp_two_lvls) {
  rand_state_t state;
  seed_rand(&state, 17, time(NULL));

  char tmp_dir[] = "/tmp/XXXXXX/XXXXXX";
  random_file_name(tmp_dir, &state);

  ck_assert_int_eq(mkdirp(tmp_dir, S_IRWXU), 0);
  assert_is_dir(tmp_dir);
}
END_TEST

START_TEST(test_mkdirp_tmp_three_lvls) {
  rand_state_t state;
  seed_rand(&state, 19, time(NULL));

  char tmp_dir[] = "/tmp/XXXXXX/XXXXXX/XXXXXX";
  random_file_name(tmp_dir, &state);

  ck_assert_int_eq(mkdirp(tmp_dir, S_IRWXU), 0);
  assert_is_dir(tmp_dir);
}
END_TEST

START_TEST(test_rmdirp_empty) {
  errno = 0;
  ck_assert_int_eq(rmdirp(""), -1);
  ck_assert_int_eq(errno, ENOENT);
}
END_TEST

START_TEST(test_rmdirp_nonempty) {
  rand_state_t state;
  seed_rand(&state, 23, time(NULL));

  char tmp_dir[] = "/tmp/XXXXXX";
  random_file_name(tmp_dir, &state);

  char tmp_file[sizeof(tmp_dir) + 1 + 8];
  memcpy(tmp_file, tmp_dir, sizeof(tmp_dir) - 1);
  strcpy(tmp_file + sizeof(tmp_dir) - 1, "/test.txt");

  ck_assert_int_eq(mkdir(tmp_dir, S_IRWXU), 0);

  int fd = open(tmp_file, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
  ck_assert_int_ge(fd, 0);
  close(fd);

  errno = 0;
  ck_assert_int_eq(rmdirp(tmp_dir), -1);
  ck_assert_int_eq(errno, ENOTEMPTY);
}
END_TEST

START_TEST(test_rmdirp_nonempty_multi_intact) {
  rand_state_t state;
  seed_rand(&state, 27, time(NULL));

  char tmp_dir[] = "/tmp/XXXXXX";
  random_file_name(tmp_dir, &state);

  char tmp_file[sizeof(tmp_dir) + 1 + 8];
  memcpy(tmp_file, tmp_dir, sizeof(tmp_dir) - 1);
  strcpy(tmp_file + sizeof(tmp_dir) - 1, "/test.txt");

  char tmp_dir1[sizeof(tmp_dir) + 1 + 6];
  memcpy(tmp_dir1, tmp_dir, sizeof(tmp_dir) - 1);
  strcpy(tmp_dir1 + sizeof(tmp_dir) - 1, "/XXXXXX");
  random_file_name(tmp_dir1 + sizeof(tmp_dir) - 1, &state);

  ck_assert_int_eq(mkdir(tmp_dir, S_IRWXU), 0);
  ck_assert_int_eq(mkdir(tmp_dir1, S_IRWXU), 0);

  int fd = open(tmp_file, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
  ck_assert_int_ge(fd, 0);
  close(fd);

  errno = 0;
  ck_assert_int_eq(rmdirp(tmp_dir), -1);
  ck_assert_int_eq(errno, ENOTEMPTY);

  assert_is_dir(tmp_dir1);
}
END_TEST

START_TEST(test_rmdirp_tmp_one_lvl) {
  rand_state_t state;
  seed_rand(&state, 29, time(NULL));

  char tmp_dir[] = "/tmp/XXXXXX";
  random_file_name(tmp_dir, &state);

  ck_assert_int_eq(mkdirp(tmp_dir, S_IRUSR | S_IWUSR), 0);
  assert_is_dir(tmp_dir);

  ck_assert_int_eq(rmdirp(tmp_dir), 0);
  assert_dne(tmp_dir);
}
END_TEST

START_TEST(test_rmdirp_tmp_two_lvls) {
  rand_state_t state;
  seed_rand(&state, 31, time(NULL));

  char tmp_dir[] = "/tmp/XXXXXX/XXXXXX";
  random_file_name(tmp_dir, &state);

  ck_assert_int_eq(mkdirp(tmp_dir, S_IRWXU), 0);
  assert_is_dir(tmp_dir);

  tmp_dir[11] = '\0';
  ck_assert_int_eq(rmdirp(tmp_dir), 0);
  assert_dne(tmp_dir);
}
END_TEST

START_TEST(test_rmdirp_tmp_three_lvls) {
  rand_state_t state;
  seed_rand(&state, 37, time(NULL));

  char tmp_dir[] = "/tmp/XXXXXX/XXXXXX/XXXXXX";
  random_file_name(tmp_dir, &state);

  ck_assert_int_eq(mkdirp(tmp_dir, S_IRWXU), 0);
  assert_is_dir(tmp_dir);

  tmp_dir[11] = '\0';
  ck_assert_int_eq(rmdirp(tmp_dir), 0);
  assert_dne(tmp_dir);
}
END_TEST

Suite* test_dircntl() {
  TCase* tc_mkdirp;
  TCase* tc_rmdirp;

  Suite* s = suite_create("DirCntl");

  tc_mkdirp = tcase_create("mkdirp");
  tcase_add_test(tc_mkdirp, test_mkdirp_empty);
  tcase_add_test(tc_mkdirp, test_mkdirp_self);
  tcase_add_test(tc_mkdirp, test_mkdirp_parent);
  tcase_add_test(tc_mkdirp, test_mkdirp_exists);
  tcase_add_test(tc_mkdirp, test_mkdirp_tmp_one_lvl);
  tcase_add_test(tc_mkdirp, test_mkdirp_tmp_two_lvls);
  tcase_add_test(tc_mkdirp, test_mkdirp_tmp_three_lvls);
  suite_add_tcase(s, tc_mkdirp);

  tc_rmdirp = tcase_create("rmdirp");
  tcase_add_test(tc_rmdirp, test_rmdirp_empty);
  tcase_add_test(tc_rmdirp, test_rmdirp_nonempty);
  tcase_add_test(tc_rmdirp, test_rmdirp_nonempty_multi_intact);
  tcase_add_test(tc_rmdirp, test_rmdirp_tmp_one_lvl);
  tcase_add_test(tc_rmdirp, test_rmdirp_tmp_two_lvls);
  tcase_add_test(tc_rmdirp, test_rmdirp_tmp_three_lvls);
  suite_add_tcase(s, tc_rmdirp);

  return s;
}
