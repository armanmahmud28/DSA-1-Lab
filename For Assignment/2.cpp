#include <bits/stdc++.h>
using namespace std;

queue<int> reverseFirstK(queue<int> q, int k) {
    stack<int> s;
    for (int i = 0; i < k && !q.empty(); i++) {
        s.push(q.front());
        q.pop();
    }

    queue<int> result;
    while (!s.empty()) {
        result.push(s.top());
        s.pop();
    }

    while (!q.empty()) {
        result.push(q.front());
        q.pop();
    }

    return result;
}

int main() {
    queue<int> q;
    for (int i = 1; i <= 5; i++) q.push(i);

    int k = 3;
    queue<int> ans = reverseFirstK(q, k);

    cout << "Output: ";
    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;
    return 0;
}
