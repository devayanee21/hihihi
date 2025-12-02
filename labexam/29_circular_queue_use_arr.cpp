#include <iostream>
using namespace std;

int q[5], front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % 5 == front) {
        cout << "Full\n";
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % 5;
    q[rear] = x;
}

void dequeue() {
    if (front == -1) {
        cout << "Empty\n";
        return;
    }
    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % 5;
    }
}

void display() {
    if (front == -1) {
        cout << "Empty\n";
        return;
    }
    int i = front;
    while (true) {
        cout << q[i] << " ";
        if (i == rear) break;
        i = (i + 1) % 5;
    }
    cout << endl;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();
}
