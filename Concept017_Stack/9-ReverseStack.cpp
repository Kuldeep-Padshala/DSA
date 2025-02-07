#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int element) {
    //basecase
    if(st.empty()) {
        st.push(element);
      	return ;
    }
    
    int num = st.top();
    st.pop();
    
    //recursive call
    insertAtBottom(st, element);
    
    st.push(num);
}

void reverseStack(stack<int> &s) {
  	//base case
    if(s.empty()) {
        return ;
    }
    
    int num = s.top();
    s.pop();
    
    //recursive call
    reverseStack(s);
    
    insertAtBottom(s,num);
}

void printStack(stack<int> sta) {
    while(!sta.empty()) {
        cout << sta.top() << " ";
        sta.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout<<"Original Stack: ";
    printStack(s);

    reverseStack(s);

    cout<<"Reversed Stack: ";
    printStack(s);
    
    return 0;
}