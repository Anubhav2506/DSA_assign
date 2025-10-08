#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int>& q) {
    int n = q.size();
    queue<int> firstHalf;

    for (int i = 0; i < n/2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(4); q.push(7); q.push(11); q.push(20); q.push(5); q.push(9);

    interleave(q);

    cout << "Interleaved: ";
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    return 0;
}
