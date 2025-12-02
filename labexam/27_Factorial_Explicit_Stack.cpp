#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n, ans=1; cin>>n;
    stack<int> st;
    for(int i=n;i>1;i--) st.push(i);
    while(!st.empty()) { ans *= st.top(); st.pop(); }
    cout<<ans;
}
