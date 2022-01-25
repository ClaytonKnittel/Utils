
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <data_structs/rtree.h>

#include "test_utils.h"


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

Suite*
test_rtree()
{
	TCase* tc_basic;

	Suite* s = suite_create("R* tree");

	tc_basic = tcase_create("Basic");
	tcase_add_test(tc_basic, test_basic);
	suite_add_tcase(s, tc_basic);

	return s;
}

