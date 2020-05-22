
#include <assert.h>
#include <stdio.h>

#include <data_structs/min_heap.h>


#define TEST_ASSERT(expr) \
    assert(expr)


int main(int argc, char *argv[]) {

    heap_t h;

    heap_node nodes[3] = {
        { .key = 5 },
        { .key = 3 },
        { .key = 7 }
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

    assert(heap_find_min(&h)->key == 2);

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
    TEST_ASSERT(min == &nodes3[0]);
    print_heap(&h);
    heap_validate(&h);

    min = heap_extract_min(&h);
    heap_validate(&h);
    TEST_ASSERT(min->key == 2);

    min = heap_extract_min(&h);
    heap_validate(&h);
    TEST_ASSERT(min->key == 3);

    min = heap_extract_min(&h);
    heap_validate(&h);
    TEST_ASSERT(min->key == 4);

    min = heap_extract_min(&h);
    heap_validate(&h);
    TEST_ASSERT(min->key == 5);

    min = heap_extract_min(&h);
    heap_validate(&h);
    TEST_ASSERT(min->key == 6);

    min = heap_extract_min(&h);
    heap_validate(&h);
    TEST_ASSERT(min->key == 8);

    min = heap_extract_min(&h);
    heap_validate(&h);
    TEST_ASSERT(min->key == 10);

    heap_destroy(&h);

    return 0;
}

