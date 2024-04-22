#include<iostream>
#include<vector>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/downtime /
///////////////////////////////////////////////////////

int main() {
    // Initialize total requests count and server capacity
    int n, k; cin >> n >> k;
    // Loop through marking requests incoming and finishing times
    vector<int> v(101001);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v[x]++;
        v[x + 1000]--;
    }
    // Loop through keeping the minimum required servers
    int p = 0;
    int ans = 0;
    for(int i = 0; i < 100001; i++){
        p += v[i];
        ans = max(ans, p / k + (p % k != 0));
    }
    // Output the resulting count
    cout << ans << endl;
    // Return exit code
    return 0;
}