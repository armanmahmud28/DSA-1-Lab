#include <iostream>
using namespace std;

// Definition for singly-linked list
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to find middle node
Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // 'slow' will be the middle node
}

// Helper function to print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Linked List: ";
    printList(head);

    Node* middle = findMiddle(head);
    cout << "Middle Node: " << middle->data << endl;

    return 0;
}
