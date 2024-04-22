#include<iostream>
#include<vector>
#include<queue>
using namespace std;

///////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/gold /
///////////////////////////////////////////////////

int main() {
    // Initialize grid dimensions
    int n, m; cin >> n >> m;
    // Initialize queue of positions
    queue<pair<int, int>> q;
    // Initialize grid with characters
    vector<vector<char>> g(m, vector<char>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> g[i][j];
            if(g[i][j] == 'P')  {
                q.push({i, j});
                g[i][j] = '.';
            }
        }
    }
    // Initialize directions
    int dirs[5] = {1, 0, -1, 0, 1};
    // Initialize result to 0
    int ans = 0;
    // Loop through counting all gold
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        // Skip invalid positions
        if(x < 0 || x >= m || y < 0 || y >= n || (g[x][y] != 'G' && g[x][y] != '.')) continue;
        // If we hit gold increment its count
        if(g[x][y] == 'G') ans++;
        // Mark the position as visited
        g[x][y] = '#';
        // Count cells that have traps neighboring
        int draft = 0;
        for(int i = 0; i < 4; i++) {
            int nx = x + dirs[i], ny = y + dirs[i + 1];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(g[nx][ny] == 'T') draft++;
        }
        // If no draft, then we can move in all 4 directions
        if(draft == 0) {
            for(int i = 0; i < 4; i++) {
                q.push({x + dirs[i], y + dirs[i + 1]});
            }
        }
    }
    // Output total count
    cout << ans << endl;
    // Return exit code
    return 0;
}
