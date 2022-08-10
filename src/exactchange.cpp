#include <iostream>
#include <vector>
using namespace std;

// Max cost for any product from question description
static const int MAX_COST = 10000;

int main() {
    // Read in case count
    int c; cin >> c;
    while(c--) {
        // Read in cost for test case and the coins
        int cost, n; cin >> cost >> n;
        vector<int> coins(n);
        for(int i = 0; i < n; i++) cin >> coins[i];
        // Initialize dp array to impossible coins value for all costs
        // and set zero to possible with 0
        vector<int> dp(MAX_COST + 1, n + 1);
        dp[0] = 0;
        // Loop through all coins updated possible spots when minimum coin
        // amount to reach it is found
        for(int i = 0; i < n; i++) {
            for(int j = MAX_COST; j >= 0; j--){
                if(dp[j] != n + 1 && j + coins[i] <= MAX_COST) dp[j + coins[i]] = min(dp[j + coins[i]], dp[j] + 1);
            }
        }
        // Lastly loop through from cost to the first value possible
        // then output the cost and the coins needed
        for(int i = cost; i <= MAX_COST; i++){
            if(dp[i] != n + 1) {
                cout << i << " " << dp[i] << endl;
                break;
            }
        }
    }
    // Return exit code
    return 0;
}