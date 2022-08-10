#include <iostream>
#include<unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Read in test cases count
    int n; cin >> n;
    while(n--) {
        // Initialize map for frequencies
        unordered_map<string, int> freq;
        // Read in product count
        int p; cin >> p;
        // Read in name and count and add to frequencies map
        while(p--){
            string name; cin >> name;
            int v; cin >> v;
            freq[name] += v;
        }
        // Copy pairs to vector
        vector<pair<string, int>> list;
        copy(freq.begin(), freq.end(), back_inserter(list));
        // Sort by value unless equal then name
        sort(list.begin(), list.end(), [](const pair<string, int> a, const pair<string, int> b) {
            if(a.second == b.second) return a.first < b.first;
            else return a.second > b.second;
        });
        // Output data for testcase
        cout << list.size() << endl;
        for(int i = 0; i < list.size(); i++) cout << list[i].first << " " << list[i].second << endl;
    }
    // Return exit code
    return 0;
}