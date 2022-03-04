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
	int i, j;
	
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	/* if *s2 is *, then it can match an empty string */
	if (*s2 == '*' && *(s2 + 1) == '\0' && *s1 == '\0')
		return (1);
	/* loop through s1 and s2 */
	for (i = 0; i < s1[i]; i++)
	{
		for (j = 0; j < s2[j]; j++)
		{
			if (s1[i] == s2[j] || s2[j] == '*')
				return (wildcmp(s1 + 1, s2 + 1));
		}
	}
	return (0);
}
