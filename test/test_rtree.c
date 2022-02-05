
#include <fcntl.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <utils/data_structs/rtree.h>
#include <utils/math/random.h>
#include <utils/timing/timing.h>
#include <utils/utils.h>

#include "test_utils.h"

static int stderr_tmp;
static int dev_null_fd;

static void
silence_stderr_setup(void)
{
	stderr_tmp = dup(STDERR_FILENO);
	dev_null_fd = open("/dev/null", O_WRONLY);
	dup2(dev_null_fd, STDERR_FILENO);
}

static void
silence_stderr_teardown(void)
{
	dup2(stderr_tmp, STDERR_FILENO);
	close(stderr_tmp);
	close(dev_null_fd);
}


#if 0
START_TEST(test_basic)
{
	rtree_t tree;

	rtree_init(&tree, 8, 25);
	uint64_t n_rects = 22;

	FILE* f = fopen("../test/test.dat", "r");
	ck_assert_ptr_ne(f, NULL);
	fseek(f, 0, SEEK_END);
	uint64_t len = ftell(f);
	fseek(f, 0, SEEK_SET);
	n_rects = len / (24);

	rtree_el_t* rects = (rtree_el_t*) malloc(n_rects * sizeof(rtree_el_t));
	for (uint64_t i = 0; i < n_rects; i++) {
		int64_t lx, ly;
		int64_t postal_code;

		ck_assert(fread(&lx, sizeof(lx), 1, f) == 1);
		ck_assert(fread(&ly, sizeof(ly), 1, f) == 1);
		ck_assert(fread(&postal_code, sizeof(postal_code), 1, f) == 1);

		printf("rect: %lld, %lld, %lld (%llu)\n", lx, ly, postal_code, i+1);

		rects[i].bb.lx = lx;
		rects[i].bb.ly = ly;
		rects[i].bb.ux = lx;
		rects[i].bb.uy = ly;
		rects[i].udata = (void*) postal_code;
	}

	/*
	srand(0);
	rtree_rect_t* rects = (rtree_rect_t*) malloc(n_rects * sizeof(rtree_rect_t));
	for (uint64_t i = 0; i < n_rects; i++) {
		rtree_coord_t lx = rand() % 1000000;
		//rtree_coord_t ux = rand() % 600;
		rtree_coord_t ux = lx;
		rtree_coord_t ly = rand() % 1000000;
		//rtree_coord_t uy = rand() % 600;
		rtree_coord_t uy = ly;
		if (lx > ux) {
			rtree_coord_t tmp = lx;
			lx = ux;
			ux = tmp;
		}
		if (ly > uy) {
			rtree_coord_t tmp = ly;
			ly = uy;
			uy = tmp;
		}
		rects[i].lx = lx;
		rects[i].ux = ux;
		rects[i].ly = ly;
		rects[i].uy = uy;
	}*/

	rtree_print(&tree);
	rtree_check(&tree);
	for (uint64_t i = 0; i < n_rects; i++) {
		printf("Inserting: <(%" PRIu64 ", %" PRIu64 "), (%" PRIu64 ", %" PRIu64 ")>\t(%" PRIu64")\n",
				rects[i].bb.lx, rects[i].bb.ly, rects[i].bb.ux, rects[i].bb.uy, i);
		rtree_insert(&tree, &rects[i].bb, rects[i].udata);
		//rtree_print(&tree);
		rtree_check(&tree);

		/*
		for (int j = 0; j <= i; j++) {
			rtree_el_t* el = rtree_find_exact(&tree, &rects[j].bb);
			ck_assert(el != NULL);
			ck_assert(el->udata == rects[j].udata);
		}*/
	}
	rtree_print(&tree);

	printf("Root bb: <(%" PRIu64 ", %" PRIu64 "), (%" PRIu64 ", %" PRIu64 ")>\n",
			tree.root->bb.lx, tree.root->bb.ly, tree.root->bb.ux, tree.root->bb.uy);

	rtree_free(&tree);
}
END_TEST
#endif

#define INIT_RTREE(m_min, m_max) \
	rtree_t tree; \
	ck_assert_int_eq(rtree_init(&tree, m_min, m_max), 0)

#define ASSERT_RECT_EQ(r1, r2) \
	ck_assert_int_eq((r1)->lx, (r2)->lx); \
	ck_assert_int_eq((r1)->ly, (r2)->ly); \
	ck_assert_int_eq((r1)->ux, (r2)->ux); \
	ck_assert_int_eq((r1)->uy, (r2)->uy)


START_TEST(test_init_half_min)
{
	INIT_RTREE(2, 4);
	rtree_free(&tree);
}

START_TEST(test_init_large_max)
{
	INIT_RTREE(5, 100);
	rtree_free(&tree);
}

START_TEST(test_init_over_half_min)
{
	rtree_t tree;
	ck_assert_int_ne(rtree_init(&tree, 4, 7), 0);
}

