#include <iostream>
#include <string>
using namespace std;

bool canSplit(string s) {
    int n = s.size();
    for (int i = 1; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            string a = s.substr(0, i);
            string b = s.substr(i, j-i);
            string c = s.substr(j);

            // check all 3 cases
            if ((a.find(b) != string::npos && c.find(b) != string::npos) ||
                (b.find(a) != string::npos && c.find(a) != string::npos) ||
                (a.find(c) != string::npos && b.find(c) != string::npos))
                return true;
        }
    }
    return false;
}

int main() {
    string s = "abcabcxabc";
    cout << (canSplit(s) ? "YES" : "NO") << endl;
    return 0;
}
