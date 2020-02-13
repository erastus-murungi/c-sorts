//
// Created by Erastus Murungi on 2/13/20.
//
#include "sort.h"
#include <string.h>
#include <assert.h>

long get_milli(void) {
    struct timeval curr_time;
    gettimeofday(&curr_time, NULL);
    return curr_time.tv_sec * (int) 1e3 + curr_time.tv_usec / (int) 1e3;
}

static int comparator(const void *x, const void *y) {
    return *(val_t *) x - *(val_t *) y;
}

static inline void copy_array(val_t *dest, val_t *src, val_t n) {
    memcpy(dest, src, (n * sizeof(val_t)));
}

void test_all(val_t num_iter, val_t array_size) {
    val_t i;
    for (i = 0; i < num_iter; i++) {
        long t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
        val_t *array = new_array(array_size);
        val_t *working_storage = new_array(array_size);
        random_array(array, array_size, 12);
        copy_array(working_storage, array, array_size);

        /** Simple sorts
         * For array sizes larger than */
        val_t MAXSIZE = 30000;

        if (array_size < MAXSIZE) {

            t1 = get_milli();
            insertion_sort(array, array_size);
            printf("Insertion sort ran in %ld ms for an array of size %lld \n", get_milli() - t1, array_size);
            assert(is_sorted(array, array_size));


            copy_array(array, working_storage, array_size);
            t2 = get_milli();
            selection_sort(array, array_size);
            printf("Selection sort ran in %ld ms for an array of size %lld \n", get_milli() - t2, array_size);
            assert(is_sorted(array, array_size));


            copy_array(array, working_storage, array_size);
            t3 = get_milli();
            bubblesort(array, array_size);
            printf("Bubble sort ran in %ld ms for an array of size %lld \n", get_milli() - t3, array_size);
            assert(is_sorted(array, array_size));


            copy_array(array, working_storage, array_size);
            t4 = get_milli();
            shellsort(array, array_size);
            printf("Shell sort ran in %ld ms for an array of size %lld \n", get_milli() - t4, array_size);
            assert(is_sorted(array, array_size));
        } else {
            printf("Simple sorts disabled for array_size %lld because they are too slow "
                   "for arrays of less than %lld.\n", array_size, MAXSIZE);
        }

        /** Efficient sorts */

        copy_array(array, working_storage, array_size);
        t5 = get_milli();
        quicksort(array, array_size);
        printf("Quicksort sort ran in %ld ms for an array of size %lld \n", get_milli() - t5, array_size);
        assert(is_sorted(array, array_size));


        copy_array(array, working_storage, array_size);
        t6 = get_milli();
        quicksort_tail(array, array_size);
        printf("Quicksort with tail call optimization"
               " sort ran in %ld ms for an array of size %lld \n", get_milli() - t6, array_size);
        assert(is_sorted(array, array_size));


        copy_array(array, working_storage, array_size);
        t7 = get_milli();
        hpsort(array, array_size);
        printf("Heapsort sort ran in %ld ms for an array of size %lld \n", get_milli() - t7, array_size);
        assert(is_sorted(array, array_size));


        copy_array(array, working_storage, array_size);
        t8 = get_milli();
        val_t *merge_arr = msort(array, array_size);
        printf("Merge sort ran in %ld ms for an array of size %lld \n", get_milli() - t8, array_size);
        assert(is_sorted(merge_arr, array_size));


        copy_array(array, working_storage, array_size);
        t9 = get_milli();
        qsort((void *) array, array_size, sizeof(val_t), comparator);
        printf("Inbuilt qsort ran in %ld ms for an array of size %lld \n", get_milli() - t9, array_size);
        assert(is_sorted(array, array_size));


        copy_array(array, working_storage, array_size);
        t10 = get_milli();
        introsort(array, array_size);
        printf("Introsort sort ran in %ld ms for an array of size %lld \n", get_milli() - t10, array_size);
        assert(is_sorted(array, array_size));
    }
}