#include <iostream>
using namespace std;

/////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/bijele /
/////////////////////////////////////////////////////

int main() {
    // Initialize array of all pieces counts
    int e[] = {1, 1, 2, 2, 2, 8};
    // Read initial value and output to avoid trailing space
    int c; cin >> c;
    cout << e[0] - c;
    // Loop through remaining, outputting space then remaining pieces
    for(int i = 1; i < 6; i++) {
        cin >> c;
        cout << " " << e[i] - c;
    }
    // Lastly output the endline
    cout << endl;
    // Return exit code
    return 0;
}