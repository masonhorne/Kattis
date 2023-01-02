#include<iostream>
#include<vector>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/bungeebuilder /
////////////////////////////////////////////////////////////

int main() {
    // Read in the number of mountains
    int n; cin >> n;
    // Initialize a list of all mountain heights
    vector<int> h(n);
    // Read all of the heights into the array
    for(int i = 0; i < n; i++) cin >> h[i];
    // Initialize a left and right array for maximum height to either side
    vector<int> l(n), r(n);
    // Initialize the max as 0
    int mx = 0;
    // Loop through assigning the biggest height to the left of current mountain
    for(int i = 0; i < n; i++){
        l[i] = mx;
        mx = max(h[i], mx);
    }
    // Initialize max as 0
    mx = 0;
    // Loop through assigning the biggest ehight to the right of current mountain
    for(int i = n - 1; i >= 0; i--){
        r[i] = mx;
        mx = max(h[i], mx);
    }
    // Initialize the result as 0
    int ans = 0;
    // Find the mountain that has the largest bungee distance
    for(int i = 0; i < n; i++) ans = max(ans, min(r[i], l[i]) - h[i]);
    // Output the resulting bungee jump height
    cout << ans << endl;
    // Return exit code
    return 0;
}