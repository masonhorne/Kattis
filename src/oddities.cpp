#include <iostream>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/oddities /
///////////////////////////////////////////////////////

int main() {
    // Read in number of test cases
    int n; cin >> n;
    // Process each test case
    for(int i = 0; i < n; i++) {
        // Read in the number
        int num; cin >> num;
        // If even output even
        if(num % 2 ==0) cout << num << " is even" << endl;
        // Otherwise output odd
        else cout << num << " is odd" << endl;
    }
    // Return exit code
    return 0;
}