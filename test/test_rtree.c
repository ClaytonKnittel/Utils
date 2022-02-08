
/**********************************************************
 *                       Includes                         *
 **********************************************************/

#include <fcntl.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <utils/data_structs/rtree.h>
#include <utils/math/random.h>
#include <utils/utils.h>

#include "test_utils.h"


/**********************************************************
 *                 Silence Test Fixtures                  *
 **********************************************************/

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
	rtree_validate(&tree);
	for (uint64_t i = 0; i < n_rects; i++) {
		printf("Inserting: <(%" PRIu64 ", %" PRIu64 "), (%" PRIu64 ", %" PRIu64 ")>\t(%" PRIu64")\n",
				rects[i].bb.lx, rects[i].bb.ly, rects[i].bb.ux, rects[i].bb.uy, i);
		rtree_insert(&tree, &rects[i].bb, rects[i].udata);
		//rtree_print(&tree);
		rtree_validate(&tree);

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


/**********************************************************
 *                      Test Utils                        *
 **********************************************************/

#define INIT_RTREE(m_min, m_max) \
	rtree_t tree; \
	ck_assert_int_eq(rtree_init(&tree, m_min, m_max), 0)

#define ASSERT_RECT_EQ(r1, r2) \
	ck_assert_int_eq((r1)->lx, (r2)->lx); \
	ck_assert_int_eq((r1)->ly, (r2)->ly); \
	ck_assert_int_eq((r1)->ux, (r2)->ux); \
	ck_assert_int_eq((r1)->uy, (r2)->uy)


/**********************************************************
 *                       Test Init                        *
 **********************************************************/

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


/**********************************************************
 *                      Test Insert                       *
 **********************************************************/

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
	seed_rand(15, 0);
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
		rtree_validate(&tree);
	}
	rtree_free(&tree);
}
END_TEST


/**********************************************************
 *                       Test Find                        *
 **********************************************************/

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

START_TEST(test_find_100_grid_with_udata)
{
	INIT_RTREE(3, 6);

	for (uint32_t i = 0; i < 10 * 10; i++) {
		rtree_rect_t rect = {
			.lx = (i % 10) * 10,
			.ly = (i / 10) * 10,
			.ux = (i % 10) * 10 + (10 / 2),
			.uy = (i / 10) * 10 + (10 / 2)
		};
		ck_assert_int_eq(rtree_insert(&tree, &rect, (void*) (ptr_int_t) i), 0);
		rtree_validate(&tree);
	}

	for (uint32_t i = 0; i < 10 * 10; i++) {
		rtree_rect_t rect = {
			.lx = (i % 10) * 10,
			.ly = (i / 10) * 10,
			.ux = (i % 10) * 10 + (10 / 2),
			.uy = (i / 10) * 10 + (10 / 2)
		};
		rtree_el_t* el = rtree_find_exact(&tree, &rect);
		ck_assert_ptr_ne(el, NULL);
		ASSERT_RECT_EQ(&el->bb, &rect);
		ck_assert_ptr_eq(el->udata, (void*) (ptr_int_t) i);
	}

	rtree_free(&tree);
}
END_TEST

static void
_run_randomized_find_udata_test(uint64_t n_rects, uint32_t m_min, uint32_t m_max,
		uint64_t seed)
{
	seed_rand(seed, 0);
	INIT_RTREE(m_min, m_max);

	for (uint32_t i = 0; i < n_rects; i++) {
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
		ck_assert_int_eq(rtree_insert(&tree, &rect, (void*) (ptr_int_t) i), 0);
		rtree_validate(&tree);
	}

	// reset the seed so we see the same sequence of rectangles
	seed_rand(seed, 0);
	for (uint32_t i = 0; i < n_rects; i++) {
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
		rtree_el_t* el = rtree_find_exact(&tree, &rect);
		ck_assert_ptr_ne(el, NULL);
		ASSERT_RECT_EQ(&el->bb, &rect);
		ck_assert_ptr_eq(el->udata, (void*) (ptr_int_t) i);
	}

	rtree_free(&tree);
}

START_TEST(test_find_100_random_with_udata)
{
	_run_randomized_find_udata_test(100, 3, 6, 16);
}
END_TEST

START_TEST(test_find_10000_random_with_udata)
{
	_run_randomized_find_udata_test(10000, 3, 6, 23);
}
END_TEST


