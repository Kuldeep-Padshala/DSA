// LC: 74 m 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // Binary search
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int s = 0;
        int e = m*n-1;
        
        while(s<=e){

          int mid = s + (e-s)/2;
          int element = matrix[mid/n][mid%n];
          
          if(element == target){
            return 1;
          }
          
          if(element < target){
            s = mid+1;
          }
          else{
            e = mid-1;
          } 
        }
        return 0;
    }
};