START_TEST(test_init_0_min)
{
	rtree_t tree;
	ck_assert_int_ne(rtree_init(&tree, 0, 5), 0);
}

START_TEST(test_init_1_min)
{
	rtree_t tree;
	ck_assert_int_ne(rtree_init(&tree, 1, 5), 0);
}

START_TEST(test_insert_1)
{
	INIT_RTREE(5, 10);

	rtree_rect_t rect = {
		.lx = 0,
		.ly = 0,
		.ux = 5,
		.uy = 5
	};
	ck_assert_int_eq(rtree_insert(&tree, &rect, NULL), 0);
	rtree_free(&tree);
}
END_TEST

START_TEST(test_insert_100)
{
	INIT_RTREE(5, 10);

	for (uint32_t i = 0; i < 100; i++) {
		rtree_rect_t rect = {
			.lx = (i % 10) * 10,
			.ly = (i / 10) * 10,
			.ux = (i % 10) * 10 + 5,
			.uy = (i / 10) * 10 + 5
		};
		ck_assert_int_eq(rtree_insert(&tree, &rect, NULL), 0);
	}
	rtree_free(&tree);
}
END_TEST

START_TEST(test_insert_10000_random)
{
	INIT_RTREE(10, 30);

	for (uint32_t i = 0; i < 10000; i++) {
		uint64_t x = gen_rand_r(65536);
		uint64_t y = gen_rand_r(65536);

		uint64_t wx = gen_rand_r(32);
		uint64_t wy = gen_rand_r(32);

		rtree_rect_t rect = {
			.lx = x,
			.ly = y,
			.ux = x + wx,
			.uy = y + wy
		};
		ck_assert_int_eq(rtree_insert(&tree, &rect, NULL), 0);
	}
	rtree_free(&tree);
}
END_TEST

START_TEST(test_find_single)
{
	INIT_RTREE(5, 10);

	rtree_rect_t rect = {
		.lx = 0,
		.ly = 0,
		.ux = 5,
		.uy = 5
	};
	ck_assert_int_eq(rtree_insert(&tree, &rect, NULL), 0);

	rtree_el_t* el = rtree_find_exact(&tree, &rect);
	ck_assert_ptr_ne(el, NULL);
	ASSERT_RECT_EQ(&el->bb, &rect);
	ck_assert_ptr_eq(el->udata, NULL);

	rtree_free(&tree);
}

START_TEST(test_find_single_fail)
{
	INIT_RTREE(5, 10);

	rtree_rect_t rect = {
		.lx = 0,
		.ly = 0,
		.ux = 5,
		.uy = 5
	};
	ck_assert_int_eq(rtree_insert(&tree, &rect, NULL), 0);

	rtree_rect_t wrong_rect = {
		.lx = 1,
		.ly = 0,
		.ux = 5,
		.uy = 5
	};

	ck_assert_ptr_eq(rtree_find_exact(&tree, &wrong_rect), NULL);

	rtree_free(&tree);
}

START_TEST(test_find_100_with_udata)
{
	INIT_RTREE(30, 100);
#define BASE 200

	printf("inserting: ");
	fflush(stdout);
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (uint32_t i = 0; i < BASE * BASE; i++) {
		rtree_rect_t rect = {
			.lx = (i % BASE) * BASE,
			.ly = (i / BASE) * BASE,
			.ux = (i % BASE) * BASE + (BASE / 2),
			.uy = (i / BASE) * BASE + (BASE / 2)
		};
		ck_assert_int_eq(rtree_insert(&tree, &rect, (void*) (ptr_int_t) i), 0);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	printf("%g s\n", timespec_diff(&start, &end));

	printf("finding: ");
	fflush(stdout);
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (uint32_t i = 0; i < BASE * BASE; i++) {
		rtree_rect_t rect = {
			.lx = (i % BASE) * BASE,
			.ly = (i / BASE) * BASE,
			.ux = (i % BASE) * BASE + (BASE / 2),
			.uy = (i / BASE) * BASE + (BASE / 2)
		};
		rtree_el_t* el = rtree_find_exact(&tree, &rect);
		ck_assert_ptr_ne(el, NULL);
		ASSERT_RECT_EQ(&el->bb, &rect);
		ck_assert_ptr_eq(el->udata, (void*) (ptr_int_t) i);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);
	printf("%g s\n", timespec_diff(&start, &end));

	rtree_free(&tree);
}
END_TEST

Suite*
test_rtree()
{
	TCase* tc_init;
	TCase* tc_insert;
	TCase* tc_find_exact;

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

	tc_find_exact = tcase_create("Find Exact");
	tcase_add_test(tc_find_exact, test_find_single);
	tcase_add_test(tc_find_exact, test_find_single_fail);
	tcase_add_test(tc_find_exact, test_find_100_with_udata);
	suite_add_tcase(s, tc_find_exact);

	return s;
}

