#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class MinStack {
private:
    Node* stack;
    Node* minStack;

public:
    MinStack() : stack(nullptr), minStack(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = stack;
        stack = newNode;

        if (!minStack || value <= minStack->data) {
            Node* minNode = new Node(value);
            minNode->next = minStack;
            minStack = minNode;
        }
    }

    int pop() {
        if (!stack) return -1;
        int val = stack->data;
        Node* temp = stack;
        stack = stack->next;
        delete temp;

        if (val == minStack->data) {
            Node* tempMin = minStack;
            minStack = minStack->next;
            delete tempMin;
        }
        return val;
    }

    int getMin() {
        if (!minStack) return -1;
        return minStack->data;
    }
};

int main() {
    MinStack s;
    s.push(10);
    s.push(20);
    s.push(5);

    cout << "Minimum Element: " << s.getMin() << endl;
    return 0;
}
