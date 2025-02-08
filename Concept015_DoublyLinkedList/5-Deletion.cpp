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

void deleteNode(int position, Node* & head,Node* & tail) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;     //2nd elment na prev ma null
        head = temp ->next;              // head ma temp no next atle ke second 
        temp -> next = NULL;             // temp next khali karvanu
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* back = NULL;

        int cnt = 1;
        while(cnt < position) {     //to reach the element to be deleted
            back = curr;
            curr = curr -> next;
            cnt++;
        }

        if(curr -> next == NULL){    //deleting last node
            tail = curr -> prev;
            back -> next = NULL;

            curr -> prev = NULL;
            delete curr;

            return;
        }
        
        if(curr->next != NULL){
            curr->next->prev = back;   // This line is essential to maintain the integrity of the linked list.
        }
        back -> next = curr -> next;

        curr -> prev = NULL;
        curr -> next = NULL;
        delete curr;

    }
}


int main() {

    Node* head = NULL;
    Node* tail = NULL;

    print(head);

    insertAtHead(tail,head, 11);
    insertAtHead(tail,head, 13);
    insertAtHead(tail,head, 8);
    insertAtTail(tail,head, 25);
    insertAtPosition(tail, head, 2, 100);
    insertAtPosition(tail, head, 1, 101);
    insertAtPosition(tail, head, 7, 102);
    print(head);
    
    deleteNode(7, head, tail);
    print(head);
    deleteNode(1, head, tail);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;
    return 0;
}