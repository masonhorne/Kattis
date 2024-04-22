#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/dasblinkenlights /
///////////////////////////////////////////////////////////////

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

int main() {
    // Read in intervals and time length
    int p, q, s;
    cin >> p >> q >> s;
    // Output result if both blink at same time before limit
    cout << (lcm(p, q) <= s ? "yes" : "no") << endl;
    // Return exit code
    return 0;
}