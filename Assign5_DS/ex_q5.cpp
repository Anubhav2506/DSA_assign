#include <iostream>
using namespace std;

struct PolyNode {
    int coeff, pow;
    PolyNode* next;
    PolyNode(int c, int p) : coeff(c), pow(p), next(nullptr) {}
};

void printPoly(PolyNode* head) {
    bool first = true;
    while (head) {
        if (!first) cout << " + ";
        cout << head->coeff << "x^" << head->pow;
        first = false;
        head = head->next;
    }
    cout << endl;
}

PolyNode* addPoly(PolyNode* p1, PolyNode* p2) {
    PolyNode dummy(0, 0);
    PolyNode* tail = &dummy;

    while (p1 && p2) {
        if (p1->pow == p2->pow) {
            int c = p1->coeff + p2->coeff;
            if (c != 0) { tail->next = new PolyNode(c, p1->pow); tail = tail->next; }
            p1 = p1->next; p2 = p2->next;
        } else if (p1->pow > p2->pow) {
            tail->next = new PolyNode(p1->coeff, p1->pow); tail = tail->next;
            p1 = p1->next;
        } else {
            tail->next = new PolyNode(p2->coeff, p2->pow); tail = tail->next;
            p2 = p2->next;
        }
    }
    while (p1) { tail->next = new PolyNode(p1->coeff, p1->pow); tail = tail->next; p1 = p1->next; }
    while (p2) { tail->next = new PolyNode(p2->coeff, p2->pow); tail = tail->next; p2 = p2->next; }

    return dummy.next;
}

int main() {
    // list1: 5x^2 + 4x^1 + 2x^0  -> [[5,2], [4,1], [2,0]]
    PolyNode* p1 = new PolyNode(5, 2);
    p1->next = new PolyNode(4, 1);
    p1->next->next = new PolyNode(2, 0);

    // list2: 5x^1 + 5x^0 -> [[5,1], [5,0]]
    PolyNode* p2 = new PolyNode(5, 1);
    p2->next = new PolyNode(5, 0);

    cout << "Poly1: "; printPoly(p1);
    cout << "Poly2: "; printPoly(p2);

    PolyNode* sum = addPoly(p1, p2);
    cout << "Sum: "; printPoly(sum);

    // cleanup
    auto freePoly = [](PolyNode* &h){
        while (h) { PolyNode* t = h; h = h->next; delete t; }
    };
    freePoly(p1); freePoly(p2); freePoly(sum);

    return 0;
}
