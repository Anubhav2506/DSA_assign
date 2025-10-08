#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSorted(queue<int> q) {
    stack<int> st;
    int expected = 1;
    int n = q.size();

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        if (f == expected) expected++;
        else {
            if (!st.empty() && st.top() < f) return false;
            st.push(f);
        }
        while (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }
    }
    return (expected - 1 == n);
}

int main() {
    queue<int> q;
    q.push(5); q.push(1); q.push(2); q.push(3); q.push(4);

    if (checkSorted(q)) cout << "Yes, can be sorted\n";
    else cout << "No\n";
    return 0;
}
