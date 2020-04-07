//
// Created by Erastus Murungi on 2/13/20.
//

#include "sort.h"


val_t binary_search(val_t *T, val_t x, val_t high){
    val_t low, high, mid;
    
    low = 0;
    high = max(high, low + 1);
    
    while (low < high){
        mid = (low + high) >> 1;
        if (x <= T[mid])
            high = mid;
        else
            low = mid + 1;        
    }
    return high;
}


void _mergesort(val_t *B, val_t *A, val_t n) {
    if (n == 1) {
        B[0] = A[0];
    
    } else {
        
        val_t mid = n / 2;
        val_t *C = malloc(sizeof(val_t) * n);

        #pragma omp task shared(A, B, C)
        _mergesort(C, A, mid);

        #pragma omp task shared(A, B, C)
        _mergesort(C + mid, A + mid, n - mid);

        #pragma omp taskwait
        pmerge(B, C, C + mid, mid, n - mid);
        free(C);
    }
}

void pmerge(val_t *C, val_t *A, val_t *B, val_t na, val_t nb) {
    if (na < nb)
        pmerge(C, B, nb, A, na);

    if (na == 0)
        return;

    int ma, mb;

    ma = na >> 1;
    mb = binary_search(A[ma], B, nb);
    C[ma + mb] = A[ma];

    #pragma omp task shared (A, B, C)
    pmerge(C, A, ma, B, mb);

    #pragma omp task shared (A, B, C)
    pmerge(C + ma + mb + 1, A + ma + 1, na - ma - 1, B + mb, nb - mb);

    #pragma omp taskwait
}

val_t *msort(val_t *A, val_t na) {
    if (na < 2)
        return A;
    val_t *B = malloc(sizeof(val_t) * na);
    _mergesort(B, A, na);
    return B;
}