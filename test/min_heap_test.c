
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

    return 0;
}

