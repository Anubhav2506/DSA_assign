#include <iostream>
using namespace std;

struct Node {
    int val; Node* next;
    Node(int v): val(v), next(nullptr) {}
};

void printList(Node* head) {
    while (head) { cout << head->val << (head->next ? "->" : ""); head = head->next; }
    cout << endl;
}

bool detectAndRemoveLoop(Node* head) {
    if (!head || !head->next) return false;
    Node* slow = head; Node* fast = head;

    // detect
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) return false; // no loop

    // find start of loop
    slow = head;
    Node* prev = fast; // will be last node in loop after we find start
    while (slow != fast) {
        slow = slow->next;
        prev = fast;
        fast = fast->next;
    }
    // 'slow' (== fast) is start of loop; 'prev' is the node before start in cycle
    prev->next = nullptr; // remove loop
    return true;
}

int main() {
    // create list: 1->2->3->4->5->3 (loop starts at 3)
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    // make loop: node 5 -> node 3
    head->next->next->next->next->next = head->next->next;

    cout << "Loop created. Attempting detect and remove...\n";
    bool removed = detectAndRemoveLoop(head);
    cout << (removed ? "Loop found and removed.\n" : "No loop found.\n");

    cout << "List after removal: ";
    printList(head);

    // cleanup
    while (head) { Node* t = head; head = head->next; delete t; }
    return 0;
}
