#include <iostream>
using namespace std;


// min heap, 0 base index

void heapify(int arr[], int n, int i) {

        int smallest = i;                          // Initialize smallest as root
        int left = 2 * i + 1;                      // left child index
        int right = 2 * i + 2;                     // right child index

        if (left < n && arr[left] < arr[smallest]) {         // If left child is smaller than root
            smallest = left;
        }

        if (right < n && arr[right] < arr[smallest]) {     // If right child is smaller than smallest so far
            smallest = right;
        }

        // If smallest is not root

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            // Recursively heapify the affected sub-tree
            heapify(arr, n, smallest);
        }
    }

int main(){

    int arr[] = {3, 1, 6, 5, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) { // Start from the last non-leaf node
        heapify(arr, n, i);
    }

    cout << "Heap after heapifying: ";
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}