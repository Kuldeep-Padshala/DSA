// LC: 2643 e

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans(2,-1);

        for(int i=0; i<m; i++){

          int count = 0;

          for(int j=0; j<n; j++){     
            if(mat[i][j] == 1){
              count++;
            }
          }

          if(count > ans[1]){
            ans[1] = count;
            ans[0] = i;
          }
        }
        return ans;
    }
};