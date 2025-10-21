#include <iostream>
using namespace std;

// Node class for singly linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to create linked list from array
Node* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* temp = head;

    for (int i = 1; i < n; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Function to find the middle node
Node* findMiddle(Node* head) {
    if (!head) return nullptr;

    Node* slow = head;
    Node* fast = head;

    // Move fast by 2 steps and slow by 1 step
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Main function
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = createLinkedList(arr, n);

    Node* middle = findMiddle(head);

    if (middle) {
        cout << "Middle Node: " << middle->data << endl;
    } else {
        cout << "List is empty!" << endl;
    }

    return 0;
}
