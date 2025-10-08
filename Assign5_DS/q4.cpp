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

void display(Node* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
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
    head = reverseLL(head);
    cout << "Reverse : " << endl;
    display(head);
    return 0;
}