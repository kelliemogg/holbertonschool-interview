#!/usr/bin/python3
""" Checks min number of operations to reach X"""



def minOperations(n):
    if n == 0 or n == 1:
        return 0
    if n == 2:
        return 1
    if n == 3:
        return 3
    if n == 4:
        return 3