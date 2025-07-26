#include <bits/stdc++.h>
using namespace std;

// Function to find the kth smallest array element
int kthSmallest(int arr[], int n, int K){
    
    priority_queue<int> pq;                                        // Create a max heap (priority queue)

    for (int i = 0; i < n; i++) {

        pq.push(arr[i]);

        
        if (pq.size() > K){               // pq ni size k jetli reva dese, ane vadhi jase to root(max) pop karavse
            pq.pop();
        }
    }                                    // we got pq with smallest k elemnts

    return pq.top();
}


int main()
{
    int n = 10;
    int arr[n] = { 10, 5, 4, 3, 48, 6, 2, 33, 53, 10 };
    int K = 4;

    cout << "Kth Smallest Element is: "
         << kthSmallest(arr, n, K);
}