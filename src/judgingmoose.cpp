#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/judgingmoose /
///////////////////////////////////////////////////////////

int main() {
    // Read in the left and right tine counts
    int l, r; cin >> l >> r;
    // If equal and not zero, output even and value
    if( l != 0 && l == r) cout << "Even " <<  l + r << endl;
    // Otherwise if either isn't 0, output odd and value
    else if(l > 0 || r > 0) cout << "Odd " << (l > r ? l * 2 : r * 2) << endl;
    // Otherwise both are 0 so not a moose
    else cout << "Not a moose" << endl;
    // Return exit code
    return 0;
}