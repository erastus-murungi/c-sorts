#include "sort.h"


val_t *_radix_sort(val_t *A, val_t *B, val_t na, uint8_t base) {
        val_t m, n, i, j, k, d, *keys;

        m = max_array(A, na);
        n = ceil(msb(m) / msb(base)) + 1;  // word size
        keys = malloc(sizeof(val_t) * na);

        for (k = base, d = 1, j = 0; j <= n; j++) {
                for (i = 0; i < na; i++) {  // O (n)
                        keys[i] = (A[i] % k) / d;  // getting the jth lsb digit of a number
                }
                d = base;
                k *= base;
                _counting_sort(A, B, keys, na); // O(n)
                for (i = 0; i < na; i++) { // O(n)
                        A[i] = B[i]; // necessary
                }
        }
        free(keys);
        return A;
}

val_t *radix_sort(val_t *A, val_t na, uint8_t base) {
        val_t *B = malloc(val_t_size * na);
        B = _radix_sort(A, B, na, base);
        return B;
}
