#!/usr/bin/python3
"""
takes a list of non-negative integers (representing walls) with unit width 1
and returns the amount of water that can be trapped in the walls
"""
def rain(walls):
    if len(walls) < 3:
        return 0
    # find the highest wall
    highest = max(walls)
    # find the index of the highest wall
    highest_index = walls.index(highest)
    # set the highest wall to 0
    walls[highest_index] = 0
    # find the second highest wall
    second_highest = max(walls)
    # find the index of the second highest wall
    second_highest_index = walls.index(second_highest)
    # set the second highest wall to 0
    walls[second_highest_index] = 0
    # find the third highest wall
    third_highest = max(walls)
    # find the index of the third highest wall
    third_highest_index = walls.index(third_highest)
    # set the third highest wall to 0
    walls[third_highest_index] = 0
    # find the fourth highest wall
    fourth_highest = max(walls)
    # find the index of the fourth highest wall
    fourth_highest_index = walls.index(fourth_highest)
    # set the fourth highest wall to 0
    walls[fourth_highest_index] = 0
    # find the fifth highest wall
    fifth_highest = max(walls)
    # find the index of the fifth highest wall
    fifth_highest_index = walls.index(fifth_highest)
    # set the fifth highest wall to 0
    walls[fifth_highest_index] = 0
    # find the sixth highest wall
    sixth_highest = max(walls)
    # find the index of the sixth highest wall
    sixth_highest_index = walls.index(sixth_highest)
    # set the sixth highest wall to 0
    walls[sixth_highest_index] = 0
    # find the seventh highest wall
    seventh_highest = max(walls)
    # find the index of the seventh highest wall
    seventh_highest_index = walls.index(seventh_highest)
    # set the seventh highest wall to 0
    walls[seventh_highest_index] = 0
    # find the eighth highest wall
    eighth_highest = max(walls)
    # find the index of the eighth highest wall
    eighth_highest_index = walls.index(eighth_highest)
    # set the eighth highest wall to 0
    walls[eighth_highest_index] = 0
    # find the ninth highest wall
    ninth_highest = max(walls)
    # find the index of the ninth highest wall
    ninth_highest_index = walls.index(ninth_highest)
    # set the ninth highest wall to 0
    walls[ninth_highest_index] = 0
    # find the tenth highest wall
    tenth_highest = max(walls)
    # find the index of the tenth highest wall
    tenth_highest_index = walls.index(tenth_highest)
    # set the tenth highest wall to 0
    walls[tenth_highest_index] = 0
