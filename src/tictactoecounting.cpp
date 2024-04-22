#include<iostream>
#include<unordered_map>
using namespace std;

////////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/tictactoecounting /
////////////////////////////////////////////////////////////////

bool isWinner(string s, char c) {
    // Try the winners in rows and columns
    for(int i = 0; i < 3; i++) {
        // Rows check
        if(s[i * 3] == c && s[i * 3] == s[i * 3 + 1] && s[i * 3] == s[i * 3 + 2]) return true;
        // Columns check
        if(s[i] == c && s[i] == s[i + 3] && s[i] == s[i + 6]) return true;
    }
    // Check the diagonals of the grid
    if(s[0] == c && s[0] == s[4] && s[4] == s[8]) return true;
    if(s[2] == c && s[2] == s[4] && s[4] == s[6]) return true;
    // Return false if so winner was found
    return false;

}

pair<int, int> solve(string s, unordered_map<string, pair<int, int>> &dp, bool x) {
    if(dp.find(s) != dp.end()) return dp[s];
    // If the current string has a winner, mark its result and return
    pair<int, int> ans = {isWinner(s, 'X') ? 1 : 0, isWinner(s, 'O') ? 1 : 0};
    if(ans.first || ans.second) return dp[s] = ans;
    // Otherwise try all possible moves
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '.'){
            string temp = s;
            temp[i] = x ? 'X' : 'O';
            if(dp.find(temp) == dp.end()) solve(temp, dp, !x);
            // All games that carried from the next state till the end are apart of the current state
            ans.first += dp[temp].first;
            ans.second += dp[temp].second;
        }
    }
    // Cache the result and store it in dp
    return dp[s] = ans;
}

int main() {
    // Initialize the total test cases
    int t; cin >> t;
    // Initialize dp array and read input
    unordered_map<string, pair<int, int>> dp;
    // Process each of the test cases
    while(t--) {
        string s; cin >> s;
        // Get the counts of current X and O
        int xc = 0, oc = 0;
        for(char c : s) {
            if(c == 'X') xc++;
            else if(c == 'O') oc++;
        }
        // Handle invalid case of non-reachable state
        if((xc != oc && xc != oc + 1) || (xc == oc && isWinner(s, 'X')) || (xc == oc + 1 && isWinner(s, 'O'))) {
            cout << "-1 -1" << endl;
        } else {
            // Otherwise, recurse to solve for the current state
            solve(s, dp, xc == oc);
            cout << dp[s].first << " " << dp[s].second << endl;
        }
    }
    // Return exit code
    return 0;
}