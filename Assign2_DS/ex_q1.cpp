#include <iostream>
#include <unordered_set>
using namespace std;

int countPairsWithDiff(int arr[], int n, int k) {
    unordered_set<int> s(arr, arr+n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s.find(arr[i] + k) != s.end()) count++;
        if (s.find(arr[i] - k) != s.end()) count++;
    }
    return count / 2; // each pair counted twice
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = 5, k = 2;
    cout << "Count: " << countPairsWithDiff(arr, n, k) << endl;
    return 0;
}
