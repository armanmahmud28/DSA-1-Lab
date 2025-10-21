#include <iostream>
#include <queue>
using namespace std;

class myStack {
    queue<int> q1, q2;

public:
    void push(int x) {
        // Always push into empty queue and transfer elements from other queue
        if (q1.empty() && q2.empty()) {
            q1.push(x);
        } else if (!q1.empty()) {
            q2.push(x);
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        } else {
            q1.push(x);
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
    }

    void pop() {
        if (!q1.empty()) {
            q1.pop();
        } else if (!q2.empty()) {
            q2.pop();
        }
    }

    int top() {
        if (!q1.empty())
            return q1.front();
        else if (!q2.empty())
            return q2.front();
        return -1; // Stack empty
    }

    int size() {
        return q1.size() + q2.size();
    }

    bool empty() {
        return q1.empty() && q2.empty();
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
