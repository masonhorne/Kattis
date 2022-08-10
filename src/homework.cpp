#include<iostream>
#include<string>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/heimavinna /
/////////////////////////////////////////////////////////

int main() {
    // Read input string
    string s; cin >> s;
    // Initialize count to 0
    int count = 0;
    // Read through input
    for(int i = 0; i < s.size(); i++) {
        // Initialize start value to 0
        int start = 0;
        // Build start value from input
        while(i < s.size() && '0' <= s[i] && s[i] <= '9') {
            start *= 10;
            start += s[i] - '0';
            i++;
        }
        // If next character is a dash, build the intervals end
        if(s[i] == '-'){
            i++;
            // Initialize the end to 0
            int end = 0;
            // Build the end from input
            while(i < s.size() && '0' <= s[i] && s[i] <= '9'){
                end *= 10;
                end += s[i] - '0';
                i++;
            }
            // Add the intervals range to the count
            count += end - start + 1;
        // Otherwise increment the count for the one value
        } else count++;
    }
    // Output the resulting number of questions
    cout << count << endl;
    // Return exit code
    return 0;
}