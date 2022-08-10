#include<iostream>
#include<string>
using namespace std;

////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/avion /
////////////////////////////////////////////////////

int main() {
    // Initialize found flag to false
    bool f = false;
    // Loop through all inputs
    for(int i = 1; i < 6; i++){
        // Read input
        string s; cin >> s;
        // Scan for the substring
        for(int j = 0; j < s.size() - 2; j++)
            // If found mark found flag and output row
            if(s[j] == 'F' && s[j + 1] == 'B' && s[j + 2] == 'I'){
                f = true;
                cout << i << endl;
            }
    }
    // If found was never set to true output message
    if(!f) cout << "HE GOT AWAY!" << endl;
    // Return exit code
    return 0;
}