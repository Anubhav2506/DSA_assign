#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    public:
    Node(int val1, Node* next1){
        val = val1;
        next = next1;
    }

    public:
    Node(int val1){
        val =val1;
        next = nullptr;
    }

};

Node* insertAtEnd(Node* head, int data){
    if(head == NULL){
        return new Node(data);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* tail = new Node(data);
    temp->next = tail;
    return head;
}


void display(Node* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int count(Node* head, int value){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        if(temp->val == value){
            cnt++;
        }
        temp = temp->next;
    }
    return cnt;
}

Node* delOccurrences(Node* head, int value) {
    while (head != NULL && head->val == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->val == value) {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    Node* head = nullptr;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: " << endl;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n; i++){
        head = insertAtEnd(head, arr[i]);
    }
    cout << "Enter key : ";
    int value;
    cin >> value;
    cout << "Count : " << count(head, value) << endl;
    head = delOccurrences(head, value);
    cout << "Updated Linked List : ";
    display(head);
    return 0;
}