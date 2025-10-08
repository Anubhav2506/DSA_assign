#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int s : students) q.push(s);

    int idx = 0, count = 0;
    while (!q.empty() && count < q.size()) {
        if (q.front() == sandwiches[idx]) {
            q.pop();
            idx++;
            count = 0;
        } else {
            q.push(q.front());
            q.pop();
            count++;
        }
    }
    return q.size();
}

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    int res = countStudents(students, sandwiches);
    cout << "Number of students unable to eat: " << res << endl;
    return 0;
}
