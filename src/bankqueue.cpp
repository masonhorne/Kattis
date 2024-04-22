#include<iostream>
#include<vector>
using namespace std;

///////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/bank /
///////////////////////////////////////////////////

int main() {
    // Read in total people and time
    int n, t; cin >> n >> t;
    // Initialize list of people information and an array for marking people as used
    vector<vector<int>> v(n, vector<int>(2));
    vector<int> vis(n);
    for(int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1];
    // Initialize our result to 0
    int ans = 0;
    // Loop through each time stamp available
    while(t >= 0) {
        // Find the maximum value we can take right now
        int mx = -1;
        for(int i = 0; i < n; i++) {
            if(!vis[i] && v[i][1] >= t && (mx == -1 || v[i][0] > v[mx][0])) {
                mx = i;
            }
        }
        // Add the maximum value to our result and mark it as used
        if(mx != -1){
            ans += v[mx][0];
            vis[mx] = 1;
        }
        // Move to the next time stamp
        t--;
    }
    // Output the total money we collected
    cout << ans << endl;
    // Return exit code
    return 0;
}