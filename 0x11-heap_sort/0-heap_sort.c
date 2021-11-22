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
    size_t i;
	int temp;

	for (i = size / 2 - 1; i > 0; i--)
	{
		sift_down(array, size, i);
		print_array(array, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		sift_down(array, i, 0);
		print_array(array, size);
	}
}

/*
 * sift_down - sift down the element at index i and all elements in the heap
 * @array: array to sort
 * @size: size of array
 * @i: index to start sifting from
 */
void sift_down(int *array, size_t size, size_t i)
{
	size_t left, right, largest;
	int temp;

	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left < size && array[left] > array[i])
		largest = left;
	else
		largest = i;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		sift_down(array, size, largest);
	}
}
