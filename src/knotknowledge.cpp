#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/knotknowledge /
////////////////////////////////////////////////////////////

int main() {
    // Read in number of knots
    int n; cin >> n;
    // Store knots in variable with XOR
    int t = 0;
    // XOR all needed knots into variable
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        t ^= v;
    }
    // XOR all learned knots to remove them from needed
    for(int i = 0; i < n - 1; i++){
        int v; cin >> v;
        t ^= v;
    }
    // Output the one remaining knot
    cout << t << endl;
    // Return exit code
    return 0;
}