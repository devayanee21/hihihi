#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int priority(char op) {
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}

string toPostfix(string inf) {
    stack<char> st;
    string post = "";
    for(int i=0; i<inf.length(); i++) {

        if(isdigit(inf[i])) {
            while(i<inf.length() && isdigit(inf[i]))
                post += inf[i++];
            post += ' ';
            i--;
        }
        else if(inf[i]=='(') st.push(inf[i]);
        else if(inf[i]==')') {
            while(!st.empty() && st.top()!='(') {
                post += st.top(); post += ' ';
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && priority(st.top()) >= priority(inf[i])) {
                post += st.top(); post += ' ';
                st.pop();
            }
            st.push(inf[i]);
        }
    }
    while(!st.empty()) {
        post += st.top(); post += ' ';
        st.pop();
    }
    return post;
}

int main() {
    string inf;
    cout<<"Enter Infix: ";
    getline(cin, inf);
    cout<<"Postfix: "<<toPostfix(inf);
}
