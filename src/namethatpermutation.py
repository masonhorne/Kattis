import sys
import math

#################################################################
# Problem: https://open.kattis.com/problems/namethatpermutation #
#################################################################

# Parse the input pair of n and k values
vs = map(lambda x: map(int, x.split()), sys.stdin.readlines())

def solve(vs):
    # Iterate through outputting permutation from each input
    for n,k in vs:
        # Initialize a list of available values and a result list
        values = [1] * n
        res = []
        # Loop through until all values are used
        while n > 0:
            # Calculate total permutations for remaining values
            n -= 1
            b = math.factorial(n)
            # Calculate the next element we want to use
            e = k // b
            k %= b
            # Move a pointer through array to find next value
            p = 0
            while e > 0 or values[p] != 1:
                if values[p] == 1: e -= 1
                p += 1
            # Mark value as used and add to the result
            values[p] = 0
            res.append(p + 1)
        # Print the resulting permutation
        print(' '.join(map(str, res)))

solve(vs)