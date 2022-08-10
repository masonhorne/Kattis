#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/ultimatebinarywatch /
//////////////////////////////////////////////////////////////////

int main() {
    // Read in digits
    int n; cin >> n;
    // Initialize arrays to contain bits
    int bits[4][4];
    // Loop through digits
    for(int i = 0; i < 4; i++){
        // Get digit
        int digit = n % 10;
        // Remove from number
        n /= 10;
        // Add bits to array
        for(int j = 0; j < 4; j++){
            bits[i][j] = digit & 1;
            digit >>= 1;
        }
    }
    // Loop through outputting the high order to low order bits in the correct order
    for(int i = 3; i >= 0; i--) cout << (bits[3][i] ? '*' : '.') << " " << (bits[2][i] ? '*' : '.') << "   " << (bits[1][i] ? '*' : '.') << " " << (bits[0][i] ? '*' : '.') << endl;
    // Return exit code
    return 0;
}