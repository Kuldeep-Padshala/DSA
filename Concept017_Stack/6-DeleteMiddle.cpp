#include<iostream>
#include<stack>
using namespace std;



void solve(stack<int>&s, int count, int size) {
    //base case
    if(count == size/2) {
        s.pop();
        return ;
    }
    
    int num = s.top();
    // cout<<"num: "<<num<<endl;
    s.pop();
    
	//RECURSIVE CALL
    solve(s, count+1, size);
    
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
    
    int count = 0;
    solve(s, count,s.size());
    
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}