#include<iostream>
#include<queue>
using namespace std;

//         Queue is a container adapter that gives the programmer the functionality of a FIFO data strucure

int main() {

    //create a queue
    queue<int> q;          

    q.push(11);
    cout << "front of q is: " << q.front() << endl;
    q.push(15);
    cout << "front of q is: " << q.front() << endl;

    q.push(13);
    cout << "front of q is: " << q.front() << endl;

    cout << "size of queue is : " << q.size() << endl;

    q.pop();
    cout << "front of q is: " << q.front() << endl;
    cout << "size of queue is : " << q.size() << endl;

    if(q.empty()) {
        cout << "Queue is empty " << endl;
    }
    else{
        cout << "queue is not empty " << endl;
    } 


    return 0;
}