#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    // array has numbers from 1 to n but one is missing
    int expectedSum = (n * (n + 1)) / 2;
    int actualSum = 0;

    for (int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }

    return expectedSum - actualSum;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; // missing 4
    int n = 6; // since range is 1 to 6
    cout << "Missing number (Linear): " << findMissingLinear(arr, n) << endl;
}
