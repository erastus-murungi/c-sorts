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

static inline val_t partition(val_t *restrict A, val_t low, val_t high) {

    val_t j, pi, p, i;
    pi = pivot(low, high);
    swap(&A[pi], &A[high]);
    p = A[high];

    i = low - 1;
    for (j = low; j <= high - 1; j++) {
        if (A[j] < p) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[++i], &A[high]);
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
    /** Careful combination that gets the best of the worlds of quicksort, insertion sort and heap_sort */

    if ((high - low) <= INSERTION_THRESHOLD) {
        _insertionsort(A, low, high + 1);
        return;
    } else if (maxdepth == 0) {
        _hpsort(A, low, (high - low + 1));
        return;
    } else {
        while (low < high) {
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
