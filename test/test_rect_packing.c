
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
_print(const rect_packing_t* packing, packed_rect_el_t** els, uint64_t n_els)
{
	uint64_t w = packing->bin_w;
	uint64_t h = packing->bin_h;

	char* arr = (char*) calloc(w * h, sizeof(char));

	for (uint64_t i = 0; i < n_els; i++) {
		packed_rect_el_t* el = els[i];
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
}

START_TEST(test_insert_one)
{
	const uint64_t N_ELS = 4;
	packed_rect_el_t* els[N_ELS];
	rect_packing_t packing;
	ck_assert_int_eq(rect_packing_init(&packing, 10, 10), 0);

	for (uint64_t i = 0; i < N_ELS; i++) {
		printf("INSERTING %llu\n", i);
		els[i] = rect_packing_insert(&packing, 3, 4);
		ck_assert_ptr_ne(els[i], NULL);
	}
	_print(&packing, els, N_ELS);

	rect_packing_free(&packing);
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

