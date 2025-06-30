#include<iostream>
using namespace std;

class Node {
    public:
        int val;
        Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Stack {

    private:
        Node* top;

    public:
        Stack() {
            top = NULL;
        }

    void push(int element) {                            //functions as insertAtHead
        Node* newNode = new Node(element);
        if (top == NULL) {
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop() {
        if (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        } 
        else {
            cout << "Stack UnderFlow" << endl;
        }
    }

    int peek() {
        
        if (top != NULL)
            return top->val;
        else {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {

    Stack st;                 

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);             

    cout << st.peek() << endl;

    st.pop();                 

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    if(st.isEmpty()) {
        cout << "Stack is Empty" << endl;
    } else {
        cout << "Stack is not Empty" << endl;
    }

    return 0;
}





