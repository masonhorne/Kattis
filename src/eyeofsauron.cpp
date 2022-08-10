#include<iostream>
#include<string>
using namespace std;

//////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/eyeofsauron /
//////////////////////////////////////////////////////////

int main() {
    // Read input string
    string s; cin >> s;
    // Initialize count and flag
    int c = 0, f = 1;
    // Proccess input by character
    for(int i = 0; i < s.size(); i++){
        // If wall character, update count
        if(s[i] == '|'){
            // Increase if before eye, decrease if after
            if(f) c++;
            else c--;
        // Otherwise set flag since in eye
        } else f = 0;
    }
    // Output if the correct number of walls were on the other side
    cout << (c == 0 ? "correct" : "fix") << endl;
    // Return exit code
    return 0;
}