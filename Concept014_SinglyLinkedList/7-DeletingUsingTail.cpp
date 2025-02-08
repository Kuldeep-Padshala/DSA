//    3 Steps
// 1)prev -> next = curr -> next
// 2)curr -> next = NULL
// 3)delete curr

// We don't need head, we can solve it only with tail

#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;
    
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    
    ~Node(){
        int value = this -> data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
    }
};

void insertNode(Node* &tail, int element, int d) {
    

    //empty list
    if(tail == NULL) {                      // d is new to add
        Node* newNode = new Node(d);
        tail = newNode;
        tail -> next = tail;         //only one node in ll pointing itself
    }
    else{
        //non-empty list
                                  //element is already present in the list

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }     //element found -> curr is representing element wado node
        
        Node* temp = new Node(d);
        temp -> next = curr -> next;//curr nathi curr no next chhe     //5 na next ma 3
        curr -> next = temp;                                           //3 na next ma 5

    }

}

void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
}

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = tail -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }   // until curr reach to the value

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list     in case we delete 3, tail then tail needs to be modified
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}


int main() {

    Node* tail = NULL;

    insertNode(tail, 5, 3);   //first time insert, so 5 is useless
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);
    
    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);
   

    deleteNode(tail, 3);
    print(tail);
    cout<<tail->data<<endl;
    
    deleteNode(tail, 10);
    print(tail);
    cout<<tail->data<<endl;

    // if(isCircularList(tail)) {                       remaining
    //     cout << " Linked List is Circular in nature" << endl;
    // }
    // else{
    //     cout << "Linked List is not Circular " << endl;
    // }

    return 0;
}