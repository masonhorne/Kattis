#include <iostream>
using namespace std;

/////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/faktor /
/////////////////////////////////////////////////////

int main() {
    // Read in the articles published and score needed
    int a, i; cin >> a >> i;
    // Output the total needed minus the planned amount (exluding self)
    cout << (i * a) - (a - 1) << endl;
    // Return exit code
    return 0;
}