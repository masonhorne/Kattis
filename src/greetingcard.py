##########################################################
# Problem: https://open.kattis.com/problems/greetingcard #
##########################################################

# Read in the input values
n = int(input())
vs = []
for i in range(n):
    vs.append(list(map(int, input().split(' '))))
# Create a set from the points
points = set()
for v in vs:
    x = v[0]
    y = v[1]
    points.add((x, y))
# Initialize the result to 0
ans = 0
# Iterate through each point counting its neighbors
for i in range(len(vs) - 1, -1, -1):
    v = vs[i]
    x = v[0]
    y = v[1]
    # Check all possible locations that the neighboring points could be
    if (x, y + 2018) in points:
        ans += 1
    if (x, y - 2018) in points:
        ans += 1
    if (x + 1118, y + 1680) in points:
        ans += 1
    if (x - 1118, y + 1680) in points:
        ans += 1
    if (x + 1118, y - 1680) in points:
        ans += 1
    if (x - 1118, y - 1680) in points:
        ans += 1
    if (x + 1680, y + 1118) in points:
        ans += 1
    if (x - 1680, y + 1118) in points:
        ans += 1
    if (x + 1680, y - 1118) in points:
        ans += 1
    if (x - 1680, y - 1118) in points:
        ans += 1
    if (x + 2018, y) in points:
        ans += 1
    if (x - 2018, y) in points:
        ans += 1
    # Remove the current point from set to avoid double counting
    points.remove((x, y))
# Print the resulting count of lines
print(ans)