#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/pokerhand /
////////////////////////////////////////////////////////

int main () {
    // Initialize a map of characters for the ranks to their counts
    unordered_map<char, int> mp;
    // Initialize max as 0
    int mx = 0;
    // Read in all 5 cards
    for(int i = 0; i < 5; i++){
        // Read card
        string s; cin >> s;
        // Increment rank count
        mp[s[0]]++;
        // If new max, update
        mx = max(mp[s[0]], mx);
    }
    // Output the max value of the hand
    cout << mx << endl;
    // Return exit code
    return 0;
}