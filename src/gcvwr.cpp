#include<iostream>
using namespace std;

////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/gcvwr /
////////////////////////////////////////////////////

int main() {
    // Read in gcvwr
    double g; cin >> g;
    // Read in truck weight and number of items
    int t, n; cin >> t >> n;
    // Set gcvwr to 90% of amount left after towing truck
    g = (g - t) * 0.9;
    // Initialize sum of 0
    int s = 0;
    // Read in sum
    while(n--){
        int v; cin >> v;
        s += v;
    }
    // Output the amount left after items
    cout << g - s << endl;
    // Return exit code
    return 0;
}