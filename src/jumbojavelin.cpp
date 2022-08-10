#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/jumbojavelin /
///////////////////////////////////////////////////////////

int main() {
    // Read in total rods
    int n; cin >> n;
    // Initialize total to 1 (to account for removal on the first rod that doesn't occur)
    int t = 1;
    // Add all rods with adjusted length to total
    while(n--){
        int v; cin >> v;
        t += v - 1;
    }
    // Output the total
    cout << t << endl;
    // Return exit code
    return 0;
}