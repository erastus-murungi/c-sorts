//
// Created by Erastus Murungi on 2/13/20.
//

#include "sort.h"


void _mergesort(val_t *B, val_t *A, val_t n) {
    if (n == 1) {
        B[0] = A[0];
    } else {
        val_t mid = n / 2;
        val_t *C = malloc(sizeof(val_t) * n);
        _mergesort(C, A, mid);
        _mergesort(C + mid, A + mid, n - mid);
        merge(B, C, C + mid, mid, n - mid);
        free(C);
    }
}

static void merge(val_t *restrict C, val_t *restrict A, val_t *restrict B, val_t na, val_t nb) {
    while (na > 0 && nb > 0) {
        if (*A <= *B) {
            *C++ = *A++;
            na--;
        } else {
            *C++ = *B++;
            nb--;
        }
    }
    while (na > 0) {
        *C++ = *A++;
        na--;
    }
    while (nb > 0) {
        *C++ = *B++;
        nb--;
    }
}

val_t *msort(val_t *A, val_t na) {
    if (na < 2)
        return A;
    val_t *B = malloc(sizeof(val_t) * na);
    _mergesort(B, A, na);
    return B;
}
