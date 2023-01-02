#include<vector>
#include<map>

/*************************************************
 * A collection of useful utility functions that *
 * are used throughout the solution files        *
 *************************************************/

double combinations(int n, int k){
    // No ways to select k from n if k is more than n
    if(k > n) return 0;
    // Initialize a vector to the size of n for computing factorials
    std::vector<double> dp(n + 1, 1);
    // Compute all factorials needed for the equation
    for(int i = 2; i <= n; i++) dp[i] = dp[i - 1] * i;
    // Return all possible combinations of k from n
    return dp[n] / (dp[k] * dp[n - k]);
}


// https://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect
std::pair<bool, std::pair<float, float>> getIntersection(float x11, float y11, float x12, float y12, float x21, float y21, float x22, float y22){
    // Initialize vectors of the line lengths
    float s1x = x12 - x11, s1y = y12 - y11;
    float s2x = x22 - x21, s2y = y22 - y21;
    // Calculate the denominator for solving the equations
    float denominator = (-s2x * s1y + s1x * s2y);
    // Return dummy pair if denominator was invalid
    if(denominator == 0) return std::make_pair(false, std::make_pair(-1, -1));
    // Solve for s and t to find the point on line that the two connect
    float s = (-s1y * (x11 - x21) + s1x * (y11 - y21)) / denominator;
    float t = (s2x * (y11 - y21) - s2y * (x11 - x21)) /  denominator;
    // If point is valid, return the intersection with valid flag
    if(s >= 0 && s <= 1 && t >= 0 && t <= 1) return std::make_pair(true, std::make_pair(x11 + (t * s1x), y11 + (t * s1y)));
    // Otherwise return a dummy pair with the false flag
    else return std::make_pair(false, std::make_pair(-1, -1));
}
