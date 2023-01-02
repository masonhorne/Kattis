#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/egypt /
////////////////////////////////////////////////////

int main() {
    // Initialize a vector to store the side lengths
    vector<int> v(3);
    // Read in sides until the dummy final value
    while(cin >> v[0] >> v[1] >> v[2] && !(v[0] == 0 && v[1] == 0 && v[2] == 0)){
        // Sort the sides
        sort(v.begin(), v.end());
        // Output if the triangle is a right triangle or not
        cout << (v[2] * v[2] == v[1] * v[1] + v[0] * v[0] ? "right" : "wrong") << endl;
    }
    // Return exit code
    return 0;
}