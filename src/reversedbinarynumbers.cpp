#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/reversebinary /
////////////////////////////////////////////////////////////

int main() {
    // Read input number
    int n; cin >> n;
    // Initialize result number
    int v = 0;
    // Process all bits in input number
    while(n != 0){
        // Shift result to left
        v <<= 1;
        // Add low order bit
        v |= (n & 1);
        // Shift lower order bit out
        n >>= 1;
    }
    // Output the resulting value
    cout << v << endl;
    // Return exit code
    return 0;
}