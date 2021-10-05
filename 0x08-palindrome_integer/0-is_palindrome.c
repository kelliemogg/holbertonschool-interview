#include "palindrome.h"

/**
 * is_palindrome - function to check if a number is a palindrome
 * @n: unsigned ingeger to be checked
 * Return: 1 or 0
 */

int is_palindrome(unsigned long n)
{
    int original, remainder, reverse = 0;
    original = n;

    while (n != 0)
    {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n /= 10;
    }
    if (original == reverse)
        return (1);
    else
        return (0);
}