#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

int minValue(Node* root) {
    
    // If left child is null, root is minimum
    if (root->left == nullptr) return root->data;
    
    // Recurse on left child
    return minValue(root->left);
}

int main() {
    // Create BST
    //        5
    //       / \
    //      4   6
    //     /     \
    //    3       7
    //   / 
    //  1
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->right->right = new Node(7);
    root->left->left->left = new Node(1);

    cout << minValue(root) << endl;
}
