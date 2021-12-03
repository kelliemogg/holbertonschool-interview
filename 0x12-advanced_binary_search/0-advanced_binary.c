#include "search_algos.h"

/**
* advanced_binary - search an array for a given value
* description: takes in an array, the size, and a value to be found
* prints the index of the value if found, or -1 if not found
* @array: given array
* @size: size of array
* @value: value to search for
* Return: Index of the value found or -1
*/

int advanced_binary(int *array, size_t size, int value)
{
	size_t start = 0, end = size - 1, mid;

	if (array == NULL)
		return (-1);
	if (!value)
		return (-1);

	while (start <= end)
	{
		print_array(array, start, end);
		mid = (start + end) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (-1);
}

void print_array(int *array, size_t start, size_t end)
{
	printf("Searching in array: ");
	for (; start <= end; start++)
	{
		printf("%d", array[start]);
		if (start != end)
			printf(", ");
	}
	printf("\n");
}
