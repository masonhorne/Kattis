#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/dyslectionary /
////////////////////////////////////////////////////////////

// Max helper function
int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    // Boolean to handle fence post separators
    bool f = true;
    while(!cin.eof()){
        // Handle separators
        if(f) f = false;
        else cout << endl;
        // Read input line
        string s; getline(cin, s);
        // Initialize list
        vector<string> v;
        // Initialize max
        int mx = 0;
        // Read until blank line
        while(s.size()){
            // Updating max length if needed
            mx = max(mx, s.size());
            // Reverse the string
            for(int i = 0; i < s.size() / 2; i++){
                int tmp = s[i];
                s[i] = s[s.size() - i - 1];
                s[s.size() - i - 1] = tmp;
            }
            // Add to list
            v.push_back(s);
            // Get next line
            getline(cin, s);
        }
        // Sort the list
        sort(v.begin(), v.end());
        // Loop through outputting sorted values
        for(int i = 0; i < v.size(); i++){
            // Reverse the value
            for(int j = 0; j  < v[i].size() / 2; j++){
                int tmp = v[i][j];
                v[i][j] = v[i][v[i].size() - j - 1];
                v[i][v[i].size() - j - 1] = tmp;
            }
            // Output right aligned
            cout << setw(mx) << v[i] << endl;
        }
    }
    // Return exit code
    return 0;
}