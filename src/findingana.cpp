#include <iostream>
#include <string>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/findingana /
/////////////////////////////////////////////////////////

int main() {
    // Read in the input string
    string s; cin >> s;
    // Initialize index to 1
    int i = 1;
    // Loop while previous isn't equal to a
    while(s[i - 1] != 'a') i++;
    // Output the subtring to the end from this index
    cout << s.substr(i - 1, s.size() - i + 1) << endl;
    // Return exit code
    return 0;
}