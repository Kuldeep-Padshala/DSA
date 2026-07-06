// LC: 115 h 

// DP on strings, string matching

class Solution {

      int recur(int i, int j, string& s, string& t){

        // Base case
        if(j<0) return 1;
        if(i<0) return 0;

        if(s[i] == t[j]){
          return recur(i-1, j-1, s, t) + recur(i-1, j, s, t);
        }
        else{
          return recur(i-1, j, s, t);
        }
      }

      long long recurMemo(int i, int j, string& s, string& t, vector<vector<long long>>& dp){

        // Base case
        if(j<0) return 1;
        if(i<0) return 0;

        // Check dp
        if(dp[i][j] != -1){
          return dp[i][j];
        }

        if(s[i] == t[j]){
          return dp[i][j] = recurMemo(i-1, j-1, s, t, dp) + recurMemo(i-1, j, s, t, dp);
        }
        else{
          return dp[i][j] = recurMemo(i-1, j, s, t, dp);
        }
      }

      int tabulation(string& s, string& t){

        int n = n;
        int m = m;
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));

        // Base case
        for (int i=0; i<=n; i++) {
          dp[i][0] = 1;   // empty t
        }

        for(int i=1; i<=n; i++){
          for(int j=1; j<=m; j++){

            if(s[i-1] == t[j-1]){
              dp[i][j] = dp[i-1][j-1] + dp[i-1][j];

              if(dp[i][j] > INT_MAX){
                dp[i][j] = 0;
              }
            }
            else{
              dp[i][j] = dp[i-1][j];
            }
            // if(dp[i][j] > INT_MAX){
            //   dp[i][j] = 0;
            // }
          }
        }
        if (dp[n][m] > INT_MAX) return -1;

        return (int)dp[n][m];
      }

      int spaceOpt(string& s, string& t){
        
        int n = s.size();
        int m = t.size();
        vector<long long> dp(m + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
          for(int j = m; j >= 1; j--){

            if(i - j > n - m) continue;
            if(s[i - 1] == t[j-1]){
              dp[j] += dp[j-1];
            }
          }
        }
        return dp[m];
      }
      
public:
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        if(m>n) return 0;

        // Recursion
        // return recur(n-1, m-1, s, t);

        // TopDown  (TLE)
        // vector<vector<long long>> dp(n, vector<long long>(m, -1));
        // long long ans = recurMemo(n-1, m-1, s, t, dp);

        // if(ans>INT_MAX){
        //   return -1;
        // }
        // return (int)ans;

        // BottomUp
        // return tabulation(s, t);

        // Space Optimization
        return spaceOpt(s, t);
    }
};