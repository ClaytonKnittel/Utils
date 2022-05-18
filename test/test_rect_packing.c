
#include <utils/algorithms/rect_packing.h>

#include "test_utils.h"

START_TEST(test_init)
{
	rect_packing_t packing;
	ck_assert_int_eq(rect_packing_init(&packing, 10, 10), 0);
	rect_packing_free(&packing);
}
END_TEST

static void
_print(const rect_packing_t* packing, vector_t* els)
{
	uint64_t w = packing->bin_w;
	uint64_t h = packing->bin_h;

	char* arr = (char*) calloc(w * h, sizeof(char));

	for (uint64_t i = 0; i < vector_size(els); i++) {
		packed_rect_el_t* el = *(packed_rect_el_t**) vector_get(els, i);
		printf("el: (%llu, %llu), (%llu x %llu) (%s)\n",
				el->lx, el->ly, el->w, el->h, boolstr(el->rotated));

		for (uint64_t r = el->ly; r < el->ly + el->h; r++) {
			for (uint64_t c = el->lx; c < el->lx + el->w; c++) {
				uint64_t idx = r * w + c;
				arr[idx] = '0' + i;
			}
		}
	}

	for (uint64_t r = h - 1; r < h; r--) {
		for (uint64_t c = 0; c < w; c++) {
			uint64_t idx = r * w + c;
			if (arr[idx] == 0) {
				printf("-");
			}
			else {
				printf("%c", arr[idx]);
			}
		}
		printf("\n");
	}

	rb_node_t* node;
	rb_for_each((rb_tree_t*) &packing->rows_height, node) {
		packed_rect_row_t* row = (packed_rect_row_t*) (((uint8_t*) node) -
				offsetof(packed_rect_row_t, rb_node_base_height));

		printf("Row: (0, %llu), h=%llu\n", row->ly, row->h);

		rb_node_t* node2;
		rb_for_each(&row->elements, node2) {
			packed_rect_el_t* el = (packed_rect_el_t*) (((uint8_t*) node2) -
					offsetof(packed_rect_el_t, rb_node_base));
			printf("\tFree rect: (%llu, %llu), %llu x %llu\n",
					el->lx, row->ly, el->w, row->h);
		}
	}
}

START_TEST(test_insert_one)
{
#define N_ELS 9
	vector_t els;
	vector_init(&els, sizeof(packed_rect_el_t*), N_ELS);
	rect_packing_t packing;
	ck_assert_int_eq(rect_packing_init(&packing, 10, 10), 0);
	rect_packing_validate(&packing);

	for (uint64_t i = 0; i < N_ELS; i++) {
		packed_rect_el_t* el;
		if (i < 6) {
			el = rect_packing_insert(&packing, 3, 4);
		}
		else {
			el = rect_packing_insert(&packing, 2, 2);
		}
		ck_assert_ptr_ne(el, NULL);
		rect_packing_validate(&packing);

		vector_push(&els, &el);
		_print(&packing, &els);
	}

	uint64_t remove_order[] = {
		1, 0, 6,
		5, 1, 0
	};

	for (uint64_t i = 0; i < sizeof(remove_order) / sizeof(uint64_t); i++) {
		rect_packing_remove(&packing, *(packed_rect_el_t**) vector_get(&els, remove_order[i]));
		vector_remove(&els, remove_order[i]);
		rect_packing_validate(&packing);
		_print(&packing, &els);
	}

	rect_packing_free(&packing);
#undef N_ELS
}
END_TEST

Suite*
test_rect_packing()
{
	TCase* tc_init;
	TCase* tc_insert;

	Suite* s = suite_create("Rectangle Bin Packing");

	tc_init = tcase_create("Init");
	tcase_add_test(tc_init, test_init);
	suite_add_tcase(s, tc_init);

	tc_insert = tcase_create("Insert");
	tcase_add_test(tc_insert, test_insert_one);
	suite_add_tcase(s, tc_insert);

	return s;
}

