#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n) {
    queue<string> q;
    q.push("1");

    for (int i = 1; i <= n; i++) {
        string s = q.front();
        q.pop();
        cout << s << " ";
        q.push(s + "0");
        q.push(s + "1");
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    generateBinary(n);
    return 0;
}
