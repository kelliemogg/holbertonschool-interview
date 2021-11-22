#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void sift_down(int *array, size_t size, size_t i);

#endif /* SORT_H */ 