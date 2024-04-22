#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

///////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/pebblesolitaire2 /
///////////////////////////////////////////////////////////////

int solve(string s, unordered_map<string, int> &dp) {
    // If we have computed this string before, return its value
    if(dp.find(s) != dp.end()) return dp[s];
    // Otherwise, try all possible moves and return the minimum pebble count
    int ans = INT_MAX;
    for(int i = 0; i < s.size(); i++) {
        if(i + 2 < s.size() && s[i] == '-' && s[i + 1] == 'o' && s[i + 2] == 'o') {
            string temp = s;
            temp[i] = 'o';
            temp[i + 1] = '-';
            temp[i + 2] = '-';
            ans = min(ans, solve(temp, dp));
        }
        if(i - 2 >= 0 && s[i] == '-' && s[i - 1] == 'o' && s[i - 2] == 'o') {
            string temp = s;
            temp[i] = 'o';
            temp[i - 1] = '-';
            temp[i - 2] = '-';
            ans = min(ans, solve(temp, dp));
        }
    }
    // If a move was found, return its result
    if(ans != INT_MAX) return dp[s] = ans;
    else {
        // Otherwise, we reached the minimum so return the pebble count
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == 'o') cnt++;
        return dp[s] = cnt;
    }
}

int main() {
    // Read in the total test cases
    int t; cin >> t;
    while(t--) {
        // Process each test and output the resulting pebble count
        string s; cin >> s;
        unordered_map<string, int> dp;
        cout << solve(s, dp) << endl;
    }
    // Return exit code
    return 0;
}