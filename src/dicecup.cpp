#include <iostream>
using namespace std;

//////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/dicecup /
//////////////////////////////////////////////////////

int main() {
    // Read in the number of faces
    int n, m; cin >> n; cin >> m;
    // Initialize hashtable of all possible values
    int o[n + m];
    for(int i = 0; i < m + n; i++) o[i] = 0;
    // Keep track of highest probability
    int b = 0;
    // Loop through all faces on first
    for(int i = 0; i < n; i++){
        // Loop through all faces on second
        for(int j = 0; j < m; j++){
            // Increment the count and update highest probability if needed
            o[i + j + 1]++;
            b = max(o[i + j + 1], b);
        } 
    }
    // Loop through from smallest outputting values if equal to highest
    for(int i = 0; i < n + m; i++)
        if(o[i] == b) cout << i + 1 << endl;
    // Return exit code
    return 0;
}