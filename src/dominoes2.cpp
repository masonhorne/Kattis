#include<iostream>
#include<vector>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/dominoes2 /
////////////////////////////////////////////////////////

void dfs(vector<vector<int>> &g, vector<int> &v, int idx){
    // If the domino has fallen, return since can't knock over others
    if(v[idx]) return;
    // Otherwise mark as fallen
    v[idx] = 1;
    // Recurse to all of its neighbors to knock them down
    for(int i : g[idx]) dfs(g, v, i);
}

int main() {
    // Read in the test case count
    int t; cin >> t;
    // Process each of the test cases
    while(t--){
        // Read in the total number, the edge count, and the starting position count
        int n, m, l; cin >> n >> m >> l;
        // Initialize the adjacency list for the graph
        vector<vector<int>> g(n);
        // Store the edges in the graph
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            g[x - 1].push_back(y - 1);
        }
        // Initialize a visited array
        vector<int> v(n);
        // Recurse from all points where we push dominos over
        for(int i = 0; i < l; i++) {
            int k; cin >> k;
            dfs(g, v, k - 1);
        }
        // Initialize a count
        int c = 0;
        // Count all of the dominos that fell
        for(int i = 0; i < v.size(); i++) c += v[i];
        // Output the result
        cout << c << endl;
    }
    // Return exit code
    return 0;
}