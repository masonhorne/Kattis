#include<iostream>
#include<cmath>
using namespace std;

//////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/janitortroubles /
//////////////////////////////////////////////////////////////

// Brahmagupta's Formula: https://en.wikipedia.org/wiki/Brahmagupta%27s_formula

int main() {
    // Read in all side lengths
    double a, b, c, d; cin >> a >> b >> c >> d;
    // Calculate the semiperimeter of quadrilateral
    double sp = (a + b + c + d) / 2;
    // Set precision for output
    cout.precision(9);
    // Use Brahmagupta's formula to calculate area (maximalized version of Bretschneider's formula)
    cout << sqrt((sp - a) * (sp - b) * (sp - c) * (sp - d)) << endl;
    // Return exit code
    return 0;
}