// 378. Kth Smallest Element in a Sorted Matrix

// Given an n x n matrix where each of the rows and columns is sorted in ascending order, 
// return the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<int> pq;

        for (int i = 0; i < matrix.size(); i++) {
          for (int j = 0; j < matrix.size(); j++) {

            pq.push(matrix[i][j]);

            if (pq.size() > k) {
                pq.pop();  // Remove largest, keep K smallest in heap
            }
          }
        }

        return pq.top();  // Top will be the K-th smallest



        // int n = matrix.size();
        // if(k%n==0){
        //   return matrix[(k/n)-1][(k/n)-1];
        // }
        // int row = k/n;
        // int col = k - (row*n) - 1;

        // return matrix[row][col];
    }
};