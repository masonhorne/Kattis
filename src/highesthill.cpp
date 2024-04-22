#include<iostream>
#include<vector>
using namespace std;

//////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/highesthill /
//////////////////////////////////////////////////////////

int main() {
    // Read in the total height values
    int n; cin >> n;
    // Initialize our list of heights
    vector<long> v(n);
    for(int i = 0; i <  n; i++) cin >> v[i];
    // Initialize lists for the left lowest and right lowest points
    vector<long> ll(n), rl(n);
    // Loop through updating the left lowest and right lowest points
    ll[0] = v[0];
    for(int i = 1; i < n; i++) {
        if(v[i] >= v[i - 1]) ll[i] = ll[i - 1];
        else ll[i] = v[i];
    }
    rl[n - 1] = v[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        if(v[i] >= v[i + 1]) rl[i] = rl[i + 1];
        else rl[i] = v[i];
    }
    // Initialize our result to 0
    long ans = 0;
    // Find the maximum of the minimums
    for(int i = 0; i < n; i++) {
        ans = max(ans, min(v[i] - ll[i], v[i] - rl[i]));
    }
    // Output the maximum height
    cout << ans << endl;
    // Return exit code
    return 0;
}