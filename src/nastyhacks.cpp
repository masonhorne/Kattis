#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/nastyhacks /
/////////////////////////////////////////////////////////

int main() {
    // Read in test cases
    int n; cin >> n;
    while(n--){
        // Read in different profits
        int r, e, c; cin >> r >> e >> c;
        // If gain less than cost, don't advertise
        if(e - r < c) cout << "do not advertise" << endl;
        // If gain more than cost, advertise
        else if(e - r > c) cout << "advertise" << endl;
        // Otherwise it doesn't matter
        else cout << "does not matter" << endl;
    }
    // Return exit code
    return 0;
}