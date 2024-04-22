#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/mountainbiking /
/////////////////////////////////////////////////////////////

int main() {
    // Read in the total hills and the gravity constant
    int n;
    double g;
    cin >> n >> g;
    // Set the output precision
    cout.precision(12);
    // Read in the hill information
    vector<vector<int>> v(n, vector<int>(2));
    for(int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1];
    // Loop through the hills and calculate the velocity
    for(int i = 0; i < n; i++) {
        // Initialize our velocity as 0 for this starting point
        double velocity = 0;
        // Loop through each slope finding the finishing velocity
        for(int j = i; j < n; j++) {
            // https://www.dummies.com/article/academics-the-arts/science/physics/finding-the-velocity-of-an-object-moving-along-an-inclined-plane-174230/
            velocity = sqrt(velocity * velocity + 2 * g * v[j][0] * cos(v[j][1] * M_PI / 180));
        }
        // Output the resulting final velocity
        cout << velocity << endl;
    }
    // Return exit code
    return 0;
}