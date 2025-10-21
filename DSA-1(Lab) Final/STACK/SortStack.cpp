
//sorting
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Push element into stack
void push(Node*& top, int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

// Pop element from stack
int pop(Node*& top) {
    if (!top) return -1; // stack empty
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

// Sort a stack using one extra stack
void sortStack(Node*& s) {
    Node* tempStack = nullptr;
    while (s) {
        int temp = pop(s);
        while (tempStack && tempStack->data > temp) {
            push(s, pop(tempStack));
        }
        push(tempStack, temp);
    }
    // Copy back to original stack
    while (tempStack) {
        push(s, pop(tempStack));
    }
}

// Print stack
void printStack(Node* top) {
    while (top) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

int main() {
    Node* stack = nullptr;
    push(stack, 30);
    push(stack, 10);
    push(stack, 20);
    push(stack, 50);
    push(stack, 40);

    sortStack(stack);

    cout << "Sorted Stack: ";
    printStack(stack);
    return 0;
}
