
#include <stddef.h>

#include <data_structs/rtree.h>

int main(int argc, char* argv[])
{
	rtree_t tree;

	rtree_init(&tree, 1, 3);

	rtree_rect_t rect1 = {
		.lx = 0,
		.ly = 0,
		.ux = 1,
		.uy = 1
	};
	rtree_rect_t rect2 = {
		.lx = 10,
		.ly = 20,
		.ux = 11,
		.uy = 21
	};
	rtree_rect_t rect3 = {
		.lx = -1,
		.ly = 5,
		.ux = 13,
		.uy = 10
	};

	rtree_rect_t rect4 = {
		.lx = 0,
		.ly = 1,
		.ux = 2,
		.uy = 3
	};
	rtree_insert(&tree, &rect1, NULL);
	rtree_insert(&tree, &rect2, NULL);
	rtree_insert(&tree, &rect3, NULL);
	rtree_print(&tree);
	rtree_insert(&tree, &rect4, NULL);

	return 0;
}

