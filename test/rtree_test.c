
#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <data_structs/rtree.h>

int main(int argc, char* argv[])
{
	rtree_t tree;

	rtree_init(&tree, 3, 10);
	const uint64_t n_rects = 3000;

	srand(0);

	rtree_rect_t* rects = (rtree_rect_t*) malloc(n_rects * sizeof(rtree_rect_t));
	for (uint64_t i = 0; i < n_rects; i++) {
		rtree_coord_t lx = rand() % 600;
		//rtree_coord_t ux = rand() % 600;
		rtree_coord_t ux = lx;
		rtree_coord_t ly = rand() % 600;
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
		printf("Inserting: <(%" PRIu64 ", %" PRIu64 "), (%" PRIu64 ", %" PRIu64 ")>\n",
				rects[i].lx, rects[i].ly, rects[i].ux, rects[i].uy);
		rtree_insert(&tree, &rects[i], NULL);
		//rtree_print(&tree);
		rtree_check(&tree);
	}
	rtree_print(&tree);

	rtree_free(&tree);
	return 0;
}

