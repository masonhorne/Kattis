#include<iostream>
using namespace std;

///////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/smil /
///////////////////////////////////////////////////

int main() {
    // Read input string
    string s; cin >> s;
    // Process characters
    for(int i = 0; i < s.size() - 1; i++){
        // If character is start of smile
        if(s[i] == ':' || s[i] == ';'){
            // If next is end of smile output index and move on
            if(s[i + 1] == ')'){
                cout << i << endl;
                i += 1;
            // Otherwise if can check another character forward, see if it has a nose smile
            } else if(i + 2 < s.size()){
                if(s[i + 1] == '-' && s[i + 2] == ')') {
                    cout << i << endl;
                    i = i + 2;
                }
            }
        }
    }
    // Return exit code
    return 0;
}