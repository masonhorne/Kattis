import sys
import math

##############################################################
# Problem: https://open.kattis.com/problems/smallestmultiple #
##############################################################

# Read in the input values
vs = map(lambda x: map(int, x.split()), sys.stdin.readlines())

# LCM helper for calculating lcm of numbers
def lcm(a, b):
    return a * b // math.gcd(a, b)

def solve(vs):
    # Loop through each input finding LCM and printing
    for v in vs:
        res = 1
        for i in v:
            res = lcm(res, i)
        print(res)

solve(vs)

