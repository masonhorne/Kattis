#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

//////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/ballotboxes /
//////////////////////////////////////////////////////////

int main() {
    // Initialize variables for number of cities and ballot boxes
    int n, b;
    // Loop through all test cases
    while(cin >> n >> b && n != -1 && b != -1){
        // Initialize priority queue for assigning cities
        priority_queue<vector<float>> pq;
        b -= n;
        // Initialize each with one ballot box
        while(n--) {
            float v; cin >> v;
            pq.push({v, v, 1});
        }
        // Distribute the remaining ballot boxes
        while(b--){
            vector<float> v = pq.top();
            pq.pop();
            pq.push({v[1] / (v[2] + 1), v[1], v[2] + 1});
        }
        // Output the maximum people that one box will be assigned
        cout << ceil(pq.top()[0]) << endl;
    }
    // Return exit code
    return 0;
}