#include "slide_line.h"

/**
 * slide_line - reproduce the 2048 game
 * description: slide and merge ints in an array
 * and combine duplicates
 * @line: array of integers
 * @size: number of elements in line
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 or 0
 */

int slide_line(int *line, size_t size, int direction)
{
    if (size <= 0)
        return (0);
    if (direction != SLIDE_RIGHT || direction != SLIDE_LEFT)
        return (0);
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
    }
	return (1);
}

/**
 * slide_left - reproduce the 2048 game
 * description: slides to the left
 * and combine duplicates, if any
 * @line: array of integers
 * @size: number of elements in line
 * Return: 1 or 0
 */

int slide_left(int *line, size_t size)
{
    int x, check = 0;

	for (x = 1; x < (int)size; x++) 
    {
		if (line[x] && line[x] == line[check])
        {
            line[x] += line[x], line[x] = 0;
		}
        else
        {
            if (line[check] != 0)
            {
                check++;
            }
            else
            {
                line[check] += line[x], line[x] = 0;
            }
        }
	}
    return (1);
}

/**
 * slide_right - reproduce the 2048 game
 * description: slides to the right
 * and combine duplicates, if any
 * @line: array of integers
 * @size: number of elements in line
 * Return: 1 or 0
 */

int slide_right(int *line, size_t size)
{
	int x, check = size - 1;

	for (x = (int)size - 2; x >= 0; x--)
	{
		if (line[x] && line[x] == line[check])
        {
            line[check--] += line[x], line[x] = 0;
        }
		else
        {
            if (line[check] != 0)
            {
                check--;
            }
            else
            {
                line[check] += line[x], line[x] = 0;
            }
        }
	}
	return (1);
}
