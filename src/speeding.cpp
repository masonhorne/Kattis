#include<iostream>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/speeding /
///////////////////////////////////////////////////////

int main() {
    // Read in number of photos
    int n; cin >> n;
    // Store previous time and distance
    int pt, pd;
    // Initialize max as -1
    int mx = -1;
    // Read in initial 0s
    cin >> pt >> pd;
    // Decerement for first point
    n -= 1;
    // Loop more photos
    while(n--){
        // Read in time and distance
        int t, d; cin >> t >> d;
        // Calculate speed and update max if possible
        mx = max(mx, (d - pd) / (t - pt));
        // Update pevious time and distance
        pt = t;
        pd = d;
    }
    // Output max speed proven
    cout << mx << endl;
    // Return exit code
    return 0;
}