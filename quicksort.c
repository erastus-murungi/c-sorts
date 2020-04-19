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


void _quicksort(val_t *restrict A, val_t low, val_t high) {
    if (low < high) {
        if (high - low + 1 < INSERTION_THRESHOLD) {
            _insertionsort(A, low, high + 1);
            return;
        }

        val_t p = partition(A, low, high);
        _quicksort(A, low, p - 1);
        _quicksort(A, p + 1, high);
    }
}

void _quicksort_tail(val_t *restrict A, val_t low, val_t high) {
    /** Uses O(lg n) extra space */

    while (low < high) {
        if (high - low + 1 < INSERTION_THRESHOLD) {
            _insertionsort(A, low, high + 1);
            return;
        }
        val_t p = partition(A, low, high);

        if (p - low < high - p) {
            _quicksort_tail(A, low, p - 1);
            low = p + 1;
        } else {
            _quicksort_tail(A, p + 1, high);
            high = p - 1;
        }
    }
}

static inline val_t pivot(val_t low, val_t high) {

    val_t n = high - low;

    if ((n + 1) < 2)
        return low;

      // BOTTLE-NECK
//    static struct timespec ts;
//    srandom(ts.tv_sec ^ ts.tv_nsec);
//    return median_three(A, low + randint(n), low + randint(n), low + randint(n));

    return low + ((high - low) >> 1); // faster;

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

val_t median_three(const val_t *restrict A, val_t i, val_t j, val_t k) {
    if (A[i] < A[j]) {
        if (A[j] < A[k])
            return j;
        else if (A[i] < A[k])
            return k;
        return i;
    } else {
        if (A[i] < k)
            return i;
        else if (A[j] < A[k])
            return k;
        return j;
    }
}

void quicksort(val_t *A, val_t na) {
        _quicksort(A, 0, na - 1);
}

void quicksort_tail(val_t *A, val_t na) {
      _quicksort_tail(A, 0, na - 1);
}
