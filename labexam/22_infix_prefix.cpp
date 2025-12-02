#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

int priority(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

string toPrefix(string inf) {
    reverse(inf.begin(), inf.end());
    for(char &c : inf) {
        if(c=='(') c=')';
        else if(c==')') c='(';
    }

    stack<char> st;
    string pre = "";

    for(int i=0;i<inf.length();i++) {

        if(isdigit(inf[i])) {
            while(i<inf.length() && isdigit(inf[i]))
                pre += inf[i++];
            pre += ' ';
            i--;
        }
        else if(inf[i]=='(') st.push(inf[i]);
        else if(inf[i]==')') {
            while(!st.empty() && st.top()!='(') {
                pre += st.top(); pre += ' ';
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && priority(st.top()) >= priority(inf[i])) {
                pre += st.top(); pre += ' ';
                st.pop();
            }
            st.push(inf[i]);
        }
    }
    while(!st.empty()) {
        pre += st.top(); pre += ' ';
        st.pop();
    }
    reverse(pre.begin(), pre.end());
    return pre;
}

int main() {
    string inf;
    cout<<"Enter Infix: ";
    getline(cin, inf);
    cout<<"Prefix: "<<toPrefix(inf);
}
