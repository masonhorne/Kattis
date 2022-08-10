#include<iostream>
#include<string>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/greetings2 /
/////////////////////////////////////////////////////////

int main() {
    // Read input string
    string s; cin >> s;
    // Initialize resulting string to h
    string ans = "h";
    // Add 2x number of e's to result
    for(int i = 0; i < (s.size() - 2) * 2; i++) ans += 'e';
    // Add the trailing y
    ans += "y";
    // Output the result
    cout << ans << endl;
    // Return exit code
    return 0;
}