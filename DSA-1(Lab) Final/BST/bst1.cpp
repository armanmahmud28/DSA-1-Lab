//Insertion & Searching

#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int item) {
        data = item;
        left = right = nullptr;
    }
};

bool search(Node* root, int key) {
 
    // root is null -> return false
    if (root == nullptr) return false;

    // if root has key -> return true
    if (root->data == key) return true;

    if (key > root->data) 
        return search(root->right, key);
        
    else
        return search(root->left, key);
}

Node* insert(Node* root, int key) {
  
    // If the tree is empty, return a new node
    if (root == NULL) 
        return new Node(key);    
    
    // If the key is already present in the tree,
    // return the node
    if (root->key == key) 
        return root;
    
    // Otherwise, recur down the tree/ If the key
    // to be inserted is greater than the node's key,
    // insert it in the right subtree
    if (root->key < key) 
        root->right = insert(root->right, key);
    
    // If the key to be inserted is smaller than 
    // the node's key,insert it in the left subtree
    else 
        root->left = insert(root->left, key);
    
    // Return the (unchanged) node pointer
    return root;
}


int main() {
    // Creating BST
    //    6
    //   / \
    //  2   8
    //     / \
    //    7   9
    Node* root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 7;
    
    // Searching for key in BST
    cout << search(root, key) << endl;
}