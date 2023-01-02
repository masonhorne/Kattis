#####################################################
# Problem: https://open.kattis.com/problems/oktalni #
#####################################################

# Read in the binary number as a base 10 integer
b = int(input(), 2)
# Initialize a result and counter for the digit we are at
ans, c = 0, 1
# Loop until the entire input has been processed
while(b):
    # Add the next digit in the input at the digit position in result
    ans += (b % 8) * c
    # Increase to the next digit position
    c *= 10
    # Remove the values that were included in that digit
    b //= 8
# Output the resulting octal value
print(ans)
