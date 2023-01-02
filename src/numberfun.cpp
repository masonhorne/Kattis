#include<iostream>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/numberfun /
////////////////////////////////////////////////////////

int main() {
    // Read in the number of test cases
    int n; cin >> n;
    // Process all test cases
    while(n--){
        // Read in each value
        double a, b, c; cin >> a >> b >> c;
        // If any operation works, output possible
        if(a + b == c || a - b == c || b - a == c || a * b == c || b / a == c || a / b == c) cout << "Possible" << endl;
        // Otherwise output impossible
        else cout << "Impossible" << endl;
    }
    // Return exit code
    return 0;
}