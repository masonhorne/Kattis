#include<iostream>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/digitswap /
////////////////////////////////////////////////////////

int main() {
    // Read in input
    int n; cin >> n;
    // Initialize value to 0 and index to 2
    int v = 0, i = 2;
    // Process digits to reverse
    while(i--){
        v *= 10;
        v += n % 10;
        n /= 10;
    }
    // Output reverse
    cout << v << endl;
    // Return exit code
    return 0;
}