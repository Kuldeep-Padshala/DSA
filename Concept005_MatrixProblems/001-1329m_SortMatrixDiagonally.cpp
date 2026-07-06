// LC: 1329 m 

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        // using min-heap
        
        priority_queue<int, vector<int>, greater<int>> pq;

        int rows = mat.size();
        int cols = mat[0].size();

        for(int col=cols-1; col>=0; col--){

          priority_queue<int, vector<int>, greater<int>> pq;
          int i=0, j=col;
          while(i != rows && j != cols){
            pq.push(mat[i++][j++]);
          }

          i=0, j=col;
          while(i != rows && j != cols){
            mat[i++][j++] = pq.top();
            pq.pop();
          }
        }

        for(int row=1; row<rows; row++){

          priority_queue<int, vector<int>, greater<int>> pq;
          int i=row, j=0;
          while(i != rows && j != cols){
            pq.push(mat[i++][j++]);
          }
          i=row, j=0;
          while(i != rows && j != cols){
            mat[i++][j++] = pq.top();
            pq.pop();
          }
        }
        return mat;


        // using array

        // int rows = mat.size();
        // int cols = mat[0].size();

        // for(int col=cols-1; col>=0; col--){

        //   vector<int> temp;
        //   int i=0, j=col, idx=0;
        //   while(i != rows && j != cols){
        //     temp.push_back(mat[i++][j++]);
        //   }
        //   sort(temp.begin(), temp.end());
        //   i=0, j=col;
        //   while(i != rows && j != cols){
        //     mat[i++][j++] = temp[idx++];
        //   }
        // }

        // for(int row=1; row<rows; row++){

        //   vector<int> temp;
        //   int i=row, j=0, idx=0;
        //   while(i != rows && j != cols){
        //     temp.push_back(mat[i++][j++]);
        //   }
        //   sort(temp.begin(), temp.end());
        //   i=row, j=0;
        //   while(i != rows && j != cols){
        //     mat[i++][j++] = temp[idx++];
        //   }
        // }
        // return mat;
    }
};