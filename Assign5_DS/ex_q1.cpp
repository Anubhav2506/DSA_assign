#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

// helper to print list
void printList(Node* head) {
    while (head) { cout << head->val << (head->next ? " -> " : ""); head = head->next; }
    cout << endl;
}

// returns intersection node or nullptr
Node* getIntersection(Node* headA, Node* headB) {
    if (!headA || !headB) return nullptr;
    Node* a = headA;
    Node* b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

int main() {
    // create first list: 4->1->8->5
    Node* a1 = new Node(4);
    a1->next = new Node(1);
    Node* intersect = new Node(8);
    intersect->next = new Node(5);
    a1->next->next = intersect;

    // create second list: 5->6->1->(8->5)
    Node* b1 = new Node(5);
    b1->next = new Node(6);
    b1->next->next = new Node(1);
    b1->next->next->next = intersect; // join here

    cout << "List A: "; printList(a1);
    cout << "List B: "; printList(b1);

    Node* ans = getIntersection(a1, b1);
    if (ans) cout << "Intersected at node with value: " << ans->val << endl;
    else cout << "No intersection\n";

    // cleanup (for demo purpose only; in real contest you may skip freeing)
    // Note: since nodes are shared, free carefully
    delete a1->next->next->next; // deletes node 5
    delete a1->next->next;       // deletes node 8
    delete a1->next;             // node 1 in A
    delete a1;                   // node 4
    delete b1->next->next;       // node 1 in B
    delete b1->next;             // node 6
    delete b1;                   // node 5
    return 0;
}
