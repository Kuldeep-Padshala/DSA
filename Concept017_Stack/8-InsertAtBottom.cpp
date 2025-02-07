#include<iostream>
#include<stack>
using namespace std;



void insertAtBottom(stack<int>&s, int element) {
    //base case
    if(s.empty()) {
        s.push(element);
        return ;
    }
    
    int num = s.top();
    // cout<<"num: "<<num<<endl;
    s.pop();
    
	//RECURSIVE CALL
    insertAtBottom(s, element);
    
    s.push(num); 
}


int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout<<"Enter the element to insert at bottom: ";
    int ele;
    cin>>ele;
    
    int count = 0;
    insertAtBottom(s, ele);
    
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}