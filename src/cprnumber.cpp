#include<string>
#include<iostream>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/cprnummer /
////////////////////////////////////////////////////////

int main() {
    // Read in cpr number
    string s; cin >> s;
    // Calculate sum of values from rule provided
    int sum = (s[0] - '0') * 4 + (s[1] - '0') * 3 + (s[2] - '0') * 2 + (s[3] - '0') * 7 + (s[4] - '0') * 6 + (s[5] - '0') * 5 + (s[7] - '0') * 4 + (s[8] - '0') * 3 + (s[9] - '0') * 2 + (s[10] - '0');
    // Output whether the sum was divisible by 11
    cout << (sum % 11 == 0 ? 1 : 0) << endl;
    // Return exit code
    return 0;
}