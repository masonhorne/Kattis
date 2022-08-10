#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/jackolanternjuxtaposition /
////////////////////////////////////////////////////////////////////////

int main() {
    // Read in all different design counts
    int n, t, m; cin >> n >> t >> m;
    // Output all possible combinations
    cout << n * t * m << endl;
    // Return exit code
    return 0;
}