#include<iostream>
#include<vector>
#include<string>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/pokechat /
///////////////////////////////////////////////////////

int main() {
    // Initialize and read in the special key and the values to use
    string s, v; 
    getline(cin, s);
    getline(cin, v);
    // Initialize the result
    string ans = "";
    // Traverse all of the ids
    for(int i = 0; i < v.size(); i += 3){
        // Initialize the result
        int a = 0;
        // Parse the result from its id value
        for(int j  = 0; j < 3; j++) a *= 10, a += v[i + j] - '0';
        // Add the character to the result
        ans += s[a - 1];
    }
    // Output the resulting message
    cout << ans << endl;
    // Return exit code
    return 0;
}