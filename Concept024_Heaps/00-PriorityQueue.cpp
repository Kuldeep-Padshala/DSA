// priority queue implementation using heaps

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

    // max heap
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.push(30);
    maxHeap.push(25);
    maxHeap.push(35);
    cout << "Max Heap: ";

    while(!maxHeap.empty()){
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    } cout << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;


// explaination:   priority_queue<int, vector<int>, greater<int>> means that we are using a vector to store the elements, 
//                 and we want the smallest element to be at the top of the priority queue.
//
//      process:   so when we push elements, they are arranged in such a way that the smallest element is always at the top.


    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(30);
    minHeap.push(25);
    minHeap.push(35);
    cout << "Min Heap: ";

    while(!minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop();
    } cout << endl;



    return 0;
}