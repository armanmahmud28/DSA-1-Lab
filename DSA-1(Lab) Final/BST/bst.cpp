//Class Code
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};


Node* insertnode(Node* root, int value)
{
    if(root==NULL)
        return new Node(value);
    if(root->data > value)
        root->left= insertnode(root->left, value);
    if(root->data < value)
        root->right= insertnode(root->right, value);

    return root;
}


void inorder(Node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

Node* minNode(Node* root)
{
    Node* current=root;
    while(current->left!=NULL)
    {
        current=current->left;
    }

    return current;
}

Node* maxNode(Node* root)
{
    Node* current=root;
    while(current->right!=NULL)
    {
        current=current->right;
    }

    return current;
}

int main()
{
    Node* root=NULL;

    root=insertnode(root,15);
    root=insertnode(root,13);
    root=insertnode(root, 23);
    root= insertnode(root,7);

    cout<<"Inorder Traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder Traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    postorder(root);
    cout<<endl;

    Node* minimum =minNode(root);
    cout<<"Minimum value: "<<minimum->data<<endl;

    Node* maximum =maxNode(root);
    cout<<"Minimum value: "<<maximum->data<<endl;
}
