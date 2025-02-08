#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d ){
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
    
    Node* head = new Node(10);
    // Node* tail = NULL;

    print(head);
    cout << getLength(head) << endl;
    
    return 0;
}
