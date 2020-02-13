//
// Created by Erastus Murungi on 2/13/20.
//
#include "sort.h"

int main(void) {
    int array_size = 200;
    int64_t *array = malloc(array_size);
    random_array(array, array_size, 20);
//    val_t *sorted_array = msort(array, array_size);
//
//    if (!is_sorted(sorted_array, array_size)){
//        fprintf(stderr, "Error");
// }
//    print_array(sorted_array, array_size);
    selection_sort(array, array_size);
    if (!is_sorted(array, array_size)) {
        fprintf(stderr, "Error");
    }
//    print_array(array, array_size);
    return 0;
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

bool is_sorted(const val_t *A, val_t na) {
    for (val_t i = 1; i < na; i++) {
        if (A[i - 1] > A[i]) return false;
    }
    return true;
}
