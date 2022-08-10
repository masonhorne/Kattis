#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int main() {
    // Initialize list to store sticks
    vector<ull> sticks;
    // Read in count of sticks
    ull n; cin >> n;
    // Add all sticks to the list
    while(n-- > 0) {
        ull l; cin >> l;
        sticks.push_back(l);
    }
    // Sort the list in ascending order
    sort(sticks.begin(), sticks.end());
    // Loop through looking for valid triangle
    for(int i = 0; i < sticks.size() - 2; i++){
        // If two sticks add to greater than another, a valid triangle exists
        if(sticks[i] + sticks[i + 1] > sticks[i + 2]){
            cout << "possible" << endl;
            return 0;
        }
    }
    // Otherwise output impossible if none were possible
    cout << "impossible" << endl;
    // Return exit code
    return 0;
}