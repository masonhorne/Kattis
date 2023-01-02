#include<iostream>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/exchangerates /
////////////////////////////////////////////////////////////

// Initialize DP array to store all best daily balances
double dp[366];

double getNewBalance(double current, double buy, double sell){
    // (Current / buy * 0.97) is the US dollars we buy with the current amount before rounding down to nearest cent
    // (USDollar * sell * 0.97) is the amount of canadian dollars we get in return before rounding down to nearest cent
    return floor(floor(current / buy * 0.97 * 100) / 100 * sell * 0.97 * 100) / 100;
}

int main() {
    // Set precision to 2 decimals
    cout << fixed;
    cout << setprecision(2);
    // Initialize a variable for storing the day count
    int n;
    // Loop until no test cases remain
    while(cin >> n && n != 0){
        // Initialize a list of all the daily prices
        double v[n + 1];
        // Read in each days value
        for(int i = 1; i <= n; i++) cin >> v[i];
        // Set the dp array to 0's
        memset(dp, 0, sizeof dp);
        // Initialize the starting value at 1000
        dp[0] = 1000;
        // Loop through all possible end days
        for(int i = 1; i <= n; i++){
            // The best here is at least the best the day before
            dp[i] = dp[i - 1];
            // Loop through all possible days before to buy on and sell today
            for(int j = 1; j <= i; j++) dp[i] = max(dp[i], getNewBalance(dp[j], v[j], v[i]));
        }
        // Output the best for the requested day
        cout << dp[n] << endl;
    }
    // Return exit code
    return 0;
}