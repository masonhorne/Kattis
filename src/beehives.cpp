#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Read in distance and count for this test case
    double d; int n;
    // Loop until 0.0 0.0 test case is reached
    while(cin >> d && cin >> n && n > 0) {
        // Array for storing input points
        double points[n][3]; // X, Y, SOUR/SWEET
        // Read in points
        for(int i = 0; i < n; i++) {
            cin >> points[i][0]; // X
            cin >> points[i][1]; // Y
            points[i][2] = 0; // SWEET
        }
        // Find distance to all others
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                // Skip itself
                if(i == j) continue;
                double distance = hypot(abs(points[i][0] - points[j][0]), abs(points[i][1] - points[j][1]));
                // If distance is less than d set to sour
                if(distance <= d){
                    points[i][2] = 1;
                    points[j][2] = 1;
                }
            }
        }
        // Start as all sweet
        int sweet = n;
        // Loop through and if sour remove from sweet
        for(int i = 0; i < n; i++) sweet -= points[i][2];
        // Output the total for this test case
        cout << n - sweet << " sour, " << sweet << " sweet" << endl;
    }
    // Return exit code
    return 0;
}