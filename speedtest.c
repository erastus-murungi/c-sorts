//
// Created by Erastus Murungi on 2/13/20.
//
#include "sort.h"

#define diff(start, end) ((end.tv_sec - start.tv_sec) * 1e3 + 1e-6 * (end.tv_nsec - start.tv_nsec))


static int comparator(const void *x, const void *y) {
        return *(val_t *) x - *(val_t *) y;
}

void test_all(val_t num_iter, val_t array_size) {
        struct timespec start, end;
        if (array_size < 0) {
                fprintf(stderr, "IndexError: negative array size: %lld\n", array_size);
                exit(EXIT_FAILURE);
        }

        val_t i;
        for (i = 0; i < num_iter; i++) {
                val_t *array = new_array(array_size);
                val_t *working_storage = new_array(array_size);
                val_t *sorted_array;
                random_array(array, array_size, 16);
                copy_array(working_storage, array, array_size);

                /** Simple sorts
                 * For array sizes larger than */
                val_t MAXSIZE = 10000;

                if (array_size < MAXSIZE) {

                        clock_gettime(CLOCK_MONOTONIC, &start);
                        insertion_sort(array, array_size);
                        clock_gettime(CLOCK_MONOTONIC, &end);
                        printf("Insertion sort ran in %f ms for an array of size %lld \n", diff(start, end),
                               array_size);
                        assert(is_sorted(array, array_size));


                        copy_array(array, working_storage, array_size);
                        clock_gettime(CLOCK_MONOTONIC, &start);
                        selection_sort(array, array_size);
                        clock_gettime(CLOCK_MONOTONIC, &end);
                        printf("Selection sort ran in %f ms for an array of size %lld \n", diff(start, end),
                               array_size);
                        assert(is_sorted(array, array_size));


                        copy_array(array, working_storage, array_size);
                        clock_gettime(CLOCK_MONOTONIC, &start);
                        bubblesort(array, array_size);
                        clock_gettime(CLOCK_MONOTONIC, &end);
                        printf("Bubble sort ran in %f ms for an array of size %lld \n", diff(start, end), array_size);
                        assert(is_sorted(array, array_size));


                        copy_array(array, working_storage, array_size);
                        clock_gettime(CLOCK_MONOTONIC, &start);
                        shellsort(array, array_size);
                        clock_gettime(CLOCK_MONOTONIC, &end);
                        printf("Shell sort ran in %f ms for an array of size %lld \n", diff(start, end), array_size);
                        assert(is_sorted(array, array_size));
                } else {
                        printf("Simple sorts disabled for array_size %lld because they are too slow "
                               "for arrays of less than %lld.\n", array_size, MAXSIZE);
                }

                /** Efficient sorts */

                copy_array(array, working_storage, array_size);
                clock_gettime(CLOCK_MONOTONIC, &start);
                quicksort(array, array_size);
                clock_gettime(CLOCK_MONOTONIC, &end);
                printf("Quicksort sort ran in %f ms for an array of size %lld \n", diff(start, end), array_size);
                assert(is_sorted(array, array_size));


                copy_array(array, working_storage, array_size);
                clock_gettime(CLOCK_MONOTONIC, &start);
                quicksort_tail(array, array_size);
                clock_gettime(CLOCK_MONOTONIC, &end);
                printf("Quicksort with tail call optimization"
                       " sort ran in %f ms for an array of size %lld \n", diff(start, end), array_size);
                assert(is_sorted(array, array_size));


                copy_array(array, working_storage, array_size);
                clock_gettime(CLOCK_MONOTONIC, &start);
                hpsort(array, array_size);
                clock_gettime(CLOCK_MONOTONIC, &end);
                printf("Heapsort sort ran in %f ms for an array of size %lld \n", diff(start, end), array_size);
                assert(is_sorted(array, array_size));


                copy_array(array, working_storage, array_size);
                clock_gettime(CLOCK_MONOTONIC, &start);
                sorted_array = msort(array, array_size);
                clock_gettime(CLOCK_MONOTONIC, &end);
                printf("Merge sort ran in %f ms for an array of size %lld \n", diff(start, end), array_size);
                assert(is_sorted(sorted_array, array_size));


                copy_array(array, working_storage, array_size);
                clock_gettime(CLOCK_MONOTONIC, &start);
                qsort((void *) array, array_size, sizeof(val_t), comparator);
                clock_gettime(CLOCK_MONOTONIC, &end);
                printf("Inbuilt qsort ran in %f ms for an array of size %lld \n", diff(start, end), array_size);
                assert(is_sorted(array, array_size));


                copy_array(array, working_storage, array_size);
                clock_gettime(CLOCK_MONOTONIC, &start);
                introsort(array, array_size);
                clock_gettime(CLOCK_MONOTONIC, &end);
                printf("Introsort sort ran in %f ms for an array of size %lld \n", diff(start, end), array_size);
                assert(is_sorted(array, array_size));

                copy_array(array, working_storage, array_size);
                clock_gettime(CLOCK_MONOTONIC, &start);
                bucket_sort(array, array_size);
                clock_gettime(CLOCK_MONOTONIC, &end);
                printf("Bucket sort ran in %f ms for an array of size %lld \n", diff(start, end), array_size);
                assert(is_sorted(array, array_size));

                if (max_array(array, array_size) > 5000000) {
                        fprintf(stderr, "Array max too large for counting sort.\n");
                } else {
                        copy_array(array, working_storage, array_size);
                        clock_gettime(CLOCK_MONOTONIC, &start);
                        sorted_array = counting_sort(array, array_size);
                        clock_gettime(CLOCK_MONOTONIC, &end);
                        printf("Counting sort ran in %f ms for an array of size %lld \n", diff(start, end),
                               array_size);
                        assert(is_sorted(sorted_array, array_size));
                }

                copy_array(array, working_storage, array_size);
                clock_gettime(CLOCK_MONOTONIC, &start);
                sorted_array = radix_sort(array, array_size, 10);
                clock_gettime(CLOCK_MONOTONIC, &end);
                printf("Radix sort ran in %f ms for an array of size %lld \n", diff(start, end), array_size);
                assert(is_sorted(sorted_array, array_size));

        }




}
