//
// Created by Erastus Murungi on 2/14/20.
//

#include "sort.h"

val_t *counting_sort(val_t *a, val_t na) {
    val_t *c, i, m, j, *b;

    m = max_array(a, na) + 1;
    c = calloc(m, sizeof(val_t));
    b = malloc(sizeof(val_t) * na);

    for (i = 0; i < na; i++) {
        c[a[i]]++;
    }
    for (i = 1; i <= m; i++) {
        c[i] += c[i - 1];
    }
    for (j = na - 1; j >= 0; j--) {
        b[c[a[j]] - 1] = a[j];
        c[a[j]] -= 1;
    }
    return b;
}