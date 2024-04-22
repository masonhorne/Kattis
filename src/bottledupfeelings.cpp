#include<iostream>
#include<queue>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/bottledup /
////////////////////////////////////////////////////////

pair<int, int> solve(int n, int v1, int v2) {
    // Find the maximum number of v1 bottles that can be used
    int d = n / v1 + 1;
    // Initialize the result as a dummy value
    pair<int, int> ans = {-1, -1};
    // Try all values for v1
    for(int i = 0; i < d; i++) {
        int r = n - (i * v1);
        // If v2 can divide the rest update result if it is a new minimum bottle count
        if(r % v2 == 0) {
            if(ans.first == -1 || ans.first + ans.second > i + r / v2) ans =  {i, r / v2};
        }
    }
    // Return the resulting bottle counts
    return ans;
}

int main() {
    // Read in the inputs
    int n, v1, v2;
    cin >> n >> v1 >> v2;
    // Solve the problem
    pair<int, int> ans = solve(n, v1, v2);
    // Output the answer
    if(ans.first == -1) cout << "Impossible" << endl;
    else cout << ans.first << " " << ans.second << endl;
    // Return exit code
    return 0;
}