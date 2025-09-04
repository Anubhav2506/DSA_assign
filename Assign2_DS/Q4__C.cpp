#include <iostream>
#include <cstring>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    char result[100];
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isVowel(str[i]))
            result[k++] = str[i];
    }
    result[k] = '\0';
    cout << "After removing vowels: " << result << endl;
}
