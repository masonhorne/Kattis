#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/lockout /
//////////////////////////////////////////////////////

int main() {
    // Initialize our world count and a running sum for all coins possible
    int n; cin >> n;
    long s = 0;
    // Initialize our value and time vectors
    vector<int> v(n), t(n);
    // Loop through values adding to sum
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        s += v[i];
    }
    // Loop through reading times
    for(int i = 0; i < n; i++) cin >> t[i];
    // Initialize our list luigi visits
    vector<int> l(n);
    // Loop through decrementing id
    for(int i = 0; i < n; i++) {
        cin >> l[i];
        l[i]--;
    }
    // Initialize a pointer and count all worlds worth going 50/50 with
    int p = 0;
    while(p < n && s - v[l[p]] <= v[l[p]]) s -= v[l[p++]];
    // Output the total probability of winning
    cout << 1.0 / pow(2, p) << endl;
    // Output the world we 50/50 on
    for(int i = 0; i < p; i++) {
        cout << l[i] + 1 << " ";
    }
    // Output the worlds we skip ahead on
    for(int i = p + 1; i < n; i++){
        cout << l[i] + 1 << " ";
    }
    // If available, output the world we diverged paths on
    if(p < n) cout << l[p] + 1 << endl;
    // Return exit code
    return 0;
}