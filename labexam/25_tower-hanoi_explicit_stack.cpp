#include <iostream>
#include <stack>
using namespace std;

struct Step { int n; char src, aux, dst; };

int main() {
    int n; cin>>n;
    stack<Step> st;
    st.push({n,'A','B','C'});
    while(!st.empty()) {
        Step s = st.top(); st.pop();
        if(s.n==0) continue;
        st.push({s.n-1, s.aux, s.src, s.dst});
        cout<<s.src<<" -> "<<s.dst<<endl;
        st.push({s.n-1, s.src, s.dst, s.aux});
    }
}
