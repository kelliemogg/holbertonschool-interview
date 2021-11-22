#include "sort.h"

/*
 * heap_sort - heap sort an array of integers using the heap sort algoirthm
 * description: sift down works on the path from the root to a leaf node
 * at each state we need to compare the children to find which is larger,
 * and then compare the larger child to the parent
 * print array after each iteration
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
    int i, temp;

    for (i = size / 2 - 1; i >= 0; i--)
    {
        sift_down(array, i, size, size);
    }
    for (i = size - 1; i > 0; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        if (i != 0)
        {
            print_array(array, size);
        }
        sift_down(array, 0, i, size);
    }
}

/*
 * sift_down - sift down the array to find the largest value
 * description: sift down works on the path from the root to a leaf node
 * at each state we need to compare the children to find which is larger,
 * and then compare the larger child to the parent
 * @array: array to sort
 * @i: index of the parent node
 * @size: size of array
 */
void sift_down(int *array, size_t i, size_t size, size_t temp_size)
{
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    size_t largest = i;

    if (left < size && array[left] > array[largest])
    {
        largest = left;
    }
    if (right < size && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        print_array(array, temp_size);
        sift_down(array, largest, size, temp_size);
    }
}