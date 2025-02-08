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

Node* floydDetectLoop(Node* head) {

    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {   // inside the llop with each iteration, distance betwwen slow and fast will be reduce by one
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            return slow;
        }
    }

    return NULL;
}

Node* previousOfStartingNode(Node* head) {          //just like the Starting loop function

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow ->next != intersection->next) {          //some optimization
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return intersection;

}

void deleteLoop(Node* head){
    if(head == NULL) 
        return;
        
    Node* temp = previousOfStartingNode(head);
    temp -> next = NULL;
}

bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;    // map with key of Node* and value bool

    Node* temp = head;

    while(temp !=NULL) {

        //cycle is present
        if(visited[temp] == true) {         //if already visited
            return true;
        }

        visited[temp] = true;      //mark true as we visited at temp
        temp = temp -> next;

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
    //print(head);    
    
    insertAtPosition(tail,head, 3, 10);
    //print(head);
    
    insertAtPosition(tail,head, 1, 30);
    print(head); 

    tail -> next = head ->next -> next;
    //print(head);                //infinite loop

    cout<< "Before deleting loop: ";
    if(detectLoop(head)){
        cout<<"Loop is present"<<endl;
    }
    else{
        cout<<"Loop is not present"<<endl;
    }
    
    deleteLoop(head);
    print(head);

    cout<< "After deleting loop: ";
    if(detectLoop(head)){
        cout<<"Loop is present"<<endl;
    }
    else{
        cout<<"Loop is not present"<<endl;
    }
    

    return 0;
}