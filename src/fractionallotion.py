import sys

##############################################################
# Problem: https://open.kattis.com/problems/fractionallotion #
##############################################################

# Read in the input values
vs = map(lambda x: list(map(int, x.split('/'))), sys.stdin.readlines())
# Cache for storing previously computed values
cache = {}

# Loop through all input calculating potential fractions
for v in vs:
    ans = 0
    n = v[1]
    # If cached return cache
    if n in cache: print(cache[n])
    else :
        # Otherwise check all possible values
        for i in range(n + 1, 2 * n + 1):
            y = i * n
            if y % (i - n) == 0: ans += 1
        print(ans)
        cache[n] = ans