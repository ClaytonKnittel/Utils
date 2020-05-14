
#include <assert.h>
#include <stdio.h>

#include <data_structs/union_find.h>


#define TEST_ASSERT(expr) \
    assert(expr)


int main() {

    union_find uf;

    uf_init(&uf, 10);


    for (uf_node_t i = 0; i < 10; i++) {
        TEST_ASSERT(uf_find(&uf, i) == i);
    }

    uf_union(&uf, 1, 3);
    uf_union(&uf, 4, 5);
    uf_union(&uf, 1, 5);

    TEST_ASSERT(uf_find(&uf, 1) == uf_find(&uf, 3));
    TEST_ASSERT(uf_find(&uf, 1) == uf_find(&uf, 4));
    TEST_ASSERT(uf_find(&uf, 1) == uf_find(&uf, 5));
    TEST_ASSERT(uf_find(&uf, 0) == 0);
    TEST_ASSERT(uf_find(&uf, 2) == 2);
    TEST_ASSERT(uf_find(&uf, 6) == 6);
    TEST_ASSERT(uf_find(&uf, 7) == 7);
    TEST_ASSERT(uf_find(&uf, 8) == 8);
    TEST_ASSERT(uf_find(&uf, 9) == 9);


    return 0;
}

