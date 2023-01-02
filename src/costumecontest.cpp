#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/costumecontest /
/////////////////////////////////////////////////////////////

int main() {
    // Initialize and read in the colleague count
    int n; cin >> n;
    // Initialize a map to count their values
    unordered_map<string, int> mp;
    // Loop through counting occurrences of each costume type
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        mp[s]++;
    }
    // Initialize a minimum value
    int mn = 10000;
    // Loop through all of the words to find the minimum
    for(auto it = mp.begin(); it != mp.end(); it++) mn = min(mn, it->second);
    // Initialize a result list
    vector<string> ans;
    // Loop through adding all minimum costume types
    for(auto it = mp.begin(); it != mp.end(); it++) if(it->second == mn) ans.push_back(it->first);
    // Sort the list of the costumes with highest winning probability
    sort(ans.begin(), ans.end());
    // Output all of the selected costume types
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
    // Return exit code
    return 0;
}
