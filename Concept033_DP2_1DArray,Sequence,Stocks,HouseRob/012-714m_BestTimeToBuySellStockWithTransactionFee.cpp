// LC: 714 m 

class Solution {

      int recur(int idx, bool canBuy, int* n, int* fee, vector<int>& prices){

        // Base case
        if(idx == *n) return 0;
        

        int profit = 0;
        if(canBuy){
          profit = max( recur(idx+1, false, n, fee, prices) - prices[idx] - (*fee), // bought, so bought value minus, no more buy now
                        recur(idx+1, true, n, fee, prices));                  // not bought today, can buy tomorrow
        }
        else{
          profit = max( recur(idx+1, true, n, fee, prices) + prices[idx],     // sold it, now i can buy again tomorrow
                        recur(idx+1, false, n, fee, prices));                 // not sold yet, no more buy 
        }
        return profit;
      }

      int recurMemo(int idx, int canBuy, int* n, int*fee, vector<int>& prices, vector<vector<int>>& dp){

        // Base case
        if(idx == *n) return 0;

        // Check dp
        if(dp[idx][canBuy] != -1){
          return dp[idx][canBuy];
        }

        int profit = 0;
        if(canBuy){
          profit = max(recurMemo(idx+1, 0, n, fee, prices, dp)-prices[idx]-(*fee),  // bought, so bought value minus, no more buy now
                        recurMemo(idx+1, 1, n, fee, prices, dp));                  // not bought today, can buy tomorrow
        }
        else{
          profit = max( recurMemo(idx+1, 1, n, fee, prices, dp) + prices[idx],     // sold it, now i can buy again tomorrow
                        recurMemo(idx+1, 0, n, fee, prices, dp));                 // not sold yet, no more buy 
        }
        return dp[idx][canBuy] = profit;
      }

      int tabulation(vector<int>& prices, int fee){

        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for(int idx=n-1; idx>=0; idx--) {

          // canBuy = 1
          dp[idx][1] = max(
            dp[idx + 1][0] - prices[idx] - fee,  // buy
            dp[idx + 1][1]                 // skip
          );

          // canBuy = 0
          dp[idx][0] = max(
            dp[idx + 1][1] + prices[idx],  // sell → cooldown
            dp[idx + 1][0]                 // hold
          );
        }
        return dp[0][1];
      }

public:
    int maxProfit(vector<int>& prices, int fee) {
        

        // int n = prices.size();

        // Recursion
        // return recur(0, true, &n, &fee, prices);

        // TopDown
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return recurMemo(0, 1, &n, &fee, prices, dp);

        // BottomUp
        // return tabulation(prices, fee);

        int buy = INT_MIN, sell = 0;
        for (auto p: prices) {
            if (p > fee)
                sell = max(sell, p - fee + buy);
            buy = max(buy, sell - p);
        }
        return sell;
    }
};