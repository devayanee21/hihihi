#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
} *head = NULL;

void insertBeg(int x) {
    Node* n = new Node{x, NULL};
    if(!head) head = n, n->next = n;
    else {
        Node* t = head;
        while(t->next != head) t = t->next;
        n->next = head;
        head = n;
        t->next = head;
    }
}

void insertEnd(int x) {
    Node* n = new Node{x, NULL};
    if(!head) head = n, n->next = n;
    else {
        Node* t = head;
        while(t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }
}

void deleteBeg() {
    if(!head) return;
    Node* t = head, *p = head;
    while(p->next != head) p = p->next;
    head = head->next;
    p->next = head;
    delete t;
}

void deleteEnd() {
    if(!head) return;
    Node* t = head, *p = NULL;
    while(t->next != head) p = t, t = t->next;
    if(!p) head = NULL;
    else p->next = head;
    delete t;
}

void show() {
    if(!head) return;
    Node* t = head;
    do { cout<<t->data<<" "; t=t->next; }
    while(t != head);
    cout<<endl;
}

void search(int k) {
    if(!head) return;
    Node* t = head; int i = 1;
    do {
        if(t->data == k) { cout<<"Found at "<<i<<endl; return; }
        i++; t=t->next;
    } while(t != head);
    cout<<"Not Found\n";
}

int main() {
    insertBeg(10); insertEnd(20); insertEnd(30);
    show();
    deleteBeg(); show();
    search(20);
}
