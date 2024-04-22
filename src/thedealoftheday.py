#############################################################
# Problem: https://open.kattis.com/problems/thedealoftheday #
#############################################################

# Read in the total card numbers and k value for cards to select
c = list(map(int, input().split()))
k = int(input())

def solve(c, k):
    # Initialize result to 0
    res = 0
    # Iterate through all possible combinations of the 10 elements
    for i in range(pow(2, 10)):
        # If k elements are in the subset calculate all possible hands
        if bin(i).count('1') == k:
            x = 1
            # Loop through multiplying card count
            for j in range(10):
                if i & (1 << j): x *= c[j]
            res += x
    # Output the resulting hand count
    print(res)

solve(c, k)