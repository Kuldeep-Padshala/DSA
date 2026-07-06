// LC: 62 m 

// DP distict way, DP Grid1 [ (0,0) to (m,n) ]
// evry time finding paths(upwards and leftward) and Sum up

class Solution {

      int recur(int i, int j){      // starts with m-1, n-1
        
        // Base cases
        if(i==0 && j==0){     // reached
          return 1;
        }
        if(i<0 || j<0){       //  invalid
          return 0;
        }

        int up = recur(i-1, j);
        int left = recur(i, j-1);

        return up + left;     // sum up
      }

      // here, top guy went down down down in order to get ans
      int recurMemo(int i, int j, vector<vector<int>>& dp){
        
        // Base cases
        if(i==0 && j==0){
          return 1;
        }
        if(i<0 || j<0){
          return 0;
        }

        // check dp
        if(dp[i][j] != -1){
          return dp[i][j];
        }

        int up = recurMemo(i-1, j, dp);
        int left = recurMemo(i, j-1, dp);

        return dp[i][j] = up + left;
      }

      // go from down to top, 
      int tabulation(int m, int n){

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
            
            if(i==0 && j==0){
              continue;
            }
            int up = (i!=0) ? dp[i-1][j] : 0;
            int left = (j!=0) ? dp[i][j-1] : 0;

            dp[i][j] = up + left;
          }
        }
        return dp[m-1][n-1];
      }

      int spaceOpt(int m, int n){

        vector<int> prev(n, 0);

        for(int i=0; i<m; i++){

          vector<int> curr(n, 0);
          for(int j=0; j<n; j++){
            
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

      // baki
      int timeOpt(int m, int n){
        
        int N = n + m - 2;
        int r = m - 1;

        double ans = 1;
        for(int i=1; i<=r; i++){
          ans = ans * (N - r + i) / i;
        }
        return (int)ans;
      }

public:
    int uniquePaths(int m, int n) {
        
        // Recursion
        // return recur(m-1, n-1);

        // TopDown
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return recurMemo(m-1, n-1, dp);

        // BottomUp
        return tabulation(m, n);

        // space optimization
        // return spaceOpt(m, n);

        // combinatorics formula, time optimization, not a dp
        // return timeOpt(m, n);
    }
};