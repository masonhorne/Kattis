#include<iostream>
#include<string>
using namespace std;

//////////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/detaileddifferences /
//////////////////////////////////////////////////////////////////

int main() {
    // Read in total test case count
    int t; cin >> t;
    // Process each test case
    while(t--){
        // Read in both input strings for test
        string a, b; cin >> a >> b;
        // Initialize result string
        string res = "";
        // Loop through inputs creating result
        for(int i = 0; i < b.size(); i++)
            // If mismatch output * otherwise .
            if(a[i] != b[i]) res += '*';
            else res += '.';
        // Output the input strings then the resulting string
        cout << a << endl << b << endl << res << endl << endl;
    }
    // Return exit code
    return 0;
}