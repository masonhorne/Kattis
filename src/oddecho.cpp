#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/oddecho /
//////////////////////////////////////////////////////

int main() {
    // Read in number of words
    int n; cin >> n;
    // Loop through input words
    for(int i = 0; i < n; i++){
        // Read word
        string s; cin >> s;
        // If even number then output
        if(i % 2 == 0) cout << s << endl;
    }
    // Return exit code
    return 0;
}