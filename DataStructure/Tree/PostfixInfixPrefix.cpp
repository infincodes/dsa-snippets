#include <iostream>
using namespace std;

// Node structure for Expression Tree
class Node {
public:
    char data;     // operand or operator
    Node* left;    // left child
    Node* right;   // right child

    Node(char value) {
        data = value;
        left = right = NULL;
    }
};

// Inorder traversal -> Infix
void inorder(Node* root) {
    if (root == NULL) return;
    if(root->left) cout << "(";      // optional for clarity
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
    if(root->right) cout << ")";     // optional for clarity
}

// Preorder traversal -> Prefix
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal -> Postfix
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main() {
    // Building example expression: (A + B) * (C - D)
    Node* root = new Node('*');

    root->left = new Node('+');
    root->right = new Node('-');

    root->left->left = new Node('A');
    root->left->right = new Node('B');

    root->right->left = new Node('C');
    root->right->right = new Node('D');

    cout << "Infix Expression: ";
    inorder(root);
    cout << endl;

    cout << "Prefix Expression: ";
    preorder(root);
    cout << endl;

    cout << "Postfix Expression: ";
    postorder(root);
    cout << endl;

    return 0;
}
