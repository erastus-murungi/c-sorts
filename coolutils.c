//
// Created by Erastus Murungi on 2/13/20.
//

#include "sort.h"

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
