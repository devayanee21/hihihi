#include <iostream>
using namespace std;

struct Term { int row, col, val; };

void simpleTranspose(Term a[], Term b[]) {
    int n = a[0].val, k = 1;
    b[0] = {a[0].col, a[0].row, n};
    for (int c = 0; c < a[0].col; c++)
        for (int i = 1; i <= n; i++)
            if (a[i].col == c)
                b[k++] = {a[i].col, a[i].row, a[i].val};
}

void fastTranspose(Term a[], Term b[]) {
    int rows = a[0].row, cols = a[0].col, n = a[0].val;
    int count[20] = {0}, pos[20];
    b[0] = {cols, rows, n};

    for (int i = 1; i <= n; i++)
        count[a[i].col]++;

    pos[0] = 1;
    for (int i = 1; i < cols; i++)
        pos[i] = pos[i - 1] + count[i - 1];

    for (int i = 1; i <= n; i++) {
        int p = pos[a[i].col]++;
        b[p] = {a[i].col, a[i].row, a[i].val};
    }
}

void print(Term a[]) {
    for (int i = 0; i <= a[0].val; i++)
        cout << a[i].row << " " << a[i].col << " " << a[i].val << endl;
}

int main() {
    Term a[20], b[20], c[20];
    cout << "Enter rows cols non-zero count: ";
    cin >> a[0].row >> a[0].col >> a[0].val;
    for (int i = 1; i <= a[0].val; i++)
        cin >> a[i].row >> a[i].col >> a[i].val;

    simpleTranspose(a, b);
    fastTranspose(a, c);

    cout << "\nSimple Transpose:\n"; print(b);
    cout << "\nFast Transpose:\n"; print(c);
}
