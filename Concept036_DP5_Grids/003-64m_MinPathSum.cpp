// LC: 64 m 

// Why not greedy
// Cause there's not uniformity in the pattern leke increase onstantly or decreasing.
// With greedy, we will choose smallest from current (down or right)
// so "today's descision might affect tommorow" (if increased huge)

// DP Grid3 [ (0,0) to (m,n) ],  min sum
// Explore all paths and then tell best(min)

class Solution {

      int recur(int i, int j, vector<vector<int>>& grid){

        // Base cases
        if(i==0 && j==0){        // Reached
          return grid[0][0];
        }
        if(i<0 || j<0){          // Invalid, give ans that can not be considered
          return INT_MAX;
        }

        int up = recur(i-1, j, grid);
        int left = recur(i, j-1, grid);

        return grid[i][j] + min(up, left);
      }

      int recurMemo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){

        // Base cases
        if(i==0 && j==0){
          return grid[0][0];
        }
        if(i<0 || j<0){
          return INT_MAX;
        }

        // check dp
        if(dp[i][j] != -1){
          return dp[i][j];
        }

        int up = recurMemo(i-1, j, grid, dp);
        int left = recurMemo(i, j-1, grid, dp);

        return dp[i][j] = grid[i][j] + min(up, left);
      }

      int tabulation(vector<vector<int>>& grid){

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));   // initialize dp with 0 or INT_MAX

        dp[0][0] = grid[0][0];
        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){

            if(i==0 && j==0) continue;

            int up = (i!=0) ? dp[i-1][j] : INT_MAX;
            int left = (j!=0) ? dp[i][j-1] : INT_MAX;

            dp[i][j] = grid[i][j] + min(up, left);
          }
        }
        return dp[m-1][n-1];
      }

      int spaceOpt(vector<vector<int>>& grid){

        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);
        prev[0] = grid[0][0];

        for(int i=0; i<m; i++){

          vector<int> curr(n, 0);

          for(int j=0; j<n; j++){

            if(i==0 && j==0){
              curr[0] = grid[0][0];
              continue;
            }

            int up = (i!=0) ? prev[j] : INT_MAX;
            int left = (j!=0) ? curr[j-1] : INT_MAX;

            curr[j] = grid[i][j] + min(up, left);
          }
          prev = curr;
        }
        return prev[n-1];
      }

public:
    int minPathSum(vector<vector<int>>& grid) {
        
        // int m = grid.size();
        // int n = grid[0].size();

        // Recursion
        // return recur(m-1, n-1, grid);

        // TopDown
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return recurMemo(m-1, n-1, grid, dp);

        // BottomUp
        // return tabulation(grid);

        // Space optimization
        return spaceOpt(grid);
    }
};