#include<iostream>
#include<string>
using namespace std;

//////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/fiftyshades /
//////////////////////////////////////////////////////////

int main() {
    // Read in number of inputs
    int n; cin >> n;
    // Initialize count to 0
    int c = 0;
    // Process all input classes
    while(n--){
        // Read input name
        string s; cin >> s;
        // Convert input to lowercase
        for(int i = 0; i < s.size(); i++){
            if(s[i] < 'a'){
                int v = s[i] - 'A';
                s[i] = 'a' + v;
            }
        }
        // If pink or rose appears, increment count
        for(int i = 0; i < s.size() - 3; i++){
            if((s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'n' && s[i + 3] == 'k') || (s[i] == 'r' && s[i + 1] == 'o' && s[i + 2] == 's' && s[i + 3] == 'e')) {
                c++;
                break;
            }
        }
    }
    // Output either excuse message or count
    if(c == 0) cout << "I must watch Star Wars with my daughter" << endl;
    else cout << c << endl;
    // Return exit code
    return 0;
}