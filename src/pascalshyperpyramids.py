import sys

###########################################################
# Problem: https://open.kattis.com/problems/hyperpyramids #
###########################################################

# Calculate all possible factorials before hand for multinomial theorem
cache = {}
def factorial(n):
    if n in cache: return cache[n]
    if n == 0: return 1
    cache[n] = n * factorial(n - 1)
    return cache[n]
factorial(32)

# Read the input dimensions and height
d, h = map(int, sys.stdin.readline().split())

def dfs(idx, c, d, h, num, v, mx):
    # If we have used all possible dimensions or have no more to use
    if sum(c) >= h - 1 or idx == d:
        # If we have a valid combination of cooridnates to reach the base of the pyramid
        if sum(c) == h - 1:
            # Calculate the coefficient and add it to result set
            den = 1
            for i in c: den *= factorial(i)
            v.add(num // den)
    else:
        # Try all values for this dimension and recurse
        for i in range(0, mx + 1):
            c[idx] = i
            dfs(idx + 1, c, d, h, num, v, i)
            c[idx] = 0

def solve(d, h):
    # List for building up the dimensions indices
    c = [0] * d
    # Set for storing the resulting base numbers
    v = set()
    # Calculate the numerator for multinomial theorem
    num = factorial(h - 1)
    # DFS to populate all base values
    dfs(0, c, d, h, num, v, h)
    # Print the sorted values
    for i in sorted(v): print(i)

solve(d, h)
