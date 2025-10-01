#include <iostream>
using namespace std;

// Define a Node
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

int main() {
    
    Node* head = new Node(10);  
    Node* second = new Node(20);
    Node* third = new Node(30);
    head->next = second;
    second->next = third;
    third->next = NULL; 
    printList(head);

    return 0;
}
