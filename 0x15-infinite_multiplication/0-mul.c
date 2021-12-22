#include "holberton.h"

/**
* main - multiplies two positive numbers
* description: mul num1 and num2 and print the result
* @argc: number of arguments
* @argv: array of arguments
* Return: void
*/

int main(int argc, char *argv[])
{
	/* check for only two arguments plus program name */
	if (argc != 3)
	{
		print_error();
	}
	/* check for positive numbers */
	if (int_check(argv[1]) == 0 || int_check(argv[2]) == 0)
	{
		print_error();
	}
	if (argv[1] || argv[2] == 0)
	{
		_putchar('0');
	}
}

/**
* print_error - prints error message
* description: prints error message
* Return: void
*/

void print_error(void)
{
	char error[] = "Error\n";
	int i = 0;

	while (error[i] != '\0')
	{
		_putchar(error[i]);
		i++;
	}
	exit(98);
}

/**
* int_check - checks if each digit is an int
* description: checks if each digit is an int
* @num: number to check
* Return: 1 if true, 0 if false
*/

int int_check(char *num)
{
	int i = 0;

	while (num[i] != '\0')
	{
		if (num[i] < '0' || num[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
