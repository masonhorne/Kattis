#include<iostream>
#include<stack>
#include<queue>
using namespace std;

////////////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/guessthedatastructure /
////////////////////////////////////////////////////////////////////

int main() {
    // Initialize instruction count
    int t;
    // Proceed while test cases remain
    while(cin >> t){
        // Initialize data structures to simulate
        stack<int> st;
        queue<int> q;
        priority_queue<int> pq;
        // Initialize flags for each
        bool sf = true, qf = true, pqf = true;
        // Read all inputs
        for(int i = 0; i < t; i++){
            // Read action and value
            int a, v; cin >> a >> v;
            // If insert, add to candidates
            if(a == 1){
                if(sf) st.push(v);
                if(qf) q.push(v);
                if(pqf) pq.push(v);
            // Otherwise remove if possible unsetting possible is invalid
            } else {
                // If stack is still active
                if(sf){
                    // If value exists check if match
                    if(st.size()){
                        int p = st.top();
                        st.pop();
                        if(p != v) sf = false;
                    } else sf = false;
                }
                // If queue is still active
                if(qf){
                    // If values exists check if match
                    if(q.size()){
                        int p = q.front();
                        q.pop();
                        if(p != v) qf = false;
                    } else qf = false;
                }
                // If priority queue is still active
                if(pqf){
                    // If values exist check if match
                    if(pq.size()){
                        int p = pq.top();
                        pq.pop();
                        if(p != v) pqf = false;
                    } else pqf = false;
                }
            }
        }
        // Output the resulting datastructure based on boolean flags
        if(sf && !qf && !pqf) cout << "stack" << endl;
        else if(qf && !sf && !pqf) cout << "queue" << endl;
        else if(pqf && !sf && !qf) cout << "priority queue" << endl;
        else if(!pqf && !sf && !qf) cout << "impossible" << endl;
        else cout << "not sure" << endl;
    }
    // Return exit code
    return 0;
}