#include <iostream>
using namespace std;

int pq[5];
int n = 0;

void insertPQ(int x) {
    pq[n] = x;
    n++;
}

void deletePQ() {
    if (n == 0) {
        cout << "Empty\n";
        return;
    }
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    cout << "Deleted: " << pq[minIndex] << endl;
    for (int i = minIndex; i < n - 1; i++) {
        pq[i] = pq[i + 1];
    }
    n--;
}

void display() {
    for (int i = 0; i < n; i++) {
        cout << pq[i] << " ";
    }
    cout << endl;
}

int main() {
    insertPQ(30);
    insertPQ(10);
    insertPQ(20);
    display();
    deletePQ();
    display();
}
