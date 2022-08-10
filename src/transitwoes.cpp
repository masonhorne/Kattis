#include<iostream>
#include<vector>
using namespace std;

//////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/transitwoes /
//////////////////////////////////////////////////////////

int main() {
    // Read in start time, end time, and number of routes
    int s, t, n; cin >> s >> t >> n;
    // Initialize lists to store walk lengths, ride lengths, and arrival schedules
    vector<int> walks, rides, arrivals;
    // Read all inputs
    for(int i = 0; i < n + 1; i++) {
        int v; cin >> v;
        walks.push_back(v);
    }
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        rides.push_back(v);
    }
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        arrivals.push_back(v);
    }
    // Initialize total travel time
    int m = 0;
    // Initialize pointers to walking and riding array
    int wp = 0, rp = 0;
    // All even steps are walks and all odd steps are rides
    for(int i = 0; i < 2 * n + 1; i++){
        if(i % 2 == 0){
            // Add time of walk to total
            m += walks[wp++];
        } else {
            // Add wait for arrival and time of ride to total
            m += m % arrivals[rp];
            m += rides[rp++];
        }
    }
    // Output if the time to travel was less than the given time
    cout << (t - s > m ? "yes" : "no") << endl;
    // Return exit code
    return 0;
}