#include<iostream>
#include<vector>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/assembly /
///////////////////////////////////////////////////////

// Constant for total possible vertices in reduced graph
const int HASH_SIZE = 26 * 2;

bool dfs(int node, vector<vector<int>> &g, vector<int> &vis) {
    // If we have been here, we have a cycle
    if(vis[node]) return true;
    // Mark as visited
    vis[node] = true;
    // Recurse to all adjacent nodes and if cycle found return true
    for(int v : g[node]) {
        if(dfs(v, g, vis)) return true;
    }
    // Mark as not visited
    vis[node] = false;
    // No cycle found
    return false;
}

bool solve(vector<vector<int>> &g) {
    // Initialize visited array
    vector<int> vis(g.size(), false);
    // Loop through all nodes and check if cycle found
    for(int i = 0; i < g.size(); i++) {
        // Return true if cycle is found
        if(dfs(i, g, vis)) return true;
    }
    // No cycle found
    return false;
}

int main() {
    // Read in number of nodes
    int n; cin >> n;
    // Initialize graph
    vector<vector<int>> g(HASH_SIZE);
    // Loop through and add edges for the molecules
    while(n--) {
        string s; cin >> s;
        // Hash molecule components to range 0-51
        vector<int> node;
        for(int i = 0; i < s.size(); i += 2){
            if(s[i] == '0') continue;
            int cv = s[i] - 'A';
            cv += s[i + 1] == '+' ? HASH_SIZE / 2 : 0;
            node.push_back(cv);
        }
        // Add edges for this molecule
        for(int i = 0; i < node.size(); i++) {
            for(int j = 0; j < node.size(); j++) {
                if(i == j) continue;
                g[node[i]].push_back((node[j] + HASH_SIZE / 2) % HASH_SIZE);
            }
        }
    }
    // Output result
    if(solve(g)) cout << "unbounded" << endl;
    else cout << "bounded" << endl;
    // Return exit code
    return 0;
}