#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/noonerizedspumbers /
/////////////////////////////////////////////////////////////////

const unsigned long MAX = (1 << 31);

string valid(string d1, string d2, string d3, string op) {
    // Convert strings to numbers
    long l1 = stol(d1), l2 = stol(d2), l3 = stol(d3);
    // Skip invalid outputs
    if(l1 >= MAX || l2 >= MAX || l3 >= MAX || l1 < 0 || l2 < 0 || l3 < 0) return "";
    // Check if valid equation
    if(op == "+") {
        if(l1 + l2 == l3) return d1 + " + " + d2 + " = " + d3;
    } else {
        if(l1 * l2 == l3) return d1 + " * " + d2 + " = " + d3;
    }
    // Return empty string if not valid
    return "";
}

string solve(string d1, string d2, string d3, string op) {
    // All swaps of digit 1 and digit 2 prefixes
    for(int i = 1; i < d1.size(); i++) {
        for(int j = 1; j < d2.size(); j++) {
            string res = valid(d2.substr(0, j) + d1.substr(i), d1.substr(0, i) + d2.substr(j), d3, op);
            if(res != "") return res;
        }
    }
    // All swaps of digit 1 and digit 3 prefixes
    for(int i = 1; i < d1.size(); i++) {
        for(int k = 1; k < d3.size(); k++) {
            string res = valid(d3.substr(0, k) + d1.substr(i), d2, d1.substr(0, i) + d3.substr(k), op);
            if(res != "") return res;
        }
    }
    // All swaps of digit 2 and digit 3 prefixes
    for(int j = 1; j < d2.size(); j++) {
        for(int k = 1; k < d3.size(); k++) {
            string res = valid(d1, d3.substr(0, k) + d2.substr(j), d2.substr(0, j) + d3.substr(k), op);
            if(res != "") return res;
        }
    }
    // Return empty string if no valid equation
    return "";
}

int main() {
    // Read input equation
    string d1, op, d2, eq, d3;
    cin >> d1 >> op >> d2 >> eq >> d3;
    // Output result
    cout << solve(d1, d2, d3, op) << endl;
    // Return exit code
    return 0;
}