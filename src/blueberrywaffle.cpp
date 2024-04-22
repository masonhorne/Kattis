#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/blueberrywaffle /
//////////////////////////////////////////////////////////////

int main() {
    // Read in the rotation time and total seconds
    int r, f; cin >> r >> f;
    // Calculate how many half rotations we complete
    int halfRot = f / r;
    // Calculate the remaining seconds
    int remainingSeconds = f % r;
    // Calculate the percentage of the current rotation
    double p = (double) remainingSeconds / r;
    // Determine if we are going up or down
    bool up = halfRot % 2 ? p > 0.5 : p < 0.5;
    // Output the direction
    cout << (up ? "up" : "down") << endl;
    // Return exit code
    return 0;
}