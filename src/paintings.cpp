#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/paintings /
////////////////////////////////////////////////////////

void dfs(unordered_map<int, unordered_map<int, int>> &c, vector<string> &colors, vector<int> &cur, vector<int> &res, int &ans, int i, int n) {
    if(cur.size() == n){
        if(ans == 0) res = vector<int>(cur);
        ans++;
    } else {
        for(int j = 0; j < colors.size(); j++) {
            if((i & (1 << j)) == 0) {
                bool valid = true;
                for(int k = 0; k < c.size() && valid; k++) {
                    if(cur.size() > 0 && c[j][cur.back()]) valid = false;
                }
                if(valid) {
                    cur.push_back(j);
                    dfs(c, colors, cur, res, ans, i | (1 << j), n);
                    cur.pop_back();
                }
            }
        }
    }
}

int main() {
    // Read in the total number of test cases
    int t; cin >> t;
    // Loop through each test case
    while(t--) {
        // Read in the total number of colors
        int n; cin >> n;
        // Initialize vector of colors and map of colors to index
        vector<string> v(n), vn;
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            mp[v[i]] = i;
        }
        // Read in the total number of constraints
        int m; cin >> m;
        unordered_map<int, unordered_map<int, int>> c;
        for(int i = 0; i < m; i++) {
            string a, b; cin >> a >> b;
            int u = mp[a], v = mp[b];
            c[u][v] = 1;
            c[v][u] = 1;
        }
        // Initialize the result values and a current array for tracking paths in DFS
        vector<int> cur, res;
        int ans = 0;
        // DFS to populate the result array
        dfs(c, v, cur, res, ans, 0, n);
        // Report the total paintings and the best painting
        cout << ans << endl;
        for(int i = 0; i < res.size(); i++) {
            cout << v[res[i]] << " ";
        }
        cout << endl;
    }
    // Return exit code
    return 0;
}