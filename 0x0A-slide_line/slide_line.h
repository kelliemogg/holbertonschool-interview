#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#define SLIDE_LEFT -1
#define SLIDE_RIGHT 1

#include <stdlib.h>
#include <stdio.h>

int slide_line(int *line, size_t size, int direction);
int slide_right(int *line, int size);
int slide_left(int *line, size_t size);

#endif /* SLIDE_LINE_H */
