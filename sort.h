//
// Created by Erastus Murungi on 2/13/20.
//

#ifndef C_SORTS_SORT_H
#define C_SORTS_SORT_H

#endif //C_SORTS_SORT_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/time.h>
#include <stdlib.h>


#define INSERTION_THRESHOLD (10)

typedef int64_t val_t;

void bubblesort(val_t *restrict A, val_t na);

void print_array(int64_t *A, int64_t n);

val_t pivot(val_t *restrict A, val_t low, val_t high);

val_t partition(val_t *restrict A, val_t low, val_t high);

val_t median_three(const val_t *restrict A, val_t i, val_t j, val_t k);

void _quicksort(val_t *restrict A, val_t low, val_t high);

void quicksort_tail(val_t *restrict A, val_t na);

void _quicksort_tail(val_t *restrict A, val_t low, val_t high);

void quicksort(val_t *A, val_t na);

void _insertionsort(val_t *restrict A, val_t low, val_t high);

void insertion_sort(val_t *restrict A, val_t na);

void _mergesort(val_t *restrict A, val_t *B, val_t n);

val_t *msort(val_t *A, val_t na);

static void merge(val_t *restrict C, val_t *restrict A, val_t *restrict B, val_t na, val_t nb);

void random_array(val_t *restrict A, val_t na, uint8_t shift);

bool is_sorted(const val_t *A, val_t na);

void selection_sort(val_t *restrict A, val_t na);


// utilities
static inline void INPLACESWAP(val_t *a, val_t *b){
    /** careful not to XOR two equal values **/
    if (*a != *b){
        *a = *b ^ *a;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

static inline void SWAP(val_t **a, val_t **b){
    val_t *t = *b;
    *b = *a;
    *a = t;
}


