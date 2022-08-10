#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/countthevowels /
/////////////////////////////////////////////////////////////

int main() {
    // Read line of input
    string s; getline(cin, s);
    // Initialize count to 0
    int c = 0;
    // Process all characters
    for(int i = 0; i < s.size(); i++)
        // If character is vowel increment the count
        if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
            c++;
    // Output the total number of vowels
    cout << c << endl;
    // Return exit code
    return 0;
}