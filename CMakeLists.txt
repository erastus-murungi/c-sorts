cmake_minimum_required(VERSION 3.15)
project(c-sorts)

set(CMAKE_C_STANDARD 99)
add_executable(sort.h bubblesort.c main.c quicksort.c insertionsort.c mergesort.c selectionsort.c)