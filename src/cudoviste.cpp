#include<iostream>
using namespace std;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/cudoviste /
////////////////////////////////////////////////////////

int main() {
    // Read grid dimensions
    int r, c; cin >> r >> c;
    // Populate the grid with values
    int grid[r][c];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            // -4 = Building, 0 = Open, 1 = Occupied
            char ch; cin >> ch;
            if(ch == '#') grid[i][j] = -4;
            else if(ch == '.') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }
    // Create an array to count all possible parking spots with the given number of crushed cars
    int crushed[5] = {0};
    // Loop through all 2x2 areas in grid
    for(int i = 1; i < r; i++){
        for(int j = 1; j < c; j++){
            // Calculate number of crushed cars
            int cars = grid[i - 1][j - 1] + grid[i - 1][j] + grid[i][j - 1] + grid[i][j];
            // As long as no building increment count for that amount of cars crushed
            if(cars >= 0) crushed[cars]++;
        }
    }
    // Output all amounts of crushed cars
    for(int i = 0; i < 5; i++) cout << crushed[i] << endl;
    // Return exit code
    return 0;
}