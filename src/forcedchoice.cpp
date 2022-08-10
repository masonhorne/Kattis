#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/forcedchoice /
///////////////////////////////////////////////////////////

int main() {
    // Read in number of cards, prediction, and number of steps
    int n, p, s; cin >> n >> p >> s;
    // Loop through all steps
    while(s--){
        // Set flag to false for containing prediction
        bool f = false;
        // Read in number in step
        int v; cin >> v;
        // Loop through step and set flag if prediction occurs
        while(v--){
            int r; cin >> r;
            if(r == p) f = true;
        }
        // Output whether or not to keep prediction
        cout << (f ? "KEEP" : "REMOVE") << endl;
    }
    // Return exit code
    return 0;
}