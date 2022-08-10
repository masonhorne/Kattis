#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/laptopsticker /
////////////////////////////////////////////////////////////

int main() {
    // Read input dimensions
    int wc, hc, ws, hs; cin >> wc >> hc >> ws >> hs;
    // Output whether sticker fits on laptop
    cout << (wc >= ws + 2 && hc >= hs + 2 ? 1 : 0) << endl;
    // Return exit code
    return 0;
}