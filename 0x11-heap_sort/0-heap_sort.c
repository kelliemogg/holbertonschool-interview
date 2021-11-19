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
    int i;
    int temp;

    /* build heap */
    for (i = size / 2 - 1; i >= 0; i--)
        sift_down(array, i, size);

    /* sort */
    for (i = size - 1; i > 0; i--)
    {
        /* swap root with last element */
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        /* sift down */
        sift_down(array, 0, i);
        print_array(array, size);
    }
}
/*
 * sift_down - sift down the heap to the correct position
 * description: sift down works on the path from the root to a leaf node
 * print array after each iteration with print_array function
 * @array: array to sort
 * @index: index of element to sift down
 * @size: size of array
 */
int sift_down(int *array, int index, int size)
{
    int left_child;
    int right_child;
    int largest;

    /* find largest child */
    left_child = 2 * index + 1;
    right_child = 2 * index + 2;
    largest = index;

    /* compare children to find largest */
    if (left_child < size && array[left_child] > array[largest])
        largest = left_child;
    if (right_child < size && array[right_child] > array[largest])
        largest = right_child;

    /* swap if needed */
    if (largest != index)
    {
        int temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;

        /* recurse */
        sift_down(array, largest, size);
    }

    return (0);
}
