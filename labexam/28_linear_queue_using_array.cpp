#include <iostream>
using namespace std;

int q[5], front = 0, rear = -1;

void enqueue(int x) {
    if (rear == 4) {
        cout << "Queue Overflow\n";
        return;
    }
    rear++;
    q[rear] = x;
}

void dequeue() {
    if (front > rear) {
        cout << "Queue Underflow\n";
        return;
    }
    front++;
}

void display() {
    for (int i = front; i <= rear; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
}
