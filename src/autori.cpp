#include <iostream>
#include <string>
using namespace std;

/////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/autori /
/////////////////////////////////////////////////////

int main() {
    // Read input from stdin
    string input; cin >> input;
    // Initialize result to first character
    string result;
    result += input[0];
    // Loop through and add characters following - to result
    for(int i = 1; i < input.size(); i++) {
        if(input[i - 1] == '-') 
            result += input[i];
    }
    // Output the result
    cout << result << endl;
    // Return exit code
    return 0;
}