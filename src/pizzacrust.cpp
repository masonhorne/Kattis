#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Read in radius and crust thickness
    int r, c; cin >> r; cin >> c;
    // Get readius of just cheese
    int cR = r - c;
    // Calculate total area
    double total = M_PI * (r * r);
    // Calculate cheese area
    double cheese = M_PI * (cR * cR);
    // Set precision and output result
    cout.precision(7);
    cout << fixed << cheese / total * 100 << endl;
    // Return exit code
    return 0;
}