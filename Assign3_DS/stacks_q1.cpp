#include <iostream>
using namespace std;

#define STACKMAX 5  

class Stack {
    int arr[STACKMAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == STACKMAX - 1);
    }

    void push(int x) {
        if (isFull()) {
            cout << "STACK OVERFLOW, CANNOT PUSH " << x << endl;
        } else {
            arr[++top] = x;
            cout << x << " PUSHED INTO STACK." << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "STACK UNDERFLOW,CANNOT POP" << endl;
        } else {
            cout << arr[top--] << " POPPED FROM STACK" << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "STACK IS EMPTY" << endl;
        } else {
            cout << "Stack elements (top → bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
};


int main() {
    Stack st;
    int choice, value;

    while (true) {
        cout << "\n Stack Operations :" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                st.push(value);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                cout << "Stack is Empty: " << (st.isEmpty() ? "Yes" : "No") << endl;
                break;
            case 4:
                cout << "Stack is Full: " << (st.isFull() ? "Yes" : "No") << endl;
                break;
            case 5:
                st.display();
                break;
            case 6:
                st.peek();
                break;
            case 7:
                cout << "Program terminated succesfully" << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
}