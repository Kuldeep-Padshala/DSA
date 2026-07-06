// LC 498 m 

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans;

        bool isUp = true;
        int curr = mat[0][0];
        int row = 0, col = 0;
        int total = m*n;
        int cnt = 0;

        while(cnt != total){

          ans.push_back(mat[row][col]);
          cnt++;
          if(isUp){
            if(row-1 >= 0 && col+1 < n){
              row = row-1;
              col = col+1;
            }
            else{
              isUp = !isUp;
              if(col+1<n) col = col+1;
              else row = row+1;
            }
          }

          else{
            if(row+1 < m && col-1 >= 0){
              row = row+1;
              col = col-1;
            }
            else{
              isUp = !isUp;
              if(row+1<m) row = row+1;
              else col = col+1;
            }
          }
        }
        return ans;
    }
};