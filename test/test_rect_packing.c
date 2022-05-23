
#include <utils/algorithms/rect_packing.h>

#include <utils/algorithms/sort.h>
#include <utils/math/random.h>

#include "test_utils.h"

START_TEST(test_init)
{
	rect_packing_t packing;
	ck_assert_int_eq(rect_packing_init(&packing, 10, 10, 1), 0);
	rect_packing_free(&packing);
}
END_TEST

typedef struct el_info {
	packed_rect_el_t* el;
	uint64_t w;
	uint64_t h;
} el_info_t;

static void
_rect_packing_validate(const rect_packing_t* packing, vector_t* els)
{
	rect_packing_validate(packing);

	uint64_t w = packing->bin_w;
	uint64_t h = packing->bin_h;
	uint64_t* bin_list = (uint64_t*) calloc(w * h * vector_size(&packing->bin_list), sizeof(uint8_t));

	for (uint64_t i = 0; i < vector_size(els); i++) {
		el_info_t* info = (el_info_t*) vector_get(els, i);
		if (info->el == NULL) {
			continue;
		}
	}

	// fill in all the empty space

	free(bin_list);
}

static void
_print(const rect_packing_t* packing, vector_t* els, bool verbose)
{
	uint64_t w = packing->bin_w;
	uint64_t h = packing->bin_h;
	char* arr;
	uint64_t area = 0;

	if (verbose) {
		arr = (char*) calloc(vector_size(&packing->bin_list) * w * h, sizeof(char));
	}

	for (uint64_t i = 0; i < vector_size(els); i++) {
		el_info_t* info = (el_info_t*) vector_get(els, i);
		packed_rect_el_t* el = info->el;
		if (el == NULL) {
			continue;
		}

		if (verbose) {
			printf("el: (%llu, %llu), (%llu x %llu) (%u) (%s)\n",
					el->lx, el->ly, el->w, el->h, el->bin_idx, boolstr(el->rotated));
		}

		if (verbose) {
			for (uint64_t r = el->ly; r < el->ly + el->h; r++) {
				for (uint64_t c = el->lx; c < el->lx + el->w; c++) {
					uint64_t idx = el->bin_idx * w * h + r * w + c;
					arr[idx] = '0' + (i % 10);
				}
			}
		}

		area += el->w * el->h;
	}

	if (verbose) {
		for (uint64_t r = h - 1; r < h; r--) {
			for (uint64_t bin_idx = 0; bin_idx < vector_size(&packing->bin_list); bin_idx++) {
				for (uint64_t c = 0; c < w; c++) {
					uint64_t idx = bin_idx * w * h + r * w + c;
					if (arr[idx] == 0) {
						printf("-");
					}
					else {
						printf("%c", arr[idx]);
					}
				}

				if (bin_idx < vector_size(&packing->bin_list) - 1) {
					printf("      ");
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

		packed_rect_row_t* terminal = (packed_rect_row_t*) (((uint8_t*) &packing->row_freelist_start) + offsetof(packed_rect_row_t, next));
		for (packed_rect_row_t* row = packing->row_freelist_start; row != terminal; row = row->next) {
			printf("Empty Row: (0, %llu), h=%llu\n", row->ly, row->h);

			rb_node_t* node2;
			rb_for_each(&row->elements, node2) {
				packed_rect_el_t* el = (packed_rect_el_t*) (((uint8_t*) node2) -
						offsetof(packed_rect_el_t, rb_node_base));
				printf("\tFree rect: (%llu, %llu), %llu x %llu\n",
						el->lx, row->ly, el->w, row->h);
			}
		}
	}

	printf("Utilization: %g\n", (double) area / (double) (vector_size(&packing->bin_list) * packing->bin_w * packing->bin_h));
}

DEFINE_CSORT_DEFAULT_FNS_NAMED_16(__uint128_t, wh, __default_sort_cmp, __default_sort_cswap)

static void
_reshuffle_els(rect_packing_t* packing, vector_t* els)
{
	uint64_t n_els = vector_size(els);
	uint64_t* wh = malloc(2 * n_els * sizeof(uint64_t));

	for (uint64_t i = 0; i < n_els; i++) {
		el_info_t* info = (el_info_t*) vector_get(els, i);
		packed_rect_el_t* el = info->el;

		wh[2 * i + 0] = el->h;
		wh[2 * i + 1] = el->w;

		rect_packing_remove(packing, el);
	}
	vector_clear(els);

	csort_wh((__uint128_t*) wh, n_els);

	for (uint64_t i = n_els - 1; i < n_els; i--) {
		el_info_t info;
		info.w = wh[2 * i + 0];
		info.h = wh[2 * i + 1];
		info.el = rect_packing_insert(packing, info.w, info.h);
		vector_push(els, &info);
	}

	free(wh);
}

START_TEST(test_insert_one)
{
#define N_ELS 12
	vector_t els;
	vector_init(&els, sizeof(el_info_t), N_ELS);
	rect_packing_t packing;
	ck_assert_int_eq(rect_packing_init(&packing, 10, 10, 2), 0);
	_rect_packing_validate(&packing, &els);

	for (uint64_t i = 0; i < N_ELS; i++) {
		el_info_t info;
		if (i < 6) {
			info.el = rect_packing_insert(&packing, 3, 4);
			info.w = 3;
			info.h = 4;
		}
		else {
			info.el = rect_packing_insert(&packing, 2, 2);
			info.w = 2;
			info.h = 2;
		}
		ck_assert_ptr_ne(info.el, NULL);

		vector_push(&els, &info);
		_print(&packing, &els, true);
		_rect_packing_validate(&packing, &els);
	}

	uint64_t remove_order[N_ELS] = {
		1, 0, 6,
		5, 1, 0,
		2, 0, 0,
		0, 0, 0
	};

	for (uint64_t i = 0; i < N_ELS; i++) {
		el_info_t* info = (el_info_t*) vector_get(&els, remove_order[i]);
		rect_packing_remove(&packing, info->el);
		vector_remove(&els, remove_order[i]);
		_print(&packing, &els, true);
		_rect_packing_validate(&packing, &els);
	}

	vector_free(&els);
	rect_packing_free(&packing);
#undef N_ELS
}
END_TEST

START_TEST(test_insert_many)
{
#define GEN_WH() \
	uint64_t w = 30 + 1 * gen_rand_r(100); \
	uint64_t h = w + ((int64_t) gen_rand_r(51) - 25)
//#define GEN_WH() \
//	uint64_t w = 5 + gen_rand_r(100); \
//	uint64_t h = 5 + gen_rand_r(100)

#define VERBOSE false
#define DO_RESHUFFLE true

#define N_ELS 40000000
	vector_t els;
	vector_init(&els, sizeof(el_info_t), N_ELS);
	rect_packing_t packing;
	ck_assert_int_eq(rect_packing_init(&packing, 8192, 8192, 8), 0);
	_rect_packing_validate(&packing, &els);

	seed_rand(0, 0);

	for (uint64_t i = 0; i < N_ELS; i++) {
		GEN_WH();

		if (VERBOSE) {
			printf("insert %llu x %llu:\n", w, h);
		}
		el_info_t info;
		info.el = rect_packing_insert(&packing, w, h);
		info.w = w;
		info.h = h;

		if (info.el == NULL) {
			break;
		}

		vector_push(&els, &info);

	}
	_print(&packing, &els, VERBOSE);
	printf("No room for el (inserted %llu)!\n", vector_size(&els));

	uint64_t size = vector_size(&els);

	// random removal order
	for (uint64_t j = 0; j < size / 2; j++) {
		uint64_t i = gen_rand_r64(vector_size(&els));

		el_info_t* info = (el_info_t*) vector_get(&els, i);
		packed_rect_el_t* el = info->el;
		if (el == NULL) {
			j--;
			continue;
		}

		if (VERBOSE) {
			printf("Removing %llu x %llu at (%llu, %llu) (%llu)\n",
					el->w, el->h, el->lx, el->ly, i);
		}

		rect_packing_remove(&packing, el);

		el_info_t zero = {
			.el = NULL,
			.w = 0,
			.h = 0
		};
		vector_set(&els, i, &zero);
	}

	uint64_t j = 0;
	for (uint64_t i = 0; i < vector_size(&els); i++) {
		el_info_t* info = (el_info_t*) vector_get(&els, i);
		if (info->el != NULL) {
			vector_set(&els, j, info);
			j++;
		}
	}
	els.len = j;

	if (VERBOSE) {
		_print(&packing, &els, VERBOSE);
	}

	if (DO_RESHUFFLE) {
		_reshuffle_els(&packing, &els);

		printf("RESHUFFLED:\n");
		if (VERBOSE) {
			_print(&packing, &els, VERBOSE);
		}
	}

	for (uint64_t i = vector_size(&els); i < N_ELS; i++) {
		GEN_WH();

		if (VERBOSE) {
			printf("insert %llu x %llu:\n", w, h);
		}
		el_info_t info;
		info.el = rect_packing_insert(&packing, w, h);
		info.w = w;
		info.h = h;

		if (info.el == NULL) {
			break;
		}

		vector_push(&els, &info);

	}
	_print(&packing, &els, VERBOSE);
	printf("No room for el (inserted %llu)!\n", vector_size(&els));

	uint64_t els_size = vector_size(&els);
	for (uint64_t i = 0; i < els_size; i++) {
		el_info_t* info = (el_info_t*) vector_get(&els, i);
		packed_rect_el_free(info->el);
	}
	vector_free(&els);
	rect_packing_free(&packing);

#undef N_ELS
#undef DO_RESHUFFLE
#undef VERBOSE
#undef GEN_WH
}
END_TEST

START_TEST(test_insert_remove_many)
{
//#define GEN_WH() \
//	uint64_t w = 30 + 1 * gen_rand_r(100); \
//	uint64_t h = w + ((int64_t) gen_rand_r(51) - 25)
#define GEN_WH() \
	uint64_t w = 1 + gen_rand_r(10); \
	uint64_t h = 1 + gen_rand_r(10)

#define VERBOSE false
#define DO_RESHUFFLE true

#define N_ELS 40000000
	vector_t els;
	vector_init(&els, sizeof(el_info_t), N_ELS);
	rect_packing_t packing;
	ck_assert_int_eq(rect_packing_init(&packing, 64, 64, 2), 0);
	_rect_packing_validate(&packing, &els);

	seed_rand(7, 0);

	for (uint64_t i = 0; i < N_ELS; i++) {
		if (i % 3 == 2) {
			uint64_t remove_idx;
			packed_rect_el_t* el;

			do {
				remove_idx = gen_rand_r64(2 * i / 3);
				el_info_t* info = (el_info_t*) vector_get(&els, remove_idx);
				el = info->el;
			} while (el == NULL);

			if (VERBOSE) {
				printf("remove %llu (%llu x %llu at %llu, %llu)\n",
						remove_idx,
						el->w, el->h, el->lx, el->ly);
			}

			rect_packing_remove(&packing, el);
			el_info_t zero = {
				.el = NULL,
				.w = 0,
				.h = 0
			};
			vector_set(&els, remove_idx, &zero);
		}
		else { 
			GEN_WH();

			if (VERBOSE) {
				printf("insert %llu x %llu:\n", w, h);
			}
			el_info_t info;
			info.el = rect_packing_insert(&packing, w, h);
			info.w = w;
			info.h = h;

			if (info.el == NULL) {
				break;
			}

			vector_push(&els, &info);
		}

	}
	_print(&packing, &els, VERBOSE);
	printf("No room for el (inserted %llu)!\n", vector_size(&els));

	uint64_t j = 0;
	for (uint64_t i = 0; i < vector_size(&els); i++) {
		el_info_t* info = (el_info_t*) vector_get(&els, i);
		if (info->el != NULL) {
			vector_set(&els, j, info);
			j++;
		}
	}
	els.len = j;

	if (DO_RESHUFFLE) {
		_reshuffle_els(&packing, &els);

		printf("RESHUFFLED:\n");
		if (VERBOSE) {
			_print(&packing, &els, VERBOSE);
		}
	}

	for (uint64_t i = vector_size(&els); i < N_ELS; i++) {
		GEN_WH();

		if (VERBOSE) {
			printf("insert %llu x %llu:\n", w, h);
		}
		el_info_t info;
		info.el = rect_packing_insert(&packing, w, h);
		info.w = w;
		info.h = h;

		if (info.el == NULL) {
			break;
		}

		vector_push(&els, &info);

	}
	_print(&packing, &els, VERBOSE);
	printf("No room for el (inserted %llu)!\n", vector_size(&els));

	uint64_t els_size = vector_size(&els);
	for (uint64_t i = 0; i < els_size; i++) {
		el_info_t* info = (el_info_t*) vector_get(&els, i);
		packed_rect_el_free(info->el);
	}
	vector_free(&els);
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
	tcase_add_test(tc_insert, test_insert_many);
	tcase_add_test(tc_insert, test_insert_remove_many);
	suite_add_tcase(s, tc_insert);

	return s;
}

