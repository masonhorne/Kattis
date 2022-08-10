#include<iostream>
using namespace std;

/////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/tarifa /
/////////////////////////////////////////////////////

int main() {
    // Read input values
    int x, n; cin >> x >> n;
    // Initialize remaining data to 0
    int sum = 0;
    // Loop through all n values adding remainder from used to sum
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        sum += x - v;
    }
    // Output the sum plus the final months allowance
    cout << sum + x << endl;
    // Return exit code
    return 0;
}