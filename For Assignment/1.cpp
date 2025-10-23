#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> st;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            st.push(stoi(token));
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (token[0]) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

int main() {
    string expr = "5 1 2 + 4 * + 3 -";
    cout << "Final Result: " << evaluatePostfix(expr) << endl;
    return 0;
}
