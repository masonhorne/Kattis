#include<iostream>
#include<string>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/isithalloween /
////////////////////////////////////////////////////////////

int main() {
    // Read in month name
    string s; cin >> s;
    // Read in day
    int d; cin >> d;
    // If one of the required days output yup
    if((s == "OCT" && d == 31) || (s == "DEC" && d == 25)) cout << "yup" << endl;
    // Otherwise output nope
    else cout << "nope" << endl;
    // Return exit code
    return 0;
}