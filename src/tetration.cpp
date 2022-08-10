#include<iostream>
#include<cmath>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/tetration /
////////////////////////////////////////////////////////

int main() {
    // Set precision for output
    cout.precision(12);
    // Read in tetrations value
    double n; cin >> n;
    // Take its value and raise it to its inverse for base value
    cout << pow(n, 1 / n) << endl;
    // Return the result
    return 0;
}