/**********************************************************
 *                    Test Intersects                     *
 **********************************************************/

static volatile int intersects_single_cnt = 0;
static bool
_intersects_single_cb(const rtree_el_t* el, void* expected_rtree_el,
		const rtree_rect_t* rect, const rtree_t* tree)
{
	(void) tree;
	rtree_el_t* expected_el = (rtree_el_t*) expected_rtree_el;

	ASSERT_RECT_EQ(rect, &expected_el->bb);
	ASSERT_RECT_EQ(rect, &el->bb);
	ck_assert_ptr_eq(el->udata, expected_el->udata);

	intersects_single_cnt++;

	return true;
}

START_TEST(test_intersects_single)
{
	INIT_RTREE(5, 10);

	rtree_rect_t rect = {
		.lx = 0,
		.ly = 0,
		.ux = 5,
		.uy = 5
	};
	ck_assert_int_eq(rtree_insert(&tree, &rect, NULL), 0);

	rtree_el_t expected_el = {
		.bb = {
			.lx = 0,
			.ly = 0,
			.ux = 5,
			.uy = 5
		},
		.udata = NULL
	};

	intersects_single_cnt = 0;
	rtree_intersects_foreach(&tree, &rect, _intersects_single_cb, &expected_el);
	ck_assert_int_eq(intersects_single_cnt, 1);

	rtree_free(&tree);
}

static void
_run_grid_intersects_single_test(uint64_t sqrt_n_rects, uint32_t m_min,
		uint32_t m_max)
{
	INIT_RTREE(m_min, m_max);

	uint64_t n_rects = sqrt_n_rects * sqrt_n_rects;

	for (uint32_t i = 0; i < n_rects; i++) {
		rtree_rect_t rect = {
			.lx = (i % sqrt_n_rects) * sqrt_n_rects,
			.ly = (i / sqrt_n_rects) * sqrt_n_rects,
			.ux = (i % sqrt_n_rects) * sqrt_n_rects + (sqrt_n_rects / 2),
			.uy = (i / sqrt_n_rects) * sqrt_n_rects + (sqrt_n_rects / 2)
		};
		ck_assert_int_eq(rtree_insert(&tree, &rect, (void*) (ptr_int_t) i), 0);
		rtree_validate(&tree);
	}

	for (uint32_t i = 0; i < n_rects; i++) {
		rtree_el_t expected_el = {
			.bb = {
				.lx = (i % sqrt_n_rects) * sqrt_n_rects,
				.ly = (i / sqrt_n_rects) * sqrt_n_rects,
				.ux = (i % sqrt_n_rects) * sqrt_n_rects + (sqrt_n_rects / 2),
				.uy = (i / sqrt_n_rects) * sqrt_n_rects + (sqrt_n_rects / 2)
			},
			.udata = (void*) (ptr_int_t) i
		};

		intersects_single_cnt = 0;
		rtree_intersects_foreach(&tree, &expected_el.bb, _intersects_single_cb,
				&expected_el);
		ck_assert_int_eq(intersects_single_cnt, 1);
	}

	rtree_free(&tree);
}

START_TEST(test_intersects_grid_single_100_with_udata)
{
	_run_grid_intersects_single_test(10, 5, 10);
}
END_TEST

START_TEST(test_intersects_grid_single_10000_with_udata)
{
	_run_grid_intersects_single_test(100, 3, 6);
}
END_TEST


typedef struct grid_neighbors {
	const uint64_t sqrt_n_rects;
	const uint32_t i;

	uint32_t neighbors;
} grid_neighbors_t;

#define RECT_W 10

/*
 * Checks whether idx is one of the neighbors of this square.
 */
static bool
expected_neighbor(const grid_neighbors_t* gn, uint32_t idx)
{
	uint64_t x = gn->i % gn->sqrt_n_rects;
	uint64_t y = gn->i / gn->sqrt_n_rects;

	uint64_t _x = idx % gn->sqrt_n_rects;
	uint64_t _y = idx / gn->sqrt_n_rects;

	return (_x - x + 1 <= 2) && (_y - y + 1 <= 2);
}

static uint32_t
neighbor_idx(const grid_neighbors_t* gn, uint32_t idx)
{
	uint64_t x = gn->i % gn->sqrt_n_rects;
	uint64_t y = gn->i / gn->sqrt_n_rects;

	uint64_t _x = idx % gn->sqrt_n_rects;
	uint64_t _y = idx / gn->sqrt_n_rects;

	return (_x - x + 1) + 3 * (_y - y + 1);
}

