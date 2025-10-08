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

Node* insertAtBeginning(Node* head, int data){
    Node* newHead = new Node(data, head);
    return newHead;
}

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

Node* insertBeforeNode(Node* head, int data, int x){
    if(head == NULL){
        return NULL;
    }
    if(head->val == x){
        return new Node(data, head);
    }
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->val == x){
            Node* new_node = new Node(data, temp->next);
            temp->next = new_node;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* deleteFromBeginning(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteFromEnd(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node* last = temp->next;
    temp->next = NULL;
    delete last;
    return head;
}

Node* deleteNode(Node* head, int x){
    if(head == NULL){
        return NULL;
    }
    if(head->val == x){
        return deleteFromBeginning(head);
    }
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->val == x){
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int searchNode(Node* head, int x){
    int cnt = 0;
    Node* temp = head;
    while(temp->next != NULL){
        cnt++;
        if(temp->val == x){
            break;
        }
        temp = temp->next;
    }
    return cnt;
}

void display(Node* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
}

int main(){
    Node* head = nullptr;
    int choice;
    do{
        cout << endl << "Enter choice as per menu below : " << endl;
        cout << "1. Insertion at the beginning" << endl;
        cout << "2. Insertion at the end" << endl;
        cout << "3. Insertion before a node" << endl;
        cout << "4. Deletion from the beginning" << endl;
        cout << "5. Deletion from the end" << endl;
        cout << "6. Deletion of a specific node" << endl;
        cout << "7. Searching of a node" << endl;
        cout << "8. Display all node values" << endl;
        cout << "9. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:{
            cout << "Enter node value: ";
            int value;
            cin >> value;
            head = insertAtBeginning(head, value);
            break;
        }
        case 2:{
            cout << "Enter node value: ";
            int value;
            cin >> value;
            head = insertAtEnd(head, value);
            break;
        }
        case 3:{
            cout << "Enter before node value: ";
            int nodeValue;
            cin >> nodeValue;
            cout << "Enter node value: ";
            int value;
            cin >> value;
            head = insertBeforeNode(head, value, nodeValue);
            break;
        }
        case 4:{
            cout << "Deleted " << head->val << endl;
            head = deleteFromBeginning(head);
            break;
        }
        case 5:{
            cout << "Deleted last node" << endl;
            head = deleteFromEnd(head);
            break;
        }
        case 6:{
            cout << "Enter node value to delete: ";
            int nodeValue;
            cin >> nodeValue;
            head = deleteNode(head, nodeValue);
            cout << "Deleted node " << nodeValue << endl;
            break;
        }
        case 7:{
            cout << "Enter node value to search: ";
            int nodeValue;
            cin >> nodeValue;
            int pos = searchNode(head, nodeValue);
            cout << "Node found at position: " << pos << endl;
            break;
        }
        case 8:{
            display(head);
            break;
        }
    }
    }
    while(choice != 9);
    return 0;
}