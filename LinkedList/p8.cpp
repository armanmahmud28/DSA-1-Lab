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

// Function to detect and remove cycle
void detectAndRemoveCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) return;

    Node* slow = head;
    Node* fast = head;

    // Detect cycle
    bool cycleExists = false;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cycleExists = true;
            break;
        }
    }

    if (!cycleExists) {
        cout << "No cycle detected." << endl;
        return;
    }

    // Find the start of the cycle
    slow = head;
    Node* prev = nullptr; // To track the node before slow
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the cycle
    prev->next = nullptr;

    cout << "Cycle detected and removed. Cycle started at node with value: " << slow->data << endl;
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
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create a cycle: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveCycle(head);

    cout << "Linked List after removing cycle: ";
    printList(head);

    return 0;
}
