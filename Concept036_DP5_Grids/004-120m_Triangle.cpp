// LC: 120 m 

// DP Grid4 [ (0,0) to Last row ],  min sum
// variable ending point
// recursion will starts from (0,0) to last row and tabulation is opposite

class Solution {

      // start recursion from single point (0, 0)
      int recur(int row, int idx, vector<vector<int>>& triangle) {
        
        // Base case
        if (row == triangle.size()-1){     // final row
          return triangle[row][idx];
        }

        int downLeft = triangle[row][idx] + recur(row+1, idx, triangle);
        int downRight = triangle[row][idx] + recur(row+1, idx+1, triangle);

        return min(downLeft, downRight);
      }

      int recurMemo(int row, int idx, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        
        // Base case
        if(row == triangle.size()-1){
          return dp[row][idx] = triangle[row][idx];
        }

        // Check dp
        if(dp[row][idx] != -1){
          return dp[row][idx];
        }

        int downLeft = triangle[row][idx] + recurMemo(row+1, idx, triangle, dp);
        int downRight = triangle[row][idx] + recurMemo(row+1, idx+1, triangle, dp);

        return dp[row][idx] = min(downLeft, downRight);
      }

      int tabulation(vector<vector<int>>& triangle){

        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case
        for(int idx=0; idx<n; idx++){
          dp[n-1][idx] = triangle[n-1][idx];
        }

        for(int row=n-2; row>=0; row--){

          for(int idx=row; idx>=0; idx--){
            
            int downLeft = triangle[row][idx] + dp[row+1][idx];
            int downRight = triangle[row][idx] + dp[row+1][idx+1];

            dp[row][idx] = min(downLeft, downRight);
          }

          // for(int idx=0; idx<=row; idx++){           // another way
            
          //   int downLeft = triangle[row][idx] + dp[row+1][idx];
          //   int downRight = triangle[row][idx] + dp[row+1][idx+1];

          //   dp[row][idx] = min(downLeft, downRight);
          // }
        }
        return dp[0][0];
      }

      int spaceOpt(vector<vector<int>>& triangle){

        int n = triangle.size();
        vector<int> next(n, 0);

        // Base case
        for(int idx=0; idx<n; idx++){
          next[idx] = triangle[n-1][idx];
        }

        for(int row=n-2; row>=0; row--){

          vector<int> curr(n, 0);

          for(int idx=row; idx>=0; idx--){
            
            int downLeft = triangle[row][idx] + next[idx];
            int downRight = triangle[row][idx] + next[idx+1];

            curr[idx] = min(downLeft, downRight);
          }
          next = curr;
        }
        return next[0];
      }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        // int n = triangle.size();
        // Recursion
        // return recur(0, 0, triangle);

        // TopDown
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return recurMemo(0, 0, triangle, dp);

        // BottomUp
        return tabulation(triangle);

        // Space optimization
        // return spaceOpt(triangle);
    }
};