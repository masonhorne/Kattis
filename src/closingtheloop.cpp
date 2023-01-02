#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/closingtheloop /
/////////////////////////////////////////////////////////////

int main() {
    // Read input count
    int n; cin >> n;
    // Loop through all cases
    for(int k = 0; k < n; k++){
        // Read in the number of ropes
        int s; cin >> s;
        // Initialize lists of values
        vector<int> red;
        vector<int> blue;
        // Process each input
        for(int i = 0; i < s; i++){
            // Read in the input portion
            string s; cin >> s;
            // Initialize the value
            int v = 0;
            // Convert value to integer
            for(int j = 0; j < s.size() - 1; j++){
                v *= 10;
                v += s[j] - '0';
            }
            // Add to appropriate list based on final value
            if(s[s.size() - 1] == 'R') red.push_back(v);
            else blue.push_back(v);
        }
        // If size of either is 0, return 0
        if(red.size() == 0 || blue.size() == 0) cout << "Case #" << k + 1 << ": " << 0 << endl;
        else {
            // Otherwise sort the lists
            sort(red.begin(), red.end(), [](const int a, const int b){
                return a > b;
            });
            sort(blue.begin(), blue.end(), [](const int a, const int b){
                return a > b;
            });
            // Initialize pointers into lists
            int p1 = 0, p2 = 0;
            // Initialize total
            int total = 0;
            // Calculate the longest rope possible
            while(p1 < red.size() && p2 < blue.size())
                total += red[p1++] + blue[p2++] - 2;
            // Output the longest rope possible
            cout << "Case #" << k + 1 << ": " << total << endl;
        }
     }
    // Return exit code
    return 0;
}