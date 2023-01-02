#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/knapsack /
///////////////////////////////////////////////////////

void knapsack(int n, int c, int w[], int v[]) {
    // Initialize dp array to 0
    int dp[n + 1][c + 1];
    memset(dp, 0, sizeof(dp));
    // Loop through all items
    for(int i = 0; i <= n; i++) {
        // Loop through all capacities
        for(int j = 0; j <= c; j++) {
            // If either is 0, set to 0 for base case
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            // Otherwise if weight is in range, set to max of current or from other
            } else if (w[i - 1] <= j) {
                dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
            // Otherwise set to currnet best
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // Get highest value from dp
    int m = dp[n][c];
    // Get total capacity
    int cw = c;
    // Initialize list of values
    std::vector<int> p;
    // Loop through all items while value is positive
    for(int i = n; i > 0 && m > 0; i--) {
        // if value equals value before this item, ignore
        if(m == dp[i - 1][cw])
            continue;
        else {
        // Otherwise add to list and subtract from totals
            p.push_back(i - 1);
            m -= v[i - 1];
            cw -= w[i - 1];
        }
    }
    // Output the size of the list
    std::cout << p.size() << std::endl;
    // If content, output the chosen values
    if(p.size() > 0) {
        std::cout << p[0];
        for(int i = 1; i < p.size(); i++) {
            std::cout << " " << p[i];
        }
        std::cout << std::endl;
    }
}

int main(){
    // Initialize capacity and item count variables
    int c;
    int n;
    // Continue while more exist
    while (std::cin >> c && std::cin >> n) {
        // Initialize value and weight arrays
        int v[n];
        int w[n];
        // Populate the arrays with input values
        for(int i = 0; i < n; i++) {
            std::cin >> v[i];
            std::cin >> w[i];
        }
        // Run knapsack for the given input
        knapsack(n, c, w, v);
    }
    // Return exit code
    return 0;
}