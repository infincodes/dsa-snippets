#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert a node into BST
Node* insert(Node* root, int value) {
    if (root == NULL) return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Find minimum value node in BST
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);  // find inorder successor
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Inorder Traversal (sorted order)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    // Delete nodes
    root = deleteNode(root, 20);  // delete leaf
    root = deleteNode(root, 30);  // delete node with one child
    root = deleteNode(root, 50);  // delete node with two children

    cout << "Inorder Traversal after deletions: ";
    inorder(root);
    cout << endl;

    return 0;
}
