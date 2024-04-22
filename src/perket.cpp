#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/perket /
/////////////////////////////////////////////////////

int main() {
    // Read in the total number of ingredients
    int n; cin >> n;
    // Initialize vectors for sour and bitter
    vector<int> sour(n), bitter(n);
    for(int i = 0; i < n; i++) cin >> sour[i] >> bitter[i];
    // Initialize an answer for minimum difference and total sets
    int ans = INT_MAX;
    int sets = (1 << n) - 1;
    // Loop through each possible subset calculating sour and bitterness
    for(int i = 1; i <= sets; i++) {
        int sourProd = 1, bitterSum = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                sourProd *= sour[j];
                bitterSum += bitter[j];
            }
        }
        // Update the result if a new best is found
        ans = min(ans, abs(sourProd - bitterSum));
    }
    // Output the result
    cout << ans << endl;
    // Return exit code
    return 0;
}