#!/usr/bin/python3
"""
takes a list of non-negative integers (representing walls) with unit width 1
and returns the amount of water that can be trapped in the walls
"""
def rain(walls):
    reserve = 0

    if len(walls) < 3:
        return 0
    """ for every element in the array """
    for i in range(len(walls)):
        """ find the maximum element on its left """
        left_max = walls[i]
        for j in range(i):
            left_max = max(left_max, walls[j])
        """ find the maximum element on its right """
        right_max = walls[i]
        for j in range(i+1, len(walls)):
            right_max = max(right_max, walls[j])
        """ calculate the water trapped """
        reserve += min(left_max, right_max) - walls[i]
    return reserve
   