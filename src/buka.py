##################################################
# Problem: https://open.kattis.com/problems/buka #
##################################################

# Read first input value
a = int(input())
# Read in the operator to use
op = input()
# Read in the second input value
b = int(input())
# Output the proper result based on the operators value
print(a * b) if op == '*' else print(a + b)