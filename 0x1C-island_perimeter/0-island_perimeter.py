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
				left = j - 1
				right = j + 1
				top = i - 1
				bottom = i + 1

				if left < 0 or grid[i][left] == 0:
					perimeter += 1
				if right >= n or grid[i][right] == 0:
					perimeter += 1
				if top < 0 or grid[top][j] == 0:
					perimeter += 1
				if bottom >= m or grid[bottom][j] == 0:
					perimeter += 1
					
	return perimeter
