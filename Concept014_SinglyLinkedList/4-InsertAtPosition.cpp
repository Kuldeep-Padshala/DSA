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

void insertAtHead(Node* &head, int d) {   //(step3)new node with value 12. this temp node get address of head at next

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;                 // new head is 12 and it got address of 10 at next
    head = temp;                         // [12 | &(10)]   [10 |&(null)]
}                                        // [15 | &(12)]   [12 | &(10)]   [10 |&(null)]

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

void insertAtPosition(Node* &tail, Node* &head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;         //temp initially at 1-head
    int cnt = 1;
                                                            //[22 | &(null)]
    while(cnt < position-1) {  // [10 | &(12)]   [12 | &(15)]   [15 | &(20)]   [20 | &(null)]
        temp = temp->next;     // for position 3 we need to jump once
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
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
    
    insertAtPosition(tail,head, 2, 22);
    print(head);
    
    return 0;
    
    
}