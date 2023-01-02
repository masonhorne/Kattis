#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/icpcawards /
/////////////////////////////////////////////////////////

int main() {
    // Read in total team count
    int n; cin >> n;
    // Initialize a set of previous winning universities
    unordered_set<string> p;
    // Initialize remaining count to 12
    int c = 12;
    // While more teams exist and awards still remain
    while(n-- && c){
        // Read school and team
        string s, t; cin >> s >> t;
        // If count for school exists, skip this team
        if(p.count(s)) continue;
        // Otherwise add the school to the set
        p.insert(s);
        // Decrement the count of remaining awards
        c--;
        // Output the school and team name
        cout << s << " " << t << endl;
    }
    // Return exit code
    return 0;
}