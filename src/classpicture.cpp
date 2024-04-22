#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/classpicture /
///////////////////////////////////////////////////////////

void dfs(vector<int> &cur, vector<int> &res, unordered_map<int, unordered_map<int, int>> &c, int i, int n) {
    // If the current list is full, update the result if needed
    if(cur.size() == n) {
        if(res.size() == 0) res = vector<int>(cur);
    } else {
        // Otherwise try placing the next best student basde on what we currently have
        for(int j = 0; j < n; j++) {
            if((i & (1 << j)) == 0) {
                if(cur.size() <= 0 || !c[j][cur.back()]) {
                    cur.push_back(j);
                    dfs(cur, res, c, i | (1 << j), n);
                    cur.pop_back();
                }
            }
        }
    }
}

int main() {
    // Initialize a variable for the total students count
    int n;
    // Loop while we have input classes
    while(cin >> n) {
        // Initialize a list of the student names
        vector<string> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        // Store their sorted order in the list
        sort(v.begin(), v.end());
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) mp[v[i]] = i;
        // Initialize a map of constraints for student placement
        int m; cin >> m;
        unordered_map<int, unordered_map<int, int>> c;
        for(int i = 0; i < m; i++) {
            string a, b; cin >> a >> b;
            int u = mp[a], v = mp[b];
            c[u][v] = 1;
            c[v][u] = 1;
        }
        // Initialize a current list for DFS and a result list for the optimal ordering
        vector<int> cur, res;
        // DFS to populate result
        dfs(cur, res, c, 0, n);
        // Output the result based on best ordering
        if(res.size() == 0) cout << "You all need therapy." << endl;
        else {
            for(int i = 0; i < res.size(); i++) {
                cout << v[res[i]] << " ";
            }
            cout << endl;
        }

    }
    // Return exit code
    return 0;
}