#include<iostream>
#include<cstring>
using namespace std;

/////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/prozor /
/////////////////////////////////////////////////////

int main() {
    // Read in the image dimensions and mallet width
    int r, c, m; cin >> r >> c >> m;
    // Initialize the grid
    char grid[r][c];
    // Read in the characters of the grid
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) cin >> grid[i][j];
    // Initialize a prefix sum array for this image
    int psum[r + 1][c + 1];
    // Set the prefix sums to 0
    memset(psum, 0, sizeof psum);
    // Loop through calculating the prefix sum from top left to current index
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] + (grid[i - 1][j - 1] == '.' ? 0 : 1) - psum[i - 1][j - 1];
    // Initialize the row and column of final result and set max to 0
    int r1, c1, mx = 0;
    // Loop through all valid mallet placements
    for(int i = m; i <= r; i++){
        for(int j = m; j <= c; j++){
            // Get the total flys covered at this point using the intersections to get the proper count
            int f = psum[i - 1][j - 1] - psum[i - 1][j - m + 1] - psum[i - m + 1][j - 1] + psum[i - m + 1][j - m + 1];
            // If the flies are more than max, update the row and column and store the max
            if(f > mx){
                r1 = i - 1;
                c1 = j - 1;
                mx = f;
            }
        }
    }
    // Loop through adding the vertical borders
    for(int i = r1 - m + 1; i <= r1; i++)
        grid[i][c1] = '|', grid[i][c1 - m + 1] = '|';
    // Loop through adding the horizontal borders
    for(int i = c1 - m + 1; i <= c1; i++)
        grid[r1][i] = '-', grid[r1 - m + 1][i] = '-';
    // Mark the corners of the mallet
    grid[r1][c1] = '+', grid[r1][c1 - m + 1] = '+', grid[r1 - m + 1][c1] = '+', grid[r1 - m + 1][c1 - m + 1] = '+';
    // Output the total flies caught
    cout << mx << endl;
    // Output the image with the mallet placement
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) cout << grid[i][j];
        cout << endl;
    }
    // Return exit code
    return 0;
}