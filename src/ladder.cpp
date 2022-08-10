#include<iostream>
#include<cmath>
using namespace std;

/////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/ladder /
/////////////////////////////////////////////////////

int main() {
    // Read in height and angle of ladder
    int h, v; cin >> h >> v;
    // Calculate the length of ladder and round up to nearest foot
    cout << ceil(h / sin(v * M_PI / 180)) << endl;
    // Return exit code
    return 0;
}