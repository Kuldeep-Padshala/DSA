#include<iostream>              //Redundant brackets in expression are those brackets which are not required
#include<string>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &s){
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        char ch =s[i];
        
        if(ch == '(' || ch == '+' ||ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else{
            //c h ya toh ')' hai or lowercase letter
            
            if(ch == ')') {
                bool isRedundant = true;
                
                while(st.top() != '(' ) {
                    char top = st.top();
                    if(top == '+' ||top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                
                if(isRedundant == true)
                    return true;
                st.pop();
            }
            
        } 
    }
    return false;
}

int main() {

    string s;
    cout<<"Enter expression: ";
    cin>>s;

    if(findRedundantBrackets(s)) {
        cout<<"Yes";
    } else {
        cout<<"No";
    }

    return 0;
}