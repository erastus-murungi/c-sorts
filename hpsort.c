//
// Created by Erastus Murungi on 2/13/20.
//


#include "sort.h"
#include <assert.h>

/**
 * implementation of a max heap for heap sort
 */

static inline val_t parent(val_t i) {
    return i >> 1;
}

static inline val_t left(val_t i) {
    return (i << 1) + 1;
}

static inline int right(val_t i) {
    return (i << 1) + 2;
}

void max_heapify(val_t *A, val_t na, val_t i) {
    val_t l, r, largest;

    while (1) {
        l = left(i);
        r = right(i);

        largest = (l < na && A[l] > A[i]) ? l : i;

        if (r < na && A[r] > A[largest]) {
            largest = r;
        }
        if (largest == i) break;

        swap(&A[i], &A[largest]);

        i = largest;
    }
}

void build_max_heap(val_t *A, val_t low, val_t na) {
    val_t j;
    for (j = (na >> 1); j >= 0; j--) {
        max_heapify(A, low + na, low + j);
    }
}

int check_max_heap_invariant(const val_t *A, val_t na) {
    /**
     * check that the mean heap invariant is not violated in the entire heap
     */
    assert(na);
    int i;

    for (i = 0; i < (na >> 1); i++) {
        if (A[left(i)] > A[i] || A[right(i)] > A[i]) {
            fprintf(stderr, "The max-heap invariant is violated at index %d", i);
            return 0;
        }
    }
    return 1;
}

void _hpsort(val_t *A, val_t low, val_t na) {
    if (na < 2) return;

    build_max_heap(A, low, na);
    uint32_t i;
    for (i = low + na - 1; i >= 1; i--) {
        swap(&A[low], &A[i]);
        max_heapify(A, i, low);
    }
}


void hpsort(val_t *A, val_t na) {
    _hpsort(A, 0, na);
}