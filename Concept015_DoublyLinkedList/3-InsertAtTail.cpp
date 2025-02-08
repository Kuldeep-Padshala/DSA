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

int getLength(Node* head){
    int length = 0;
    Node* temp  = head ;

    while(temp != NULL) {
        length++;
        temp  = temp -> next;
    }
    return length;
}

int main() {


    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    cout << "Length is " <<getLength(head) << endl;

    insertAtHead(tail,head, 11);
    print(head);
    // cout << "head  " << head -> data << endl;
    // cout << "tail  " << tail -> data << endl <<endl;

    insertAtHead(tail,head, 13);
    print(head);
    // cout << "head  " << head -> data << endl;
    // cout << "tail  " << tail -> data << endl << endl;

    insertAtHead(tail,head, 8);
    print(head);
    // cout << "head  " << head -> data << endl;
    // cout << "tail  " << tail -> data << endl << endl;
    
    insertAtTail(tail,head, 25);
    print(head);
    // cout << "head  " << head -> data << endl;
    // cout << "tail  " << tail -> data << endl << endl;

    cout << "Length is " <<getLength(head) << endl;

    return 0;
}