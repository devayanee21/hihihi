#include <iostream>
using namespace std;

int cmp=0, sw=0;

int partitionArr(int arr[], int low, int high) {
    int p = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++) {
        cmp++;
        if(arr[j] < p) {
            i++;
            swap(arr[i], arr[j]);
            sw++;
        }
    }
    swap(arr[i+1], arr[high]);
    sw++;
    return i+1;
}

void quick(int arr[], int low, int high) {
    if(low<high) {
        int pi = partitionArr(arr, low, high);
        quick(arr, low, pi-1);
        quick(arr, pi+1, high);
    }
}

int main() {
    int n, arr[50];
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];

    quick(arr,0,n-1);

    cout<<"\nQuick Sort Comparisons="<<cmp<<" Swaps="<<sw;
}
