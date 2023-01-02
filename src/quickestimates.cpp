#include<iostream>
#include<string>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/quickestimate /
////////////////////////////////////////////////////////////

int main () {
    // Read in number of test cases
    int n; cin >> n;
    // Initialize string and read in new line
    string s;
    getline(cin, s);
    // Loop through test cases
    while(n--){
        // Read in estimate
        getline(cin, s);
        // Output its length
        cout << s.size() << endl;
    }
    // Return exit code
    return 0;
}