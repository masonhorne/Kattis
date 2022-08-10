#include<iostream>
#include<vector>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/weakvertices /
///////////////////////////////////////////////////////////

int main() {
    // Read in dimensions for graph
    int n; cin >> n;
    // Loop until no more input
    while(n != -1){
        // Initialize graph to store input
        vector<vector<int>> graph(n, vector<int>(0));
        // Loop through input populating graph
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int v; cin >> v;
                if(v) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        // Initialize visited list
        vector<int> visited(n, 0);
        // Loop through all nodes
        for(int node = 0; node < n; node++){
            // If the node isn't visited yet
            if(!visited[node]){
                // Check all neighbors
                for(int neighbor : graph[node]){
                    // Check all of your neighbors neighbors
                    for(int neighborneighbor : graph[neighbor]){
                        // If any of them match another of your neigbors, they are in strong connected pair
                        for(int nhbr : graph[node]) {
                            // So mark all with 1
                            if(neighborneighbor == nhbr){
                                visited[node] = 1;
                                visited[neighbor] = 1;
                                visited[nhbr] = 1;
                            }
                        }
                    }
                }
            }   
        }
        // Loop through list of nodes and output those that weren't visited
        for(int i = 0; i < visited.size(); i++) if(!visited[i]) cout << i << " ";
        cout << endl;
        // Read in next rows dimensions
        cin >> n;
    }
    // Return exit code
    return 0;
}