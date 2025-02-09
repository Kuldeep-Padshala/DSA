#include<iostream>           //stack is a container adapter that gives the programmer the functionality of a stack - specifically, 
#include<stack>              //a LIFO (Last In, First Out) data structure.

using namespace std;

int main(){

// Stack Containers
// back() -                 Returns a reference to the last element in the stack
// push_back() -
// pop_back() -

// .empty() -                Returns whether the stack is empty: i.e. whether its size is zero
// .size() -                 Returns the number of elements in the stack
// .top() -                  Returns a reference to the top element in the stack
// .push() -                 Adds a new element at the top of the stack, above its current top element
// .pop() -                  Removes the element on top of the stack, effectively reducing its size by one

    stack<string> s;
    s.push("Apple");
    s.push("Mango");
    s.push("Guava");
    s.push("Banana");

    // while(!s.empty()){                           //way to print all elements of stack
    //     cout<<s.top()<<endl;
    //     // s.pop();
    // }
    
    cout<< "Top is " <<s.top()<<endl;
    s.pop();                                           //pop the top element
    cout<< "Top is " <<s.top()<<endl;
    cout<< "Size is " <<s.size()<<endl;                //size of stack
    cout<<"Is empty? "<<s.empty()<<endl;               //check if stack is empty or not
    
    return 0;
}