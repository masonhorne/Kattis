#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/birds /
////////////////////////////////////////////////////

typedef long long ll;

int main() {
    // Read input values
    ll l, d, n; cin >> l >> d >> n;
    // If no values output the total that can fit
    if(n == 0){
        cout << (l - 12) / d + 1 << endl;
    } else {
        // Otherwise greedily place them in the list
        // Initialize list of values
        vector<ll> v(n);
        // Read inputs to list
        for(int i = 0; i < n; i++) cin >> v[i];
        // Sort the list of locations
        sort(v.begin(), v.end());
        // Initialize the total to 0 and current spot to 6
        ll c = 0, cur = 6;
        // Process all birds
        for(int i = 0; i < n; i++){
            // Place birds until running into space of the next
            while(v[i] - cur >= d){
                cur += d;
                c++;
            }
            // Set the next spot to check after the space of this bird
            cur = v[i] + d;
        }
        // Now traverse up to the pole
        while(cur <= l - 6){
            c++;
            cur += d;
        }
        // Output the total number of birds
        cout << c << endl;
    }
    // Return exit code
    return 0;
}