#include<iostream>
using namespace std;

//////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/fyi /
//////////////////////////////////////////////////

int main() {
    // Read input value
    int n; cin >> n;
    // Divide out non area code digits
    n /= 10000;
    // Check if equal to 555
    cout << (n == 555 ? 1 : 0 ) << endl;
    // Return exit code
    return 0;
}