#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
} *head = NULL;

void insertBeg(int x) {
    Node *n = new Node;
    n->data = x;
    n->next = head;
    n->prev = NULL;
    if (head) head->prev = n;
    head = n;
}

void insertEnd(int x) {
    Node *n = new Node;
    n->data = x;
    n->next = NULL;
    if (!head) { n->prev = NULL; head = n; return; }
    Node *t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void delBeg() {
    if (!head) return;
    Node* t = head;
    head = head->next;
    if (head) head->prev = NULL;
    delete t;
}

void delEnd() {
    if (!head) return;
    Node *t = head;
    while (t->next) t = t->next;
    if (t->prev) t->prev->next = NULL;
    else head = NULL;
    delete t;
}

void search(int key) {
    int pos = 1;
    for (Node* t = head; t; t = t->next, pos++)
        if (t->data == key) { cout<<"Found at "<<pos<<endl; return; }
    cout<<"Not Found"<<endl;
}

void show() {
    cout<<"Forward: ";
    Node* t = head;
    while (t) { cout<<t->data<<" "; t=t->next; }
    cout<<"\nReverse: ";
    while (t && t->prev) t=t->prev;
    t = head;
    while (t && t->next) t=t->next;
    while (t) { cout<<t->data<<" "; t=t->prev; }
    cout<<endl;
}

int main() {
    insertBeg(10);
    insertEnd(20);
    insertEnd(30);
    show();
    delBeg(); show();
    search(20);
}


/*“In a doubly linked list, each node has two pointers — next and prev.
This helps in moving forward and backward easily.
Deleting from end is easy because we already have a prev pointer.”*/
