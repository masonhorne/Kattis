#include <iostream>
#include <cmath>
using namespace std;

/////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/sibice /
/////////////////////////////////////////////////////

int main() {
    // Read number of matches
    int n; cin >> n;
    // Read width and height of box
    int w, h; cin >> w; cin >> h;
    // Calculate max length (diagonal) of box
    int m = sqrt(w * w + h * h);
    // Initialize value and loop while more values exist
    int l;
    while(cin >> l) {
        // If match fits, output accordingly
        if(l <= m) cout << "DA" << endl;
        else cout << "NE" << endl;
    }
    // Return exit code
    return 0;
}