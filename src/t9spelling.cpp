#include<iostream>
#include<string>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/t9spelling /
/////////////////////////////////////////////////////////

int main() {
    // Lookup table for all characters
    string tbl[26] = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", 
    "6", "66", "666", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999","9999"};
    // Read in test case count
    int n; cin >> n;
    // Initialize string and read end of line
    string s;
    getline(cin, s);
    // Loop through all test cases
    for(int i = 1; i <= n; i++){
        // Get the input line to translate
        getline(cin, s);
        // Initialize the beginning of the line
        string ans = "Case #" + to_string(i) + ": ";
        // Loop through adding the appropriate key combinations to the string
        for(int j = 0; j < s.size(); j++){
            // Handle spaces since not mapped to hash table
            if(s[j] == ' '){
                // Add initial
                ans += "0";
                // If others follow print with spaces
                while(s[j + 1] == ' '){
                    ans += " 0";
                    j++;
                }
            // If on same key as previous character, add with a space
            } else if(ans[ans.size() - 1] == tbl[s[j] - 'a'][0]) ans += " " + tbl[s[j] - 'a'];
            // Otherwise just add the key combination
            else ans += tbl[s[j] - 'a'];
        }
        // Output the resulting string
        cout << ans << endl;
    }
    // Return exit code
    return 0;
}