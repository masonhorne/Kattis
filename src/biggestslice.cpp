#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;

//////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/biggest /
//////////////////////////////////////////////////////

// Constant for the number of seconds in a 360 degree rotation
const int FULL_CIRCLE =  360 * 60 * 60;

int main() {
    // Set the precision of the output to 6 decimals
    cout << fixed << setprecision(6);
    // Initialize a hash table for all possible slice locations
    bool ht[FULL_CIRCLE];
    // Read in the number of test cases
    int t; cin >> t;
    // Process each of the test cases
    while(t--){
        // Read in radius, number of slices, degree, minutes, and seconds
        int r, n, d, m, s; cin >> r >> n >> d >> m >> s;
        // Set the hashtable to 0s for no slices 
        memset(ht, 0, sizeof ht);
        // Get the value we are rotating by in seconds
        long theta = d * 60 * 60 + m * 60 + s;
        // If we are sharing with more people than seconds in a 360 rotation, just cut for each second
        if(n > FULL_CIRCLE) n = FULL_CIRCLE;
        // Loop through making all n slices in the pizza
        for(int i = 0; i < n; i++) ht[i * theta % FULL_CIRCLE] = 1;
        // Loop between these slices calculating the differences
        int p = 0, mx = 0;
        for(int i = 1; i < FULL_CIRCLE; i++){
            // If the position isn't sliced, skip it
            if(!ht[i]) continue;
            // Otherwise update max if a new best is found
            mx = max(i - p, mx);
            // Set the previous position to the current index
            p = i;
        }
        // Update the maximum if the final slice to the first slice is largest piece
        mx = max(FULL_CIRCLE - p, mx);
        // Output the area of this slice of pizza since it is the largest
        cout << (double) mx / FULL_CIRCLE * M_PI * r * r << endl;
    }
    // Return exit code
    return 0;
}