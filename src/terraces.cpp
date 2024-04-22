#include<iostream>
#include<vector>
#include<queue>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/terraces /
///////////////////////////////////////////////////////

int bfs(int i, int j, vector<vector<int>>& g, vector<vector<int>>& vis){
    // If we have visited this spot, return 0
    if(vis[i][j]) return 0;
    // BFS from the current location
    queue<vector<int>> q;
    q.push({i, j});
    // Initialize the count to 0
    int c = 0;
    while(!q.empty()) {
        int x = q.front()[0], y = q.front()[1];
        q.pop();
        // Skip invalid spots and higher mountains
        if(x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y] > g[i][j]) continue;
        // If it is lower then mark as invalid and continue
        if(g[x][y] < g[i][j]) {
            c = -1;
            continue;
        }
        // If we have visited this spot, continue
        if(vis[x][y]) continue;
        // Increase the count if we are still valid
        if(c >= 0) c++;
        // Mark as visited and explore neighbors
        vis[x][y] = 1;
        q.push({x - 1, y});
        q.push({x + 1, y});
        q.push({x, y - 1});
        q.push({x, y + 1});
    }
    // Return the total count of crop spots if it was valid otherwise 0
    return c > 0 ? c : 0;
}

int main () {
    // Read in input dimensions
    int n, m; cin >> n >> m;
    // Build matrix of terrace heights
    vector<vector<int>> g(m, vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> g[i][j];
        }
    }
    // Initialize crop spots to 0 and visited array
    int ans = 0;
    vector<vector<int>> vis(m, vector<int>(n));
    // Loop through all points and check if it is in a crop path, if so add all the connected spots
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            ans += bfs(i, j, g, vis);
        }
    }
    // Output the total number of crop spots
    cout << ans << endl;
    // Return exit code
    return 0;
}