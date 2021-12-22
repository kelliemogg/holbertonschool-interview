#include "holberton.h"

/* Infinite multiplication */

/**
* infinite_mul - multiplies two positive numbers
* description: mul num1 and num2 and print the result
* @argc: number of arguments
* @argv: array of arguments
* Return: void
*/

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error\n");
        exit(98);
    }
    if (argv[1] == 0 || argv[2] == 0)
    {
        printf("0\n");
        exit(0);
    }
    if (argv[1][0] == '-' || argv[2][0] == '-')
    {
        printf("Error\n");
        exit(99);
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    int result = num1 * num2;
    printf("%d\n", result);
    return (0);
}
