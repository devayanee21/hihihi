#include <iostream>
using namespace std;

void bubble(int arr[], int n, int &cmp, int &sw) {
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++) {
            cmp++;
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                sw++;
            }
        }
}

void insertion(int arr[], int n, int &cmp, int &sw) {
    for(int i=1;i<n;i++) {
        int key=arr[i], j=i-1;
        while(j>=0 && ++cmp && arr[j]>key) {
            arr[j+1]=arr[j];
            sw++;
            j--;
        }
        arr[j+1]=key;
    }
}

int main() {
    int n, a[50], b[50];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i], b[i]=a[i];

    int c1=0,s1=0,c2=0,s2=0;
    bubble(a,n,c1,s1);
    insertion(b,n,c2,s2);

    cout<<"\nBubble: Comparisons="<<c1<<" Swaps="<<s1;
    cout<<"\nInsertion: Comparisons="<<c2<<" Swaps="<<s2;
}
