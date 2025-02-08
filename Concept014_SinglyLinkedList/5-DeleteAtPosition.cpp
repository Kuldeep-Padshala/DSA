#include<iostream>
#include<map>
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

void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start node
        temp -> next = NULL;    //setting it null just before deleting it
        delete temp;
    }
    else{
        //deleting any middle node or last node
        Node* curr = head;      // [10 | &(12)]   [12 | &(15)]   [15 | &(20)]   [20 | &(null)]
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
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
    
    deleteNode(1, head);
    print(head);
    
    return 0;
    
    
}