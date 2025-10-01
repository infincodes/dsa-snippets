#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// Print Doubly Linked List (forward)
void printForward(Node* head) {
    Node* temp = head;
    cout << "Forward: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Print Doubly Linked List (backward)
void printBackward(Node* tail) {
    Node* temp = tail;
    cout << "Backward: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create 3 nodes
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // Connect nodes
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // Print in both directions
    printForward(head);
    printBackward(third);

    return 0;
}
