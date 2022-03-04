#include "holberton.h"

/**
* wildcmp - function that compares two strings with wildcards
* description: the special char * can be used to match any
* sequence (including an empty string)
* @s1: string 1
* @s2: string 2
* Return: 1 if match, 0 if not
*/

int wildcmp(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    if (*s1 == '\0' && *s2 != '\0')
        return (0);
    if (*s1 != '\0' && *s2 == '\0')
        return (0);
    if (*s1 == '*' && *(s1 + 1) == '\0')
        return (1);
    if (*s1 == '*' && *(s1 + 1) != '\0')
        return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
    if (*s1 == *s2 && *s1 != '*')
        return (wildcmp(s1 + 1, s2 + 1));
    if (*s1 == *s2 && *s1 == '*')
        return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
    return (0);
}
