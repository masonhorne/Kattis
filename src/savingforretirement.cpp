#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/savingforretirement /
//////////////////////////////////////////////////////////////////

int main() {
    // Read in the inputs
    int b, br, bs, a, as;
    cin >> b >> br >> bs >> a >> as;
    // Calculate the total savings for Bob
    int s = (br - b) * bs;
    // Output the age that alice can retire
    cout << (s / as + 1 + a) << endl;
    // Return exit code
    return 0;
}