#include<iostream>
using namespace std;

////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/zamka /
////////////////////////////////////////////////////

int main() {
    // Read in range and target value
    int l, d, x; cin >> l >> d >> x;
    // Set min and max values for indices with target values
    int mn = 10000, mx = 0;
    // Loop through the range
    for(int i = l; i <= d; i++){
        // Calculate sum of digits
        int v = i;
        int s = 0;
        while(v > 0){
            s += v % 10;
            v /= 10;
        }
        // Update min and max if equal to target
        if(s == x){
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    // Output target indices
    cout << mn << endl;
    cout << mx << endl;
    // Return exit code
    return 0;
}