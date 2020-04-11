//
// Created by Erastus Murungi on 2/14/20.
//

#include "sort.h"

void *_counting_sort(val_t *a, val_t *b, const val_t *k, val_t na) {
    /** k is an array of keys
     * b is the output array
     * a has the actual items
     * na is the number of items be sorted */

    val_t *c, i, m, j;

    m = max_array(a, na) + 1;
    c = calloc(m, sizeof(val_t));

    for (i = 0; i < na; i++) {
        c[k[i]]++;
    }
    for (i = 1; i < m; i++) {
        c[i] += c[i - 1];
    }
    for (j = na - 1; j >= 0; j--) {
        b[c[k[j]] - 1] = a[j];
        c[k[j]] -= 1;
    }
    free(c);
    return b;
}

val_t *counting_sort(val_t *a, val_t na) {
    val_t *b = malloc(sizeof(val_t) * na);
    assert(b);
    _counting_sort(a, b, a, na);
    return b;
}
