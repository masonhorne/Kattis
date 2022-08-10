#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/bela /
///////////////////////////////////////////////////

int main() {
    // Read in number of hands and dominant card type
    int n; cin >> n; char d; cin >> d;
    // Initialize total to 0
    int t = 0;
    // Loop through all hands of hards (4 cards each)
    for(int i = 0; i < 4 * n; i++) {
        // Reach in the hand
        string h; cin >> h;
        // Split the string into card type and suit
        char c = h[0];
        char s = h[1];
        // Switch based on the card value
        switch(c) {
            // Add appropriate values based on suit and dominant suit
            case 'A':
                t += 11;
                break;
            case 'K':
                t += 4;
                break;
            case 'Q':
                t += 3;
                break;
            case 'J':
                t += s == d ? 20 : 2;
                break;
            case 'T':
                t += 10;
                break;
            case '9':
                t += s == d ? 14 : 0;
        }
    }
    // Output the total of the cards
    cout << t << endl;
    // Return exit code
    return 0;
}