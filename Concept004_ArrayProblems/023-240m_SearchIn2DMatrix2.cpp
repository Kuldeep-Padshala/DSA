// LC: 240 m 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // binary search

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int row = 0;
        int col = cols-1;
        
        while(row<rows && col>=0){

            int element = matrix[row][col];
            
            if(element == target){
              return 1;
            }
            
            if(element < target){
              row++;
            }
            else
            {
              col--;
            }
        }
        return 0;
    }
};