static bool
mark_neighbor(grid_neighbors_t* gn, uint32_t idx)
{
	uint32_t n_idx = neighbor_idx(gn, idx);
	if (((gn->neighbors >> n_idx) & 1) != 0) {
		return false;
	}

	gn->neighbors |= (1u << n_idx);
	return true;
}

static void
all_neighbors_marked(grid_neighbors_t* gn)
{
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

	ck_assert_msg(n_mask == gn->neighbors, "Unexpected neighbor list, expected "
			"0x%03x, but got 0x%03x at index %u", n_mask, gn->neighbors, gn->i);
	ck_assert_int_eq(n_mask, gn->neighbors);
}

static bool
_intersects_all_neighbors_cb(const rtree_el_t* el, void* gn_ptr,
		const rtree_rect_t* rect, const rtree_t* tree)
{
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
	ck_assert_ptr_eq(el->udata, (void*) (ptr_int_t) el_idx);

	ck_assert(expected_neighbor(gn, el_idx));
	ck_assert(mark_neighbor(gn, el_idx));

	return true;
}

static void
_run_grid_intersects_all_neighbors_test(uint64_t sqrt_n_rects, uint32_t m_min,
		uint32_t m_max)
{
	INIT_RTREE(m_min, m_max);

	uint64_t n_rects = sqrt_n_rects * sqrt_n_rects;

	for (uint32_t i = 0; i < n_rects; i++) {
		rtree_rect_t rect = {
			.lx = (i % sqrt_n_rects) * RECT_W,
			.ly = (i / sqrt_n_rects) * RECT_W,
			.ux = (i % sqrt_n_rects) * RECT_W + (3 * RECT_W / 2),
			.uy = (i / sqrt_n_rects) * RECT_W + (3 * RECT_W / 2)
		};

		ck_assert_int_eq(rtree_insert(&tree, &rect, (void*) (ptr_int_t) i), 0);
		rtree_validate(&tree);
	}

	for (uint32_t i = 0; i < n_rects; i++) {
		rtree_rect_t rect = {
			.lx = (i % sqrt_n_rects) * RECT_W,
			.ly = (i / sqrt_n_rects) * RECT_W,
			.ux = (i % sqrt_n_rects) * RECT_W + (3 * RECT_W / 2),
			.uy = (i / sqrt_n_rects) * RECT_W + (3 * RECT_W / 2)
		};

		grid_neighbors_t gn = {
			.sqrt_n_rects = sqrt_n_rects,
			.i = i,
			.neighbors = 0x000u
		};
		rtree_intersects_foreach(&tree, &rect,
				_intersects_all_neighbors_cb, &gn);
		all_neighbors_marked(&gn);
	}

	rtree_free(&tree);
}

START_TEST(test_intersects_grid_all_neighbors_100_with_udata)
{
	_run_grid_intersects_all_neighbors_test(10, 5, 10);
}
END_TEST

START_TEST(test_intersects_grid_all_neighbors_10000_with_udata)
{
	_run_grid_intersects_all_neighbors_test(100, 4, 12);
}
END_TEST


/**********************************************************
 *                      Test Suite                        *
 **********************************************************/

Suite*
test_rtree()
{
	TCase* tc_init;
	TCase* tc_insert;
	TCase* tc_find_exact;
	TCase* tc_intersects;

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
	tcase_add_test(tc_find_exact, test_find_100_grid_with_udata);
	tcase_add_test(tc_find_exact, test_find_100_random_with_udata);
	tcase_add_test(tc_find_exact, test_find_10000_random_with_udata);
	suite_add_tcase(s, tc_find_exact);

	tc_intersects = tcase_create("Intersects");
	tcase_add_test(tc_intersects, test_intersects_single);
	tcase_add_test(tc_intersects, test_intersects_grid_single_100_with_udata);
	tcase_add_test(tc_intersects, test_intersects_grid_single_10000_with_udata);
	tcase_add_test(tc_intersects, test_intersects_grid_all_neighbors_100_with_udata);
	tcase_add_test(tc_intersects, test_intersects_grid_all_neighbors_10000_with_udata);
	suite_add_tcase(s, tc_intersects);

	return s;
}

