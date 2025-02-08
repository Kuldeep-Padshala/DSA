//    3 Steps
// 1)create node
// 2)temp -> next = curr -> next
// 3)curr -> next = temp

// We don't need head, we can solve it only with tail

#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node* next;
    
    Node(int d){                      //constructor
        this->data = d;
        this->next = NULL;
    }
    
    ~Node(){                         //destructor
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
   

    // deleteNode(tail, 5);
    // print(tail);

    // if(isCircularList(tail)) {
    //     cout << " Linked List is Circular in nature" << endl;
    // }
    // else{
    //     cout << "Linked List is not Circular " << endl;
    // }

    return 0;
}