// LC: 73 m 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        

        // If any element in the first column (other than the first row) is zero, you set matrix[row][0] = 0. If you don't track
        // the first column separately, and you later process the first row based on the value of matrix[0][0], you might
        // accidentally wipe out the entire first row just because an element in the first column was zero.

        int n=matrix.size();
        int m=matrix[0].size();
        bool first_col=false;

        for(int row=0; row<n; row++){
            
          if(matrix[row][0]==0) first_col=true;
        
          for(int col=1; col<m; col++){

            if(matrix[row][col]==0){
              matrix[row][0]=0;
              matrix[0][col]=0;
            }
          }
        }

        for(int row=n-1; row>=0; row--){

          for(int col=m-1; col>=1; col--){

            if(matrix[row][0]==0 || matrix[0][col]==0){
              matrix[row][col]=0;
            }
          }
          if(first_col==true)
          matrix[row][0]=0;
        }
    }
};