// LC: 309 m 

class Solution {

      int recur(int idx, bool canBuy, int* n, vector<int>& prices){

        // Base case
        if(idx >= *n) return 0;
        

        int profit = 0;
        if(canBuy){
          profit = max( recur(idx+1, false, n, prices) - prices[idx],    // bought, so bought value minus, no more buy now
                        recur(idx+1, true, n, prices));                  // not bought today, can buy tomorrow
        }
        else{
          profit = max( recur(idx+2, true, n, prices) + prices[idx],     // sold it, now i can buy again tomorrow
                        recur(idx+1, false, n, prices));                 // not sold yet, no more buy 
        }
        return profit;
      }

      int recurMemo(int idx, int canBuy, int* n, vector<int>& prices, vector<vector<int>>& dp){

        // Base case
        if(idx >= *n) return 0;

        // Check dp
        if(dp[idx][canBuy] != -1){
          return dp[idx][canBuy];
        }

        int profit = 0;
        if(canBuy){
          profit = max( recurMemo(idx+1, 0, n, prices, dp) - prices[idx],    // bought, so bought value minus, no more buy now
                        recurMemo(idx+1, 1, n, prices, dp));                  // not bought today, can buy tomorrow
        }
        else{
          profit = max( recurMemo(idx+2, 1, n, prices, dp) + prices[idx],     // sold it, now i can buy again tomorrow
                        recurMemo(idx+1, 0, n, prices, dp));                 // not sold yet, no more buy 
        }
        return dp[idx][canBuy] = profit;
      }

      int tabulation(vector<int>& prices){

        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for(int idx=n-1; idx>=0; idx--) {

          // canBuy = 1
          dp[idx][1] = max(
            dp[idx + 1][0] - prices[idx],  // buy
            dp[idx + 1][1]                 // skip
          );

          // canBuy = 0
          dp[idx][0] = max(
            dp[idx + 2][1] + prices[idx],  // sell → cooldown
            dp[idx + 1][0]                 // hold
          );
        }
        return dp[0][1];
      }

public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        // Recursion
        // return recur(0, true, &n, prices);

        // TopDown
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return recurMemo(0, 1, &n, prices, dp);

        // BottomUp
        return tabulation(prices);
    }
};