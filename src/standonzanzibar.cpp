#include<iostream>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/zanzibar /
///////////////////////////////////////////////////////

int main() {
    // Read in total test cases
    int t; cin >> t;
    // Process each test case
    while(t--){
        // Read in previous and next values
        int n, p; cin >> p >> n;
        // Initialize total non natives to 0
        int mx = 0;
        // Loop through all counts
        while(n != 0){
            // If gain is more than double, add the extra to non native gain
            if(n > p * 2) mx += n - p * 2;
            // Update previous and read in next
            p = n;
            cin >> n;
        }
        // Ouput the total number of non natives
        cout << mx << endl;
    }
    // Return exit code
    return 0;
}