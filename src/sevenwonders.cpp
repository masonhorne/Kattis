#include<iostream>
#include<string>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/sevenwonders /
///////////////////////////////////////////////////////////

int main() {
    // Read input string
    string s; cin >> s;
    // Initialize counts of card types to 0
    int t = 0, c = 0, g = 0;
    // Count all cards
    for(int i = 0; i < s.size(); i++)
        if(s[i] == 'T') t++;
        else if(s[i] == 'C') c++;
        else if(s[i] == 'G') g++;
    // Output the score
    cout << t * t + c * c + g * g  + 7 * min(min(t, c), g) << endl;
    // Return exit code
    return 0;
}