#include<iostream>
using namespace std;

class Node {             //class named Node

    public:
    int data;
    Node* next;          //pointer of type Node

    //constructor
    Node(int data) {                           //(step1) made a node, data 10 given, and address null at next
        this -> data = data;
        this -> next = NULL;
    }
};


void insertAtHead(Node* &head, int d) {       //(step3)new node with value 12. this temp node get address of head at next

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;                 // new head is 12 and it got address of 10 at next
    head = temp;                         // [12 | &(10)]   [10 |&(null)]
}                                        // [15 | &(12)]   [12 | &(10)]   [10 |&(null)]


void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {             //pela 15 nu address, print 15 with temp -> data, next means 12 nu address
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int main() {
    
    //created a new node
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
  // cout << node1 -> next << endl;
    
    Node* head = node1;               //(step2)head pointed to node1(10)
    print(head);
    
    insertAtHead(head, 12);
    print(head);
    
    insertAtHead(head, 15);
    print(head);
    return 0;
}