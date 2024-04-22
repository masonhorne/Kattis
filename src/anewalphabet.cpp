#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/anewalphabet /
///////////////////////////////////////////////////////////

int main() {
    // Initialize a map of the characters to their new strings
    unordered_map<char, string> alphabet = {
        {'a', "@"},
        {'b', "8"},
        {'c', "("},
        {'d', "|)"},
        {'e', "3"},
        {'f', "#"},
        {'g', "6"},
        {'h', "[-]"},
        {'i', "|"},
        {'j', "_|"},
        {'k', "|<"},
        {'l', "1"},
        {'m', "[]\\/[]"},
        {'n', "[]\\[]"},
        {'o', "0"},
        {'p', "|D"},
        {'q', "(,)"},
        {'r', "|Z"},
        {'s', "$"},
        {'t', "']['"},
        {'u', "|_|"},
        {'v', "\\/"},
        {'w', "\\/\\/"},
        {'x', "}{"},
        {'y', "`/"},
        {'z', "2"}
    };
    // Read in the input
    string s;
    getline(cin, s);
    // Convert the input to the new format
    string ans;
    for (char c : s) {
        if (isalpha(c)) ans += alphabet[tolower(c)];
        else ans += c;
    }
    // Output the new string
    cout << ans << endl;
    // Return exit code
    return 0;
}