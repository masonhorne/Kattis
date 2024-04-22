#include<iostream>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/testdrive /
////////////////////////////////////////////////////////

int main() {
    // Read in the 3 position locations
    int a, b, c; cin >> a >> b >> c;
    // Check for a swap in direction
    if((b < a && b < c) || (c < b && a < b)) cout << "turned" << endl;
    // Check for a constant speed
    else if(abs(b - a) == abs(c - b)) cout << "cruised" << endl;
    // Check for a deceleration
    else if(abs(b - a) > abs(c - b)) cout << "braked" << endl;
    // Otherwise we are accelerating
    else cout << "accelerated" << endl;
    // Return exit code
    return 0;
}