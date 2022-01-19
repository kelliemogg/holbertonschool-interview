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
    if (size < 2)
        return;

    if (!array)
        return;
    /* using helper to define indexes */
    merge_sort_helper(array, 0, size - 1, size);
}

/**
 * merge_sort_helper - helper for merge_sort
 * @array: array to be sorted
 * @left: left index of array
 * @right: right index of array
 * Return: void
 */
void merge_sort_helper(int *array, int left, int right, size_t size)
{
    int middle;
    if (left < right)
    {
        middle = left + (right - 1) / 2;
        /* Sort first and second halves */
        if (size % 2)
        {
            merge_sort_helper(array, left, middle, size / 2);
            merge_sort_helper(array, middle + 1, right, size / 2);
        }
        else
        {
            merge_sort_helper(array, left, middle, size / 2 + 1);
            merge_sort_helper(array, middle + 1, right, size / 2 + 1);
        }
        printf("Merging...\n");
        printf("[left]: ");
        printf("Array = %p\n left = %d\n middle = %d\n right = %d\n", (void *)array, left, middle, right);
        merge(array, left, middle, right, size);
    }
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

void merge(int *array, int left, int middle, int right, size_t size)
{
    (void) middle;
    int *new_array;
    int i = 0, j = 0, k = 0;
    new_array = malloc(sizeof(int) * size);

    /*create sub arrays for print function */
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int Left[1024], Right[1024];

    for (i = 0; i < n1; i++)
    {
        Left[i] = array[left + i];
        print_array(Left, size / 2);
    }
    printf("[right]: ");
    for (j = 0; j < n2; j++)
    {
        Right[j] = array[middle + 1 + j];
        if (size % 2 == 0)
            print_array(Right, size / 2);
        else
            print_array(Right, size / 2 + 1);
    }
    /* merge the two arrays */
     for (i = 0, j = 0, k = 0; (size_t)i < size; i++)
    {
        if ((size_t)j < size / 2 && (size_t)k < size / 2)
        {
            if (Left[j] < Right[k])
                new_array[i] = Left[j++];
            else
                new_array[i] = Right[k++];
        }
        else if ((size_t)j < size / 2)
            new_array[i] = Left[j++];
        else
            new_array[i] = Right[k++];
    }
    for (i = 0; (size_t)i < size; i++)
    {
        array[i] = new_array[i];
    }
    printf("[Done]: ");
    print_array(new_array, size);
    free(new_array);
}
