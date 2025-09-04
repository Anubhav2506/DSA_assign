#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    char arr[10][50];

    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i+1 << ": ";
        cin >> arr[i];
    }

    // Bubble sort on strings
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                char temp[50];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }

    cout << "Sorted Strings:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}
