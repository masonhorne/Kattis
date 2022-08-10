#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/doublepassword /
/////////////////////////////////////////////////////////////

int main() {
    // Read input values
    int a, b; cin >> a >> b;
    // Initialize ways to 1
    int w = 1;
    // Loop through all 4 digits
    for(int i = 0; i < 4; i++){
        // Get the lowest order digit
        int d1 = a % 10;
        int d2 = b % 10;
        // Remove from numbers
        a /= 10;
        b /= 10;
        // If didn't match, two options for this digit so multiply ways by 2
        if(d1 != d2) w *= 2;
    }
    // Output the total ways
    cout << w << endl;
    // Return exit code
    return 0;
}