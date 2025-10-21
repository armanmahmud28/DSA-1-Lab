
//Reverse Stack using Linked List
#include <iostream>
using namespace std;

class StackNode {
public:
    int data;
    StackNode* next;

    StackNode(int newdata) {
        data = newdata;
        next = nullptr;
    }
};

class Stack {
    StackNode* top;
public:
    Stack() { top = nullptr; }

    void push(int data) {
        StackNode* s = new StackNode(data);
        s->next = top;
        top = s;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        StackNode* temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    void display() {
        StackNode* s = top;
        while (s != nullptr) {
            cout << s->data << " ";
            s = s->next;
        }
        cout << endl;
    }

    void reverse() {
        StackNode *prev = nullptr, *cur = top, *succ = nullptr;

        while (cur != nullptr) {
            succ = cur->next;
            cur->next = prev;
            prev = cur;
            cur = succ;
        }
        top = prev;
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Original stack: ";
    st.display();   // 40 30 20 10

    st.reverse();

    cout << "Reversed stack: ";
    st.display();   // 10 20 30 40
}
