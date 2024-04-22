#include<iostream>
#include<vector>
using namespace std;

////////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/neighborhoodwatch /
////////////////////////////////////////////////////////////////

int main() {
    // Initialize the total houses and total number of security houses
    int n, k; cin >> n >> k;
    // Initialize a hash table for storing the houses information
    vector<int> v(n);
    // Loop through input marking the secure houses
    for(int i = 0; i < k; i++){
        int d; cin >> d;
        v[d - 1] = 1;
    }
    // Initialize a pointer into the houses and the result variable
    int p = 0;
    long ans = 0;
    for(int i = 0; i < n; i++) {
        // If we have a new secure house, all in section we just covered can go to the remaining
        if(v[i]) {
            // Houses before the secure (including the secure)
            long s = i - p + 1;
            // Houses after the secure house
            long e = n - i;
            // Total combinations of walks
            ans += s * e;
            // Update our pointer to not count this secure house again
            p = i + 1;
        }
    }
    // Output the total safety rating for the neighborhood
    cout << ans << endl;
    // Return exit code
    return 0;
}