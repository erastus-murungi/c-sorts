//
// Created by Erastus Murungi on 2/13/20.
//

#include "sort.h"


void selection_sort(val_t *A, val_t na) {
    val_t i, j, min_pos;

    for (i = 0; i < na; i++) {
        min_pos = i;
        for (j = i + 1; j < na; j++) {
            if (A[j] < A[min_pos]) {
                min_pos = j;
            }
        }
        if (min_pos != i) {
            INPLACESWAP(&A[i], &A[min_pos]);
        }
    }
}