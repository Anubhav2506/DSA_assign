#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string s) {
    unordered_map<char,int> freq;
    queue<char> q;

    for (char ch : s) {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1)
            q.pop();

        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
}

int main() {
    string s = "aabc";
    firstNonRepeating(s);
    return 0;
}
