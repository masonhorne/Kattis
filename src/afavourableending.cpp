#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/favourable /
/////////////////////////////////////////////////////////

// DP Array to store paths ending favourably from the node
long long dp[401];

long dfs(int n, unordered_map<int, vector<int>> &g){
    // If this node has been calculated, return its answer
    if(dp[n] != -1) return dp[n];
    // Initialize its total to 0
    long long sum = 0;
    // Add its neighbors to its value
    for(int i : g[n]) sum += dfs(i, g);
    // Set the value for the current and retutrn
    return dp[n] = sum;
}

int main() {
    // Read int the test cases and process them
    int t; cin >> t;
    while(t--){
        // Read in number of sections in the book
        int n; cin >> n;
        // Create a graph of the sections with the sections they lead to as neighbors
        unordered_map<int, vector<int>> g;
        // Set dp array to 0
        memset(dp, -1, sizeof dp);
        // Proccess each sections information
        for(int i = 0; i < n; i++){
            // Get the section number
            int v; cin >> v;
            // Read the next value in as a string
            string s; cin >> s;
            // If the string is a digit, add its neighbors in the graph
            if(s[0] >= '0' && s[0] <= '9'){
                int e = stoi(s);
                g[v].push_back(e);
                for(int i = 0; i < 2; i++) {
                    cin >> e;
                    g[v].push_back(e);
                }
            // Otherwise it is an ending so mark it as either valid or invalid
            } else if(s == "favourably") dp[v] = 1;
            else dp[v] = 0;
        }
        // Output the number of paths beginning from the start of the book
        cout << dfs(1, g) << endl;
    }
    // Return exit code
    return 0;
}