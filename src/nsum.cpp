#include<iostream>
using namespace std;

///////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/nsum /
///////////////////////////////////////////////////

int main() {
    // Read input value count
    int n; cin >> n;
    // Initialize total to 0
    int t = 0;
    // Read in all values and add to total
    while(n--){
        int v; cin >> v;
        t += v;
    }
    // Output total
    cout << t << endl;
    // Return exit code
    return 0;
}