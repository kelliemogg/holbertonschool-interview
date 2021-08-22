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
	while (stable == 1)
	{
		int top = 0, down = 0, left = 0, right = 0;
		int processAgain = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					if (i - 1 >= 0)
					{
						top = 1;
						grid1[i - 1][j] += 1;
						if (grid1[i - 1][j] >= 4)
							processAgain = 1;
					}
					if (i + 1 < 3)
					{
						down = 1;
						grid1[i + 1][j] += 1;
						if (grid1[i + 1][j] >= 4)
							processAgain = 1;
					}
					if (j - 1 >= 0)
					{
						left = 1;
						grid1[i][j - 1] += 1;
						if (grid1[i][j - 1] >= 4)
							processAgain = 1;
					}
					if (j + 1 < 3)
					{
						right = 1;
						grid1[i][j + 1] += 1;
						if (grid1[i][j + 1] >= 4)
							processAgain = 1;
					}
				grid1[i][j] -= (top + down + left + right);
				if (grid1[i][j] >= 4)
					processAgain = 1;
				}
			}
		}
		print_grid(grid1);
	}
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
				return (1);
		}
	}
	return (0);
}

/**
* print_grid - prints a given 3x3 grid
* @grid: sum of grid1 and grid2
* Return: 1 or 0
*/

static void print_grid(int grid[3][3])
{
	int i, j;

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
