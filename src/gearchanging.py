##########################################################
# Problem: https://open.kattis.com/problems/gearchanging #
##########################################################

# Read in total gear counts and acceptable cadence percentage change
n, m, p = map(int, input().split(' '))
# Adjust the percentage to a decimal
p /= 100
# Read in the input gear counts
v1 = list(map(int, input().split(' ')))
v2 = list(map(int, input().split(' ')))
# Initialize a list of sorted gear ratious
s = []
for i in range(n):
    for j in range(m):
        s += [v1[i] / v2[j]]
s = sorted(s)
# Set the current gear and mark the configuration as valid
cur = s[0]
valid = True
# Loop through verifying all gears can be reached
for i in range(1, len(s)):
    if cur + cur * p < s[i]:
        valid = False
    cur = s[i]
# Print the resulting output based on gears reachable
if valid: print('Ride on!')
else: print('Time to change gears!')