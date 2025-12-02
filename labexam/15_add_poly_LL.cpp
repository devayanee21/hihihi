#include <iostream>
using namespace std;

struct Node {
    int coef, exp;
    Node* next;
};

Node* addNode(Node* head, int c, int e) {
    Node* n = new Node{c, e, head};
    return n;
}

Node* addPoly(Node* p1, Node* p2) {
    Node* res = NULL;
    while(p1 && p2) {
        if(p1->exp == p2->exp) {
            res = addNode(res, p1->coef + p2->coef, p1->exp);
            p1 = p1->next; p2 = p2->next;
        }
        else if(p1->exp > p2->exp)
            res = addNode(res, p1->coef, p1->exp), p1 = p1->next;
        else
            res = addNode(res, p2->coef, p2->exp), p2 = p2->next;
    }
    return res;
}

void show(Node* p) {
    while(p) { cout << p->coef << "x^" << p->exp << " "; p = p->next; }
}

int main() {
    Node *p1 = NULL, *p2 = NULL;
    p1 = addNode(p1, 2, 1); p1 = addNode(p1, 3, 2);
    p2 = addNode(p2, 4, 1); p2 = addNode(p2, 2, 2);
    Node* sum = addPoly(p1, p2);
    show(sum);
}
/*

1️⃣ Each node has: coefficient, exponent, next link
2️⃣ We walk both lists together
3️⃣ If same exponent → add coefficients
4️⃣ Result is a new linked list storing final polynomial

“Linked lists let us store only required polynomial terms without wasting memory.”

*/