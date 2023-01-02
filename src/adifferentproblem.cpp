#include<iostream>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/different /
////////////////////////////////////////////////////////

int main() {
    // Initialize a and b variables
    long long a, b;
    // Read until eof
    while(cin >> a){
        // Read in second value
        cin >> b;
        // Output absolute difference of the two
        cout << abs(a - b) << endl;
    }
    // Return exit code
    return 0;
}