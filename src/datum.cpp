#include<iostream>
using namespace std;

////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/datum /
////////////////////////////////////////////////////

int main() {
    // Number of days in each month
    int dim[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Prefix sum array of all days leading to a given month
    int psum[12] = {0};
    // Calculate prefix sums
    for(int i = 1; i < 12; i++)
        psum[i] = psum[i - 1] + dim[i - 1];
    // Read inputs and add the number of days for the month provided
    int d, m; cin >> d >> m;
    // NOTE: 2009 Started on a Thursday
    int day = 4;
    // Add all days to the current date
    day += (d - 1) + psum[m - 1];
    // Mod by 7 for day of week index
    day %= 7;
    // Output day of the week
    switch(day) {
        case 0:
            cout << "Sunday" << endl;
            break;
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
    }
    // Return exit code
    return 0;
}