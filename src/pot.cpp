#include <iostream>
#include <cmath>
using namespace std;

//////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/pot /
//////////////////////////////////////////////////

int main () {
    // Read in number of input values
    int n; cin >> n;
    // Initialize total to 0
    int total = 0;
    // Loop through reading inputs and adding calculated value to total
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        total += pow(num / 10, num % 10);
    }
    // Output the result
    cout << total << endl;
    // Return exit code
    return 0;
}