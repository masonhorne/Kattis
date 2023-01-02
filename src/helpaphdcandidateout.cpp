#include<iostream>
#include<string>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/helpaphd /
///////////////////////////////////////////////////////

int main() {
    // Read in number of problems
    int n; cin >> n;
    // Process each problem
    while(n--){
        // Read in the input string
        string s; cin >> s;
        // If first character is P, output skipped
        if(s[0] == 'P') {
            cout << "skipped" << endl;
        } else {
            // Otherwise we need to build a and b from the string
            int a = 0, b = 0;
            // Set a flag for which variable we are building
            bool f = true;
            // Loop through the string
            for(int i = 0; i < s.size(); i++){
                // If encountering a +, set flag for next variable
                if(s[i] == '+') f = false;
                else {
                    // Otherise add digit to the appropriate value
                    if(f){
                        a *= 10;
                        a += s[i] - '0';
                    } else {
                        b *= 10;
                        b += s[i] - '0';
                    }
                }
            }
            // Output the sum of the values
            cout << a + b << endl;
        }
    }
    // Return exit code
    return 0;
}