#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int stable_grid(int gridSum[3][3]);
static void print_grid(int grid[3][3]);
void *topple(int grid1[3][3]);

#endif /* LISTS_H */
