#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Traverse & print
void traverse(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create nodes
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // Link nodes
    head->next = second;
    second->next = third;

    // Traverse & print
    traverse(head);

    return 0;
}
