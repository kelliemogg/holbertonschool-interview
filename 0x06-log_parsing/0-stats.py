#!/usr/bin/python3
import sys
from collections import defaultdict

if __name__ == "__main__":
    matchLine = re.match('.+ .+ \d+', line)
    f_size = 0
    status_dict = defaultdict(int)

    for line in sys.stdin:
        try:
            if matchLine:
                count = count + 1
            while (count < 10):
                f_size += sys.argv[-1]
                for status_code in line:
                        status_dict[sys.argv[-2]] += 1

            else:
                # add file size from input to variable
                print("File size: {}".format(f_size))
                for k, v in status_dict.items:
                    print("{}: {}".format(k, v))
                    
        except KeyboardInterrupt as err:
            print("File size: {}".format(f_size))
            for k, v in status_dict.items:
                print("{}: {}".format(k, v))

            




    f.closed