//implementing qack using Array

#include<iostream>
using namespace std;

class Queue {
    
    int* arr;
    int front;
    int rear; 
    int size;
    
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(front == rear) {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data) {
        if(rear == size)
            cout << "Queue is Full" << endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(front == rear) {
            return -1;
        }
        else{	
            
            int ans = arr[front];
            arr[front] = -1;
            front++;

            if(front==rear){
                front = 0;
                rear = 0;
            }
            
         return ans;
        }
    }

    int frontElement() {
        if(front == rear) {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

};

int main() {

    //object of qack class
    Queue q(5);                 //size of qack is 5         

    q.enqueue(22);
    q.enqueue(43);
    q.enqueue(44);
    q.enqueue(22);
    q.enqueue(43);               //top
    q.enqueue(44);               // qack overflow

    cout << q.frontElement() << endl;  //22

    q.dequeue();                //22 is removed
    cout << q.frontElement() << endl;  //43 front

    q.dequeue();
    cout << q.frontElement() << endl;

    q.dequeue();
    cout << q.frontElement() << endl;

    if(q.isEmpty()) {
        cout << "qack is Empty" << endl;
    }
    else{
        cout << "qack is not Empty" << endl;
    }

    return 0;
}