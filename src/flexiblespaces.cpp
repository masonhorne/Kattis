#include<iostream>
#include<vector>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/flexible /
///////////////////////////////////////////////////////

int main() {
    // Read in total width and partitions
    int w, p;
    cin >> w >> p;
    // Initialize array of wall positions
    vector<int> partitions(p + 2);
    partitions[p + 1] = w;
    for(int i = 1; i <= p; i++)
        cin >> partitions[i];
    // Initialize array of possible widths
    int r[100] = {};
    // For all possible partitions find widths and mark possible
    for(int i = 0; i < p + 2; i++)
        for(int j = i + 1; j < p + 2; j++)
            r[partitions[j] - partitions[i]] = 1;
    // Output all possible widths
    for(int i = 0; i <= w; i++)
        if(r[i]) cout << i << " ";
    // Return exit code
    return 0;
}