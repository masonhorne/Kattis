#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/fruitbaskets /
///////////////////////////////////////////////////////////

// DP Array for number of baskets that have the index as weight
long long dp[40001];

int main() {
    // Set the dp array to no baskets
    memset(dp, 0, sizeof dp);
    // Read in the number of items
    int n; cin >> n;
    // Place them into a list
    vector<int> w(n + 1);
    for(int i = 1; i < n + 1; i++) cin >> w[i];
    // There is one way to have a weight of 0
    int mx = 0;
    dp[0] = 1;
    // Progressively add each item
    for(int i = 1; i <= n; i++){
        // Trying sums from right to left to avoid adding to created values
        for(int j = mx; j >= 0; j--){
            // If the weight has baskets, add them to their new weight with this item and update max cost
            if(dp[j]) dp[j + w[i]] += dp[j], mx = max(mx, j + w[i]);
        }
    }
    // Initialize the result to 0
    long long ans = 0;
    // Loop through all costs from 200 to the maximum we have seen
    for(int i = 200; i <= mx; i++)
        // If the weight has baskets, add them to the total weight
        if(dp[i]) ans += i * dp[i];
    // Output the total weight of all the valid baskets
    cout << ans << endl;
    // Return exit code
    return 0;
}