// LC: 1289 h 

// DP Grid5

class Solution {

      int tabulation(vector<vector<int>>& grid){

        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case
        int ans = INT_MAX;
        for(int j=0; j<n; j++) {
          dp[0][j] = grid[0][j];

          if(n==1){
            ans = min(ans, dp[0][j]);
          }
        }

        if(n==1) return ans;

        for(int i=1; i<n; i++){
          for(int j=0; j<n; j++){
            
            int best = INT_MAX;
            for (int k = 0; k < n; k++) {
              if (k == j) continue;
              best = min(best, dp[i-1][k]);
            }
            dp[i][j] = grid[i][j] + best;

            if(i==n-1){
              ans = min(ans, dp[n-1][j]);
            }
            
          }
        }
        return ans;
      }

      int spaceOpt(vector<vector<int>>& grid){
        
        int n = grid.size();
        vector<int> prev(n, 0), curr(n, 0);

        int ans = INT_MAX;

        // Base case
        for(int j = 0; j < n; j++){
          prev[j] = grid[0][j];

          if(n==1){
            ans = min(ans, prev[j]);
          }
        }
        if(n==1) return ans;

        for(int i=1; i<n; i++){

          for (int j=0; j<n; j++){
              
            int best = INT_MAX;

            for(int k = 0; k < n; k++){
              if (k == j) continue;
              best = min(best, prev[k]);
            }
            curr[j] = grid[i][j] + best;

            if(i == n-1){
              ans = min(ans, curr[j]);
            }
          }
          prev = curr;
        }

        return ans;
      }


public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        // BottomUp
        // return tabulation(grid);

        // Space Optimization
        return spaceOpt(grid);
    } 
};