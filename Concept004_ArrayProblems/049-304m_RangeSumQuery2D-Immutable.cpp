// LC: 304 m 

class NumMatrix {
  int rows, cols;
  vector<vector<int>> prefixSum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        
        rows = matrix.size();
        cols = matrix[0].size();

        prefixSum = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));
        
        for(int row=1; row<=rows; row++){
          for(int col=1; col<=cols; col++){

              prefixSum[row][col] = matrix[row-1][col-1] + 
                                    prefixSum[row-1][col] + prefixSum[row][col-1] 
                                    - prefixSum[row-1][col-1] ;
          }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        return prefixSum[row2+1][col2+1] 
              - prefixSum[row2+1][col1] 
              - prefixSum[row1][col2+1] 
              + prefixSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */