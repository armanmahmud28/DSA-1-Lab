#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// Function to find the maximum value in BST
int maxValue(Node* root) {
   
    if (root == NULL) {
        return -1;
    }

    Node* curr = root;

    
    while (curr->right != NULL) {
        curr = curr->right;
    }

    
    return curr->data;
}

int main() {
    // Representation of input binary search tree
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

    cout << maxValue(root) << endl;
    return 0;
}