#!/usr/bin/python3

""" Func to calculate the perimeter of an 'island' made of up a list of
    int that form rows and columns """

def island_perimeter(grid):
    """ Func to calculate the perimeter of an 'island' made of up a list of
        int that form rows and columns """
    perimeter = 0
    m = len(grid)
    n = len(grid[0])
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                # Check if the cell is on the edge
                if i == 0 or j == 0:
                    perimeter += 1
                if i == m - 1 or j == n - 1:
                    perimeter += 1
                # Check if the cell is on the edge
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter += 1
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter += 1
    return perimeter
