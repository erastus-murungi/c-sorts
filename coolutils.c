//
// Created by Erastus Murungi on 2/13/20.
//

#include "sort.h"

#ifdef _OPENMP
#include <omp.h>
#endif

uint64_t msb(uint64_t v) {
    static int deBruijn[64] = {0,
                               1, 2, 53, 3, 7, 54, 27, 4, 38, 41, 8, 34, 55, 48, 28,
                               62, 5, 39, 46, 44, 42, 22, 9, 24, 35, 59, 56, 49, 18, 29, 11,
                               63, 52, 6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10,
                               51, 25, 36, 32, 60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12
    };
    static uint64_t multiplier = 0x022fdd63cc95386dUL;

    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v |= v >> 32;
    if (v == (uint64_t) -1) return 64;
    v++;
    return deBruijn[(v * multiplier) >> 58];
}

val_t max_array(const val_t *A, val_t na) {
    if (na < 0) {
        fprintf(stderr, "error");
        exit(EXIT_FAILURE);
    }

    val_t max_val, i;
#pragma omp parallel for
    for (i = 0, max_val = A[0]; i < na; i++)
        max_val = (A[i] > max_val) ? A[i] : max_val;
    return max_val;
}

bool is_sorted(const val_t *A, val_t na) {
    for (val_t i = 1; i < na; i++) {
        if (A[i - 1] > A[i]) return false;
    }
    return true;
}

void print_array(val_t *A, val_t n) {
    if (n) {
        printf("[");
        val_t i;
        for (i = 0; i < (n - 1); i++) printf("%lld, ", A[i]);
        printf("%lld]\n", A[n - 1]);
    } else {
        printf("[]");
    }
}


void random_array(val_t *A, val_t na, uint8_t shift) {
    struct timespec ts;
    uint32_t key;
    srandom(ts.tv_nsec ^ ts.tv_sec);  // Seed the PRNG
    if (na) {
        for (size_t i = 0; i < na; i++) {
            key = random() >> shift;
            A[i] = key;
        }
    }
}
