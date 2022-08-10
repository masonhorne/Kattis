#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/lastfactorialdigit /
/////////////////////////////////////////////////////////////////

int main() {
    // Initialize dp array to 1 for all values
    int dp[11] = {1};
    // Loop through all integers calculating factorial values with index
    for(int i = 1; i <= 10; i++) dp[i] = dp[i - 1] * i;
    // Read in number of test cases
    int n; cin >> n;
    // Loop through test cases
    while(n--){
        // Read in value
        int m; cin >> m;
        // Output its factorials final digit
        cout << dp[m] % 10 << endl;
    }
    // Return exit code
    return 0;
}