#include<iostream>
#include<vector>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/oddgnome /
///////////////////////////////////////////////////////

int main () {
    // Read input size and iterate through test cases
    int n; cin >> n;
    while(n--) {
        // Store values in vector
        int c; cin >> c;
        vector<int> v;
        while(c--){
            int d; cin >> d;
            v.push_back(d);
        }
        // Iterate through and find first non-consecutive gnome
        int ans = -1;
        for(int i = 1; i < v.size() - 1 && ans == -1; i++)
            if(v[i] != v[i - 1] + 1) ans = i + 1;
        // Output this index
        cout << ans << endl;
    }
    // Return exit code
    return 0;
}