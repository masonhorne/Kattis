#include<iostream>
#include<string>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/apaxiaaans /
/////////////////////////////////////////////////////////

int main() {
    // Read input string
    string s; cin >> s;
    // Initialize result to first character of input
    string ans = " ";
    ans[0] = s[0];
    // Loop through remainder of input
    for(int i = 1; i < s.size(); i++){
        // While repeated characters, skip
        while(i < s.size() && s[i] == s[i - 1]) i++;
        // Once a new character is found add to result
        ans += s[i];
    }
    // Output the result
    cout << ans << endl;
    // Return exit code
    return 0;
}