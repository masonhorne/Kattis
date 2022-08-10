#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/jobexpenses /
//////////////////////////////////////////////////////////

int main() {
    // Read in amount of numbers written
    int n; cin >> n;
    // Initialize total to 0
    int t = 0;
    // Read in numbers adding expenses to total
    while(n--){
        int v; cin >> v;
        if(v < 0) t += -v;
    }
    // Output the total expenses
    cout << t << endl;
    // Return exit code
    return 0;
}