#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

//////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/grasshopper /
//////////////////////////////////////////////////////////

int solve(int r, int c, int gr, int gc, int lr, int lc) {
    // Fix leaf for zero index
    lr--, lc--;
    // Initialize queue of positions
    queue<pair<int, int>> q;
    // Initialize visited grid
    vector<vector<bool>> vis(r, vector<bool>(c, false));
    // Push start position
    q.push({gr - 1, gc - 1});
    // Initialize result to -1 and step to 0
    int ans = -1, step = 0;
    // Loop until we find result or no more positions
    while(!q.empty() && ans == -1) {
        // Get total moves at this step
        int sz = q.size();
        // Loop through moves
        for(int i = 0; i < sz && ans == -1; i++) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            // Skip invalid positions
            if(x < 0 || x >= r || y < 0 || y >= c || vis[x][y]) continue;
            // Mark as visited
            vis[x][y] = true;
            // If we find leaf store result
            if(x == lr && y == lc) return step;
            // Push all possible moves
            q.push({x + 2, y + 1});
            q.push({x + 2, y - 1});
            q.push({x - 2, y + 1});
            q.push({x - 2, y - 1});
            q.push({x + 1, y + 2});
            q.push({x + 1, y - 2});
            q.push({x - 1, y + 2});
            q.push({x - 1, y - 2});
        }
        // Increment step
        step++;
    }
    // Return -1 since not possible to reach
    return -1;
}

int main() {
    // Read in total rows, start positions, and leaf positions
    int r, c, gr, gc, lr, lc;
    while(cin >> r >> c >> gr >> gc >> lr >> lc) {
        // Solve input
        int ans = solve(r, c, gr, gc, lr, lc);
        // Output proper result
        if(ans == -1) cout << "impossible" << endl;
        else cout << ans << endl;
    }
    // Return exit code
    return 0;
}
