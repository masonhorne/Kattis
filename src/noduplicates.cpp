#include<iostream>
#include<string>
#include<set>
using namespace std;

////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/nodup /
////////////////////////////////////////////////////

int main() {
    // Initialize string to read input and set to keep up with seen words
    string s;
    set<string> st;
    // Initialize valid flag to true
    bool f = true;
    // Loop while more words and is valid
    while(cin >> s && f){
        // If word is new add to seen
        if(st.find(s) == st.end()) st.insert(s);
        // Otherwise mark as invalid
        else f = false;
    }
    // If input was valid output yes otherwise no
    cout << (f ? "yes" : "no") << endl;
    // Return exit code
    return 0;
}