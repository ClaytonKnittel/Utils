
#include <stdio.h>

#include <data_structs/min_heap.h>

#include "test_utils.h"


START_TEST(test_basic)
{
    heap_t h;

    heap_node nodes[3] = {
        { .key = 5 },
        { .key = 3 },
        { .key = 7 },
    };

    heap_init(&h);

    heap_insert(&h, &nodes[0]);
    heap_validate(&h);

    heap_insert(&h, &nodes[1]);
    heap_validate(&h);

    heap_insert(&h, &nodes[2]);
    heap_validate(&h);

    heap_decrease_key(&h, &nodes[2], 2);
    heap_validate(&h);

    ck_assert(heap_find_min(&h)->key == 2);

    heap_destroy(&h);

#define N_TESTS 10

    heap_node * nodes2 = (heap_node *) malloc(N_TESTS * sizeof(heap_node));

    for (int i = 0; i < N_TESTS; i++) {
        nodes2[i].key = i;
    }

    heap_init(&h);

    for (int i = 0; i < N_TESTS; i++) {
        heap_insert(&h, &nodes2[i]);
        heap_validate(&h);
    }

    heap_decrease_key(&h, &nodes2[5], -1);
    heap_validate(&h);

    heap_decrease_key(&h, &nodes2[7], 2);
    heap_validate(&h);

    heap_destroy(&h);

    free(nodes2);


#undef N_TESTS
#define N_TESTS 8

    heap_node nodes3[N_TESTS] = {
        { .key = 1 },
        { .key = 5 },
        { .key = 8 },
        { .key = 10 },
        { .key = 2 },
        { .key = 4 },
        { .key = 6 },
        { .key = 3 },
    };

    heap_init(&h);

    for (int i = 0; i < N_TESTS; i++) {
        heap_insert(&h, &nodes3[i]);
        heap_validate(&h);
    }

    heap_node * min = heap_extract_min(&h);
    ck_assert(min == &nodes3[0]);
    heap_validate(&h);

    min = heap_extract_min(&h);
    heap_validate(&h);
    ck_assert(min->key == 2);

    min = heap_extract_min(&h);
    heap_validate(&h);
    ck_assert(min->key == 3);

    min = heap_extract_min(&h);
    heap_validate(&h);
    ck_assert(min->key == 4);

    min = heap_extract_min(&h);
    heap_validate(&h);
    ck_assert(min->key == 5);

    min = heap_extract_min(&h);
    heap_validate(&h);
    ck_assert(min->key == 6);

    min = heap_extract_min(&h);
    heap_validate(&h);
    ck_assert(min->key == 8);

    min = heap_extract_min(&h);
    heap_validate(&h);
    ck_assert(min->key == 10);

    heap_destroy(&h);


#undef N_TESTS
#define N_TESTS 100

    // test with heapsort

    heap_node * nodes4 = (heap_node *) malloc(N_TESTS * sizeof(heap_node));

    for (int i = 0; i < N_TESTS; i++) {
        nodes4[i].key = i;
    }

    heap_init(&h);

    for (int i = 0; i < N_TESTS; i++) {
        heap_insert(&h, &nodes4[i]);
        heap_validate(&h);
    }

    for (int i = 0; i < N_TESTS; i++) {
        heap_node * m = heap_extract_min(&h);
        heap_validate(&h);
        ck_assert(m->key == i);
    }

    ck_assert(heap_extract_min(&h) == NULL);

    heap_destroy(&h);


    // test with deleting random nodes

    heap_init(&h);

    for (int i = 0; i < N_TESTS; i++) {
        heap_insert(&h, &nodes4[i]);
        heap_validate(&h);
    }

    // delete every other node
    for (int i = 0; i < N_TESTS; i += 2) {
        heap_delete(&h, &nodes4[i]);
        heap_validate(&h);
    }

    for (int i = 0; i < 25; i++) {
        heap_node * m = heap_extract_min(&h);
        heap_validate(&h);
        ck_assert(m->key == 1 + i * 2);
    }

    // delete every other remaining node
    for (int i = 51; i < N_TESTS; i += 4) {
        heap_delete(&h, &nodes4[i]);
        heap_validate(&h);
    }

    for (int i = 0; i < 12; i++) {
        heap_node * m = heap_extract_min(&h);
        heap_validate(&h);
        ck_assert(m->key == 53 + i * 4);
    }

    ck_assert(heap_extract_min(&h) == NULL);

    heap_destroy(&h);


    // test with decreasing random nodes

    heap_init(&h);

    for (int i = 0; i < N_TESTS; i++) {
        heap_insert(&h, &nodes4[i]);
        heap_validate(&h);
    }

    // decrease every other node
    for (int i = 1; i < N_TESTS; i += 2) {
        heap_decrease_key(&h, &nodes4[i], i / 2);
        heap_validate(&h);
    }

    for (int i = 0; i < 75; i++) {
        heap_node * m = heap_extract_min(&h);
        heap_validate(&h);
        ck_assert(m->key == (2 * i) / 3);
    }

    // now just 50, 52, ... 98 remain

    for (int i = 52; i < N_TESTS; i += 4) {
        heap_decrease_key(&h, &nodes4[i], i - 2);
        heap_validate(&h);
    }

    for (int i = 0; i < 25; i++) {
        heap_node * m = heap_extract_min(&h);
        heap_validate(&h);
        ck_assert(m->key == 50 + 4 * (i / 2));
    }

    ck_assert(heap_extract_min(&h) == NULL);


    heap_destroy(&h);


    // test with increasing random nodes

    for (int i = 0; i < N_TESTS; i++) {
        nodes4[i].key = i;
    }

    heap_init(&h);

    for (int i = 0; i < N_TESTS; i++) {
        heap_insert(&h, &nodes4[i]);
        heap_validate(&h);
    }

    // increase every other node
    for (int i = 1; i < N_TESTS; i += 2) {
        heap_increase_key(&h, &nodes4[i], i * 2);
        heap_validate(&h);
    }

    for (int i = 0; i < 75; i++) {
        heap_node * m = heap_extract_min(&h);
        heap_validate(&h);
        ck_assert(m->key == 2 * ((2 * (i + 2)) / 3 - 1));
    }

    heap_validate(&h);

    // now just 102, 106, ... 198 remain

    for (int i = 51; i < N_TESTS; i += 4) {
        ck_assert(nodes4[i].key == i * 2);
        heap_increase_key(&h, &nodes4[i], i * 2 + 8);
        heap_validate(&h);
    }

    for (int i = 0; i < 25; i++) {
        heap_node * m = heap_extract_min(&h);
        heap_validate(&h);
        ck_assert(m->key == 106 + 4 * i || (i == 24 && m->key == 206));
    }

    ck_assert(heap_extract_min(&h) == NULL);

    heap_destroy(&h);


    free(nodes4);
}
END_TEST


Suite*
test_min_heap()
{
	TCase* tc_basic;

	Suite* s = suite_create("Min heap");

	tc_basic = tcase_create("Basic");
	tcase_add_test(tc_basic, test_basic);
	suite_add_tcase(s, tc_basic);

	return s;
}

