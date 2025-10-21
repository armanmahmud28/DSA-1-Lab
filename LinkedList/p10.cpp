#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to remove duplicates from sorted linked list
void removeDuplicates(Node* head) {
    Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            // Duplicate found, remove it
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;  // free memory
        } else {
            current = current->next;
        }
    }
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Example: 10 -> 20 -> 20 -> 30 -> 30 -> 30 -> 40 -> NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    head->next->next->next = new Node(30);
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->next = new Node(30);
    head->next->next->next->next->next->next = new Node(40);

    cout << "Original List: ";
    printList(head);

    removeDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}
