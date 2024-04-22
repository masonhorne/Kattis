#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/pivot /
////////////////////////////////////////////////////

int main() {
    // Read in total numbers
    int n; cin >> n;
    // Initialize our list of numbered elements
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    // Keep maximum seen from left to right and minimum seen from right to left
    vector<int> dp(n), dp2(n);
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            dp[i] = v[i];
            dp2[n - i - 1] = v[n - i - 1];
        } else {
            dp[i] = max(dp[i - 1], v[i]);
            dp2[n - i - 1] = min(dp2[n - i], v[n - i - 1]);
        }
    }
    // Initialize our result to 0
    int ans = 0;
    // Count all points that were valid pivots
    for(int i = 0; i < n; i++) {
        if(v[i] == dp[i] && v[i] == dp2[i]) ans++;
    }
    // Output the resulting count
    cout << ans << endl;
    // Return exit code
    return 0;
}