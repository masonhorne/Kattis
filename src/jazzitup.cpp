#include<iostream>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/jazzitup /
///////////////////////////////////////////////////////

int findNotes(int n) {
    // Try all possible notes and return the first one that works
    for(int m = 2; m < n; m++) {
        bool valid = true;
        // If any squre divides the product of m and n, then it is not valid
        for(int k = 2; k * k <= m * n && valid; k++){
            if(((m * n) % (k * k)) == 0) valid = false;
        }
        if(valid) return m;
    }
    // If no note works, return -1
    return -1;
}

int main() {
    // Read in the number of beats
    int n; cin >> n;
    // Output the first note count that works
    cout << findNotes(n) << endl;
    // Return exit code
    return 0;
}