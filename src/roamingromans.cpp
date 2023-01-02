#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

/////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/romans /
/////////////////////////////////////////////////////

int main() {
    // Read in distance
    double x; cin >> x;
    // Convert using formula provided
    double v = x * 1000 * 5280.0 / 4854.0;
    // Set precision for cout and output
    cout << fixed << setprecision(0);
    cout << round(v) << endl;
    // Return exit code
    return 0;
}