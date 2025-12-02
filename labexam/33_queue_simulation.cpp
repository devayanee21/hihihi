#include <iostream>
using namespace std;

string q[5];
int front = 0, rear = -1;

void add(string s) {
    rear++;
    q[rear] = s;
}

void process() {
    cout << "Processed: " << q[front] << endl;
    front++;
}

int main() {
    add("File1");
    add("File2");
    process();
    process();
}
