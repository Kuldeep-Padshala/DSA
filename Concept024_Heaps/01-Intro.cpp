// heap is a data structure that satisfies the heap property, which states that for a max-heap, 
// every parent node is greater than or equal to its child nodes, and for a min-heap, 
// every parent node is less than or equal to its child nodes. Heaps are commonly implemented using binary trees, 
// but they can also be represented as arrays.

// in short, heap is a complete binary tree with the heap property.
// here nodes always filled from left to right.

// Heap order property

// For a max heap, the value of each node is greater than or equal to the values of its children.
// For a min heap, the value of each node is less than or equal to the values

// when binary tree is in array form by traversing level order,

// root at index 1,
// for i, left child: 2*i
//       right child: 2*i + 1
//       parent: i/2
// leaf nodes: (n/2 +1) to n

// root at index 0,
// for i, left child: 2*i + 1
//       right child: 2*i + 2
//       parent: (i-1)/2
// leaf nodes: (n/2) to n



#include <iostream>
using namespace std;

class heap{

    public:

    int arr[100];   // or int *arr;
    int size;

    heap() {
        arr[0] = -1;  // to make it 1 based index
        size = 0;
    }

    void insert(int val){

        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index>1){

            int parent = index/2;
            if(arr[parent] < arr[index]){       // max heap
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;  // heap property satisfied
            }
        } 
    }

    void printHeap(){

        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap(){         // delete the root node

        if(size == 0){
            cout << "Heap is empty." << endl;
            return;
        }

        // step 1: put last element at root
        arr[1] = arr[size];
        size--;                    // remove last element;

        // step 2: heapify: putting the root element at its correct position
        int i = 1;

        while(i<size){

            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if(leftIndex <= size && arr[leftIndex] > arr[i]){  // max heap
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex <= size && arr[rightIndex] > arr[i]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;           // heap property satisfied
            }
        }

        // while(i<size){

        //     int leftIndex = 2*i;
        //     int rightIndex = 2*i + 1;
        //     int largestIndex = i;

        //     if(leftIndex <= size && arr[leftIndex] > arr[largestIndex]){
        //         largestIndex = leftIndex;
        //     }
        //     if(rightIndex <= size && arr[rightIndex] > arr[largestIndex]){
        //         largestIndex = rightIndex;
        //     }

        //     if(largestIndex != i){
        //         swap(arr[i], arr[largestIndex]);
        //         i = largestIndex;   // continue heapifying downwards
        //     }
        //     else{
        //         return;  // heap property satisfied
        //     }
        // }


    }
};

int main(){

    heap h;

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(25);
    h.insert(35);

    h.printHeap();  // should print: 30 20 5 10 25

    h.deleteFromHeap();
    h.printHeap();  // should print: 25 20 5 10

    h.deleteFromHeap();
    h.printHeap();  // should print: 20 10 5

    return 0;
}