#include<iostream>
#include<cstring>
using namespace std;

/////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/anti11 /
/////////////////////////////////////////////////////

// DP Array for storing number of strings at this length
// O - Ending with 0 of this length
// 1 - Ending with 1 of this length
long long dp[2][10001];

// Value to mod result by to keep reasonable size
const int MOD = 1000000007;

int main() {
    // Set DP array to all 0s
    memset(dp, 0, sizeof dp);
    // Initialize the base cases of length 1 (one for each character)
    dp[0][1] = 1, dp[1][1] = 1;
    // Loop through to maximum test case populating dp array
    for(int i = 2; i < 10001; i++){
        // Any valid string can have a 0 added, so both are valid at this length
        dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
        // Only string that had ended with 0 can have a 1 added to be valid at this length
        dp[1][i] = (dp[0][i - 1]) % MOD;
    }
    // Read in the number of test cases
    int n; cin >> n;
    // Process each of the test cases
    while(n--){
        // Read in the value to calculate
        int v; cin >> v;
        // Output its total possible strings
        cout << (dp[0][v] + dp[1][v]) % MOD << endl;
    }
    // Return exit code
    return 0;
}