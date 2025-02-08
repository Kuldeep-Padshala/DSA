#include<iostream>
using namespace std;

class Node {             //class named Node

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {                           //(step1) made a node, data 10 given, and address null at next
        this -> data = data;
        this -> next = NULL;
    }
};


void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}


void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int main() {
    
    Node* node1 = new Node(10);
    
    //head pointed to node1
    Node* head = node1; 
    Node* tail = node1;
    print(head);

    insertAtTail(tail, 12);
    print(head);
    
    insertAtTail(tail, 15);
    print(head);
    return 0;
    
    
}