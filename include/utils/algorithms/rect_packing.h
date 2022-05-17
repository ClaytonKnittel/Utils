#ifndef _RECT_PACKING_H
#define _RECT_PACKING_H

#include <utils/data_structs/rbtree.h>
#include <utils/data_structs/vector.h>

/*
 * Implementation of rectangle bin-packing, with fixed bin sizes of
 * bin_width x bin_height.
 *
 * The algorithm tries to pack all rectangles given into as few bins of fixed
 * size as possible. Rectangles are allowed to be rotated, but must stay
 * axis-aligned.
 */

typedef uint64_t packed_rect_coord_t;

typedef struct packed_rect_el {

	// The x-coordinate of the lower-left side of the rectangle in the bin it is
	// placed.
	packed_rect_coord_t lx;

	// The width of the rectangle.
	packed_rect_coord_t w;

	union {
		// Struct containing information about allocated rect entries.
		struct {
			// y-coordinate of the lower-left side of the rectangle.
			packed_rect_coord_t ly;
			// The height of the rectangle.
			packed_rect_coord_t h;

			// True if the rectangle is rotated 90 degrees.
			bool rotated;

			// The index of the bin this rectangle is packed into.
			uint32_t bin_idx;

			// Pointer to the packed_rect_row this rect is in. Not needed when
			// empty.
			struct packed_rect_row* parent_row;
		};

		struct {
			// packed_rect_el's are stored in a red-black tree within their row sorted
			// by their lx coordinate.
			rb_node_t rb_node_base;

			// Pointer to the next and previous free packed rect element in this
			// row. Only defined when empty.
			struct packed_rect_el* next;
			struct packed_rect_el* prev;
		};
	};
} packed_rect_el_t;

typedef struct packed_rect_row {
	// Red-black tree of packed_rect_row's sorted by their height.
	rb_node_t rb_node_base_height;

	// Red-black tree of packed_rect_row's sorted by their lower y-coordinate.
	rb_node_t rb_node_base_ly;

	// The lower y-coordinate of this row (x is always 0).
	packed_rect_coord_t ly;
	// The height of this row (width always equals bin width).
	packed_rect_coord_t h;

	// A tree of the packed_rect_el's in this row, ordered from lowest to
	// highest lx coordinate.
	rb_tree_t elements;

	// Pointers to the first and last empty packed rect el in the list of
	// elements.
	// TODO test if sorting by width or placing in rb tree increases perf for
	// best-fit.
	packed_rect_el_t* freelist_start;
	packed_rect_el_t* freelist_end;

	// Pointer to the packed_rect_bin this row is in.
	struct packed_rect_bin* parent_bin;
} packed_rect_row_t;

typedef struct packed_rect_bin {
	// Red-black tree of the rows of this bin sorted by lower y-coordinate.
	rb_tree_t rows_ly;
} packed_rect_bin_t;


typedef struct rect_packing {
	// The fixed dimensions of bins to pack rectangles in.
	packed_rect_coord_t bin_w;
	packed_rect_coord_t bin_h;

	// The list of bins being used. This list should ideally not get very large.
	vector_t bin_list;

	// Red-black tree of the rows of all bins sorted by height.
	rb_tree_t rows_height;
} rect_packing_t;


int rect_packing_init(rect_packing_t*, packed_rect_coord_t bin_w,
		packed_rect_coord_t bin_h);
void rect_packing_free(rect_packing_t*);

packed_rect_el_t* rect_packing_insert(rect_packing_t*, packed_rect_coord_t w,
		packed_rect_coord_t h);

void rect_packing_remove(rect_packing_t*, packed_rect_el_t* el);

void rect_packing_validate(const rect_packing_t*);

#endif /* _RECT_PACKING_H */
