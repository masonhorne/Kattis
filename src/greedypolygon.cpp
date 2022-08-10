#include <iostream>
#include <cmath>
using namespace std;


int main() {
    // Read in number of test cases
    int t; cin >> t;
    while(t--){
        // Read input (sides, length, expansion distance, land grabs)
        int n, l, d, g;
        cin >> n >> l >> d >> g;
        // Area of the new side expansion from original (rectangles)
        double x1 = l * g * d * n;
        // Area of complete edge radius (full circle since polygon covers 360 degrees)
        double x2 = M_PI * pow(d * g, 2);
        // l * tan(M_PI / 2 - M_PI / 2) / 2 = apothem
        // Area of polygon = a (apothem) * s (side length) * n (num sides) / 2
        double x3 = l * tan(M_PI / 2 - M_PI / n) / 2 * n * l / 2; // Area of initial polygon
        // Output total area
        cout.precision(12);
        cout << x1 + x2 + x3 << endl;
    }
    // Return exit code
    return 0;
}