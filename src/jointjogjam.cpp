#include<iostream>
#include<cmath>
using namespace std;

//////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/jointjogjam /
//////////////////////////////////////////////////////////

int main() {
    // Read in all initial points
    double x1, y1, x2, y2, x3, y3, x4, y4; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    // Set output precision
    cout.precision(12);
    // Calculate the distances at the end and start since these are extremes
    cout << max(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)), sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2))) << endl;
    // Return the exit code
    return 0;
}