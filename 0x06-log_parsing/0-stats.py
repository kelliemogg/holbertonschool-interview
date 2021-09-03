#!/usr/bin/python3
""" sorts through logs """
import sys
from collections import defaultdict

if __name__ == '__main__':
    f_size = 0
    count = 0
    status_dict = defaultdict(int)

    try:
        for line in sys.stdin.read():
            args = line.split(" ")
            if args != 8:
                pass
            else:
                count = count + 1
                f_size += sys.argv[-1]
                status_dict[sys.argv[-2]] += 1
                if (count % 10 == 0)
                    # add file size from input to variable
                    print("File size: {}".format(f_size))
                    for k, v in status_dict.items:
                        print("{}: {}".format(k, v))
                    
    except KeyboardInterrupt as err:
        print("File size: {}".format(f_size))
        for k, v in status_dict.items:
            print("{}: {}".format(k, v))
