#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int prec(char c) {
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return -1;
}

int main() {
    string infix, post="";
    cin >> infix;
    stack<char> st;
    for(char c : infix) {
        if(isalnum(c)) post+=c;
        else if(c=='(') st.push(c);
        