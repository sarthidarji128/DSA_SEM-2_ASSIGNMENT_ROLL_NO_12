#include <iostream>
using namespace std;
// Define the structure for the BST nodes
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Define the BST class
class BinarySearchTree {
private:
    Node* root;

    // Helper function to insert a new node
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Helper function for in-order traversal
    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    // Helper function to search for a value
    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        }
        if (value < node->data) {
            return search(node->left, value);
        }
        return search(node->right, value);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Public function to insert a value
    void insert(int value) {
        root = insert(root, value);
    }

    // Public function to check if a value exists in the tree
    bool search(int value) {
        return search(root, value);
    }

    // Public function to perform in-order traversal
    void inOrderTraversal() {
        inOrderTraversal(root);
        cout << endl;
    }
};

// Example usage
int main() {
    BinarySearchTree bst;
    bst.insert(0);
    bst.insert(5);
    bst.insert(15);
    bst.insert(30);
    bst.insert(0);

    cout << "In-order Traversal: ";
    bst.inOrderTraversal();

    cout << "Search for 5: " << (bst.search(5) ? "Found" : "Not Found") << endl;
    cout << "Search for 20: " << (bst.search(20) ? "Found" : "Not Found") << endl;

    return 0;
}
