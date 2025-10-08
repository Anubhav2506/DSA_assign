#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    int possibleDups = 0;
    int length = n - 1;

    for (int left = 0; left <= length - possibleDups; left++) {
        if (arr[left] == 2) {
            if (left == length - possibleDups) {
                arr[length] = 2;
                length -= 1;
                break;
            }
            possibleDups++;
        }
    }

    int last = length - possibleDups;
    for (int i = last; i >= 0; i--) {
        if (arr[i] == 2) {
            arr[i + possibleDups] = 2;
            possibleDups--;
            arr[i + possibleDups] = 2;
        } else {
            arr[i + possibleDups] = arr[i];
        }
    }
}

int main() {
    int arr[] = {1,2,3,2,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    duplicateTwos(arr, n);

    cout << "Modified: ";
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}
