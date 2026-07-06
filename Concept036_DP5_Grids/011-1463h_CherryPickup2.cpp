// LC: 1463 h 

// DP Grid6
// 3D dp

// both robots are ate topLeft and topRight
// fix starting point, variable ending point
// we will start recursion from start

class Solution {

      // both robots will always be on same row, so row is shown common i

      int recur(int i, int j1, int j2, vector<vector<int>>& grid){

        int m = grid.size();
        int n = grid[0].size();

        // Base case
        if(j1<0 || j2<0 || j1>=n || j2>=n){
          return INT_MIN;                 // jo grid ma (-ve) values hot to -1e8, cause (-ve) value + INT_MIN --> overflow
        }

        if(i == m-1){           // destination 
          if(j1 == j2) return grid[i][j1];
          else return grid[i][j1] + grid[i][j2];
        }


        int ans = INT_MIN;
        for(int dj1 = -1; dj1 <= 1; dj1++){
          for(int dj2 = -1; dj2 <= 1; dj2++){

            int currVal;
            if(j1 == j2) currVal = grid[i][j1];
            else currVal = grid[i][j1] + grid[i][j2];

            ans = max(ans, currVal + recur(i+1, (j1+dj1), (j2+dj2), grid));
          }
        }
        return ans;
      }

      int recurMemo(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){

        int m = grid.size();
        int n = grid[0].size();

        // Base case
        if(j1<0 || j2<0 || j1>=n || j2>=n){
          return INT_MIN;                 // jo grid ma (-ve) values hot to -1e8, cause (-ve) value + INT_MIN --> overflow
        }

        if(i == m-1){
          if(j1 == j2) return dp[i][j1][j2] = grid[i][j1];
          else return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
        }

        // check dp
        if(dp[i][j1][j2] != -1){
          return dp[i][j1][j2];
        }

        int ans = INT_MIN;
        for(int dj1 = -1; dj1 <= 1; dj1++){
          for(int dj2 = -1; dj2 <= 1; dj2++){

            int currVal;
            if(j1 == j2) currVal = grid[i][j1];
            else currVal = grid[i][j1] + grid[i][j2];

            ans = max(ans, currVal + recurMemo(i+1, (j1+dj1), (j2+dj2), grid, dp));
          }
        }
        return dp[i][j1][j2] = ans;
      }

      int tabulation(vector<vector<int>>& grid){

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

        // Base case
        for(int j1=0; j1<n; j1++){
          for(int j2=0; j2<n; j2++){

            if(j1==j2) dp[m-1][j1][j2] = grid[m-1][j1];
            else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
          }
        }

        for(int i=m-2; i>=0; i--){

          for(int j1=0; j1<n; j1++){
            for(int j2=0; j2<n; j2++){

              int ans = INT_MIN;
              for(int dj1 = -1; dj1 <= 1; dj1++){
                for(int dj2 = -1; dj2 <= 1; dj2++){

                  int currVal;
                  if(j1 == j2) currVal = grid[i][j1];
                  else currVal = grid[i][j1] + grid[i][j2];

                  if(j1+dj1 >= 0 && j1+dj1 < n && j2+dj2 >= 0 && j2+dj2 < n){
                    ans = max(ans, currVal + dp[i+1][j1+dj1][j2+dj2]);
                  }
                }
              }
              dp[i][j1][j2] = ans;
            }
          }
        }
        return dp[0][0][n-1];
      }

      int spaceOpt(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> front(n, vector<int>(n, 0));
        vector<vector<int>> curr(n, vector<int>(n, 0));

        // Base case
        for (int j1 = 0; j1 < n; j1++) {
          for (int j2 = 0; j2 < n; j2++) {
            if (j1 == j2) front[j1][j2] = grid[m-1][j1];
            else front[j1][j2] = grid[m-1][j1] + grid[m-1][j2];
          }
        }

        // fow all rows from m-2
        for (int i = m-2; i >= 0; i--) {

          for (int j1 = 0; j1 < n; j1++) {
            for (int j2 = 0; j2 < n; j2++) {
                
              int ans = INT_MIN;
              for (int dj1 = -1; dj1 <= 1; dj1++) {
                for (int dj2 = -1; dj2 <= 1; dj2++) {       
                  int currVal = (j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2]);

                  if (j1+dj1 >= 0 && j1+dj1 < n && j2+dj2 >= 0 && j2+dj2 < n) {
                      ans = max(ans, currVal + front[j1+dj1][j2+dj2]);
                  }
                }
              }
              curr[j1][j2] = ans;
            }
          }
          swap(front, curr); // move to next row
        }

        return front[0][n-1];
      }


public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        // recursion
        // return recur(0, 0, n-1, grid);

        // topdown
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return recurMemo(0, 0, n-1, grid, dp);

        // bottomUp
        // return tabulation(grid);

        // space optimization
        // return spaceOpt(grid);
    }
};