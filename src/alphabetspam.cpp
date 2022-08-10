#include<iostream>
#include<string>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/alphabetspam /
///////////////////////////////////////////////////////////

int main() {
    // Initialize all counts to 0
    double ws = 0, lc = 0, uc = 0, sy = 0;
    // Read input string
    string s; cin >> s;
    // Processes string into character type counts
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '_') ws++;
        else if('a' <= s[i] && s[i] <= 'z') lc++;
        else if('A' <= s[i] && s[i] <= 'Z') uc++;
        else sy++;
    }
    // Set output precision
    cout.precision(12);
    // Output all decimal values
    cout << ws / s.size() << endl;
    cout << lc / s.size() << endl;
    cout << uc / s.size() << endl;
    cout << sy / s.size() << endl;
    // Return exit code
    return 0;
}