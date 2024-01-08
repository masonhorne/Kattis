#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

///////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/continuousmedian /
///////////////////////////////////////////////////////////////

int main() {
    // Read in the test case count
    int t; cin >> t;
    // Process test cases
    while(t--){
        // Read in total numbers in this sequence
        int n; cin >> n;
        // Initialize a low and high priority queue
        priority_queue<double> low;
        priority_queue<double, vector<double>, greater<double>> high;
        // Initialize the sum for this test case
        long sum = 0;
        // Iterate through all values
        while(n--) {
            // Read in out next value
            double v; cin >> v;
            // Add it to the correct queue adjusting each as needed
            if(low.size() > high.size()){
                if(low.top() < v) high.push(v);
                else {
                    high.push(low.top());
                    low.pop();
                    low.push(v);
                }
            } else {
                if(high.empty() || high.top() >= v) low.push(v);
                else {
                    low.push(high.top());
                    high.pop();
                    high.push(v);
                }

            }
            // If we are at an odd value, add the middle element
            if(low.size() > high.size()) sum += low.top();
            // Otherwise, add the average of the two middle elements
            else sum += floor((low.top() + high.top()) / 2);
        }
        // Output the sum for this sequence's medians
        cout << sum << endl;
    }
    // Return exit code
    return 0;
}