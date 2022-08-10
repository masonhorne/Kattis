#include <iostream>
using namespace std;

//////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/cetvrta /
//////////////////////////////////////////////////////

int main() {
    // Read in all x and y values from input
    int x1, y1, x2, y2, x3, y3; cin >> x1; cin >> y1; cin >> x2; cin >> y2; cin >> x3; cin >> y3;
    // Initialize values for the missing point
    int x4, y4;
    // Find the matching x values, the missing x is the same as the non matching
    if(x1 == x2) x4 = x3;
    else if(x2 == x3) x4 = x1;
    else x4 = x2;
    // Find the matching y values, the missing y is the same as the non matching
    if(y1 == y2) y4 = y3;
    else if(y2 == y3) y4 = y1;
    else y4 = y2;
    // Output the missing coordinates
    cout << x4 << " " << y4 << endl;
    // Return exit code
    return 0;
}