// LC: 54 m 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int cnt = 0;
        int total = rows*cols;
        
        //i initialisation
        int fisrtRow = 0;
        int fisrtCol = 0;
        int lastRow = rows-1;
        int lastCol = cols-1;
        
         while(cnt < total) {
            
            //print starting row
            for(int col = fisrtCol; col <= lastCol; col++){

              if(cnt < total){
                ans.push_back(matrix[fisrtRow][col]);
                cnt++;
              } 
            }
            fisrtRow++;
            
            //print ending column
            for(int row = fisrtRow; row<=lastRow; row++){

              if(cnt < total){
                ans.push_back(matrix[row][lastCol]);
                cnt++;
              }       
            }
            lastCol--;
            
            //print ending row
            for(int col = lastCol; col>=fisrtCol; col--){

              if(cnt < total){
                ans.push_back(matrix[lastRow][col]);
                cnt++;
              }
            }
            lastRow--;
            
            //print starting column
            for(int row = lastRow; row>=fisrtRow; row--) {
              
              if(cnt < total){
                ans.push_back(matrix[row][fisrtCol]);
                cnt++;
              }
            }
            fisrtCol++;
        } 
        return ans;
    }
};