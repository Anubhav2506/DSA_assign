#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // not found
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 7, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int lin = linearSearch(arr, n, key);
    int bin = binarySearch(arr, n, key);

    if (lin != -1) cout << "Linear Search: Found at index " << lin << endl;
    else cout << "Linear Search: Not found\n";

    if (bin != -1) cout << "Binary Search: Found at index " << bin << endl;
    else cout << "Binary Search: Not found\n";
}
