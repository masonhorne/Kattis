#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/goodmorning /
//////////////////////////////////////////////////////////

bool dfs(vector<vector<int>> &graph, int n, int idx){
    // If entire number was processed, return true
    if(n == 0) return true;
    // Otherwise see if can access the next digit
    for(int i = 0; i < graph[idx].size(); i++)
        // If so recurse to that digit
        if(graph[idx][i] == n % 10) return dfs(graph, n / 10, n % 10);
    // Otherwise return false since number cannot be made
    return false;
}

int main() {
    // Initialize a graph where each index is the number on keypad and list is the numbers it can access
    vector<vector<int>> graph = {{0, 1, 2, 4, 5, 7, 8}, {1}, {1, 2}, {1, 2, 3}, {1, 4}, {1, 2, 4, 5}, {1, 2, 3, 4, 5, 6}, {1, 4, 7}, {1, 2, 4, 5, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8, 9}};
    // Read in the number of test cases
    int t; cin >> t;
    // Loop until all tests have processed
    while(t--){
        // Read in the number for the test case
        int num; cin >> num;
        // If you can create this number itself, output the number
        if(dfs(graph, num / 10, num % 10)) cout << num << endl;
        else {
            // Otherwise search the closest numbers
            int ans = 0;
            // Set offset to one
            int offset = 1;
            // Loop until a result is found
            while(ans == 0) {
                // If you can make the number plus the offset, set as answer
                if(dfs(graph, (num + offset) / 10, (num + offset) % 10)) ans = num + offset;
                // If you can make the number minus the offset, set as answer
                if(dfs(graph, (num - offset) / 10, (num - offset) % 10)) ans = num - offset;
                // Increase the offset for next iteration
                offset++;
            }
            // Output the resulting number
            cout << ans << endl;
        }
    }
    // Return exit code
    return 0;
}