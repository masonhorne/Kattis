#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/sorttwonumbers /
/////////////////////////////////////////////////////////////

int main() {
    // Read in x and y
    int x, y; cin >> x >> y;
    // If x is smaller output it first
    if(x < y) cout << x << " " << y << endl;
    // Otherwise output y first
    else cout << y << " " << x << endl;
    // Return exit code
    return 0;
}