#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at start
void insertBeg(int x) {
    Node* n = new Node{x, head};
    head = n;
}

// Insert at end
void insertEnd(int x) {
    Node* n = new Node{x, NULL};
    if (!head) head = n;
    else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
}

// Insert at specific position (1-based index)
void insertPos(int x, int pos) {
    if (pos == 1) return insertBeg(x);
    Node* n = new Node{x, NULL};
    Node* t = head;
    for (int i = 1; i < pos - 1 && t; i++) t = t->next;
    if (!t) return;
    n->next = t->next;
    t->next = n;
}

// Delete at beginning
void deleteBeg() {
    if (!head) return;
    Node* t = head;
    head = head->next;
    delete t;
}

// Delete at end
void deleteEnd() {
    if (!head) return;
    if (!head->next) return deleteBeg();
    Node* t = head;
    while (t->next->next) t = t->next;
    delete t->next;
    t->next = NULL;
}

// Delete at position
void deletePos(int pos) {
    if (!head) return;
    if (pos == 1) return deleteBeg();
    Node* t = head;
    for (int i = 1; i < pos - 1 && t; i++) t = t->next;
    if (!t || !t->next) return;
    Node* del = t->next;
    t->next = del->next;
    delete del;
}

// Search element
void search(int key) {
    Node* t = head;
    int pos = 1;
    while (t) {
        if (t->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        pos++; t = t->next;
    }
    cout << "Not Found!\n";
}

// Display list
void display() {
    Node* t = head;
    cout << "List: ";
    while (t) {
        cout << t->data << " -> ";
        t = t->next;
    }
    cout << "NULL\n";
}

int main() {
    insertBeg(10);
    insertEnd(20);
    insertEnd(30);
    insertPos(15, 2);
    display();

    deleteBeg();
    display();

    deleteEnd();
    display();

    search(20);
    search(100);

    deletePos(2);
    display();
}



/*Operation	How it works
Insert Beginning	Point new node to head → new node becomes head
Insert End	        Traverse to last node → attach new node
Insert Position	Find pos-1 node →    link new node between
Delete Beginning	          Move head to next node → delete old
Delete End	        Traverse till 2nd last → delete last
Delete Position	    Go to pos-1 → remove next node
Search	            Traverse check each node value
Display	            Print all nodes till NULL*/