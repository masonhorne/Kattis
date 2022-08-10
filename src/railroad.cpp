#include<iostream>
using namespace std;

int main() {
    // Read input values
    int x, y; cin >> x >> y;
    // Number of pieces that connect odd number of edges decide if possible based on if they have pair
    cout << (y % 2 == 0 ? "possible" : "impossible") << endl;
    // Return exit code
    return 0;
}