#include<iostream>
#include<string>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/alphabet /
///////////////////////////////////////////////////////

int main() {
    // Read in the input string
    string s; cin >> s;
    // Store its size in a variable
    int n = s.size();
    // Initialize a dp array that is a hashtable for each character
    // the values stored are the number of ordered elements that exist before
    int dp[26] = {};
    // Initialize the result to zero
    int ans = 0;
    // Loop through the input string
    for(int i = 0; i < n; i++){
        // Initialize the maximum characters before current to 0
        int mx = 0;
        // Get the character index in the table
        int idx = s[i] - 'a';
        // Loop through all values and update max if a new best is found
        for(int j = 0; j < idx; j++)
            if(mx < dp[j]) mx = dp[j];
        // Update current best as the max plus 1 for the character itself
        dp[idx] = mx + 1;
        // Update the answer if a better value is found
        ans = max(ans, dp[idx]);
    }
    // Output the number of characters needed for a full alphabet sequence
    cout << (26 - ans) << endl;
    // Return exit code
    return 0;
}