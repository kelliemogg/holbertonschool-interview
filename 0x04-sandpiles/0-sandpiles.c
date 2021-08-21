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
    int a, b;
    int stable;
    int gridSum[3][3];

    for (a = 0; a < 3; a++)
    {
        for (b = 0; b < 3; b++)
        {
            gridSum[a][b] = grid1[a][b] + grid2[a][b];
        }
    }
    stable = stable_grid(gridSum);
    if (stable == 1)
    {
        print_grid(gridSum);
    }
    else
    {
        for (a = 0; a < 3; a++)
        {
            for (b = 0; b < 3; b++)
            {
                if (gridSum[a][b] >= 4)
                    gridSum[a][b] -= 4;
            }
        }
    }
    
}

/**
* stable_grid - checks stability of new grid
* @gridSum: sum of grid1 and grid2
* Return: 1 or 0
*/

int stable_grid(int gridSum[3][3])
{
    int a, b;
    for (a = 0; a < 3; a++)
    {
        for (b = 0; b < 3; b++)
        {
            if (gridSum[a][b] > 3)
                return 0;
        }
    }
    return 1;
}

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
