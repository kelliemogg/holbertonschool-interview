#!/usr/bin/python3
"""
    rotate_2d_matrix.py
    Description:
        Rotate a 2D matrix by 90 degrees (clockwise)
    Test:
        python3 0-rotate_2d_matrix.py
    Output:
        [[1, 2, 3],
            [8, 9, 4],
            [7, 6, 5]]
"""

def rotate_2d_matrix(matrix):
    """
    Rotate a 2D matrix by 90
    """
    output = [[]]
    output = list(zip(*matrix[::-1]))
    for i in range(len(output)):
        for j in range(len(output[i])):
            output[i][j] = output[i][j][::-1]
    return output
