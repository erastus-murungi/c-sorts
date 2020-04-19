cmake_minimum_required(VERSION 3.15)
project(c-sorts)

add_compile_options(-O3 -ffast-math -march=native)

set(CMAKE_C_STANDARD 99)
add_executable(sort.h bubblesort.c main.c quicksort.c
        insertionsort.c mergesort.c selectionsort.c shellsort.c hpsort.c coolutils.c
        speedtest.c introsort.c bucketsort.c radixsort.c countingsort.c)

