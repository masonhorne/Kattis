#include<iostream>
using namespace std;

////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/filip /
////////////////////////////////////////////////////

int main() {
    // Read input
    int a, b; cin >> a >> b;
    // Initialize numbers to store reverse
    int ua = 0, ub = 0;
    // Build reverse
    while(a != 0){
        ua *= 10;
        ub *= 10;
        ua += a % 10;
        ub += b % 10;
        b /= 10;
        a /= 10;
    }
    // Output the greater of the two
    cout << (ua > ub ? ua : ub) << endl;
    // Return exit code
    return 0;
}