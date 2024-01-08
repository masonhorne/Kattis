#include<iostream>
#include<vector>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/overdraft /
////////////////////////////////////////////////////////

int main() {
    // Read the input size
    int n; cin >> n;
    // Initialize a balance and answer
    int b = 0, ans = 0;
    // Read all inputs
    while(n--) {
        // Update the balance to this value
        int v; cin >> v;
        b += v;
        // Update the result if a new minimum balance was found
        ans = min(ans, b);
    }
    // Output the opposite of the most negative balance
    cout << -ans << endl;
    // Return exit code
    return 0;
}