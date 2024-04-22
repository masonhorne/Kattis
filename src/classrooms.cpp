#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/classrooms /
/////////////////////////////////////////////////////////

int main() {
    // Read in the total activities and capacity
    int n, k; cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        v[i][0] = e, v[i][1] = s;
    }
    // Sort the activities by earliest end time and then earliest start
    sort(v.begin(), v.end());
    // Initialize our result to 0
    int ans = 0;
    // Initialize a multiset of all ongoing activities
    multiset<int> ms;
    // Loop through the activities seeing what can be done
    for(int i = 0; i < n; i++) {
        // Find the most recent activity to end before this one starts
        multiset<int>::iterator it = ms.lower_bound(-v[i][1]);
        // If no activity was found check if we can add a new one
        if(it == ms.end()){
            // If so add it to the set
            if(ms.size() < k) {
                ms.insert(-v[i][0] - 1);
                ans++;
            }
        } else {
            // Otherwise, remove what ended last and add the new activity
            ms.erase(it);
            ms.insert(-v[i][0] - 1);
            ans++;
        }
    }
    // Output the total activities that we can do
    cout << ans << endl;
    // Return exit code
    return 0;
}