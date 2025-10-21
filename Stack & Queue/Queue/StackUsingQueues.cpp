//Implement Stack using  Two Queues

#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int frontIndex, rearIndex;
public:
    Queue() { frontIndex = 0; rearIndex = 0; }

    void push(int x) {
        arr[rearIndex++] = x;
    }

    void pop() {
        if (!empty())
            frontIndex++;
    }

    int front() {
        if (!empty())
            return arr[frontIndex];
        return -1;
    }

    bool empty() { return frontIndex == rearIndex; }

    int size() { return rearIndex - frontIndex; }
    
    // helper to move all elements to another queue
    void moveTo(Queue &other) {
        while (!empty()) {
            other.push(front());
            pop();
        }
    }
};

class myStack {
    Queue q1, q2;

public:
    void push(int x) {
        // Push x into empty q2
        q2.push(x);
        // Move all elements from q1 to q2
        q1.moveTo(q2);
        // Move everything back to q1 manually (instead of swap)
        q2.moveTo(q1);
    }

    void pop() {
        if (!q1.empty())
            q1.pop();
    }

    int top() {
        return q1.front();
    }

    int size() {
        return q1.size();
    }
};

int main() {
    myStack st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << st.top() << endl; // 3
    st.pop();
    cout << st.top() << endl; // 2
    st.pop();
    cout << st.top() << endl; // 1

    cout << st.size() << endl; // 1
    return 0;
}
