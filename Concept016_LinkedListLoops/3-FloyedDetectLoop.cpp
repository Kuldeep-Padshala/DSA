//                                      Floyd's Cycle-Finding Algorithm
//                                      "Tortoise and Hare" algorithm
// Time complexity: O(n)
// Space complexity: O(1)

// Here, we have two pointers, slow and fast. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. 
// If there is a loop in the linked list, the fast pointer will eventually meet the slow pointer. If there is no loop, 
// the fast pointer will reach the end of the linked list.

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

bool floydDetectLoop(Node* head) {

    if(head == NULL){
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {   // inside the loop with each iteration, distance betwwen slow and fast will be reduce by one
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            return true;
        }
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
    
    insertAtTail(tail, head, 21);
    //print(head);

    insertAtPosition(tail,head, 4, 22);
    print(head);    
    //deleteNode(4, head);
    
    // tail -> next = NULL;

    tail -> next = head ->next->next;
    //print(head);                infinite loop
    
    if(floydDetectLoop(head)){
        cout<<"Loop is present"<<endl;
    }
    else{
        cout<<"Loop is not present"<<endl;
    }


    return 0;
}