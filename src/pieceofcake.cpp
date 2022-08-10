#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/pieceofcake2 /
///////////////////////////////////////////////////////////

int main() {
    // Read input dimensions and cut locations
    int n, h, w; cin >> n >> h >> w;
    // Calculate max width and height possible
    int mw = max(n - w, w);
    int mh = max(n - h, h);
    // Output cubic volume
    cout << mw * mh * 4 << endl;
    // Return exit code
    return 0;
}