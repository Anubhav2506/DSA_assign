#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int a[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "Reversed array: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }
}
