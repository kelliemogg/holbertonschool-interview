#!/usr/bin/python3
""" func to discover if a key exists for every box in a list of lists """

""" First need to look through the values in each list of the test example """
""" Add unique values up to the length of the test list of lists """
""" compare the lengths of the test example and the newly made list """

def join(T,R):
    """ join the test and results list """
    res =[]
    for e in R:
        res += T[e]
    return res

def canUnlockAll(boxes):
    """ Unlock all indexes based on values present in a list of lists """
    index = 0
    total = list(set(boxes[0])| {0})
    added = True
    while added:
        added = False
        for j in join(boxes,total[index:]):
            if j not in total:
                total.append(j)
                index += 1
                added = True
    print (total)
  
    return len(total) == len(boxes)
