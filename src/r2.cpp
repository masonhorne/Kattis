#include <iostream>
using namespace std;

/////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/r2 /
/////////////////////////////////////////////////

int main() {
    // Read input values
    int r1, s; cin >> r1; cin >> s;
    // Calculate missing value and ouput
    cout << s * 2 - r1 << endl;
    // Return exit code
    return 0;
}