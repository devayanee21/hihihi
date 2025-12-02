#include <iostream>
using namespace std;

struct GNode {
    char data;
    GNode *next, *down;
};

GNode* node(char d) {
    return new GNode{d, NULL, NULL};
}

void show(GNode* p) {
    cout << "(";
    while(p) {
        if(p->down) show(p->down);
        else cout << p->data;
        if(p->next) cout << ", ";
        p = p->next;
    }
    cout << ")";
}

int main() {
    GNode *A = node('A');
    GNode *B = node('B');
    GNode *C = node('C');
    GNode *D = node('D');

    A->next = B;
    B->next = D;
    B->down = C; // Nested list

    show(A);
}



/*1️⃣ Some nodes store normal data (data pointer used)
2️⃣ Some nodes point to another list using down pointer
3️⃣ This creates a nested / hierarchical structure
4️⃣ Print uses recursion to print full structure
“GLL supports nested lists, just like folders inside folders.”
*/