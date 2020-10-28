
#include <data_structs/rbtree.h>


int main(int argc, char * argv[]) {

    rb_tree tree;

    rb_init(&tree);

#define N_NODES 100

    rb_node nodes[N_NODES];

    for (int i = 1; i < N_NODES; i += 2) {
        rb_insert_ptr(&tree, &nodes[i]);
        rb_validate_ptr(&tree);
    }

    for (int i = 0; i < N_NODES; i += 2) {
        rb_insert_ptr(&tree, &nodes[i]);
        rb_validate_ptr(&tree);
    }

    return 0;
}

