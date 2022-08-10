#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/speedlimit /
/////////////////////////////////////////////////////////

int main() {
    // Read in number of test cases
    int t; cin >> t;
    // Process test cases
    while(t != -1) {
        // Initialize sum to first speed and prev to first time
        int sum; cin >> sum;
        int prev; cin >> prev;
        // Multiply sum by time for initial distance
        sum *= prev;
        // Decrement t for first variable
        t--;
        // Add remaining distances
        while(t--){
            int s, d; cin >> s >> d;
            sum += s * (d - prev);
            prev = d;
        }
        // Output the total
        cout << sum << " miles" << endl;
        // Read in next test case
        cin >> t;
    }
    // Return exit code
    return 0;
}