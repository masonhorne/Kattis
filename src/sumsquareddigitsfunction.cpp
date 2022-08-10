#include<iostream>
#include<cmath>
using namespace std;

///////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/sumsquareddigits /
///////////////////////////////////////////////////////////////

int main() {
    // Read in number of test cases
    int t; cin >>t;
    // Process test cases
    while(t--){
        // Read in test case base and value
        int k, b, n; cin >> k >> b >> n;
        int s = 0;
        while(n > 0){
            // Get digit from base
            int d = n % b;
            // Remove digit from base
            n /= b;
            // Add square of digit to sum
            s += d * d;
        }
        // Output test case and sum of squared digits
        cout << k << " " << s << endl;
    }
    // Return exit code
    return 0;
}