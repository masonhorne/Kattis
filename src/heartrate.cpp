#include<iostream>
using namespace std;


////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/heartrate /
////////////////////////////////////////////////////////

int main() {
    // Read in input count
    int n; cin >> n;
    // Set precision for output
    cout.precision(7);
    // Process input values
    while(n--){
        // Read in beats and time
        double b, p; cin >> b >> p;
        // Calculate BPM
        double bpm = b * 60 / p;
        // Calculate ABPM
        double err = 60 / p;
        // Output minimum, average, and maximum
        cout << bpm - err << " " << bpm << " " << bpm + err << endl;
    }
    // Return exit code
    return 0;
}