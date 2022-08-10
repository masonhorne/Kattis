#include <iostream>
#include <iomanip>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/grassseed /
////////////////////////////////////////////////////////

int main() {
    // Read in cost per square meter
    long double c; cin >> c;
    // Read in number of lawns to mow
    int n; cin >> n;
    // Initialize total square meters to 0
    long double t = 0;
    // Loop through all lawns
    for(int i = 0; i < n; i++) {
        // Read in with and length
        long double w, l; cin >> w; cin >> l;
        // Add area to total
        t += w * l;
    }
    // Set precision and output value
    cout.precision(7);
    cout << fixed << t * c << endl;
    // Return exit code
    return 0;
}