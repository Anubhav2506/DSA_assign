#include <iostream>
#include <queue>
using namespace std;

// return index of minimum element in queue up to limit
int minIndex(queue<int>& q, int sortIndex) {
    int min_idx = -1;
    int min_val = INT_MAX;
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int curr = q.front(); q.pop();
        if (curr <= min_val && i <= sortIndex) {
            min_val = curr;
            min_idx = i;
        }
        q.push(curr);
    }
    return min_idx;
}

// move minimum element at given index to rear
void insertMinToRear(queue<int>& q, int min_index) {
    int n = q.size();
    int min_val;
    for (int i = 0; i < n; i++) {
        int curr = q.front(); q.pop();
        if (i == min_index) min_val = curr;
        else q.push(curr);
    }
    q.push(min_val);
}

void sortQueue(queue<int>& q) {
    for (int i = 1; i <= q.size(); i++) {
        int min_index = minIndex(q, q.size()-i);
        insertMinToRear(q, min_index);
    }
}

int main() {
    queue<int> q;
    q.push(11); q.push(5); q.push(4); q.push(21);

    cout << "Original: ";
    queue<int> tmp = q;
    while (!tmp.empty()) { cout << tmp.front() << " "; tmp.pop(); }
    cout << endl;

    sortQueue(q);

    cout << "Sorted: ";
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    return 0;
}
