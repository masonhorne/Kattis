#include<iostream>
#include<string>
using namespace std;

//////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/drmmessages /
//////////////////////////////////////////////////////////

int main() {
    // Read input string
    string s; cin >> s;
    // Calculate size of halves
    int n = s.size() / 2;
    // Sum the characters of each string
    int r1 = 0;
    int r2 = 0;
    for(int i = 0; i < n; i++){
        r1 += s[i] - 'A';
        r2 += s[i + n] - 'A';
    }
    // Mod the shift by 26
    r1 %= 26;
    r2 %= 26;
    // Loop through updating values by the shift
    for(int i = 0; i < n; i++){
        s[i] = ((s[i] - 'A' + r1) % 26) + 'A';
        s[i + n] = ((s[i + n] - 'A' + r2) % 26) + 'A';
    }
    // Build the resulting string from merge
    string ans;
    for(int i = 0; i < n; i++)
        ans += ((s[i] - 'A' + s[i + n] - 'A') % 26) + 'A';
    // Output resulting string
    cout << ans << endl;
    // Return exit code
    return 0;
}