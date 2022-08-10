#include<iostream>
#include<string>
using namespace std;

int main() {
    // Initialize keyword string
    string start = "Simon says ";
    // Get in line count
    string s; getline(cin, s);
    // Process value from string
    int v = 0;
    for(int i = 0; i < s.size(); i++){
        v *= 10;
        v += s[i] - '0';
    }
    // Read in lines outputting valid commands
    while(v--){
        getline(cin, s);
        if(s.substr(0, start.size()) == start) cout << s.substr(start.size(), s.size() - start.size()) << endl;
    }
    // Return exit code
    return 0;
}