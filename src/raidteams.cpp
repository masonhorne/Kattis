#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/raidteams /
////////////////////////////////////////////////////////

// Custom comparator for pairs to sort priority queue with
bool compare(pair<long long, string> a, pair<long long, string> b){
    // If equal numeric value, we want to sort by smaller strings
    if(a.first == b.first) return a.second > b.second;
    // If not equal we want to sort by larger numeric values
    else return a.first < b.first;
}

int main() {
    // Read in count
    int t; cin >> t;
    // Initialize priority queue for each skill
    priority_queue<pair<long long, string>, vector<pair<long long, string>>, decltype(&compare)> pqa(compare);
    priority_queue<pair<long long, string>, vector<pair<long long, string>>, decltype(&compare)> pqb(compare);
    priority_queue<pair<long long, string>, vector<pair<long long, string>>, decltype(&compare)> pqc(compare);
    // Add pairs of values with string to priority queues
    for(int i = 0; i < t; i++){
        // Read in the adventurers name
        string n; cin >> n;
        // Read in all skill levels for the adventurer
        long long a, b, c; cin >> a >> b >> c;
        // Add the skills to the appropriate queue
        pqa.push({a, n});
        pqb.push({b, n});
        pqc.push({c, n});
    }
    // Initialize a map of used adventurers
    unordered_map<string, int> mp;
    // Make teams until not enough people remain
    while(t >= 3){
        // Initialize the team list
        vector<string> team;
        // Skip all used adventurers
        while(mp[pqa.top().second]) pqa.pop();
        // Push the next best for skill a to the team
        team.push_back(pqa.top().second);
        // Mark this adventurer as used
        mp[pqa.top().second] = 1;
        // Remove from the queue
        pqa.pop();
        // Skip all used adventurers
        while(mp[pqb.top().second]) pqb.pop();
        // Push the next best for skill a to the team
        team.push_back(pqb.top().second);
        // Mark this adventurer as used
        mp[pqb.top().second] = 1;
        // Remove from the queue
        pqb.pop();
        // Skip all used adventurers
        while(mp[pqc.top().second]) pqc.pop();
        // Push the next best for skill a to the team
        team.push_back(pqc.top().second);
        // Mark this adventurer as used
        mp[pqc.top().second] = 1;
        // Remove from the queue
        pqc.pop();
        // Sort teams names alphabetically
        sort(team.begin(), team.end());
        // Output the space separated team
        cout << team[0] << " " << team[1] << " " << team[2] << endl;
        // Remove the adventurers from the total count
        t -= 3;
    }
    // Return exit code
    return 0;
}