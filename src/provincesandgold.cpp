#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/provincesandgold /
///////////////////////////////////////////////////////////////

int main() {
    // Read in all drawn cards
    int g, s, c; cin >> g >> s >> c;
    // Calculate all buying power
    int bp = g * 3 + s * 2 + c;
    // Output best land possible to buy or none if not possible
    if(bp >= 8) cout << "Province or ";
    else if(bp >= 5) cout << "Duchy or ";
    else if(bp >= 2) cout << "Estate or ";
    // Output the best treasure card to receive
    if(bp >= 6) cout << "Gold" << endl;
    else if(bp >= 3) cout << "Silver" << endl;
    else cout << "Copper" << endl;
    // Return exit code
    return 0;
}