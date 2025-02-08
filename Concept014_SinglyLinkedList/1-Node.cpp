// Linked list is a one type of linear data structure which is made of collection of nodes
// Nodes include data and the address of next node

// Types
// Singly LL
// Doubly LL
// Circular LL
// Circular Doubly LL

// Advantages
// Dynamic data structure (grow/shrink on runtime)
// no shift needed of insertion and deletion

// Disadvantages
// Random access is not allowed

#include<iostream>
using namespace std;

class Node {             //class named Node

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

};

int main() {
    
    //created a new node
    Node* Vibhu = new Node(10);      //Pointer Vibhu with type Node(just a name)
    cout << Vibhu -> data << endl;
    cout << Vibhu -> next << endl;

    return 0;
}