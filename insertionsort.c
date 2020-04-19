//
// Created by Erastus Murungi on 2/13/20.
//

#include "sort.h"

void _insertionsort(val_t *A, val_t low, val_t na) {
    if (na < 2) return;

    val_t i, j, key;
    for (j = low + 1; j < na; j++) {
        key = A[j];
        for (i = j - 1; i >= 0 && A[i] > key; i--) {
            A[i + 1] = A[i];
        }
        A[i + 1] = key;
    }
}


void insertion_sort(val_t *restrict A, val_t na) {
        _insertionsort(A, 0, na);
}
