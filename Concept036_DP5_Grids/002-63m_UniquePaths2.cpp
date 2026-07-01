// LC: 63 m 

// DP distict way, DP Grid2 [ (0,0) to (m,n) ]

class Solution {

      int recur(int i, int j, vector<vector<int>>& grid){
        
        // Base cases
        if(i==0 && j==0){      // Reached
          return 1;
        }
        if(i<0 || j<0){        // Invalid
          return 0;
        }
        if(grid[i][j] == 1){   // Obstacle
          return 0;
        }

        int up = recur(i-1, j, grid);
        int left = recur(i, j-1, grid);

        return up + left;
      }

      int recurMemo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        
        // Base cases
        if(i==0 && j==0){
          return 1;
        }
        if(i<0 || j<0){
          return 0;
        }
        if(grid[i][j] == 1){
          return 0;
        }

        if(dp[i][j] != -1){
          return dp[i][j];
        }
        int up = recurMemo(i-1, j, grid, dp);
        int left = recurMemo(i, j-1, grid, dp);

        return dp[i][j] = up + left;
      }

      int tabulation(int m, int n, vector<vector<int>>& grid){

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
            
            if(i==0 && j==0){
              continue;
            }
            if(grid[i][j] == 1){
              continue;
            }
            int up = (i!=0) ? dp[i-1][j] : 0;
            int left = (j!=0) ? dp[i][j-1] : 0;

            dp[i][j] = up + left;
          }
        }
        return dp[m-1][n-1];
      }

      int spaceOpt(int m, int n, vector<vector<int>>& grid){

        vector<int> prev(n, 0);

        for(int i=0; i<m; i++){

          vector<int> curr(n, 0);
          for(int j=0; j<n; j++){
            
            if(grid[i][j] == 1){
              continue;
            }
            if(i==0 && j==0){
              curr[j] = 1;
              continue;
            }
            int up = (i!=0) ? prev[j] : 0;
            int left = (j!=0) ? curr[j-1] : 0;

            curr[j] = up + left;
          }
          prev = curr;
        }
        return prev[n-1];
      }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1){
          return 0;
        }

        // Recursion
        // return recur(m-1, n-1, obstacleGrid);

        // TopDown
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return recurMemo(m-1, n-1, obstacleGrid, dp);

        // BottomUp
        // return tabulation(m, n, obstacleGrid);

        // space optimization
        return spaceOpt(m, n, obstacleGrid);
    }
};