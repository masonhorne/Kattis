#include <iostream>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/quadrant /
///////////////////////////////////////////////////////

int main() {
    // Read input coordinates
    int x, y; cin >> x; cin >> y;
    // Output proper quadrant based on values
    if(x > 0) cout << (y > 0 ? 1 : 4) << endl;
    else cout << (y > 0 ? 2 : 3) << endl;
    // Return exit code
    return 0;
}