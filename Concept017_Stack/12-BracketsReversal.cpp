#include<iostream>
#include<stack>
#include<string>

using namespace std;

// for odd length of string, it is not possible to make it balanced. return -1
// remove valid pairs of braces and count the remaining braces
// remaining parts are of type {{{{, }}}}, }}{{

void printStack(stack<char> sta) {
    while(!sta.empty()) {
        cout<<sta.top()<<" ";
        sta.pop();
    }
    cout<<endl;
}

int findMinimumCost(string str) {
  	
    //odd condition
    if(str.length()%2 == 1) {
        return -1;
    }
    
    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        
        if(ch == '{') 
            s.push(ch);
		else
        {
            //ch is closed brace
            if(!s.empty() && s.top() == '{') {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }

    // printStack(s);
        //stack contains invalid expression
        int a = 0, b = 0;
        while(!s.empty()) {
            if(s.top() == '{') {
                b++;
            }
            else{
                a++;
            }
            s.pop();
        }
        
		int ans = (a+1)/2 + (b+1)/2;
        return ans;
}

int main() {
    string str;
    cout<<"Enter string: ";
    cin>>str;
    
    cout<< "Minimum Cost: " <<findMinimumCost(str);
    return 0;
}