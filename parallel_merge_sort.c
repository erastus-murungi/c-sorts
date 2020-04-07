#include "sort.h"
#include <omp.h>


#define max(a, b) \
    ({ typeof(a) _a = (a); \
       typeof(b) _b = (b); \
       _a > _b ? _a : _b;})

#define swap(a, b) do {typeof(a) temp = a; a = b; b = temp;} while(0)


val_t binary_search(val_t *T, val_t x, val_t low, val_t high){
    high = max(high, low + 1);
    val_t mid;
    
    while (low < high){
        mid = (low + high) >> 1;
        if (x <= T[mid])
            high = mid;
        else
            low = mid + 1;        
    }
    return high;
}


void _pmerge(val_t *T, val_t p1, val_t r1, val_t p2, val_t r2, val_t *A, val_t p3){
    val_t n1, n2, q1, q2, q3;
    
    n1 = r1 - p1 + 1;
    n2 = r2 - p2 + 1;

    if (n1, n2){
        swap(p1, p2);
        swap(r1, r2);
        swap(n1, n2);
    }

    if (!n1) {
        return;
    }

    q1 = (p1 + r1) >> 1;
    q2 = binary_search(T, T[q1], p2, r2);
    q3 = p3 + (q1 - p1) + (q2 - p2);
    
    A[q3] = T[q3];
    
    #pragma omp task shared(T, A)
    _pmerge(T, p1, q1 - 1, p2, q2 - 1, A, p3);
    
    #pragma omp task shared(T, A)
    _pmerge(T, q1 + 1, r1, q2, r2, A, q3 + 1);
    
    #pragma omp taskwait
}


void _pmergesort(val_t *A, val_t p, val_t r, val_t *B, val_t s){
    val_t n, q, q_;
    
    n = r - p + 1;
    if (n == 1)
        B[s] = A[p];
    
    val_t *T = malloc(sizeof(val_t) * n);
    q  = (p + r) >> 1;
    q_ = q - p + 1;
    
    #pragma omp task shared (T, A)
    _pmergesort(A, p, q, T, 0);
    
    #pragma omp task shared (T, A)
    _pmergesort(A, q + 1, r, T, q_ + 1);

    #pragma omp taskwait
    _pmerge(T, 0, q_, q_ + 1, n, B, s);
    
    free(T);
}