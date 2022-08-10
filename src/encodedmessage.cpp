#include<iostream>
#include<string>
#include<cmath>
using namespace std;

/////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/encodedmessage /
/////////////////////////////////////////////////////////////

int main() {
    // Read in number of test cases
    int t; cin >> t;
    // Process test cases
    while(t--){
        // Read in string and calculate grid dimensions
        string s; cin >> s;
        int n = sqrt(s.size());
        // Populate matrix with string
        char encoded[n][n];
        for(int i = 0, k = 0; i < n; i++)
            for(int j = 0; j < n; j++, k++)
                encoded[i][j] = s[k];
        // Horizontal flip matrix
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n / 2; j++)
                swap(encoded[i][j], encoded[i][n - j - 1]);
        // Transpose matrix
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++) 
                swap(encoded[i][j], encoded[j][i]);
        // Retrieve decoded message
        string ans = "";
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ans += encoded[i][j];
        // Output decoded string
        cout << ans << endl;
    }
    // Return exit code
    return 0;
}