#include <iostream>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/timeloop /
///////////////////////////////////////////////////////

int main() {
    // Read input value
    int n; cin >> n;
    // Output abracadabra with index in front of it
    for(int i = 1; i <= n; i++) cout << i << " Abracadabra" << endl;
    // Return exit code
    return 0;
}