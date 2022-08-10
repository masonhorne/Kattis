#include<iostream>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/ofugsnuid /
////////////////////////////////////////////////////////
int main() {
    // Read input count
    int n; cin >> n;
    // Back up input count
    int t = n;
    // Initialize value array
    int v[n];
    // Populate array from back to front
    while(n--) cin >> v[n];
    // Output the array values in order (now reversed)
    for(int i = 0; i < t; i++) cout << v[i] << endl;
    // Return exit code
    return 0;
}