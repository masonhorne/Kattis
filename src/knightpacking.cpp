#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/knightpacking /
////////////////////////////////////////////////////////////

int main() {
    // Read in the board dimensions
    int n; cin >> n;
    // If dimensions are odd, total spaces is odd, so first wins, otherwise second
    cout << ((n & 1) ? "first" : "second") << endl;
    // Return exit code
    return 0;
}