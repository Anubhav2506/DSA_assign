#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int a[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "After removing duplicates: ";
    for (int i = 0; i < n; i++) {
        bool repeat = false;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                repeat = true;
                break;
            }
        }
        if (!repeat) cout << a[i] << " ";
    }
}
