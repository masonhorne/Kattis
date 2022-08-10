#include <iostream>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/fizzbuzz /
///////////////////////////////////////////////////////

int main() {
    // Read in fizz count, buzz count, and total count
    int x, y, n; cin >> x; cin >> y; cin >> n;
    // Loop through all values
    for(int i = 1; i <= n; i++){
        // If divisible by either output one of the two or both
        if(i % x == 0 || i % y == 0) cout << (i % x == 0 ? "Fizz" : "") <<  (i % y == 0 ? "Buzz" : "") << endl; 
        // Otherwise output the value
        else cout << i << endl;
    }
    // Return exit code
    return 0;
}