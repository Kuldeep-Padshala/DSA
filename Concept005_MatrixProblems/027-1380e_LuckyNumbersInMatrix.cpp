// LC: 1380 e 

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int> row_min(rows, INT_MAX);
        vector<int> col_min(cols, 0);
        
        for(int row=0; row<rows; row++){
          for (int col=0; col<cols; col++) {
              
            int elem = matrix[row][col];
            row_min[row] = min(row_min[row], elem);
            col_min[col] = max(col_min[col], elem);
          }
        }
        
        for(int row=0; row<rows; row++){
          for(int col=0; col<cols; col++){

            int elem = matrix[row][col];
            if(elem == row_min[row] && elem == col_min[col]) {
            return {elem};
            }
          }
        }
        
        return {};
    }
};