#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to merge two sorted linked lists
Node* mergeLists(Node* l1, Node* l2) {
    Node dummy(0); // Dummy node
    Node* tail = &dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (l1 != nullptr) tail->next = l1;
    if (l2 != nullptr) tail->next = l2;

    return dummy.next;
}

// Utility function to print linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // First sorted list: 1 -> 3 -> 5
    Node* l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(5);

    // Second sorted list: 2 -> 4 -> 6
    Node* l2 = new Node(2);
    l2->next = new Node(4);
    l2->next->next = new Node(6);

    Node* merged = mergeLists(l1, l2);

    cout << "Merged Sorted List: ";
    printList(merged);

    return 0;
}
