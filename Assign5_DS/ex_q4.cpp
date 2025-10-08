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

Node* rotateLeft(Node* head, int k) {
    if (!head || k == 0) return head;
    // compute length and tail
    Node* tail = head;
    int n = 1;
    while (tail->next) { tail = tail->next; ++n; }

    k = k % n;
    if (k == 0) return head;

    // connect tail to head to form circle
    tail->next = head;

    // new tail is node at position k-1 (0-indexed)
    Node* newTail = head;
    for (int i = 1; i < k; ++i) newTail = newTail->next;
    Node* newHead = newTail->next;

    newTail->next = nullptr;
    return newHead;
}

int main() {
    // example: 1->2->3->4->5->6, k=4 -> rotate left by 4 => 5->6->1->2->3->4
    Node* head = new Node(1);
    Node* cur = head;
    for (int i = 2; i <= 6; ++i) { cur->next = new Node(i); cur = cur->next; }

    cout << "Original: "; printList(head);
    int k = 4;
    head = rotateLeft(head, k);
    cout << "After rotating left by " << k << ": "; printList(head);

    // cleanup
    while (head) { Node* t = head; head = head->next; delete t; }
    return 0;
}
