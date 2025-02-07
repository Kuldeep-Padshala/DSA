#include<iostream>                //implementing stack using Array
#include<stack>
using namespace std;

class Stack {
    public:                     //properties
        int *arr;               //pointer to array
        int top;                //index of top element
        int size;               //size of stack 

    Stack(int size) {            //constructor
        this -> size = size;
        arr = new int[size];               //array created dynamically
        top = -1;
    }

    void push(int element) {
        if(top < size-1 ) {                //if stack is not full
            top++;
            arr[top] = element;
        }
        else{
            cout << "Stack OverFlow" << endl;
        }
    }

    void pop() {
        if(top != -1 ) {                  //if stack is not empty
            top--;                        //new last element
        }
        else{
            cout << "Stack UnderFlow" << endl;
        }
    }

    int peek() {                       //return top element
        if(top != -1 )
            return arr[top];

        else{
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if( top == -1)
            return true;
        else
            return false;
    }

};


int main() {

    //object of stack class
    Stack st(5);                 //size of stack is 5         

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);               //top
    st.push(44);               //stack overflow

    cout << st.peek() << endl;

    st.pop();                //43 is removed

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    if(st.isEmpty()) {
        cout << "Stack is Empty" << endl;
    }
    else{
        cout << "Stack is not Empty" << endl;
    }

    return 0;
}