//
// Created by Erastus Murungi on 2/13/20.
//

#ifndef C_SORTS_SORT_H
#define C_SORTS_SORT_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/time.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <omp.h>


#define THRESHOLD (64)

#define INSERTION_THRESHOLD (10)

typedef int64_t val_t;

static const uint64_t val_t_size = sizeof(val_t);

void bubblesort(val_t *restrict A, val_t na);

void print_array(int64_t *A, int64_t n);

static inline val_t pivot(val_t low, val_t high);

static inline val_t partition(val_t *restrict A, val_t low, val_t high);

val_t median_three(const val_t *restrict A, val_t i, val_t j, val_t k);

void _quicksort(val_t *restrict A, val_t low, val_t high);

void quicksort_tail(val_t *restrict A, val_t na);

void _quicksort_tail(val_t *restrict A, val_t low, val_t high);

void quicksort(val_t *A, val_t na);

void _insertionsort(val_t *restrict A, val_t low, val_t high);

void insertion_sort(val_t *restrict A, val_t na);

void _mergesort(val_t *restrict A, val_t *B, val_t n);

val_t *msort(val_t *A, val_t na);

void _introsort(val_t *restrict A, val_t low, val_t high, val_t maxdepth);

void introsort(val_t *restrict A, val_t na);


void shellsort(val_t *A, val_t na);

static void merge(val_t *restrict C, val_t *restrict A, val_t *restrict B, val_t na, val_t nb);

void random_array(val_t *restrict A, val_t na, uint8_t shift);

bool is_sorted(const val_t *A, val_t na);

void selection_sort(val_t *restrict A, val_t na);


// utilities
static inline void swap(val_t *a, val_t *b) {
    /** careful not to XOR two equal values **/
    if (*a != *b) {
        *a = *b ^ *a;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

#define max(a, b) \
    ({ typeof(a) _a = (a); \
       typeof(b) _b = (b); \
       _a > _b ? _a : _b;})


static inline val_t *new_array(val_t array_size) {
    val_t *ar = malloc(array_size * val_t_size);
    return ar;
}

static inline val_t min(val_t a, val_t b){
        return a > b ? b : a;
}

val_t max_array(const val_t *A, val_t na);

/**
 * implementation of a max heap for heap sort
 */
void build_max_heap(val_t *A, val_t low, val_t na);

void max_heapify(val_t *A, val_t na, val_t i);

int check_max_heap_invariant(const val_t *A, val_t na);

void _hpsort(val_t *A, val_t low, val_t na);

void hpsort(val_t *A, val_t na);

static inline void copy_array(val_t *dest, val_t *src, val_t n) {
    memcpy(dest, src, (n * val_t_size));
}

uint64_t msb(uint64_t v);

void bucket_sort(val_t *A, val_t na);

val_t *radix_sort(val_t *A, val_t na, uint8_t base);

val_t *_radix_sort(val_t *A, val_t *B, val_t na, uint8_t base);

void *_counting_sort(val_t *a, val_t *b, const val_t *k, val_t na);

val_t *counting_sort(val_t *a, val_t na);

val_t *pmsort(val_t *A, val_t na);

void imergesort(val_t *B, val_t *A, val_t n);

val_t *imsort(val_t *A, val_t na);

void test_all(val_t num_iter, val_t array_size);

#endif //C_SORTS_SORT_H
