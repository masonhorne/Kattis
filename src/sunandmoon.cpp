#include<iostream>
#include<vector>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/sunandmoon /
/////////////////////////////////////////////////////////

const int MAX_DAYS = 5000;

int solve(int sp, int sn, vector<int> &d) {
    // Skip the first negative cycle
    int s = -sp;
    while(s < 0) s += sn;
    // Store years that were skipped for next sun cycle
    int c = s;
    // Loop through all possible days and check if moon cycle occurred
    while(s <= MAX_DAYS) {
        if(d[s]) return c;
        s += sn;
        c += sn;
    }
    // Return -1 since not possible to reach
    return -1;
}

int main() {
    // Read all inputs for cycles
    int mp, mn, sp, sn; cin >> mp >> mn >> sp >> sn;
    // Mark days for moon cycle to 5000
    int m = -mp;
    vector<int> d(MAX_DAYS + 1);
    while(m < 0) m += mn;
    while(m <= MAX_DAYS) {
        d[m] = 1;
        m += mn;
    }
    // Solve for first possible day
    cout << solve(sp, sn, d) << endl;
    // Return exit code
    return 0;
}
