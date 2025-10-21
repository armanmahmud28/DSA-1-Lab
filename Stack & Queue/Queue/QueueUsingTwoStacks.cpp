//Implement Queue using two stakes 

#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int topIndex;
public:
    Stack() { topIndex = -1; }

    void push(int x) {
        arr[++topIndex] = x;
    }

    void pop() {
        if (!empty()) topIndex--;
    }

    int top() {
        if (!empty()) return arr[topIndex];
        return -1; // empty stack
    }

    bool empty() { return topIndex == -1; }
    int size() { return topIndex + 1; }
};

class myQueue {
    Stack s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);  // always push to s1
    }

    void dequeue() {
        if (s2.empty()) {
            // Move all elements from s1 to s2
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty())
            s2.pop();
    }

    int front() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    int size() {
        return s1.size() + s2.size();
    }
};

int main() {
    myQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.front() << endl; // 1
    //q.dequeue();
    cout << q.front() << endl; // 2
    //q.dequeue();
    cout << q.front() << endl; // 3

    cout << q.size() << endl; // 1
    return 0;
}
