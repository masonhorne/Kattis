#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/kornislav /
////////////////////////////////////////////////////////

int main() {
    // Initialize vector to store moves
    vector<int> m(4);
    // Read in moves
    for(int i = 0; i < 4; i++) cin >> m[i];
    // Sort moves in ascending order
    sort(m.begin(), m.end());
    // Output the minimum multiplied by the second to max value (largest enclosed area)
    cout << m[0] * m[2] << endl;
    // Return exit code
    return 0;
}