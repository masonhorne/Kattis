#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;

///////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/minorsetback /
///////////////////////////////////////////////////////////

int main() {
    // Read in number of notes
    int n; cin >> n;
    vector<int> notes;
    // Read in notes and store the numerator of fraction  2 is raised 2
    while(n--){
        double freq; cin >> freq;
        freq /= 440;
        // Divide until it is 2 to power of a fraction
        while(2 <= freq) freq /= 2;
        while(freq < 1) freq *= 2;
        // Push log 2's numerator to note list
        notes.push_back(log2(freq + .00001) * 12);
    }
    // Map of pitches to their values
    unordered_map<string, unordered_map<int, string>> pitches;
    pitches["G major"] = {{10,"G"}, {0,"A"}, {2,"B"}, {3,"C"}, {5,"D"}, {7,"E"}, {9,"F#"}};
    pitches["C major"] = {{3,"C"}, {5,"D"}, {7,"E"}, {8,"F"}, {10,"G"}, {0,"A"}, {2,"B"}};
    pitches["Eb major"] = {{6,"Eb"}, {8,"F"}, {10,"G"}, {11,"Ab"}, {1,"Bb"}, {3,"C"}, {5,"D"}};
    pitches["F# minor"] = {{9,"F#"}, {11,"G#"}, {0,"A"}, {2,"B"}, {4,"C#"}, {5,"D"}, {7,"E"}};
    pitches["G minor"] = {{10,"G"}, {0,"A"}, {1,"Bb"}, {3,"C"}, {5,"D"}, {6,"Eb"}, {8,"F"}};
    // Valid pitches and last encountered valid
    int valid = 0;
    string pitch = "";
    // Try all pitches
    for(auto possible : pitches) {
        bool works = true;
        // Try all notes and if any don't match doesn't work
        for(int freq : notes) {
            if(possible.second.find(freq) == possible.second.end()){
                works = false;
                break;
            }
        }
        // If all worked increment valid count and set pitch
        if(works) {
            valid++;
            pitch = possible.first;
        }
    }
    // If none or more than 1 is matched cannot determine
    if(valid != 1) cout << "cannot determine key" << endl;
    // Otherwise output pitch and the notes names from it
    else {
        cout << pitch << endl;
        for(int freq : notes)
            cout << pitches[pitch][freq] << endl;
    }
    // Return exit code
    return 0; 
}