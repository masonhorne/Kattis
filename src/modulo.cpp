#include<iostream>
using namespace std;

/////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/modulo /
/////////////////////////////////////////////////////

int main() {
    // Initialize a hash table for all values
    int tbl[42] = {};
    // Loop through input incrementing value counts
    for(int i = 0; i < 10; i++) {
        int v; cin >> v;
        tbl[v % 42]++;
    }
    // Loop through hash table counting unique values
    int c = 0;
    for(int i = 0; i < 42; i++) if(tbl[i]) c++;
    // Output the total unique numbers
    cout << c << endl;
    // Return exit code
    return 0;
}