#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

////////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/travelingmerchant /
////////////////////////////////////////////////////////////////

void build(vector<int> &v, vector<vector<int>> &t, int i, int tl, int tr) {
    // If we are at a leaf node, store the value
    if(tl == tr) t[i] = {v[tl], v[tl], 0};
    else {
        // Otherwise calculate the middle
        int tm = tl + (tr - tl) / 2;
        // Recursively build the left and right side of the tree
        build(v, t, i * 2, tl, tm);
        build(v, t, i * 2 + 1, tm + 1, tr);
        // Retrieve the node values for the left and right subtrees
        vector<int> l = t[i * 2], r = t[i * 2 + 1];
        // Calculate the potential profit of a merge
        int mergedProfit = r[1] - l[0];
        // Store the result node with minimum cost, maximum cost, and maximum profit
        t[i] = {min(l[0], r[0]), max(l[1], r[1]), max(mergedProfit, max(r[2], l[2]))};
    }
}

vector<int> query(vector<vector<int>> &t, int i, int tl, int tr, int l, int r) {
    // If invalid range, return -1
    if(l > r) return {0, 0, -1};
    // If our tree range matches the range, return the nodes value
    if(l == tl && r == tr) return t[i];
    // Otherwise calculate the middle
    int tm = tl + (tr - tl) / 2;
    // Query the left and right side of the tree
    vector<int> ql = query(t, i * 2, tl, tm, l, min(r, tm));
    vector<int> qr = query(t, i * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    // If one of the queries is invalid, return the other
    if(ql[2] == -1) return qr;
    if(qr[2] == -1) return ql;
    // Calculate the potential profit of a merge
    int mergedProfit = qr[1] - ql[0];
    // Return the result node with minimum cost, maximum cost, and maximum profit
    return {min(ql[0], qr[0]), max(ql[1], qr[1]), max(mergedProfit, max(ql[2], qr[2]))};
}

int main() {
    // Read in the total count of cities to visit
    int n; cin >> n;
    // Read in the city start pricing and their price deltas
    vector<int> v(n), d(n);
    for(int i = 0; i < n; i++) cin >> v[i] >> d[i];
    // Read the queries into a list
    int q; cin >> q;
    vector<vector<int>> queries;
    while(q--) {
        int l, r; cin >> l >> r;
        queries.push_back({l - 1, r - 1});
    }
    // Initialize our result vector
    vector<int> res(queries.size());
    // Loop through all possible 7 starting days
    for(int i = 0; i < 7; i++) {
        // Create two lists of the values one of which is reversed for traveling backwards
        vector<int> vn(v);
        vector<int> vn2(v);
        reverse(vn2.begin(), vn2.end());
        // Loop through calculating what the cost will be on the day we visit this city
        for(int j = 0; j < vn.size(); j++){
            int offset = abs(j - i) % 7;
            if(offset == 0) vn[j] = vn[j], vn2[j] = vn2[j];
            if(offset == 1) vn[j] = vn[j] + d[j], vn2[j] = vn2[j] + d[n - 1 - j];
            if(offset == 2) vn[j] = vn[j] + d[j] * 2, vn2[j] = vn2[j] + d[n - 1 - j] * 2;
            if(offset == 3) vn[j] = vn[j] + d[j] * 3, vn2[j] = vn2[j] + d[n - 1 - j] * 3;
            if(offset == 4) vn[j] = vn[j] + d[j] * 2, vn2[j] = vn2[j] + d[n - 1 - j] * 2;
            if(offset == 5) vn[j] = vn[j] + d[j], vn2[j] = vn2[j] + d[n - 1 - j];
            if(offset == 6) vn[j] = vn[j], vn2[j] = vn2[j];
        }
        // Build a segment tree for the forward list
        vector<vector<int>> t(4 * n);
        build(vn, t, 1, 0, n - 1);
        // Query all the queries for the forward list that start on this day
        for(int j = 0; j < queries.size(); j++){
            if(queries[j][0] % 7 == i && queries[j][0] < queries[j][1]) {
                vector<int> ans = query(t, 1, 0, n - 1, queries[j][0], queries[j][1]);
                res[j] = ans[2] == -1 ? 0 : ans[2];
            }
        }
        // Build a segment tree for the reverse list
        t = vector<vector<int>>(4 * n);
        build(vn2, t, 1, 0, n - 1);
        // Query all the queries for the reverse list that start on this day
        for(int j = 0; j < queries.size(); j++){
            int l = n - 1 - queries[j][0], r = n - 1 - queries[j][1];
            if(l % 7 == i && l < r) {   
                vector<int> ans = query(t, 1, 0, n - 1, l, r);
                res[j] = ans[2] == -1 ? 0 : ans[2];
            }
        }
    }
    // Output the results
    for(int i = 0; i < res.size(); i++) cout << res[i] << endl;
    // Return exit code
    return 0;
}