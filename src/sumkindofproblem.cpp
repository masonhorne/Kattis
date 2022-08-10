#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/sumkindofproblem /
///////////////////////////////////////////////////////////////

int main() {
    // Read in test case count
    int t; cin >> t;
    // Process test cases
    while(t--){
        int k, n; cin >> k >> n;
        // Sum of arithmetic sequence for first n numbers
        int s1 = n * (1 + n) / 2;
        // Sum of arithmetic sequence for first n odd numbers
        int s2 = n * (2 * 1 + (n - 1) * 2) / 2;
        // Sum of arithmetic sequence for first n even numbers
        int s3 = n * (2 * 2 + (n - 1) * 2) / 2;
        // Output values
        cout << k << " " << s1 << " " << s2 << " " << s3 << endl;
    }
    // Return exit code
    return 0;
}