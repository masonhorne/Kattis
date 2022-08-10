#include<iostream>
using namespace std;

///////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/qaly /
///////////////////////////////////////////////////

int main() {
    // Read in number of periods
    int n; cin >> n;
    // Initialize total
    double t = 0;
    // Process all periods onto total
    while(n--){
        double q, y; cin >> q >> y;
        t += q * y;
    }
    // Set precision and output
    cout.precision(7);
    cout << t << endl;
    // Return exit code
    return 0;
}