// LC: 375 m 

class Solution {

      int recur(int s, int e){

        // base case
        if(s>=e){
          return 0;
        }
        
        int ans = INT_MAX;
        for(int i=s; i<=e; i++){
          ans = min(ans, i+max(recur(s, i-1), recur(i+1, e)));
        }
        return ans;
      }

      int recurMemo(int s, int e, vector<vector<int>>& dp){

        // base case
        if(s>=e){
          return 0;
        }

        //check dp
        if(dp[s][e] != -1){
          return dp[s][e];
        }
        
        int ans = INT_MAX;
        for(int i=s; i<=e; i++){
          ans = min(ans, i+max(recurMemo(s, i-1, dp), recurMemo(i+1, e, dp)));
        }
        return dp[s][e] = ans;
      }

      int tabulation(int n){

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int s=n; s>=1; s--){
          for(int e=s+1; e<=n; e++){

            int ans = INT_MAX;
            for(int i=s; i<=e; i++) {
              ans = min(ans, i + max(dp[s][i - 1], dp[i + 1][e]));
            }

            dp[s][e] = ans;
          }
        }
        return dp[1][n];
      }

public:
    int getMoneyAmount(int n) {
        
        // Recursion
        // return recur(1, n);

        // TopDown
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return recurMemo(1, n, dp);

        // BottomUp
        return tabulation(n);
    }
};