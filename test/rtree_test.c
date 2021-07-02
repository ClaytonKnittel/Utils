
#include <assert.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <data_structs/rtree.h>

int main(int argc, char* argv[])
{
	rtree_t tree;

	rtree_init(&tree, 3, 10);
	const uint64_t n_rects = 4000;

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
	}

	rtree_print(&tree);
	rtree_check(&tree);
	for (int i = 0; i < n_rects; i++) {
		printf("Inserting: <(%" PRIu64 ", %" PRIu64 "), (%" PRIu64 ", %" PRIu64 ")>\t(%d)\n",
				rects[i].lx, rects[i].ly, rects[i].ux, rects[i].uy, i);
		rtree_insert(&tree, &rects[i], (void*) ((uint64_t) i));
		//rtree_print(&tree);
		rtree_check(&tree);

		for (int j = 0; j <= i; j++) {
			rtree_el_t* el = rtree_find_exact(&tree, &rects[j]);
			assert(el != NULL);
			assert(el->udata == (void*) ((uint64_t) j));
		}
	}
	rtree_print(&tree);

	rtree_free(&tree);
	return 0;
}

