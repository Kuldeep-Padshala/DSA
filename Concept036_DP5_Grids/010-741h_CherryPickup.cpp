// LC: 741 h 

// fixed starting and ending

class Solution {

      int recur(int i1, int j1, int i2, vector<vector<int>>& grid) {
        
        int n = grid.size();
        int j2 = i1 + j1 - i2;    // since steps are same

        // Base case
        if (i1>=n || j1>=n || i2>=n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) {
          return INT_MIN;
        }

        if(i1 == n-1 && j1 == n-1){
          return grid[n-1][n-1];
        }

        int cherries = 0;
        if (i1 == i2 && j1 == j2){
          cherries = grid[i1][j1];
        }
        else{
          cherries = grid[i1][j1] + grid[i2][j2];
        }

        // Both move: (down, right) × (down, right)
        int best = max({
          recur(i1+1, j1, i2+1, grid), // both down
          recur(i1, j1+1, i2, grid),   // p1 right, p2 right
          recur(i1+1, j1, i2, grid),   // p1 down, p2 right
          recur(i1, j1+1, i2+1, grid)  // p1 right, p2 down
        });

        return cherries + best;
      }

      int recurMemo(int i1, int j1, int i2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        
        int n = grid.size();
        int j2 = i1 + j1 - i2;    // since steps are same

        // Base case
        if (i1>=n || j1>=n || i2>=n || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) {
          return INT_MIN;
        }

        if(i1 == n-1 && j1 == n-1){
          return grid[n-1][n-1];
        }

        // check dp
        if(dp[i1][j1][i2] != -1){
          return dp[i1][j1][i2];
        }

        int cherries = 0;
        if (i1 == i2 && j1 == j2){
          cherries = grid[i1][j1];
        }
        else{
          cherries = grid[i1][j1] + grid[i2][j2];
        }

        // Both move: (down, right) × (down, right)
        int best = max({
          recurMemo(i1+1, j1, i2+1, grid, dp), // both down
          recurMemo(i1, j1+1, i2, grid, dp),   // p1 right, p2 right
          recurMemo(i1+1, j1, i2, grid, dp),   // p1 down, p2 right
          recurMemo(i1, j1+1, i2+1, grid, dp)  // p1 right, p2 down
        });

        // if (best == INT_MIN) {
        //   return dp[i1][j1][i2] = INT_MIN;
        // }
        return dp[i1][j1][i2] = cherries + best;
      }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();

        // Recursion
        // return max(0, recur(0, 0, 0, grid));

        // topDown
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, recurMemo(0, 0, 0, grid, dp));
    }
};