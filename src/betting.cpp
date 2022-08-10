#include<iostream>
using namespace std;

//////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/betting /
//////////////////////////////////////////////////////

int main() {
    // Read in percent of total
    double a; cin >> a;
    // Set to decimal
    a /= 100;
    // Output the amount gained by each person in group 1
    cout << 100 / a / 100 << endl;
    // Output the amount gained by each person in group 2 (complement to group 1 percent)
    cout << 100 / (1 - a) / 100 << endl;
    // Return exit code
    return 0;
}