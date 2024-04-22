#include<iostream>
#include<algorithm>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/candydivision /
////////////////////////////////////////////////////////////

vector<long> factors(long x) {
    // Initialize vector of factors
    vector<long> v;
    // Iterate through possible factors
    for(long i = 1; i * i <= x; i++){
        // Add factors to list
        if(x % i == 0) {
            v.push_back(i);
            long j = x / i;
            if(i != j) v.push_back(j);
        }
    }
    // Sort factors and return list
    sort(v.begin(), v.end());
    return v;
}

int main() {
    // Read in total number of candies
    long n; cin >> n;
    // Get factors of n and output result
    vector<long> v = factors(n);
    // Output result
    for(int i = 0; i < v.size(); i++)
        cout << v[i] - 1 << " ";
    // Return exit code
    return 0;
}