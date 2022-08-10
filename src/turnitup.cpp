#include<iostream>
#include<string>
using namespace std;

/////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/skruop /
/////////////////////////////////////////////////////

int main() {
    // Read in number of requests
    int n; cin >> n;
    // Initialize volume to 7
    int level = 7;
    // Increment request numbers to account for 0 indexing
    n += 1;
    // Process requests
    while(n--){
        // Read in request
        string s; getline(cin, s);
        // If says to go up and can, go up
        if(s == "Skru op!" && level < 10) level++;
        // Otherwise if says to go down and can, go down
        else if(s == "Skru ned!" && 0 < level) level--;
    }
    // Output the final volume
    cout << level << endl;
    // Return exit code
    return 0;
}