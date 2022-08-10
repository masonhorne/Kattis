#include <iostream>
#include<vector>
using namespace std;

//////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/planina /
//////////////////////////////////////////////////////

int main() {
    // Read in value of n
    int n; cin >> n;
    // Initialize dp with base case of 0 being 2
    vector<int> dp(1, 2);
    // Loop up until n calculating the base that needs to be squared based on previous
    for(int i = 0; i < n; i++) dp.push_back(dp.back() * 2 - 1);
    // Output the final base squared
    cout << dp.back() * dp.back() << endl;
    // Return exit code
    return 0;
}