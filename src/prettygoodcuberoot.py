import sys

################################################################
# Problem: https://open.kattis.com/problems/prettygoodcuberoot #
################################################################

# Read in the input values
vs = map(int, sys.stdin.readlines())

def solve(vs):
    # Loop through each input finding the best cube root
    for v in vs:
        # Initialize pointers for binary search
        l, h = 0, v
        # Search for the best potential cube root
        while l < h:
            m = l + (h - l) // 2
            if m * m * m < v:
                l = m + 1
            else:
                h = m
        # Check if the prior lower value was better and output the closer of the two
        if abs(v - (l * l * l)) > abs(v - ((l - 1) * (l - 1) * (l - 1))): print(l - 1)
        else: print(l)

solve(vs)