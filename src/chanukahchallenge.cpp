#include <iostream>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/chanukah /
///////////////////////////////////////////////////////

int main() {
    // Read in input test cases
    int sets; cin >> sets;
    // Loop through processing each set
    for(int i = 0; i < sets; i++) {
        // Read in case number and number of days
        int round, days; cin >> round >> days;
        // 1 = first value, days = final value, 2.0 = offset from shamma, days = number of values
        int candles = (1 + days + 2.0) / 2 * days; // Sum of Arithmetic Series
        // Output the total candle count for number of days
        cout << round << ' ' << candles << endl;
    } 
    // Return exit code
    return 0;
}