#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/taisformula /
//////////////////////////////////////////////////////////

int main() {
    // Read in total points
    int n; cin >> n;
    // Read in initial point
    double pt, pv; cin >> pt >> pv;
    // Decrement for first read
    n--;
    // Initialize answer to 0
    double ans = 0;
    while(n--){
        // Read in next section
        double t, v; cin >> t >> v;
        // Add ranges area to result
        ans += ((pv + v) / 2) * (t - pt);
        // Update previous values
        pv = v;
        pt = t;
    }
    // Set precision for output
    cout.precision(12);
    // Convert to from mL to L and output
    cout << ans / 1000 << endl;
    // Return exit code
    return 0;
}