
#include <time.h>
#include <stdlib.h>

#include <data_structs/irbtree.h>
#include <timing/timing.h>
#include <math/random.h>


struct node {
    irb_node base;
    int val;
};


static int node_less(const struct irb_node * a, const struct irb_node * b) {
    return ((struct node *) a)->val < ((struct node *) b)->val;
}

IRB_DEFINE_TYPE(node, node_less);


int main() {
    irb_tree tree;
    struct timespec start, end;

    irb_init(&tree);

#define N_NODES 1000000

    struct node * nodes = (struct node *) malloc(N_NODES * sizeof(struct node));

    seed_rand(time(NULL), 0);

    fprintf(stderr, "generating %d nodes\n", N_NODES);
    for (int i = 0; i < N_NODES; i++) {
        nodes[i].val = gen_rand();
    }

    fprintf(stderr, "inserting: ");
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < N_NODES; i++) {
        irb_insert_node(&tree, &nodes[i].base);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fprintf(stderr, "%lf s\n", timespec_diff(&end, &start));

    fprintf(stderr, "finding idxs unsafe: ");
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < N_NODES; i++) {
        irb_idx_t idx = irb_get_idx_unsafe(&nodes[i].base);
        (void) idx;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fprintf(stderr, "%lf s\n", timespec_diff(&end, &start));

    fprintf(stderr, "finding succs: ");
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < N_NODES - 1; i++) {
        irb_node * n = irb_find_succ(&nodes[i].base);
        (void) n;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fprintf(stderr, "%lf s\n", timespec_diff(&end, &start));

    fprintf(stderr, "finding preds: ");
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 1; i < N_NODES; i++) {
        irb_node * n = irb_find_pred(&nodes[i].base);
        (void) n;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fprintf(stderr, "%lf s\n", timespec_diff(&end, &start));

    fprintf(stderr, "finding upper/lower bounds: ");
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < N_NODES; i++) {
        irb_node * u = irb_upper_bound_node(&tree, &nodes[i].base);
        irb_node * l = irb_lower_bound_node(&tree, &nodes[i].base);
        (void) u;
        (void) l;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    fprintf(stderr, "%lf s\n", timespec_diff(&end, &start));

    fprintf(stderr, "done\n");

    free(nodes);

    return 0;
}
