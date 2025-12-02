#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    int size = rows * cols;
    int *arr1 = new int[size];

    // INSERT VALUES
    cout << "\nEnter elements (row-wise):\n";
    for (int i = 0; i < size; i++) {
        cin >> arr1[i];
    }

    // PRINT WITH MEMORY ADDRESS
    cout << "\nMatrix with memory addresses:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i * cols + j;
            cout << arr1[index] << "(@" << (arr1 + index) << ")  ";
        }
        cout << endl;
    }

    // DELETE ELEMENT
    int r, c;
    cout << "\nEnter row and column to delete: ";
    cin >> r >> c;
    arr1[r * cols + c] = 0;

    cout << "\nAfter deletion:\n";
    for (int i = 0; i < size; i++)
        cout << arr1[i] << " ";
    cout << endl;

    // MERGE
    int *arr2 = new int[size];
    cout << "\nEnter second matrix elements:\n";
    for (int i = 0; i < size; i++)
        cin >> arr2[i];

    int *merged = new int[size * 2];
    for (int i = 0; i < size; i++)
        merged[i] = arr1[i];
    for (int i = 0; i < size; i++)
        merged[size + i] = arr2[i];

    cout << "\nMerged array:\n";
    for (int i = 0; i < size * 2; i++)
        cout << merged[i] << " ";

    delete[] arr1;
    delete[] arr2;
    delete[] merged;

    return 0;
}
/*Insert
✔ Delete
✔ Merge
✔ Pointer memory address
✔ Row-Major mapping*/