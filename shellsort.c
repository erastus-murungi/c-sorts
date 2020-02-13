//
// Created by Erastus Murungi on 2/13/20.
//


#include "sort.h"

void shellsort(val_t *A, val_t na) {
    static uint8_t ng = 16;
    static int gaps[16] = {1391376, 463792, 198768, 86961, 33936,
                           13776, 4592, 1968, 861, 336,
                           112, 48, 21, 7, 3, 1};
    val_t i, j, k, t, gap;

    for (k = ng - 1; k >= 0; k--) {
        for (i = gap = gaps[k]; i < na; i++) {
            t = A[i];
            for (j = i; j >= gap && A[j - gap] > t; j -= gap) {
                A[j] = A[j - gap];
            }
            A[j] = t;
        }
    }
}