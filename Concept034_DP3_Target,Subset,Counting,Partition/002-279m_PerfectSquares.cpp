// LC: 279 m 

class Solution {
  
      int recur(int n){

        // Base case
        if(n==0){
          return 0;
        }

        int ans = n;
        for(int i=1; i*i <= n; i++){
          // int temp = i*i;
          ans = min(ans, 1+recur(n-(i*i)));
        }
        return ans;
      }

      int recurMemo(int n, vector<int>& dp){

        // Base case
        if(n==0){
          return dp[0] = 0;
        }

        // check dp
        if(dp[n] != -1){
          return dp[n];
        }

        int ans = n;
        for(int i=1; i*i <= n; i++){
          // int temp = i*i;
          ans = min(ans, 1 + recurMemo(n-(i*i), dp) );
        }
        return dp[n] = ans;
      }

      int tabulation(int n){

        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int num = 1; num<=n; num++){

          for(int i=1; i*i<=n; i++){
            if(num - (i*i) >= 0){
              dp[num] = min(dp[num], dp[num - (i*i)] + 1);
            }
          }
        }
        return dp[n];
      }

public:
    int numSquares(int n) {

        // Recursion (TLE)
        // return recur(n);

        // TopDown
        // vector<int> dp(n+1, -1);
        // return recurMemo(n, dp);

        // BottomUp
        return tabulation(n);
    }
};