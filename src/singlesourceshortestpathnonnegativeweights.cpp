#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<cmath>
#include<climits>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/shortestpath1 /
////////////////////////////////////////////////////////////

int main() {
    // Initialize values for vertices, edges, queries, and start point
    int n, m, q, s;
    // Read until the terminating input
    while(cin >> n >> m >> q >> s && !(n == 0 && m == 0 && q == 0 && s == 0)){
        // Initialize a graph of directed edges with weights
        unordered_map<int, unordered_map<int, int>> g;
        while(m--){
            int u, v, w, p = INT_MAX; cin >> u >> v >> w;
            if(g[u].find(v) != g[u].end()) p = g[u][v];
            g[u][v] = min(p, w);
        }
        // Initialize a priority queue and distance array for dijkstra
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, -1);
        pq.push({0, s});
        // Run dijkstra to populate distances
        while(!pq.empty()) {
            // Get the next position
            pair<int, int> pos = pq.top();
            pq.pop();
            int cost = pos.first, position = pos.second;
            // Ignore already computed values
            if(dist[position] != -1) continue;
            dist[position] = cost;
            // Add neighbors to queue
            for(unordered_map<int, int>::iterator it = g[position].begin(); it != g[position].end(); it++)
                pq.push({cost + it->second, it->first});
        }
        // Output the resulting query results
        while(q--){
            int t; cin >> t;
            if(dist[t] == -1) cout << "Impossible" << endl;
            else cout << dist[t] << endl;
        }
    }
    // Return exit code
    return 0;
}