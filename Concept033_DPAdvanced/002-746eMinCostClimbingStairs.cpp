// LC: 746 e 

class Solution {

      int solve(int n, vector<int>& dp, vector<int>& cost){

        if(dp[n] != -1){
          return dp[n];
        }
        // Base case
        if(n<=1){
          return cost[n];
        }

        // Add memorization
        dp[n] = cost[n] + min(solve(n-1, dp, cost), solve(n-2, dp, cost));
        return dp[n];
      }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();

        // ------------------ TopDown: Recursion + Memoization ------------------
        // vector<int> dp(n+1, -1);
        // return min(solve(n-1, dp, cost), solve(n-2, dp, cost));



        // ------------------  BottomUp: Tabulation  ---------------------

        // vector<int> dp(n+1, -1);
        // dp[0] = cost[0];
        // dp[1] = cost[1];
        // for(int i = 2; i < n; i++) {
        //   dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        // }
        // // cost[n] not exist, need to handle this case separately 
        // return min(dp[n-1], dp[n-2]);



        // ------------------ BottomUp Space Optimization  ---------------------

        vector<int> dp(3, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++) {
          dp[i%3] = min(dp[(i-1)%3], dp[(i-2)%3]) + cost[i];
        }
        return min(dp[(n-1)%3], dp[(n-2)%3]);
    }
};