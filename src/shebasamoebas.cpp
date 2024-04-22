#include<iostream>
#include<vector>
using namespace std;

//////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/amoebas /
//////////////////////////////////////////////////////

void dfs(vector<vector<char>> &g, int i, int j) {
    // If invalid cell, return
    if(i < 0 || i >= g.size() || j < 0 || j >= g[i].size() || g[i][j] != '#') return;
    // Mark cell as visited
    g[i][j] = '.';
    // Recurse to all 8 adjacent cells
    for(int dx = -1; dx <= 1; dx++){
        for(int dy = -1; dy <= 1; dy++){
            if(dx == 0 && dx == dy) continue;
            dfs(g, i + dx, j + dy);
        }
    }
}

int main() {
    // Read in grid dimensions
    int m, n; cin >> m >> n;
    // Initialize grid with characters
    vector<vector<char>> g(m, vector<char>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    // Initialize result to 0
    int ans = 0;
    // Loop through counting all amoebas
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(g[i][j] == '#') {
                dfs(g, i, j);
                ans++;
            }
        }
    }
    // Output total count
    cout << ans << endl;
    // Return exit code
    return 0;
}
