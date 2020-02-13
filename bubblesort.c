
#include <stdint.h>
#include "sort.h"

void bubblesort(val_t *restrict A, val_t n) {
    /**
     * O(n^2)
     */
    uint32_t swapped, i;
    swapped = 1;
    while (swapped) {
        swapped = 0;
        for (i = 0; i < n - 1; i++) {
            if (A[i] > A[i + 1]) {
                swap(&A[i], &A[i + 1]);
                swapped = 1;
            }
        }
        n--;
    }
}