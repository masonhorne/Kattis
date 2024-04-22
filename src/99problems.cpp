#include<iostream>
#include<vector>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/99problems /
/////////////////////////////////////////////////////////

int main() {
    // Initialize our price
    int n; cin >> n;
    // Initialize a vector for storing candidate values in descending order
    vector<int> v;
    for(int i = 99; i >= -99; i--) {
        if((n + i) % 100 == 99) v.push_back(n + i);
    }
    // Initialize our result to a value outside of bounds
    int ans = 1e9;
    // Find the closest value
    for(int i : v) {
        if(abs(n - ans) > abs(n - i)) ans = i;
    }
    // Output the new cost
    cout << ans << endl;
    // Return exit code
    return 0;
}