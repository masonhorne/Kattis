#include<iostream>
using namespace std;

/////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/ignore /
/////////////////////////////////////////////////////

string fn(int n) {
    // Initialize the resulting number
    string ans = "";
    // Convert to base 7 adding digits as you go
    while(n > 0) {
        int d = n % 7;
        n /= 7;
        // Digits based on base 7 parity
        if(d == 0) ans += '0';
        if(d == 1) ans += '1';
        if(d == 2) ans += '2';
        if(d == 3) ans += '5';
        if(d == 4) ans += '9';
        if(d == 5) ans += '8';
        if(d == 6) ans += '6';
    }
    // Return the resulting number
    return ans;
}

int main() {
    // Initialize variable for reading input
    int n;
    // Loop through outputting resulting numbers
    while(cin >> n) cout << fn(n) << endl;
    // Return exit code
    return 0;
}