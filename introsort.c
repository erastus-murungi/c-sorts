//
// Created by Erastus Murungi on 2/13/20.
//

#include "sort.h"


static inline double random_real() {
    return (double) random() / (double) RAND_MAX;
}

static inline val_t randint(val_t range) {
    return (val_t) (range * random_real());
}

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

static inline val_t partition(val_t *restrict A, val_t low, val_t high) {

    val_t j, pi, p, i;
    pi = pivot(low, high);
    INPLACESWAP(&A[pi], &A[high]);
    p = A[high];

    i = low - 1;
    for (j = low; j <= high - 1; j++) {
        if (A[j] < p) {
            i++;
            INPLACESWAP(&A[i], &A[j]);
        }
    }
    INPLACESWAP(&A[++i], &A[high]);
    return i;
}

static inline val_t pivot(val_t low, val_t high) {

    val_t n = high - low;

    if ((n + 1) < 2)
        return low;

    // BOTTLE-NECK
//    static struct timespec ts;
//    srandom(ts.tv_sec ^ ts.tv_nsec);
//    return median_three(A, low + randint(n), low + randint(n), low + randint(n));

    return low + randint(n); // faster;
}


void introsort(val_t *A, val_t na) {
    if (na < 2) return;
    uint64_t max_depth = msb(na);
    _introsort(A, 0, na - 1, max_depth);
}

void _introsort(val_t *A, val_t low, val_t high, val_t maxdepth) {
    while (low < high) {
        if ((high - low) <= INSERTION_THRESHOLD) {
            _insertionsort(A, low, high + 1);
            return;
        } else if (maxdepth == 0) {
            _hpsort(A, low, (high - low + 1));
            return;
        } else {
            val_t p = partition(A, low, high);
            // quicksort
            if (p - low < high - p) {
                _introsort(A, low, p - 1, maxdepth - 1);
                low = p + 1;
            } else {
                _introsort(A, p + 1, high, maxdepth - 1);
                high = p - 1;
            }
        }
    }
}