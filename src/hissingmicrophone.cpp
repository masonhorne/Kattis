#include<iostream>
#include<string>
using namespace std;

////////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/hissingmicrophone /
////////////////////////////////////////////////////////////////

int main() {
    // Read input string
    string s; cin >> s;
    // Initialize flag for hiss
    bool f = true;
    // Loop through input until repeated s's are found
    for(int i = 1; i < s.size() && f; i++) if(s[i] == 's' && s[i] == s[i - 1]) f = false;
    // Output based on whether consecutive s were found
    cout << (f ? "no hiss" : "hiss") << endl;
    // Return exit code
    return 0;
}