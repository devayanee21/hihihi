#include <iostream>
using namespace std;

void shell(int arr[], int n, int &cmp, int &sw) {
    for(int gap=n/2; gap>0; gap/=2)
        for(int i=gap; i<n; i++) {
            int temp=arr[i], j=i;
            while(j>=gap && ++cmp && arr[j-gap]>temp) {
                arr[j]=arr[j-gap]; sw++; j-=gap;
            }
            arr[j]=temp;
        }
}

int getMax(int arr[], int n) {
    int mx=arr[0];
    for(int i=1;i<n;i++) if(arr[i]>mx) mx=arr[i];
    return mx;
}

void counting(int arr[], int n, int exp, int &cmp) {
    int out[50], cnt[10]={0};
    for(int i=0;i<n;i++) cnt[(arr[i]/exp)%10]++;
    for(int i=1;i<10;i++) cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--) cmp++, out[--cnt[(arr[i]/exp)%10]]=arr[i];
    for(int i=0;i<n;i++) arr[i]=out[i];
}

void radix(int arr[], int n, int &cmp) {
    for(int exp=1; getMax(arr,n)/exp>0; exp*=10)
        counting(arr,n,exp,cmp);
}

int main() {
    int n,a[50],b[50];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i], b[i]=a[i];

    int cs=0,ss=0,cr=0;
    shell(a,n,cs,ss);
    radix(b,n,cr);

    cout<<"\nShell: Comparisons="<<cs<<" Swaps="<<ss;
    cout<<"\nRadix: Approx Comparisons="<<cr;
}
