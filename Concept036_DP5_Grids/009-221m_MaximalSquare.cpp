// LC: 221 m 

class Solution {

      int recur(int i, int j, vector<vector<char>>& mat, int& maxi){

        if(i>=mat.size() || j>=mat[0].size()){
          return 0;
        }

        int right = recur(i, j+1, mat, maxi);
        int down = recur(i+1, j, mat, maxi);
        int diagonal = recur(i+1, j+1, mat, maxi);

        if(mat[i][j] == '1'){

          int ans = 1 + min(right, min(down, diagonal));
          maxi = max(maxi, ans);
          return ans;
        }
        else{
          return 0;
        }
      }

      int recurMemo(int i, int j, vector<vector<char>>& mat, int& maxi, vector<vector<int>>& dp){

        // base case
        if(i>=mat.size() || j>=mat[0].size()){
          return 0;
        }

        // check dp
        if(dp[i][j] != -1){
          return dp[i][j];
        }

        int right = recurMemo(i, j+1, mat, maxi, dp);
        int down = recurMemo(i+1, j, mat, maxi, dp);
        int diagonal = recurMemo(i+1, j+1, mat, maxi, dp);

        if(mat[i][j] == '1'){

          dp[i][j] = 1 + min(right, min(down, diagonal));
          maxi = max(maxi, dp[i][j]);
          return dp[i][j];
        }
        else{
          return dp[i][j] == 0;
        }
      }

      int tabulation(vector<vector<char>>& mat){

        int m = mat.size();
        int n = mat[0].size();
        int maxi = 0;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=m-1; i>=0; i--){
          for(int j=n-1; j>=0; j--){

              int right = dp[i][j+1];
              int down = dp[i+1][j];
              int diagonal = dp[i+1][j+1];

              if(mat[i][j] == '1'){
                dp[i][j] = 1 + min(right, min(down, diagonal));
                maxi = max(maxi, dp[i][j]);
              }
              else{
                dp[i][j] = 0;
              }
          }
        }
        return pow(maxi, 2);
      }

      int spaceOpt(vector<vector<char>>& mat){

        int m = mat.size();
        int n = mat[0].size();
        int maxi = 0;

        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int i=m-1; i>=0; i--){
          for(int j=n-1; j>=0; j--){

              int right = curr[j+1];
              int down = next[j];
              int diagonal = next[j+1];

              if(mat[i][j] == '1'){
                curr[j] = 1 + min(right, min(down, diagonal));
                maxi = max(maxi, curr[j]);
              }
              else{
                curr[j] = 0;
              }
          }
          next = curr;
        }
        return pow(maxi, 2);
      }

      int spaceOpt2(vector<vector<char>>& mat){

        int m = mat.size();
        int n = mat[0].size();
        int maxi = 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i=m-1; i>=0; i--){
          for(int j=n-1; j>=0; j--){
            if (mat[i][j] == '1') {

              if (i < m-1 && j < n-1) {
                dp[i][j] = 1 + min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]});
              } 
              else {
                dp[i][j] = 1;
              }
              maxi = max(maxi, dp[i][j]);
            }
          }  
        }

        return pow(maxi, 2);

        // this logic od storing data in matrix only instead of dp is failing
        // because char data type can store upto 127. so values are getting overlap.
        // if (i == m - 1 || j == n - 1) {
        //   maxi = max(maxi, mat[i][j] - '0');
        // }
        // else {
        //   if (mat[i][j] == '1') {
        //     int right    = mat[i][j+1] - '0';
        //     int down     = mat[i+1][j] - '0';
        //     int diagonal = mat[i+1][j+1] - '0';
        //     mat[i][j] = 1 + min(right, min(down, diagonal)) + '0';
        //     maxi = max(maxi, mat[i][j] - '0');
        //   }
        // }
      }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        // int m = matrix.size();
        // int n = matrix[0].size();

        // Recursion
        // int maxi = 0;
        // recur(0, 0, matrix, maxi);
        // return pow(maxi, 2);

        // Topdown
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        // int maxi = 0;
        // recurMemo(0, 0, matrix, maxi, dp);
        // return pow(maxi, 2);

        // BottomUp
        // return tabulation(matrix);

        // Space Optimization
        // return spaceOpt(matrix);

        // Space Optimization 2
        return spaceOpt2(matrix);

    }
};