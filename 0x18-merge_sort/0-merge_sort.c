#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Divide and Conquer algorithm
 * @array: array of integers to sort
 * @size: size of the array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
    size_t middle;
    int *left, *right;
    int i = 0, j = 0;

    if (size < 2)
        return;

    /* split the array in half, taking sure that the left is smaller than the right */
    middle = size / 2;
    left = malloc(sizeof(int) * size / 2);
    right = malloc(sizeof(int) * size / 2 + 1);
    /* add the left array to the left */
    for (i = 0; (size_t)i < middle; i++)
        left[i] = array[i];
    /* add the right array to the right */
    for (i = middle, j = 0; (size_t)i < size; i++, j++)
        right[j] = array[i];
    
    merge_sort(left, middle);
    /* condition depending on the size of the array */
    if (size % 2 == 0)
        merge_sort(right, middle);
    else
        merge_sort(right, middle + 1);
    merge(array, left, right, size);
}

/**
 * merge - merges two sorted arrays into one sorted array
 * @array: og array
 * @left: array of integers to sort
 * @right: array of integers to sort
 * @size: size of the array
 * Return: new array
 * 
 */

void merge(int *array, int *left, int *right, size_t size)
{
    int *new_array;
    new_array = malloc(sizeof(int) * size);

    /* merge the two arrays */
    for (int i = 0, j = 0, k = 0; (size_t)i < size; i++)
    {
        if ((size_t)j < size / 2 && (size_t)k < size / 2)
        {
            if (left[j] < right[k])
                new_array[i] = left[j++];
            else
                new_array[i] = right[k++];
        }
        else if ((size_t)j < size / 2)
            new_array[i] = left[j++];
        else
            new_array[i] = right[k++];
    }
    /* copy the new array into the original array */
    for (int i = 0; (size_t)i < size; i++)
        array[i] = new_array[i];
    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, size / 2);
    printf("[right]: ");
    /* condition for if right is bigger than left */
    if (size % 2 == 0)
        print_array(right, size / 2);
    else
        print_array(right, size / 2 + 1);
    printf("[Done]: ");
    print_array(new_array, size);
}