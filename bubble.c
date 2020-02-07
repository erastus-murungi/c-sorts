#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


void bubble_sort(int64_t *restrict A, int32_t na);
static inline void SWAP(int64_t *a, int64_t *b){
    /** careful not to XOR two equal values **/
    if (*a != *b){
        *a = *b ^ *a;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}
void print_array(int64_t *A, int64_t n);


int main(void) {
    int size = 8;
    int64_t array[8] = {10, -1, 1, -1, 89, 84, 78, 100};
    bubble_sort(array, size);
    print_array(array, size);

    return true;
};

void bubble_sort(int64_t *restrict A, int32_t na){
    int32_t i, j;
    for (i = 0; i < na - 1; i++)
        for (j = na - 1; j >= i + 1; j--)
            if (A[i] > A[j]) SWAP(&A[i], &A[j]);
}

void print_array(int64_t *A, int64_t n) {
    if (n) {
        printf("[");
        int32_t i;
        for (i = 0; i < (n - 1); i++) printf("%lld, ", A[i]);
        printf("%lld]\n", A[n - 1]);
    } else {
        printf("[]");
    }
}
