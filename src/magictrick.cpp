#include<iostream>
#include<string>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/magictrick /
/////////////////////////////////////////////////////////

int main() {
    // Read input string
    string s; cin >> s;
    // Initialize hash table of characters
    int table[26] = {0};
    // Count all characters in input string
    for(int i = 0; i < s.size(); i++) table[s[i] - 'a']++;
    // Initialize flag to true
    bool f = true;
    // Loop through and if more than 1 of a character appears mark flag as false
    for(int i = 0; i < 26 && f; i++) if(table[i] > 1) f = false;
    // Output 1 if flag otherwise 0
    cout << (f ? 1 : 0) << endl;
    // Return exit code
    return 0;
}