#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    Node* n = new Node();
    n->data = x;
    n->next = NULL;

    if (front == NULL) {
        front = rear = n;
    }
    else {
        rear->next = n;
        rear = n;
    }
}

void dequeue() {
    if (front == NULL) {
        cout << "Empty\n";
        return;
    }
    Node* temp = front;
    front = front->next;
    delete temp;
}

void display() {
    Node* t = front;
    while (t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    display();
    dequeue();
    display();
}
