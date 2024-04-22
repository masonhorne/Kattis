#include<iostream>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/beekeeper /
////////////////////////////////////////////////////////

bool isVowel(char ch) {
    // Return true if the character is a vowel
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

int duplicates(string s) {
    // Initialize the count of adjacent duplicate vowels to 0
    int cnt = 0;
    for(int i = 0; i < s.size() - 1; i++){
        // Count the duplicates that are vowels
        if(isVowel(s[i]) && s[i] == s[i+1]) {
            cnt++;
            i++;
        }
    }
    // Return the total count of the adjacent duplicate vowels
    return cnt;
}

int main() {
    // Read in the number of words
    int n;
    while(cin >> n && n != 0) {
        // Loop through and find the word with the most adjacent duplicate vowels
        string res;
        int resCount = -1;
        while(n--){
            string s; cin >> s;
            int cnt = duplicates(s);
            // Store as result if this word has more adjacent duplicate vowels
            if(cnt > resCount) {
                resCount = cnt;
                res = s;
            }
        }
        // Output the word with the most adjacent duplicate vowels
        cout << res << endl;
    }
    // Return exit code
    return 0;
}