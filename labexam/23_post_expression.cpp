#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main() {
    string p; stack<int> st;
    getline(cin, p);

    for(int i=0;i<p.size();i++) {
        if(isdigit(p[i])) {
            int n = 0;
            while(i<p.size() && isdigit(p[i]))
                n = n*10 + (p[i++]-'0');
            st.push(n);
        }
        else if(p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/') {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if(p[i]=='+') st.push(a+b);
            if(p[i]=='-') st.push(a-b);
            if(p[i]=='*') st.push(a*b);
            if(p[i]=='/') st.push(a/b);
        }
    }
    cout<<"Result = "<<st.top();
}
