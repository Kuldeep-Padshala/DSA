#include <iostream>
using namespace std;


// max heap, 1 base index

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

void heapSort(int arr[], int n) {

    // step1: build heap
    //        (here for this case, heap is already built)

    int size = n;

    while(size>1){

        // step 2: put last element at root
        swap(arr[size], arr[1]);
        size--;                    // remove last element;

        // step 3: heapify: putting the root element at its correct position
        int i = 0;
        heapify(arr, size, 1);
    }
}

int main(){

    int arr[6] = {-1, 1, 3, 5, 2, 4};
    int n = 5;       // -1 to ignore the first element which is -1

    // Build heap (rearrange array)
    for (int i = n/2; i>0; i--) { // Start from the last non-leaf node
        heapify(arr, n, i);
    }

    cout << "Heap after heapifying: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    } cout << endl;


    heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    } cout << endl;



    return 0;
}