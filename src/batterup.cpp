#include<iostream>
using namespace std;

///////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/batterup /
///////////////////////////////////////////////////////

int main() {
    // Read at bat count
    int n; cin >> n;
    // Initialize total and valid hits to 0
    double total = 0;
    int c = 0;
    // Read at bats
    while(n--){
        int v; cin >> v;
        // If is valid at bat increment count and add to total
        if(v != -1){
            c++;
            total += v;
        }
    }
    // Output slugger score
    cout << total / c << endl;
    // Return exit code
    return 0;
}