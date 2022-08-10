#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/echoechoecho /
///////////////////////////////////////////////////////////

int main() {
    // Read in the string
    string s; cin >> s;
    // Output the string 3 times
    cout << s << ' ' << s << ' ' << s << endl;
    // Return exit code
    return 0;
}