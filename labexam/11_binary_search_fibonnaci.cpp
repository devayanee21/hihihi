#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key, int &c) {
    int l=0, r=n-1;
    while(l<=r) {
        c++;
        int mid=(l+r)/2;
        if(arr[mid]==key) return mid;
        else if(key < arr[mid]) r=mid-1;
        else l=mid+1;
    }
    return -1;
}

int fibonacciSearch(int arr[], int n, int key, int &c) {
    int f2=0, f1=1, f=f1+f2;
    while(f<n) { f2=f1; f1=f; f=f1+f2; }

    int offset=-1;
    while(f>1) {
        c++;
        int i=min(offset+f2, n-1);
        if(arr[i]<key) { f=f1; f1=f2; f2=f-f1; offset=i; }
        else if(arr[i]>key) { f=f2; f1=f1-f2; f2=f-f1; }
        else return i;
    }
    if(f1 && arr[offset+1]==key) return offset+1;
    return -1;
}

int main() {
    int n, key, arr[50];
    cout<<"Enter size: "; cin>>n;
    cout<<"Enter sorted elements:\n";
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Enter key: "; cin>>key;

    int c1=0,c2=0;
    binarySearch(arr,n,key,c1);
    fibonacciSearch(arr,n,key,c2);

    cout<<"\nBinary Search Comparisons: "<<c1;
    cout<<"\nFibonacci Search Comparisons: "<<c2;
}
