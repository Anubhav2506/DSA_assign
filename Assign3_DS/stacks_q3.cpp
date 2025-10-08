#include <iostream>
#include <stack>
using namespace std;

int main() {
    string exp;
    cin >> exp;
    stack<char> st;
    for(char c : exp) {
        if(c=='('||c=='{'||c=='[') st.push(c);
        else {
            if(st.empty()) { cout<<"Not Balanced"; return 0; }
            char x=st.top(); st.pop();
            if((c==')'&&x!='(')||(c=='}'&&x!='{')||(c==']'&&x!='[')) {
                cout<<"Not Balanced"; return 0;
            }
        }
    }
    cout << (st.empty() ? "Balanced" : "Not Balanced");
}
