#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/howmanydigits /
////////////////////////////////////////////////////////////

int main() {
    // Array for keeping up with log10 of the index factorial
    vector<double> v(1e6 + 1);
    // Each index will have the log10 of the number itself plus its predecessors log10
    for(int i = 1; i <= 1e6; i++) v[i] = v[i - 1] + log10(i);
    // Read in input values and output the resulting counts
    int n;
    while(cin >> n) cout << ((int) v[n]) + 1 << endl;
    // Return exit code
    return 0;
}