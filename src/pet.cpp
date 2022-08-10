#include<iostream>
using namespace std;

//////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/pet /
//////////////////////////////////////////////////

int main() {
    // Initialize max score and index to -1
    int ms = -1, mi = -1;
    // Read all 5 participants scores
    for(int i = 0; i < 5; i++){
        // Calculate total for each
        int total = 0;
        // Read all 4 score and add to total
        for(int j = 0; j < 4; j++){
            int v; cin >> v;
            total += v;
        }
        // If new best keep index and score
        if(total > ms){
            ms = total;
            mi = i + 1;
        }
    }
    // Output best index and score found
    cout << mi << " " << ms << endl;
    // Return exit code
    return 0;
}