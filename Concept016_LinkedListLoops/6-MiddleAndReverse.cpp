#include<iostream>
#include<map>
using namespace std;

class ListNode {

    public:
    int data;
    ListNode* next;

    //constructor
    ListNode(int data) {
        this -> data = data;
        this -> next = NULL;
    }

};

void insertAtHead(ListNode* &tail, ListNode* & head, int d) {

    // new node create
    ListNode* temp = new ListNode(d);
        if(head == NULL) {
        tail = temp;
        head = temp;
        return;
    }
    temp -> next = head;
    head = temp;
}

void insertAtTail(ListNode* &tail, ListNode* & head, int d) {
     // new node create
    ListNode* temp = new ListNode(d);
        if(tail == NULL) {
        tail = temp;
        head = temp;
        return;
    }
    tail -> next = temp;
    tail  = temp;
}

void insertAtPosition(ListNode* &tail, ListNode* & head, int position, int d) {

    if(position == 1) {
        insertAtHead(tail, head, d);
        return;
    }

    ListNode* temp  = head;
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
    ListNode* nodeToInsert = new ListNode(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void print(ListNode* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    ListNode* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

ListNode* getMid(ListNode* head ) {
      ListNode* slow = head;
      ListNode* fast = head -> next;
        
        while(fast != NULL && fast-> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    }

ListNode* reverse(ListNode* head) {
        
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* forw = NULL;
        
        while(curr != NULL) {
            forw = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }

int main() {
    
    ListNode* head = NULL; 
    ListNode* tail = NULL;
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
    
    ListNode* mid = getMid(head);
    cout << "Mid is " << mid -> data << endl;
    print(head);

    head = reverse(head);
    print(head);
}