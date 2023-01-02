#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

//////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/welcomeeasy /
//////////////////////////////////////////////////////////

// Dp array for matching subsequence counts from index combinations to the end of string
int dp[31][20];

int main() {
    // Target string we want to count subsequences of
    string target = "welcome to code jam";
    int t = target.size();
    // Read in the number of test cases to process
    int n; cin >> n;
    // Skip the new line for the test counts
    string s; getline(cin, s);
    // Process each of the strings
    for(int k = 0; k < n; k++){
        // Read in the string and store its size
        getline(cin, s);
        int sz = s.size();
        // Set the dp array to 0 so none occur
        memset(dp, 0, sizeof dp);
        // If the target is empty, all characters can create the string
        for(int i = 0; i < sz; i++) dp[i][0] = 1;
        // Loop through trying all possible character counts of string
        for(int i = 1; i <= sz; i++){
            // Try all possible character lengths in target
            for(int j = 1; j <= t; j++){
                // If the character match, total is before either were included plus before target wasn't included
                if(s[i - 1] == target[j - 1]) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10000;
                // Otherwise the best is the same as we had before this new character was included
                else dp[i][j] = dp[i - 1][j];
                
            }
        }
        // Output the case number followed by the subsequence count
        cout << "Case #" << k + 1 << ": " << setfill('0') << setw(4) << dp[s.size()][target.size()] << endl;
    }
    // Return exit code
    return 0;
}