#include <iostream>
using namespace std;

///////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/cold /
///////////////////////////////////////////////////

int main() {
    // Read in number of tempuratures and initialize count to 0
    int n; cin >> n;
    int count = 0;
    // Loop through reading inputs and incrementing count if negative
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        if(temp < 0) count++;
    }
    // Output the count
    cout << count << endl;
    // Return exit code
    return 0;
}