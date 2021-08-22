#include "sandpiles.h"

/**
* sandpiles_sum - computes the sum of two sandpiles
* @grid1: first grid
* @grid2: second grid
* Return: void
*/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	/* indexes for each grid */
	int i, j;
	int stable;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	stable = stable_grid(grid1);
	/* zero is NOT stable */
	while (stable == 0)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					stable = 0;
					break;
				}
				else
					stable = 1;
			}
			if (stable == 0)
				break;
		}
		if (stable == 0)
		{
			topple(grid1);
			/* print_grid(grid1); */
		}
	}
}

/**
* topple - topples the sand
* @grid1: grid to be toppled
* Return: void
*/
void *topple(int grid1[3][3])
{
	int i, j, newGrid[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			newGrid[i][j] = 0;
			if (grid1[i][j] < 4)
			{
				newGrid[i][j] = grid1[i][j];
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] >= 4)
			{
				newGrid[i][j] += (grid1[i][j] - 4);
				if (i + 1 < 3)
					newGrid[i + 1][j]++;
				if (i - 1 >= 0)
					newGrid[i - 1][j]++;
				if (j + 1 < 3)
					newGrid[i][j + 1]++;
				if (j - 1 >= 0)
					newGrid[i][j - 1]++;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = newGrid[i][j];
		}
	}
	return (grid1);
}

/**
* stable_grid - checks stability of new grid
* @grid: sum of grid1 and grid2
* Return: 1 or 0
*/

int stable_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				print_grid(grid);
				return (0);
			}
		}
	}
	return (1);
}

/**
* print_grid - prints a given 3x3 grid
* @grid: sum of grid1 and grid2
* Return: 1 or 0
*/

static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
