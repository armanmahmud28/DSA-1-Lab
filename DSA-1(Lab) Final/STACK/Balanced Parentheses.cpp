#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(char c) {
        if (!isFull()) {
            arr[++top] = c;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        return 0; // return null char if stack empty
    }

    char peek() {
        if (!isEmpty()) return arr[top];
        return '\0';
    }
};

bool isBalanced(string exp) {
    Stack st;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            st.push('(');
        } else if (exp[i] == ')') {
            if (st.isEmpty()) return false;
            st.pop();
        }
    }
    return st.isEmpty();
}

int main() {
    string exp;
    cout << "Enter an expression: ";
    cin >> exp;

    if (isBalanced(exp))
        cout << "Balanced: Yes" << endl;
    else
        cout << "Balanced: No" << endl;

    return 0;
}
