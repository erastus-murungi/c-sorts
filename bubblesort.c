
#include <stdint.h>
#include "sort.h"

void bubblesort(val_t *restrict A, val_t na) {
    int32_t i, j;
    for (i = 0; i < na - 1; i++)
        for (j = na - 1; j >= i + 1; j--)
            if (A[i] > A[j]) INPLACESWAP(&A[i], &A[j]);
}