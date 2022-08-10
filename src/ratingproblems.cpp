#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/ratingproblems /
/////////////////////////////////////////////////////////////

int main() {
    // Read input judge count and voted count
    int n, k; cin >> n >> k;
    // Get total of all current votes
    double tot = 0;
    for(int i = 0; i < k; i++){
        double v; cin >> v;
        tot += v;
    }
    // Output minimum and maximum based on remaining votes
    cout << (tot + -3 * (n - k)) / n << " " << (tot + 3 * (n - k)) / n << endl;
    // Return exit code
    return 0;
}