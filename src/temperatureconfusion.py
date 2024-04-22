import sys
import math

##################################################################
# Problem: https://open.kattis.com/problems/temperatureconfusion #
##################################################################
 
# Read in the input fraction
a, b = map(int, sys.stdin.readline().split('/'))
# Solve for the celcius value
a -= b * 32
a *= 5
b *= 9
c = math.gcd(a, b)
a //= c
b //= c
# Output the resulting fraction
print(a, '/', b, sep='')