#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key, int &cmp) {
    for(int i = 0; i < n; i++) {
        cmp++;
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int sentinelSearch(int arr[], int n, int key, int &cmp) {
    int last = arr[n-1];
    arr[n-1] = key;
    int i = 0;
    while(true) {
        cmp++;
        if(arr[i] == key) break;
        i++;
    }
    arr[n-1] = last;
    if(i < n-1 || arr[n-1] == key) return i;
    return -1;
}

int main() {
    int n, key;
    cout << "Enter size: ";
    cin >> n;

    int arr[50];
    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter key to search: ";
    cin >> key;

    int c1 = 0, c2 = 0;

    int idx1 = linearSearch(arr, n, key, c1);
    int idx2 = sentinelSearch(arr, n, key, c2);

    cout << "\nLinear Search Comparisons: " << c1;
    cout << "\nSentinel Search Comparisons: " << c2;
}
