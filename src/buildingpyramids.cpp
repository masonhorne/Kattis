#include<iostream>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/pyramids /
///////////////////////////////////////////////////////

int main() {
    // Read in total blocks
    double v; cin >> v;
    // Initialize size width
    int b = 1;
    // Initialize layers to 0
    int c = 0;
    // Loop while blocks remain
    while(v > 0){
        // Remove for this later
        v -= b * b;
        // Update for next layer
        b += 2;
        // Increment the layer count
        c++;
    }
    // If we went negative on blocks, last layer doesn't count
    cout << (v < 0 ? c - 1 : c) << endl;
    // Return exit code
    return 0;
}