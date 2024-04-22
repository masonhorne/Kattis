#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/almostperfect /
////////////////////////////////////////////////////////////

int factorSum(int x) {
    // Sum of factors
    int sum = 0;
    // Iterate through possible factors
    for(int i = 1; i * i <= x; i++){
        if(x % i == 0) {
            sum += i;
            int j = x / i;
            // Add greater factor if proper
            sum += j < x && i != j ? j : 0;
        }
    }
    // Return total sum of factors
    return sum;
}

int main() {
    // Read in input numbers
    int n;
    while(cin >> n) {
        // Get the sum of the factors of n
        int sum = factorSum(n);
        // Output the proper result based on sum
        if(sum == n) cout << n << " perfect" << endl;
        else if(abs(sum - n) <= 2) cout << n << " almost perfect" << endl;
        else cout << n << " not perfect" << endl;
    }
    // Return exit code
    return 0;
}