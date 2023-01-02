#include<iostream>
#include<cmath>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/beavergnaw /
/////////////////////////////////////////////////////////

int main() {
    // Initialize variables for diameter and volume
    double d, v;
    // Set the precision for cout
    cout.precision(9);
    // Loop until end of input
    while(cin >> d  >> v && d != 0 && v != 0){
        // Calculate the total volume of area
        double total = M_PI * (d / 2) * (d / 2) * d;
        // Calculate the remaining volume of wood left
        double rem = total - v;
        // Calculate the volume of the cones that are remaining
        double cones = M_PI * (d / 2) * (d / 2) * (d / 3);
        // Calculate the remaining area of the center piece
        double center = rem - cones;
        // Calculate the volume of the inner cylinder
        double cylinder = center * 1.5;
        // Solve for the radius of that cylinder
        double r = pow((cylinder / (2 * M_PI)), 1.0 / 3);
        // Output the diameter of the inner cylinder
        cout << r * 2 << endl;
    }
    // Return exit code
    return 0;
}