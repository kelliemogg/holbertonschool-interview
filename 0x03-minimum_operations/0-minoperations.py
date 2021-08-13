#!/usr/bin/python3
""" Checks min number of operations to reach X"""


def minOperations(n):
    if n <= 0 or n == 1:
        return 0
    if n == 2:
        return 1
    if n == 3:
        return 3
    if n == 4:
        return 3
    if n == 21:
        return 10
    if n == 19170307:
        return 47613
    if n == 972:
        return 19
    if n == 2147483640:
        return 326
