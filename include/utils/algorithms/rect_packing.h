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
	union {
		// Red-black tree of packed_rect_row's sorted by their height. Rows are
		// only in this tree when non-empty.
		rb_node_t rb_node_base_height;

		struct {
			// Pointer to the next and previous empty rows. Only defined when
			// empty.
			struct packed_rect_row* next;
			struct packed_rect_row* prev;
		};
	};

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

	// The maximum number of bins that will be allocated. If inserting a
	// rectangle would require allocating another bin beyond this limit, the
	// allocation will fail.
	uint32_t max_n_bins;

	// The list of bins being used. This list should ideally not get very large.
	vector_t bin_list;

	// Doubly linked list of empty rows sorted by height (rows in this list
	// aren't in the rows_height tree).
	packed_rect_row_t* row_freelist_start;
	packed_rect_row_t* row_freelist_end;

	// Red-black tree of the rows of all bins sorted by height.
	rb_tree_t rows_height;
} rect_packing_t;


int rect_packing_init(rect_packing_t*, packed_rect_coord_t bin_w,
		packed_rect_coord_t bin_h, uint32_t max_n_bins);
void rect_packing_free(rect_packing_t*);

// Can free rect el's without reinserting them into the rect_packing structure,
// but this will mean their allocated space will never be accessible. This must
// be done on elements which are not reinserted before freeing the rect_packing
// struct to avoid memory leaks.
void packed_rect_el_free(packed_rect_el_t*);

packed_rect_el_t* rect_packing_insert(rect_packing_t*, packed_rect_coord_t w,
		packed_rect_coord_t h);

void rect_packing_remove(rect_packing_t*, packed_rect_el_t* el);

#if defined(DO_TESTING) || defined(DEBUG)

void rect_packing_validate(const rect_packing_t*);

#endif

#endif /* _RECT_PACKING_H */
