#include<iostream>
#include<string>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/kleptography /
///////////////////////////////////////////////////////////

int main (){
    // Read in key length and message length
    int n, m; cin >> n >> m;
    // Read in the key offset and encoded message
    string k, s; cin >> k >> s;
    // Add enough space for remainder of message to key
    k = string(m - n, ' ') + k;
    // Loop from end of the string up until the start of the special characters
    for(int i = m - 1; i > n - 1; i--) 
        // Calculate the values before the shift was applied
        k[i - n] = 'a' + (26 + s[i] - k[i]) % 26;
    // Output the decrypted message
    cout << k << endl;
    // Return exit code
    return 0;
}