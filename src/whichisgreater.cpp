#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/whichisgreater /
/////////////////////////////////////////////////////////////

int main() {
    // Read input values
    int a, b; cin >> a >> b;
    // Output 1 if a > b 0 otherwise
    cout << (a > b ? 1 : 0) << endl;
    // Return exit code
    return 0;
}