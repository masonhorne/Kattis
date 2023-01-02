#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

/////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/racingalphabet /
/////////////////////////////////////////////////////////////

int main() {
    // Read in number of test cases
    int n; cin >> n;
    // Set precision for output
    cout << fixed << setprecision(6);
    // Read the new line character
    string s; getline(cin, s);
    // Process each test case
    for(int i = 0; i < n; i++){
        // Get the next line
        getline(cin, s);
        // Calculate distance traveled around the circumference
        double d = 0;
        // Traverse from one character to next
        for(int i = 0; i < s.size() - 1; i++){
            // Get location of current character
            int src = s[i] == ' ' ? 27 : (s[i] == '\'' ? 28 : s[i] - 64);
            // Get location of next character
            int dest = s[i + 1] == ' ' ? 27 : (s[i + 1] == '\'' ? 28 : s[i + 1] - 64);
            // Calculate the distance between the two
            int c = src < dest ? dest - src : src - dest;
            // If it is more than 14, travel the other way
            if(c > 14) c = 28 - c;
            // Add this to the total distance
            d += c;
        }
        // Multiply the total circumference by the amount traversed and divided by 
        // the speed of travel, adding in the time for each stop
        double ans = 60.0 * M_PI  * (d / 28) / 15 + s.size();
        // Output the result
        cout << ans << endl;
    }
    // Return exit code
    return 0;
}