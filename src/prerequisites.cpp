#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/prerequisites /
////////////////////////////////////////////////////////////

int main() {
    // Initialize class count and category count
    int k, m;
    // Continue processing while k reads in and isn't 0
    while(cin >> k && k != 0){
        // Read in category count
        cin >> m;
        // Initialize a list of selected classes
        vector<int> s(k);
        // Read in to populate list of selected
        for(int i = 0; i < k; i++) cin >> s[i];
        // Initialize graph of classes for the category
        vector<unordered_set<int>> graph(m);
        // Initialize a list of required courses from each category
        vector<int> reqs(m);
        for(int i = 0; i < m; i++){
            // Store count and required count
            int c; cin >> c >> reqs[i];
            // Populate category with classes
            for(int j = 0; j < c; j++) {
                int v; cin >> v;
                graph[i].insert(v);
            }
        }
        // Loop through all selected classes, marking as required if present for a category
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < graph.size(); j++){
                if(graph[j].count(s[i]) && reqs[j] > 0) reqs[j]--;
            }
        }
        // Set passing to true
        bool pass = true;
        // Loop through all and if any requirements weren't met set to false
        for(int i = 0; i < reqs.size() && pass; i++) if(reqs[i] != 0) pass = false;
        // Ouput whether or not a valid schedule was chosen
        cout << (pass ? "yes" : "no") << endl;
    }
    // Return exit code
    return 0;
}