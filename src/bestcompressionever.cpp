#include<iostream>
#include<cmath>
using namespace std;

//////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/bestcompression /
//////////////////////////////////////////////////////////////

int main() {
    // Read in total documents and numbers of bits
    long n, b; cin >> n >> b;
    // Output yes if enough bits to enumerate no otherwise
    cout << (pow(2, b + 1) > n ? "yes" : "no") << endl;
    // Return exit code
    return 0;
}