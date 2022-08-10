#include <iostream>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/twostones /
////////////////////////////////////////////////////////

int main() {
    // Read input value
    int n; cin >> n;
    // Output value based on how many remain after as many sets of 2 as possible were removed
    cout << (n % 2 == 0 ? "Bob" : "Alice") << endl;
    // Return exit code
    return 0;
}