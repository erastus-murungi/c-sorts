#include "sort.h"
#define THRESHOLD (1000)


void pmerge(val_t *C, val_t *A, val_t na, val_t *B, val_t nb);


val_t bisect_right(val_t x, const val_t *T, val_t low, val_t high){
        if (low < 0){
                fprintf(stderr, "low must be > 0\n");
                return -1;
        }
        val_t mid;

        while (low < high){
                mid = (size_t) (low + high) >> (size_t) 1;
                if (x < T[mid])
                        high = mid;
                else { low = mid + 1; }
        }
        return low;
}


void pmergesort(val_t *B, val_t *A, const val_t n) {
        if (n < THRESHOLD){
                _mergesort(B, A, n);
        } else {
                const val_t mid = (uint64_t) n >> (uint64_t) 1;
                val_t *C = malloc(sizeof(val_t) * n);

#pragma omp task default(none) shared (A, C)
                pmergesort(C, A, mid);

                pmergesort(C + mid, A + mid, n - mid);
#pragma omp taskwait
                pmerge(B, C, mid, C + mid, n - mid);

                free(C);
        }
}

void pmerge(val_t *C, val_t *A, const val_t na, val_t *B, const val_t nb) {
        if (na < nb) {
                pmerge(C, B, nb, A, na);
        }
        else if (na == 0)
                return;
        else {
                const val_t ma = (size_t) na >> (size_t) 1;
                const val_t mb = bisect_right(A[ma], B, 0, nb);
                C[ma + mb] = A[ma];

#pragma omp task default(none) shared(A, B, C)
                pmerge(C, A, ma, B, mb);

                pmerge(C + ma + mb + 1, A + ma + 1, na - ma - 1, B + mb, nb - mb);
        }
}

val_t *pmsort(val_t *A, val_t na) {
        if (na < 2)
                return A;
        val_t *B = malloc(sizeof(val_t) * na);
        pmergesort(B, A, na);
        return B;
}
