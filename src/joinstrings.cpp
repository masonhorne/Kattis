#include<iostream>
#include<string>
#include<vector>
using namespace std;

//////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/joinstrings /
//////////////////////////////////////////////////////////

void dfs(vector<string> &v, vector<vector<int>> &g, int idx){
    // Output this nodes value since it is before its concatenations
    cout << v[idx];
    // Loop through concatenations recursing for their full form
    for(int i : g[idx]) dfs(v, g, i);
}

int main() {
    // Use fast IO since input is large
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Read in the total number of words and initialize a variable for storing final index
    int n, f; cin >> n;
    // Initialize a list of strings at their respective indices
    vector<string> v(n);
    // Initialize a graph of the connections between each index
    vector<vector<int>> g(n, vector<int>(0));
    // Loop through reading all words into its index
    for(int i = 0; i < n; i++) cin >> v[i];
    // Loop through all commands attaching roots to their concatenated children
    for(int i = 0; i < n - 1; i++){
        // Read in the command values
        int a, b; cin >> a >> b;
        // Decrement for 0-based indexing
        a--, b--;
        // Push the child (b) to a's list of children
        g[a].push_back(b);
        // Store the index this operation added to
        f = a;
    }
    // DFS from the final index for the resulting string
    dfs(v, g, f);
    // Output the new line to end the output
    cout << endl;
    // Return exit code
    return 0;
}