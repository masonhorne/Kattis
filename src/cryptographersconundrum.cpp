#include<iostream>
#include<string>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/conundrum /
////////////////////////////////////////////////////////

int main() {
    // Read input string
    string s; cin >> s;
    // Initialize count as 0
    int c = 0;
    // Process in groups of 3
    for(int i = 0; i < s.size(); i += 3){
        // Add to count for each mismatched characters
        c += s[i] != 'P';
        c += s[i + 1] != 'E';
        c += s[i + 2] != 'R';
    }
    // Output the count
    cout << c << endl;
    // Return exit code
    return 0;
}