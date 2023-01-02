#include<iostream>
#include<vector>
#include<complex>
#include<algorithm>
#include<cmath>
using namespace std;

/////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/mosquitoes /
/////////////////////////////////////////////////////////

// Angular Sweep Algorithm: https://www.geeksforgeeks.org/angular-sweep-maximum-points-can-enclosed-circle-given-radius/

// Complex from STL to deal with angle and euclidean distance calculation
typedef complex<double> Point;

// Comparator to sort angles based on value, if equal we want the valid one to appear first
bool compare(pair<double , bool> a, pair<double, bool> b){
    // If equal, return if a is entering, otherwise we want b since it may be entering
    if(a.first == b.first) return a.second == 1;
    // Otherwise return the angle that is encountered first
    else return a.first < b.first;
}

int angularSweep(int i, double r, int n, vector<Point> &points, vector<vector<double>> &distances) {
    // Initialize a list of all angles from the x axis this point is on to the other points
    vector<pair<double, bool>> angles;
    // Try all other points
    for(int j = 0; j < n; j++){
        // If the point isn't the anchor and is within the diameter of the circle in distance
        if(i != j && distances[i][j] <= 2 * r){
            // Calculate its angle between the anchor to center circle line and the anchor to point that mosquito enters circle at
            double B = acos(distances[i][j] / (2 * r));
            // Calculate the angle between the x-axis and the anchor to point mosquito enters line
            double A = arg(points[j] - points[i]);
            // Calculate the angle the point enters and leaves the circle
            double alpha = A - B;
            double beta = A + B;
            // Add the two angles to the set of all angles
            angles.push_back({alpha, true});
            angles.push_back({beta, false});
        }
    }
    // Sort the angles in ascending order
    sort(angles.begin(), angles.end(), compare);
    // Initialize the count and result to 1
    int count = 1, res = 1;
    // Loop through all angles in the set
    for(auto it = angles.begin(); it != angles.end(); it++) {
        // Update the count if a point entered or left the circle
        if(it->second) count++;
        else count--;
        // Update the max if a new best is found
        if(count > res) res = count;
    }
    // Return the resulting maximum points contained
    return res;
}

int main(){
    // Read in all test case counts
    int t; cin >> t;
    // Process each test case
    while(t--){
        // Read in the mosquito count
        int m; cin >> m;
        // Read in the bowl diameter
        double d; cin >> d;
        // Initialize the points array
        vector<Point> points;
        // Read in all points to the list
        for(int i = 0; i < m; i++){
            double x, y; cin >> x >> y;
            points.push_back(Point(x, y));
        }
        // Initialize a list of distances between all points
        vector<vector<double>> distances(m, vector<double>(m));
        // Calculate the distances between all points
        for(int i = 0; i < m - 1; i++)
            for(int j = i + 1; j < m; j++)
                distances[i][j] = distances[j][i] = abs(points[i] - points[j]);
        // Initialize the result to 0
        int ans = 0;
        // Run angular sweep with each point as an anchor, updating max if new best is found
        for(int i = 0; i < m; i++)
            ans = max(ans, angularSweep(i, d / 2, m, points, distances));
        // Output the maximum number of contained mosquitoes
        cout << ans << endl;
    }
    // Return exit code
    return 0;
}