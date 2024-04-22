#include<iostream>
#include<vector>
using namespace std;

///////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/disgruntledjudge /
///////////////////////////////////////////////////////////////

// Maximum value for a and b
const int MAX = 10000;

int next(int v, int a, int b) {
    // Next value in sequence
    return (v * a + b) % (MAX + 1);
}

vector<int> solve(vector<int> v) {
    // Iterate over all possible a and b values
    for(int a = 0; a <= MAX; a++){
        for(int b = 0; b <= MAX; b++){
            int v1 = next(next(v[0], a, b), a, b);
            int v2 = next(next(v1, a, b), a, b);
            // If these a and b values work, return them
            if(v[1] == v1 && v[2] == v2) return {a, b};
        }
    }
    // Return invalid values if no solution
    return {-1, -1};
} 

int main() {
    // Read in total numbers
    int n; cin >> n;
    // Read in all numbers
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    // Get a and b values and output results
    vector<int> coeffs = solve(v);
    // Output the resulting values with these coefficients
    for(int i = 0; i < v.size(); i++)
        cout << next(v[i], coeffs[0], coeffs[1]) << endl;
    // Return exit code
    return 0;
}