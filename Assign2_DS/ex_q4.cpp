#include <iostream>
using namespace std;

void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n-1;
    while (mid <= high) {
        if (arr[mid] == 0) swap(arr[low++], arr[mid++]);
        else if (arr[mid] == 1) mid++;
        else swap(arr[mid], arr[high--]);
    }
}

int main() {
    int arr[] = {0,1,2,1,0,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort012(arr, n);
    cout << "Sorted: ";
    for (int x : arr) cout << x << " ";
    return 0;
}
