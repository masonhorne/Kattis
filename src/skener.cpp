#include<iostream>
#include<string>
using namespace std;

/////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/skener /
/////////////////////////////////////////////////////

int main() {
    // Read in row and column along with change in both
    int r, c, dr, dc; cin >> r >> c >> dr >> dc;
    // Loop through all rows
    for(int i = 0; i < r; i++){
        // Read in default row and initialize updated
        string s; cin >> s;
        string a = "";
        // For each character in original, output change in column amount of that character
        for(int j = 0; j < s.size(); j++)
            for(int k = 0; k < dc; k++) a += s[j];
        // Then output the resulting string change in row times
        for(int j = 0; j < dr; j++) cout << a << endl;
    }
    // Return exit code
    return 0;
}