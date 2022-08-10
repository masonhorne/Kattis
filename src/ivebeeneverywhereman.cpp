#include<iostream>
#include<set>
#include<string>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/everywhere /
/////////////////////////////////////////////////////////

int main() {
    // Read in number of test cases
    int t; cin >> t;
    // Process test cases
    while(t--){
        // Read in number of trips
        int n; cin >> n;
        // Initialize set of names
        set<string> vis;
        // Add all names to set
        while(n--){
            string s; cin >> s;
            vis.insert(s);
        }
        // Output size of set
        cout << vis.size() << endl;
    }
    // Return exit code
    return 0;
}