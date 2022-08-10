#include<iostream>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/spavanac /
///////////////////////////////////////////////////////

int main() {
    // Read in time to adjust
    int h, m; cin >> h >> m;
    // If minutes are less than 45 handle hour adjust
    if(m < 45) {
        // If hour is zero adjust to 23 otherwise just subtract 1
        if(h == 0) cout << "23 " << 60 - (45 - m) << endl;
        else cout << h - 1 << " " << 60 - (45 - m) << endl;
    // Otherwise just output same hour but 45 minutes earlier
    } else cout << h << " " << m - 45 << endl;
    // Return exit code
    return 0;
}