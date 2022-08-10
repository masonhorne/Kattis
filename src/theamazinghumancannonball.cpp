#include<iostream>
#include<cmath>
using namespace std;

///////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/humancannonball2 /
///////////////////////////////////////////////////////////////

int main() {
    // Read in test case count
    int n; cin >> n;
    while(n--){
        // Read in values for test case
        double v, t, x, h1, h2; cin >> v >> t >> x >> h1 >> h2;
        // Solve for time when distance x is reached
        double time = x / (v * cos(t * M_PI / 180));
        // Plug in time value for height at this time
        double h = v * time * sin(t * M_PI / 180) - 0.5 * 9.81 * time * time;
        // Output if the height is within the proper range
        cout << (h1 < h - 1 && h2 > h + 1 ? "Safe" : "Not Safe") << endl;
    }
    // Return exit code
    return 0;
}