#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};


void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


Node* deleteAtBeginning(Node* head) {
    if (head == NULL) return NULL; // empty list
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}


Node* deleteAtEnd(Node* head) {
    if (head == NULL) return NULL; // empty list
    if (head->next == NULL) {      // only one node
        delete head;
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

Node* deleteAtPosition(Node* head, int pos) {
    if (head == NULL) return NULL;
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return head; // position out of range

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;

    return head;
}

int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original List: ";
    printList(head);


    head = deleteAtBeginning(head);
    cout << "After deleting at beginning: ";
    printList(head);

    head = deleteAtEnd(head);
    cout << "After deleting at end: ";
    printList(head);


    head = deleteAtPosition(head, 2);
    cout << "After deleting at position 2: ";
    printList(head);

    return 0;
}
