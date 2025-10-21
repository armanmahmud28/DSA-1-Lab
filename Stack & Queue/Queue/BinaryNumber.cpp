#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Queue {
    string arr[MAX];
    int front, rear;
public:
    Queue() { front = 0; rear = -1; }

    bool isEmpty() { return front > rear; }
    bool isFull() { return rear == MAX - 1; }

    void enqueue(string val) {
        if (!isFull()) {
            arr[++rear] = val;
        }
    }

    string dequeue() {
        if (!isEmpty()) {
            return arr[front++];
        }
        return "";
    }
};

void generateBinary(int n) {
    Queue q;
    q.enqueue("1");

    cout << "Binary Numbers: ";
    for (int i = 1; i <= n; i++) {
        string s = q.dequeue();
        cout << s << " ";

        q.enqueue(s + "0");
        q.enqueue(s + "1");
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    generateBinary(n);

    return 0;
}
