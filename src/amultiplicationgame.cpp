#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/amultiplicationgame /
//////////////////////////////////////////////////////////////////

int main() {
    // Read in the goal number a create a variable for the current game number
    long n, p;
    while(cin >> n) {
        // Set their starting number to 1
        p = 1;
        // Loop until a winner is found
        while(p < n) {
            // Stan will rush to the number as fast as possible with 9
            p *= 9;
            if(p >= n) cout << "Stan wins." << endl;
            else {
                // Ollie will try to slow it down for a point where they can win by 9x
                p *= 2;
                if(p >= n) cout << "Ollie wins." << endl;  
            }
        }
    }
    // Return the exit code
    return 0;
}