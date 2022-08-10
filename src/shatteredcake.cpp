#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/shatteredcake /
////////////////////////////////////////////////////////////

int main() {
    // Read in width of cake and number of pieces
    int width, n; cin >> width >> n;
    // Initialize total area to 0
    int t = 0;
    // Read in total pieces
    while(n--){
        // Add pieces area to total
        int w, h; cin >> w >> h;
        t += w * h;
    }
    // Calculate height from total area divided by width
    cout << t / width << endl;
    // Return exit code
    return 0;
}