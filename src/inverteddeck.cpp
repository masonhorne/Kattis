#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/inverteddeck /
///////////////////////////////////////////////////////////

int main() {
    // Initialize input list
    int n; cin >> n;
    vector<int> v;
    while(n--) {
        int c; cin >> c;
        v.push_back(c);
    }
    // Initialize sorted version of input
    vector<int> sv = v;
    sort(sv.begin(), sv.end());
    // Find leftmost point that doesn't match
    int l = 0, r = v.size() - 1;
    while(l < v.size() && v[l] == sv[l]) l++;
    // If equal, return middle element for both endpoints
    if(l == v.size()) l = r = v.size() / 2;
    else {
        // Otherwise find the rightmost position where different
        while(v[r] == sv[r]) r--;
        reverse(v.begin() + l, v.begin() + r + 1);
    }
    // Output the range or impossible based on match
    cout << (v == sv ? to_string(l + 1) + " " + to_string(r + 1) : "impossible") << endl;
    // Return exit code
    return 0;
}