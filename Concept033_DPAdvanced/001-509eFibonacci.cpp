// LC: 509 e 

class Solution {              // nth term of fibonacci

    int solve(int n, vector<int>& dp){

      if(dp[n] != -1){
        return dp[n];
      }
      
      // base case
      if(n <= 1) return n;

      dp[n] = solve(n-1, dp) + solve(n-2, dp);
      return dp[n];
    }
public:
    int fib(int n) {

        // DP TopDown: Recursion + Memorization
        vector<int> dp(n+1, -1);
        return solve(n, dp);

        // DP BottomUp : Tabulation
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];

        // Space Optimization
        vector<int> dp(3, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
          dp[i % 3] = dp[(i - 1) % 3] + dp[(i - 2) % 3];
        }
        return dp[n % 3];

    }
};