#include <iostream>
using namespace std;

struct Term { int row, col, val; };

void add(Term A[], Term B[], Term C[]) {
    int i = 1, j = 1, k = 1;
    C[0] = A[0];
    C[0].val = 0;

    while (i <= A[0].val && j <= B[0].val) {
        if (A[i].row == B[j].row && A[i].col == B[j].col) {
            C[k] = {A[i].row, A[i].col, A[i].val + B[j].val};
            if (C[k].val != 0) k++, C[0].val++;
            i++, j++;
        }
        else if (A[i].row < B[j].row ||
                (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++]; C[0].val++;
        }
        else {
            C[k++] = B[j++]; C[0].val++;
        }
    }

    while (i <= A[0].val) C[k++] = A[i++], C[0].val++;
    while (j <= B[0].val) C[k++] = B[j++], C[0].val++;
}

int main() {
    Term A[20], B[20], C[40];
    cin >> A[0].row >> A[0].col >> A[0].val;
    for (int i = 1; i <= A[0].val; i++)
        cin >> A[i].row >> A[i].col >> A[i].val;

    cin >> B[0].row >> B[0].col >> B[0].val;
    for (int i = 1; i <= B[0].val; i++)
        cin >> B[i].row >> B[i].col >> B[i].val;

    add(A, B, C);

    for (int i = 0; i <= C[0].val; i++)
        cout << C[i].row << " " << C[i].col << " " << C[i].val << endl;
}
