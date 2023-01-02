#include <iostream>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/lyklagangriti /
////////////////////////////////////////////////////////////

// Node structure for doubly linked list
typedef struct NodeStruct {
    // Character for node
    char ch;
    // Node before the current
    NodeStruct *b;
    // Node after the current
    NodeStruct *a;
} Node;

int main(){
    // Initialize head node
    Node *head = (Node *) malloc(sizeof(Node));
    // Set current pointer to head
    Node *current = head;
    // Read input string
    string input; cin >> input;
    // Process the character of string
    for(int i = 0; i < input.length(); i++){
        // If a control character move accordingly
        if (input[i] == 'L'){
            // Move back if left
            current = current->b;
        } else if (input[i] == 'R'){
            // Move forward if right
            current = current->a;
        } else if (input[i] == 'B'){
            // If back delete character by unlinking pointers
            if (current->a == NULL){
                Node *tmp = current;
                current = current->b;
                current->a = NULL;
                free(tmp);
            } else if (current->b == head) {
                Node *tmp = current;
                head->a = current->a;
                current->a->b = head;
                current = head;
                free(tmp);
            }  else {
                Node *tmp = current;
                current = current->b;
                current->a = current->a->a;
                current->a->b = current;
                free(tmp);
            }
        // Otherwise add new node to list
        } else {
            Node *n = (Node *) malloc(sizeof(Node));
            // Relink the node into list
            if(current->a != NULL) {
                current->a->b = n;
            }
            n->b = current;
            n->a = current->a;
            n->ch = input[i];
            current->a = n;
            current = n;
        }
    }
    // Set current to the first real node
    current = head->a;
    // Free dummy head node
    free(head);
    // Loop through list outputting values that remain
    while (current != NULL){
        std::cout << current->ch;
        Node *b = current;
        current = current->a;
        free(b);
    }
    // Output newline
    cout << endl;
    // Return exit code
    return 0;
}
