#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

///////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/bryr /
///////////////////////////////////////////////////

int main() {
    // Read in total cities and edges
    int n, m; cin >> n >> m;
    // Initialize our map to the input values
    unordered_map<int, unordered_map<int, int>> g;
    while(m--){
        int u, v, c; cin >> u >> v >> c;
        g[u][v] = c;
        g[v][u] = c;
    }
    // Initialize our priority queue and distance array
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, -1);
    // Use Dijkstra to calculate all minimum path costs
    pq.push({0, 1});
    while(!pq.empty()) {
        // Get the next best value
        pair<int, int> pos = pq.top();
        pq.pop();
        int cost = pos.first, position = pos.second;
        // If we have already visited, ignore
        if(dist[position] != -1) continue;
        // Otherwise, update cost and add neighbors
        dist[position] = cost;
        for(unordered_map<int, int>::iterator it = g[position].begin(); it != g[position].end(); it++)
            pq.push({cost + it->second, it->first});
    }
    // Return the total minimum path to goal
    cout << dist[n] << endl;
    // Return exit code
    return 0;
}