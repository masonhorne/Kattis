#include<iostream>
using namespace std;

//////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/triarea /
//////////////////////////////////////////////////////

int main() {
    // Read height and base lengths
    double h, b; cin >> h >> b;
    // Set precision and output area
    cout.precision(15);
    cout << h * (b / 2) << endl;
    // Return exit code
    return 0;
}