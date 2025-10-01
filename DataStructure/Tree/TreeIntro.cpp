// 🌳 What is a Tree?

// A Tree is a hierarchical data structure (like a family tree).

// It is made up of nodes connected by edges.

// The topmost node is called the Root.

// Each node can have children.

// Nodes with no children are called Leaf nodes.

// 🔹 Tree Terminology

// Root → Starting node (only one).

// Parent → Node which has children.

// Child → Node that comes from a parent.

// Leaf → Node with no children.

// Subtree → Tree formed by any node and its descendants.

// Height → Longest path from root to a leaf.

// Example:

//         1   <-- Root
//        / \
//       2   3
//      / \
//     4   5   <-- Leaf Nodes


#include <iostream>
using namespace std;

// Define a Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Traversal (Inorder)
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    // Creating nodes manually
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);

    return 0;
}
