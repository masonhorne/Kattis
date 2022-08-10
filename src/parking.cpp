#include<iostream>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/parking2 /
///////////////////////////////////////////////////////

int main() {
    // Read total test cases
    int t; cin >> t;
    while(t--){
        // Read in the number of stores
        int n; cin >> n;
        // Calculate the min and max store
        int mn = 100;
        int mx = 0;
        for(int i = 0; i < n; i++){
            int v; cin >> v;
            mn = min(mn, v);
            mx = max(mx, v);
        }
        // Output the distance from min to max * 2 since must traverse to and from each
        cout << (mx - mn) * 2 << endl;
    }
    return 0;
}