#include<iostream>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/stopwatch /
////////////////////////////////////////////////////////

int main() {
    // Read input count
    int n; cin >> n;
    // If count is odd output still running
    if(n % 2 == 1) cout << "still running" << endl;
    else {
        // Otherwise read in all inputs adding time periods the watch was on
        int t = 0;
        while(n--){
            n--;
            int v1, v2; cin >> v1 >> v2;
            t += v2 - v1;
        }
        // Output the total time spent on
        cout << t << endl;
    }
    // Return exit code
    return 0;
}