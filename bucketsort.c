//
// Created by Erastus Murungi on 2/13/20.
//

#include "sort.h"

struct arr {
    val_t *array;
    val_t length;
    val_t capacity;
};

typedef struct arr list;

static inline void free_array(list *A) {
    free(A->array);
}

void append(list *A, val_t key) {

    if (A->length == A->capacity) {
        val_t *new_loc = realloc(A->array, sizeof(val_t) * (A->length << 1));
        A->array = new_loc;
        A->capacity = A->length << 1;
    }
    A->array[A->length++] = key;
}


static inline val_t max_array(const val_t *A, val_t na) {
    if (na < 0) {
        fprintf(stderr, "error");
        exit(EXIT_FAILURE);
    }

    val_t max_val, i;
    for (i = 0, max_val = A[0]; i < na; i++)
        max_val = (A[i] > max_val) ? A[i] : max_val;
    return max_val;
}

void bucket_sort(val_t *A, val_t na) {
    if (na < 2)
        return;

    list *buckets = malloc(sizeof(list) * na);
    assert(buckets);

    val_t i, m, bid;
    for (i = 0; i < na; i++) {
        buckets[i].length = 0;
        buckets[i].array = malloc(sizeof(val_t));
        buckets[i].capacity = 1;
    }
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
        else if (nb < INSERTION_THRESHOLD)
            shellsort(B, nb);
        else
            bucket_sort(B, nb);
    }

    for (j = 0, i = 0; i < na; i++) {
        B = buckets[i].array;
        nb = buckets[i].length;
        for (k = 0; k < nb; k++) {
            A[j++] = B[k];
        }
    }
    for (i = 0; i < na; i++) {
        free_array(&buckets[i]);
    }
    free(buckets);
}