#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> sta) {
    while(!sta.empty()) {
        cout << sta.top() << " ";
        sta.pop();
    }
    cout << endl;
}

void sortedInsert(stack<int> &stack, int num) {
    // printStack(stack);
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    
    int n = stack.top();
    stack.pop();
    
    //recusrive call
    sortedInsert(stack, num);
    
    stack.push(n);
}

void sortStack(stack<int> &stack){
		//base case
    	if(stack.empty()) {
            return ;
        }
    
    int num = stack.top();
    	stack.pop();
    
    	//recursive call
    	sortStack(stack);
    
    	sortedInsert(stack, num);
}

int main() {
    stack<int> s;
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);
    
    cout<<"Original Stack: ";
    printStack(s);
    
    sortStack(s);
    
    cout<<"Sorted Stack: ";
    printStack(s);
    
    return 0;
}