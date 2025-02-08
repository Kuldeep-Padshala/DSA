#include<iostream>
#include<map>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

};

void insertAtHead(Node* &tail, Node* & head, int d) {

    // new node create
    Node* temp = new Node(d);
        if(head == NULL) {
        tail = temp;
        head = temp;
        return;
    }
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, Node* & head, int d) {
     // new node create
    Node* temp = new Node(d);
        if(tail == NULL) {
        tail = temp;
        head = temp;
        return;
    }
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

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {

    //insert at Start
    if(position == 1) {
        insertAtHead(tail, head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,head,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}


bool isCircularList(Node* &head) {
    //empty list
    if(head == NULL) {
        return false;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;
}

int main() {
    
    Node* head = NULL; 
    Node* tail = NULL;
    //print(head);

    insertAtHead(tail, head, 12);
    //print(head);
    
    insertAtTail(tail, head, 15);
    //print(head);
    
    insertAtTail(tail, head, 18);
    //print(head);

    insertAtPosition(tail,head, 3, 22);
    print(head);    
    //deleteNode(4, head);
    
    // tail -> next = NULL;

    tail -> next = head;
    //print(head);                infinite loop


    if(isCircularList(head)) {
        cout << "Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }


    return 0;
}