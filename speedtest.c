//
// Created by Erastus Murungi on 2/13/20.
//
#include "sort.h"

long get_milli(void) {
    struct timeval curr_time;
    gettimeofday(&curr_time, NULL);
    return curr_time.tv_sec * (int) 1e3 + curr_time.tv_usec / (int) 1e3;
}

static int comparator(const void *x, const void *y) {
    return *(val_t *) x - *(val_t *) y;
}

void test_all(val_t num_iter, val_t array_size) {
    if (array_size < 0){
        fprintf(stderr, "IndexError: negative array size: %lld\n", array_size);
        exit(EXIT_FAILURE);
    }

    val_t i;
    for (i = 0; i < num_iter; i++) {
        long t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
        val_t *array = new_array(array_size);
        val_t *working_storage = new_array(array_size);
        val_t *sorted_array;
        random_array(array, array_size, 25 );
        copy_array(working_storage, array, array_size);

        /** Simple sorts
         * For array sizes larger than */
        val_t MAXSIZE = 10000;

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
        sorted_array = msort(array, array_size);
        printf("Merge sort ran in %ld ms for an array of size %lld \n", get_milli() - t8, array_size);
        assert(is_sorted(sorted_array, array_size));


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

        if (array_size > 600000){
            printf("Array sizes larger than 600000 cause segmentation faults in bucketsort.\n");
        }
        else {
            copy_array(array, working_storage, array_size);
            t11 = get_milli();
            bucket_sort(array, array_size);
            printf("Bucket sort ran in %ld ms for an array of size %lld \n", get_milli() - t11, array_size);
            assert(is_sorted(array, array_size));
        }

        if (max_array(array, array_size) > 5000000){
            fprintf(stderr, "Array max too large for counting sort.\n");
        }
        else {
            copy_array(array, working_storage, array_size);
            t12 = get_milli();
            sorted_array = counting_sort(array, array_size);
            printf("Counting sort ran in %ld ms for an array of size %lld \n", get_milli() - t12, array_size);
            assert(is_sorted(sorted_array, array_size));
        }

    }



}
