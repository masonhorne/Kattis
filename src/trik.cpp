#include<iostream>
#include<string>
using namespace std;

///////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/trik /
///////////////////////////////////////////////////

int main() {
    // Read input string
    string s; cin >> s;
    // Initialize cups with ball in leftmost
    int l = 1, m = 0, r = 0;
    // Read input string
    for(int i = 0; i < s.size(); i++)
        // Move ball between cups
        if(s[i] == 'A') swap(l, m);
        else if(s[i] == 'B') swap(m, r);
        else swap(l, r);
    // Output the value for the cup the ball is in
    cout << (l == 1 ? 1 : (m == 1 ? 2 : 3)) << endl;
    // Return exit code
    return 0;
}