#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize n for storing number of values
    int n; cin >> n;
    // Loop while input exists
    while(n){
        // Store vector of all values and the sum of them all
        vector<int> vals;
        int sum = 0;
        // Read in values adding to sum and values list
        for(int i = 0; i < n; i++) {
            int v; cin >> v;
            vals.push_back(v);
            sum += v;
        }
        // Initialize dp array to find all reachable sums
        vector<bool> dp(sum + 1, false);
        // Base case of sum of 0 is set to true
        dp[0] = true;
        // Loop through all values in list
        for(int i = 0; i < vals.size(); i++) {
            // Index in dp set to final index
            int idx = sum;
            // Loop from back updating reachable spots for this value
            while(idx >= 0) {
                // If possible to reach here, add value and mark as reachable
                if(dp[idx]) dp[idx + vals[i]] = true;
                idx--;
            }
        }
        // Loop from the middle to the start looking for first reachable value
        for(int i = sum / 2; i >= 0; i--){
            if(dp[i]){
                // Output the value and its complement
                cout << sum - i << " " << i << endl;
                break;
            }
        }
        // Read next test case value
        cin >> n;
    }
    // Return exit code
    return 0;
}