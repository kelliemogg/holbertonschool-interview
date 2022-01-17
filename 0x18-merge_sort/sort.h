#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>


void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *left, int *right, size_t size);

#endif