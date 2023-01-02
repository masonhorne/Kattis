#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/fallingapart /
///////////////////////////////////////////////////////////

int main() {
    // Read in input size
    int n; cin >> n;
    // Initialize list
    vector<int> vals(n);
    // Read values into list
    for(int i = 0; i < n; i++) cin >> vals[i];
    // Sort the list in descending order
    sort(vals.begin(), vals.end(), [](const int a, const int b) {
        return a > b;
    });
    // Initialize counts
    int a = 0, b = 0;
    // Add each persons optimal choice
    for(int i = 0; i < n; i++)
        if(i % 2 == 0) a += vals[i];
        else b += vals[i];
    // Output the resulting values
    cout << a << " " << b << endl;
    // Return exit code
    return 0;
}