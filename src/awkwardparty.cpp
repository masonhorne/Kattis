#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/awkwardparty /
///////////////////////////////////////////////////////////

int main () {
    // Initialize the input count and map for storing indices
    int n; cin >> n;
    unordered_map<int, int> mp;
    int ans = INT_MAX;
    // Loop through all values caching indices and calculating range between last seen
    for(int i = 0; i < n; i++) {
        int v; cin >> v;
        if(mp.find(v) != mp.end()) ans = min(ans, i - mp[v]);
        mp[v] = i;
    }
    // Output the minimum distance of list length based on if value occurred twice
    cout << (ans == INT_MAX ? n : ans) << endl;
    // Return exit code
    return 0;
}