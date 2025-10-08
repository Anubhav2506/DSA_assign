#include <iostream>
using namespace std;

struct Node {
    int val; Node* next;
    Node(int v): val(v), next(nullptr) {}
};

void printList(Node* h) {
    while (h) { cout << h->val << (h->next ? "->" : ""); h = h->next; }
    cout << endl;
}

int length(Node* h) {
    int cnt=0; while (h) { cnt++; h = h->next; } return cnt;
}

Node* reverseKGroup(Node* head, int k) {
    if (!head || k <= 1) return head;
    Node dummy(0); dummy.next = head;
    Node* prevGroup = &dummy;

    while (true) {
        Node* kth = prevGroup;
        for (int i = 0; i < k && kth; ++i) kth = kth->next;
        if (!kth) break; // fewer than k nodes

        Node* groupNext = kth->next;
        // reverse group
        Node* prev = groupNext;
        Node* cur = prevGroup->next;
        while (cur != groupNext) {
            Node* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        // adjust pointers
        Node* tmp = prevGroup->next; // new tail of group
        prevGroup->next = kth;
        prevGroup = tmp;
    }
    return dummy.next;
}

int main() {
    // example: 1->2->3->4->5->6->7->8, k=3 -> 3->2->1->6->5->4->7->8
    Node* head = new Node(1);
    Node* cur = head;
    for (int i = 2; i <= 8; ++i) { cur->next = new Node(i); cur = cur->next; }

    cout << "Original: "; printList(head);
    int k = 3;
    head = reverseKGroup(head, k);
    cout << "After reversing in groups of " << k << ": "; printList(head);

    // cleanup
    while (head) { Node* t = head; head = head->next; delete t; }
    return 0;
}
