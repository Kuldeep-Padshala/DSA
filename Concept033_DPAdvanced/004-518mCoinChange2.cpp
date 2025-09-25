// LC: 518 m 

class Solution {

      int solve(int n, vector<int>& dp, vector<int>& coins){

        // Base case
        if(n == 0) return 0;
        // Invalid
        if(n < 0) return INT_MAX;

        if(dp[n] != -1){
          return dp[n];
        }

        // Adding Memorization
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){

          int val = solve(n-coins[i], dp, coins);
          if(val != INT_MAX){
            //           counting ith coin, so +1
            mini = min(mini, val+1);
          }
        }
        return mini;
      }
public:
    int coinChange(vector<int>& coins, int amount) {

        // ------------------ TopDown: Recursion + Memoization ------------------
        vector<int> dp(amount+1, -1);
        int ans = solve(amount, dp, coins);

        if(ans != INT_MAX) return ans;
        else return -1;

        // ------------------  BottomUp: Tabulation  ---------------------
        // vector<int> dp(amount+1, INT_MAX);
        // dp[0] = 0;

        // for(int i=1; i<=amount; i++){

        //   for(int c : coins){

        //     if( i-c >= 0 && dp[i-c] != INT_MAX){
        //       // 
        //       dp[i] = min(dp[i], dp[i-c] + 1);
        //     }
        //   }
        // }
        // if(dp[amount] != INT_MAX) return dp[amount];
        // else return -1;
    }
};