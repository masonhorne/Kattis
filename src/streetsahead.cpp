#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/streetsahead /
///////////////////////////////////////////////////////////

int main() {
    // Read in the total streets and drivers
    int n, q; cin >> n >> q;
    // Initialize a map with streets and their index on the road
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        mp[s] = i;
    }
    // Loop over queries outputting the number of crossed streets
    for (int i = 0; i < q; i++) {
        string s, e; cin >> s >> e;
        cout << abs(mp[e] - mp[s]) - 1 << endl;
    }
    // Return exit code
    return 0;
}