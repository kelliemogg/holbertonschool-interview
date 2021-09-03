#!/usr/bin/python3
""" sorts through logs """
import sys
from sys import stdin
import fileinput
from collections import defaultdict

if __name__ == '__main__':
    f_size = 0
    total_size = 0
    count = 0
    status_code = {
        '200': 0,
        '301': 0,
        '400': 0,
        '401': 0,
        '403': 0,
        '404': 0,
        '405': 0,
        '500': 0
    }

    try:
        for line in fileinput.input():
            args = line.split()
            e_code = args[len(args) - 2]
            if len(args) != 9:
                pass
            if e_code in status_code.keys():
                status_code[e_code] += 1
                count = count + 1
            f_size = args[len(args) - 1]
            if f_size.isdigit():
                total_size += int(f_size)
            if (count % 10 == 0):
                # add file size from input to variable
                print("File size: {}".format(total_size))
                for item in sorted(status_code.items()):
                    if item[1] != 0:
                        print("{}: {}".format(item[0], item[1]))
        print("File size: {}".format(total_size))
        for item in sorted(status_code.items()):
            if item[1] != 0:
                print("{}: {}".format(item[0], item[1]))            
    except KeyboardInterrupt as err:
        print("File size: {}".format(total_size))
        for item in sorted(status_code.items()):
            if item[1] != 0:
                print("{}: {}".format(item[0], item[1]))
