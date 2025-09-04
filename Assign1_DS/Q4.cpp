#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int a[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    int max = a[0], min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }

    cout << "Largest = " << max << endl;
    cout << "Smallest = " << min << endl;
}
