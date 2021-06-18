
#include <stddef.h>

#include <data_structs/rtree.h>

int main(int argc, char* argv[])
{
	rtree_t tree;

	rtree_init(&tree, 1, 3);

	rtree_rect_t rects[] = {
		{
			.lx = 0,
			.ly = 0,
			.ux = 10,
			.uy = 10
		},
		{
			.lx = 100,
			.ly = 200,
			.ux = 110,
			.uy = 210
		},
		{
			.lx = 0,
			.ly = 10,
			.ux = 130,
			.uy = 50
		},
		{
			.lx = 0,
			.ly = 10,
			.ux = 20,
			.uy = 30
		},
		{
			.lx = 50,
			.ly = 180,
			.ux = 60,
			.uy = 208
		},
		{
			.lx = 0,
			.ly = 300,
			.ux = 10,
			.uy = 310
		},
		{
			.lx = 110,
			.ly = 320,
			.ux = 115,
			.uy = 330
		},
		{
			.lx = 140,
			.ly = 50,
			.ux = 180,
			.uy = 7
		}
	};

	rtree_print(&tree);
	rtree_check(&tree);
	for (int i = 0; i < sizeof(rects) / sizeof(rects[0]); i++) {
		printf("Inserting: <(%lld, %lld), (%lld, %lld)>\n",
				rects[i].lx, rects[i].ly, rects[i].ux, rects[i].uy);
		rtree_insert(&tree, &rects[i], NULL);
		rtree_print(&tree);
		rtree_check(&tree);
	}

	rtree_free(&tree);
	return 0;
}

