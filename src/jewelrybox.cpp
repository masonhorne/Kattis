#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/jewelrybox /
/////////////////////////////////////////////////////////

int main() {
    // Read in total test cases and set precision
    int n; cin >> n;
    cout.precision(7);
    // Loop until input is finished
    while(n--) {
        // Read in x and y
        double x, y; cin >> x; cin >> y;
        // Make sure x is smaller of the two
        if(x > y) swap(x, y);
        // Initialize binary search bounds
        double low = 0;
        double high = x / 2;
        // Binary search for the best area
        while(high - low > .00000001) {
            // 1/3 height (1/3 of smaller dimension)
            double mid1 = low + (high - low) * (1.0 / 3);
            // 2/3 height (2/3 of smaller dimension)
            double mid2 = low + (high - low) * (2.0 / 3);
            // Get volume at both heights
            double v1 = mid1 * (x - 2 * mid1) * (y - 2 * mid1);
            double v2 = mid2 * (x - 2 * mid2) * (y - 2 * mid2);
            // If volume1 is greater, search lower half
            if(v1 > v2) high = mid2;
            // Otherwise search upper half
            else low = mid1;
        }
        // Output the resulting area
        cout << fixed <<  low * (x - 2 * low) * (y - 2 * high) << endl;
    }
    // Return exit code
    return 0;
}