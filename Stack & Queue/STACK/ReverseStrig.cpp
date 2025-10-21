#include <iostream>
using namespace std;

class Stack {
    char *arr;   
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }

    void push(char c) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = c;
    }

   
    char pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    ~Stack() {
        delete[] arr;
    }
};

string reverseString(string str) {
    Stack s(str.length()); 
    string reversed = "";

 
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    
    while (!s.isEmpty()) {
        reversed += s.pop();
    }

    return reversed;
}

int main() {
    string str = "HelloWorld";
    cout << "Original: " << str << endl;
    cout << "Reversed: " << reverseString(str) << endl;
    return 0;
}
