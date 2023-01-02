#include<iostream>
#include<cmath>
#include"../lib.cpp"
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/character /
////////////////////////////////////////////////////////

int main() {
    // Read in the total number of characters
    int n; cin >> n;
    // Generate the total in the power set, then remove the n single sets along with the empty set
    cout << (int) pow(2, n) - n - 1 << endl;
    // Return exit code
    return 0;
}

/************************************************************************************************************
 *                                                                                                          *
 *   An alternative solution that counts the different combinations that can be made choosing groups of two *
 *   two or more people from the provided inputs amount.                                                    *
 *                                                                                                          *
 ************************************************************************************************************
 *   int main() {                                                                                           *
 *       // Read in the number of characters                                                                *
 *      int n; cin >> n;                                                                                    *
 *       // Initialize result to 0                                                                          *
 *        double ans = 0;                                                                                   *
 *       // Count all combinations (n choose i) of every size 2 up to and including n, adding to result     *
 *        for(int i = 2; i <= n; i++) ans += combinations(n, i);                                            *
 *        // Output the resulting value                                                                     *
 *        cout << (int) ans << endl;                                                                        *
 *        // Return exit code                                                                               *
 *        return 0;                                                                                         *
 *    }                                                                                                     *
 *                                                                                                          *
 ************************************************************************************************************/