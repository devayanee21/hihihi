#include <iostream>
using namespace std;

int dq[5];
int front = -1, rear = -1;

void insertFront(int x) {
    if (front == -1) {
        front = rear = 0;
    }
    else {
        front--;
    }
    dq[front] = x;
}

void insertRear(int x) {
    if (rear == -1) {
        front = rear = 0;
    }
    else {
        rear++;
    }
    dq[rear] = x;
}

void deleteFront() {
    if (front == -1) {
        cout << "Empty\n";
        return;
    }
    front++;
}

void deleteRear() {
    if (rear == -1) {
        cout << "Empty\n";
        return;
    }
    rear--;
}

void display() {
    for (int i = front; i <= rear; i++) {
        cout << dq[i] << " ";
    }
    cout << endl;
}

int main() {
    insertFront(10);
    insertRear(20);
    display();
}
