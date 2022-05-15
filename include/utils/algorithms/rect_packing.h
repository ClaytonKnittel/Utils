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
	// packed_rect_el's are stored in a red-black tree within their row sorted
	// by their lx coordinate.
	rb_node_t rb_node_base;

	// The coordinates of the lower-left side of the rectangle in the bin it is
	// placed.
	packed_rect_coord_t lx;
	packed_rect_coord_t ly;

	// True if this is an empty rectangle placeholder.
	bool empty;
	// True if the rectangle is rotated 90 degrees.
	bool rotated;
	// The index of the bin this rectangle is packed into.
	uint32_t bin_idx;

	// The width and height of the rectangle are fixed when the rectangle is
	// inserted.
	packed_rect_coord_t w;
	packed_rect_coord_t h;

	// Pointer to the packed_rect_row this rect is in.
	struct packed_rect_row* row;

	union {
		// Pointer to user-defined type pertaining to this packed element. Only
		// defined when !empty.
		void* udata;

		// Pointer to the next free packed rect element in this row, or NULL if
		// it is the last free element. Only defined when empty.
		struct packed_rect_el* next;
	};
} packed_rect_el_t;

_Static_assert(offsetof(packed_rect_el_t, lx) == offsetof(rb_uint_node_t, val),
		"Expect packed_rect_el_t to alias rb_uint_node with val == lx");

typedef struct packed_rect_row {
	// packed_rect_row's are stored in a red-black tree sorted by their height
	rb_node_t rb_node_base;

	// The height of this row (width always equals bin width).
	packed_rect_coord_t h;

	// The lower y-coordinate of this row (x is always 0).
	packed_rect_coord_t ly;

	// A tree of the packed_rect_el's in this row, ordered from lowest to
	// highest lx coordinate.
	rb_tree_t elements;

	// Pointer to the first empty packed rect el in the list of elements.
	packed_rect_el_t* empty_list;

	// Pointer to the packed_rect_bin this row is in.
	struct packed_rect_bin* bin;
} packed_rect_row_t;

_Static_assert(offsetof(packed_rect_row_t, h) == offsetof(rb_uint_node_t, val),
		"Expect packed_rect_row_t to alias rb_uint_node with val == h");

typedef struct packed_rect_bin {
	rb_tree_t rows;
} packed_rect_bin_t;


typedef struct rect_packing {
	// The fixed dimensions of bins to pack rectangles in.
	packed_rect_coord_t bin_w;
	packed_rect_coord_t bin_h;

	vector_t bin_list;
} rect_packing_t;


int rect_packing_init(rect_packing_t*, packed_rect_coord_t bin_w,
		packed_rect_coord_t bin_h);
void rect_packing_free(rect_packing_t*);

packed_rect_el_t* rect_packing_insert(rect_packing_t*, packed_rect_coord_t w,
		packed_rect_coord_t h, void* udata);

void rect_packing_remove(rect_packing_t*, packed_rect_el_t* el);

#endif /* _RECT_PACKING_H */
