#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

//traversing a linked list
void print(Node* head) {
    Node* temp  = head ;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}

void insertAtHead(Node* &tail, Node* &head, int d) {
    
    Node* temp = new Node(d);
    
    //empty list
    if(head == NULL) {    //initially head pointed at nothing
        
        head = temp;
        tail = temp;
    }
    else{
        temp -> next = head;     //13(temp) comes first, 11 goes to 13's next
        head -> prev = temp;
        head = temp;
    }

}

void insertAtTail(Node* &tail, Node* &head, int d) {
    Node* temp = new Node(d);
    
    if(tail == NULL) {
        tail = temp;
        head = temp;
    }
    else{
        tail -> next  = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* & tail, Node* &head, int position, int d) {
    
    //insert at Start
    if(position == 1) {
        insertAtHead(tail,head, d);
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

    nodeToInsert ->next = temp -> next;   //imp step
    temp -> next -> prev = nodeToInsert;
    
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}



int main() {

    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    //cout << getLength(head) << endl;

    insertAtHead(tail,head, 11);
    // print(head);
    // cout << "head  " << head -> data << endl;
    // cout << "tail  " << tail -> data << endl <<endl;

    insertAtHead(tail,head, 13);
    // print(head);
    // cout << "head  " << head -> data << endl;
    // cout << "tail  " << tail -> data << endl << endl;

    insertAtHead(tail,head, 8);
    // print(head);
    // cout << "head  " << head -> data << endl;
    // cout << "tail  " << tail -> data << endl << endl;
    
    insertAtTail(tail,head, 25);
    print(head);
    // cout << "head  " << head -> data << endl;
    // cout << "tail  " << tail -> data << endl << endl;
    
    insertAtPosition(tail, head, 3, 100);
    print(head);
    // cout << "head  " << head -> data << endl;
    // cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 1, 101);
    print(head);
    // cout << "head  " << head -> data << endl;
    // cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 7, 102);
    print(head);
    // cout << "head  " << head -> data << endl;
    // cout << "tail  " << tail -> data << endl;

    return 0;
}