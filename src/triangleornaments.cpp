#include <iostream>
#include <cmath>
using namespace std;

////////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/triangleornaments /
////////////////////////////////////////////////////////////////

int main() {
    // Read in the total number of ornaments to process
    int n; cin >> n;
    // Initialize rod length to 0
    double len = 0;
    // Process all inputs
    while(n--) {
        // Read in sides of triangle
        int a, b, c; cin >> a >> b >> c;
        // If sides are equal, must have space on the 3rd side
        if(a == b) len += c;
        // Otherwise we calculate the horizontal space taken by this dangling triangle
        else {
            // Make sure a is larger
            if(a < b) swap(a, b);
            // Get squared of all edges
            long long aS = a * a, bS = b * b, cS = c * c;
            // Calculate difference in a squared and b squared
            long long x = aS - bS;
            // The horizontal distance is the square root after solving with law of cosines
            len += sqrt(cS - x * x / (double) (2 * aS + 2 * bS - cS));
        }
    }
    // Set precision and output resulting length
    cout.precision(15);
    cout << len << endl;
    // Return exit code
    return 0;
}