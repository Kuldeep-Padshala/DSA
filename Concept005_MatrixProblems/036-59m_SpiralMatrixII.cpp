// LC: 59 m 

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n, vector<int>(n));   

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while(top<=bottom && left<=right){
          
          //  left -> right
          for(int i=left; i<=right; i++){
            ans[top][i] = num;               // top vadi row no ith element
            num++;
          }
          top++; // ek row puri


          // top ↓ bottom
          for(int i=top; i<=bottom; i++){
            ans[i][right] = num;           // right column ma ith row   
            num++;
          }
          right--;


          // left <- right
          for(int i=right; i>=left; i--){
            ans[bottom][i] = num;           // bottom row, ith element   
            num++;
          }
          bottom--;   


          // bottom ↑ top
          for(int i=bottom; i>=top; i--){
            ans[i][left] = num;           // right column ma ith row   
            num++;
          }
          left++;
         
        }

        return ans;

    }
};