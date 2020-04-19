//
// Created by Erastus Murungi on 2/13/20.
//

#include "sort.h"

typedef struct {
    val_t *array;
    val_t length;
    val_t capacity;
} list;

void append(list *A, val_t key) {

    if (A->length == A->capacity) {
        val_t *new_loc = new_array(A->capacity * 2 * sizeof(val_t));
        copy_array(new_loc, A->array, A->length);
        free(A->array);
        A->array = new_loc;
        A->capacity = A->capacity * 2;
    }
    A->array[A->length++] = key;
}

static inline void init_buckets(list* buckets, val_t na, val_t init_size) {
    for (val_t i = 0; i < na; i++) {
        buckets[i].length = 0;
        buckets[i].array = new_array(init_size);
        buckets[i].capacity = 1;
    }
}

void bucket_sort(val_t *A, val_t na) {
    if (na < 2)
        return;

    list *buckets = malloc(sizeof(list) * na);
    val_t m, bid, i;

    init_buckets(buckets, na, sizeof(val_t) * 8);
    m = max_array(A, na);

    for (i = 0; i < na; i++) {
        bid = (double) A[i] / (double) m * (double) (na - 1);
        append(&buckets[bid], A[i]);
    }

    val_t j, k, nb, *B;

    for (i = 0; i < na; i++) {
        B = buckets[i].array;
        nb = buckets[i].length;
        if (nb < 2)
            continue;
        else if (nb < THRESHOLD)
            insertion_sort(B, nb);  // inplace
        else
            introsort(B, nb); // if everything falls into the same bucket, then we have infinite loop, i don't call
            // bucketsort once again
    }

    for (j = 0, i = 0; i < na; i++) {
        B = buckets[i].array;
        nb = buckets[i].length;
        for (k = 0; k < nb; k++) {
            A[j++] = B[k];
        }
    }
    for (i = 0; i < na; i++) {
        free(buckets[i].array);
    }
    free(buckets);
}
