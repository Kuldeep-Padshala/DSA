// root at index 1,
// for i, left child: 2*i
//       right child: 2*i + 1
//            parent: i/2
//        leaf nodes: (n/2 +1) to n 

// heapify: take any node to its right place under that node.

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
    }

    void printHeap(){

        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }


};


// maxHeap, 1 based index

void heapify(int arr[], int n, int i) {

        int largest = i;                          // Initialize largest as root
        int left = 2 * i;                         // left child index
        int right = 2 * i + 1;                    // right child index


        if (left <= n && arr[left] > arr[largest]) {         // If left child is larger than root
            largest = left;
        }

        if (right <= n && arr[right] > arr[largest]) {     // If right child is larger than largest so far
            largest = right;
        }

        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);
            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }


int main(){


    int arr[] = {-1, 10, 20, 5, 30, 25, 35}; // -1 for 1 based index
    int n = 6; // size of the heap

    for (int i = n / 2; i >= 1; i--) { // Start from the last non-leaf node
        heapify(arr, n, i);
    }

    cout << "Heap after heapifying: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}