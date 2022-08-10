#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/electricaloutlets /
////////////////////////////////////////////////////////////////

int main() {
    // Read in total test cases
    int t; cin >> t;
    // Process test cases
    while(t--){
        // Read total outlets
        int n; cin >> n;
        // Initialize appliances to zero since the one outlet plugs up first 
        int s = 0;
        // Chain outlets together
        while(n--){
            // Read total ports
            int v; cin >> v;
            // Add total minus 1 to plug in next
            s += v - 1;
        }
        // Output result plus 1 since final outlet didn't use its port
        cout << s + 1 << endl;
    }
    // Return exit code
    return 0;
}