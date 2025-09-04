#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0, choice, pos, val, key;

    while (1) {
        cout << "\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Search\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter size: ";
            cin >> n;
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++) cin >> arr[i];
        }
        else if (choice == 2) {
            cout << "Array: ";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
        }
        else if (choice == 3) {
            cout << "Enter position and value: ";
            cin >> pos >> val;
            for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
            arr[pos] = val;
            n++;
        }
        else if (choice == 4) {
            cout << "Enter position: ";
            cin >> pos;
            for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
            n--;
        }
        else if (choice == 5) {
            cout << "Enter key: ";
            cin >> key;
            int f = 0;
            for (int i = 0; i < n; i++) {
                if (arr[i] == key) {
                    cout << "Found at index " << i << endl;
                    f = 1;
                }
            }
            if (!f) cout << "Not found\n";
        }
        else if (choice == 6) break;
        else cout << "Invalid choice!\n";
    }
}
