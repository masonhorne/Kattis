#include<iostream>
#include<cstring>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/compositions /
///////////////////////////////////////////////////////////

/////////////////////////////////////////
//                                     //
//  [1, 0, 0, 0, 0]                    //
//  [1, 0, 0, 0, 0] 1                  //
//  [1, 1, 0, 0, 0] 1 -> 2             //
//  [1, 1, 2, 0, 0] 2 -> 3 -> 4        //
//  [1, 1, 2, 4, 0] 4 -> 6 -> 7 -> 8   //
//  [1, 1, 2, 4, 8]                    //
//                                     //
//  Each of the combinations that adds //
//  to one less than the current value //
//  can be carried on if the increment //
//  value isn't in the arithmetic      //
//  sequence given by m and k. This    //
//  is true for all values across the  //
//  dp array.                          //
//                                     //
/////////////////////////////////////////

// Initialize DP array to store all possible values
long long dp[32];

int main() {
    // Read in total test cases
    int t; cin >> t;
    // Process each of the tests
    while(t--){
        // Read in the case number, value to get composition of, and m and k values
        int a, n, m, k; cin >> a >> n >> m >> k;
        // Set the dp array to all 0s
        memset(dp, 0, sizeof dp);
        // Mark the initial value of 1
        dp[0] = 1;
        // Loop through all values up until n
        for(int i = 1; i < n + 1; i++){
            // Loop all values up until this point in iteration
            for(int j = 1; j < i + 1; j++){
                // If the value is in the geometric sequence, skip it
                if((j % k) - m == 0) continue;
                // Otherwise add its value to the current since it is sub composition
                dp[i] += dp[i - j];
            }
        }
        // Output the case number and the total compositions
        cout << a << " " << dp[n] << endl;
    }
    // Return exit code
    return 0;
}