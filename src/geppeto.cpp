#include<iostream>
#include<vector>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/geppetto /
///////////////////////////////////////////////////////

bool valid(vector<vector<int>> &c, int i) {
    // Loop through the constraints and return false if any are violated
    for(vector<int> &v : c)
        if((i & (1 << v[0])) && (i & (1 << v[1]))) return false;
    // Return true if all constraints were met
    return true;
}

int main() {
    // Initialize the total number of ingredients and constraints
    int n, m; cin >> n >> m;
    vector<vector<int>> c(m, vector<int>(2));
    for(int i = 0; i < m; i++) {
        cin >> c[i][0] >> c[i][1];
        c[i][0]--, c[i][1]--;
    }
    // Iterate through all sets possible
    int sets = (1 << n) - 1;
    int ans = 0;
    // If the set is valid increment the answer
    for(int i = 0; i <= sets; i++)
        if(valid(c, i)) ans++;
    // Output the total number of valid pizzas
    cout << ans << endl;
    // Return exit code
    return 0;
}