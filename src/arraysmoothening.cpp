#include<queue>
#include<iostream>
#include<unordered_map>
using namespace std;

///////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/arraysmoothening /
///////////////////////////////////////////////////////////////

int main() {
    // Read in total elements and elements to remove
    int n, k; cin >> n >> k;
    // Initialize map for counting and pq for keeping up with maximum
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> mp;
    // Count the elements
    for(int i = 0; i < n; i++) {
        int v; cin >> v;
        mp[v]++;
    }
    // Input the counted values to the priority queue
    for(unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) 
        pq.push({it->second, it->first});
    // Loop until all removals have been made
    while(k--){
        pair<int, int> v = pq.top();
        pq.pop();
        pq.push({v.first - 1, v.second});
    }
    // Output the next maximum value
    cout << pq.top().first << endl;
    // Return exit code
    return 0;
}