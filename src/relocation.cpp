#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/relocation /
/////////////////////////////////////////////////////////

int main() {
    // Read in number of companies and queries
    int n, q; cin >> n >> q;
    // Initialize table for all locations
    int table[n];
    // Read all initial locations
    for(int i = 0; i < n; i++) cin >> table[i];
    // Process all queries
    while(q--){
        // Read query information
        int t, a, b; cin >> t >> a >> b;
        // Execute query based on type
        if(t == 1) table[a - 1] = b;
        else cout << abs(table[b - 1] - table[a - 1]) << endl;
    }
    // Return exit code
    return 0;
}