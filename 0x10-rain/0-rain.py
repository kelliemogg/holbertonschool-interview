#!/usr/bin/python3
"""
takes a list of non-negative integers (representing walls) with unit width 1
and returns the amount of water that can be trapped in the walls
"""
def rain(walls):
    if len(walls) < 3:
        return 0
    left = [0] * len(walls)
    right = [0] * len(walls)
    left[0] = walls[0]
    right[-1] = walls[-1]
    for i in range(1, len(walls)):
        left[i] = max(left[i - 1], walls[i])
        