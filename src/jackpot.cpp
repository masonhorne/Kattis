#include<iostream>
#include<vector>
using namespace std;

//////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/jackpot /
//////////////////////////////////////////////////////

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

long lcm(vector<int> v) {
    // Initialize lcm to first value
    long res = v[0];
    // Iterate over all others for remaining lcms
    for(int i = 1; i < v.size(); i++) {
        res = res * v[i] / gcd(res, v[i]);
        // If over 1 billion, return -1
        if(res > 1e9) return -1;
    }
    // Return final lcm
    return res;
}

int main() {
    // Read in total machines
    int n; cin >> n;
    while(n--) {
        // Get total wheels for machine
        int w; cin >> w;
        // Read in wheel periods
        vector<int> v(w);
        for(int i = 0; i < w; i++) cin >> v[i];
        // Get lcm of all wheel periods
        long d = lcm(v);
        // Output result
        cout << (d == -1 ? "More than a billion." : to_string(d)) << endl;
    }
    // Return exit code
    return 0;
}